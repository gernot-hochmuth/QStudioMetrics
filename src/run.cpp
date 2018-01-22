
#include "run.h"
#include "qstudiometricstypes.h"

#include <QtCore>
#include <QThread>
#include <QThreadPool>
#include <QtConcurrent/QtConcurrent>

#include <scientific.h>

#include <cstdlib>
#include <ctime>

void RUN::DoClusterValidation()
{
  if(vt == BOOTSTRAPRGCV_){
    KMeansRandomGroupsCV(m, nmaxclusters, clusteralgoritm, ngroup, niter, &dv, &scientifisignal);
  }
  else{
    KMeansJumpMethod(m, nmaxclusters, clusteralgoritm, &dv, &scientifisignal);
  }
}

void RUN::DoClustering()
{
  if(objselectiontype == 3){ /*get all objects...*/
    if(clusteralgoritm < 4){
      KMeans(m, nclusters, clusteralgoritm, &uiv, NULL, &scientifisignal);
    }
    else{
      HierarchicalClustering(m, nclusters, &uiv, NULL, &dendogram, (enum LinkageType)linktype, &scientifisignal);
    }
  }
  else{
    matrix *centroids;
    initMatrix(&centroids);
    KMeans(m, nclusters, clusteralgoritm, &uiv, &centroids, &scientifisignal);
    PruneResults(m, centroids, nmaxobjects, objselectiontype, uiv);
    DelMatrix(&centroids);
  }
}

void RUN::DoRandomSelection()
{
  srand(time(0));
  uint i = 0;
  while(i < nobjects){
    if(scientifisignal == SIGSCIENTIFICSTOP){
      break;
    }
    else{
      uint id = rand() % maxnobjects;
      if(id < maxnobjects){
        bool getid = true;
        for(uint j = 0; j < uiv->size; j++){
          if(getUIVectorValue(uiv, j) != id){
            continue;
          }
          else{
            getid = false;
          }
        }

        if(getid == true){
          UIVectorAppend(&uiv, id);
          i++;
        }
        else{
          continue;
        }
      }
      else{
        continue;
      }
    }
  }
}

void RUN::DoMaxDisSelection()
{
  MaxDis(m, nobjects, metric, &uiv, &scientifisignal);
}

void RUN::DoMDCSelection()
{
  MDC(m, nobjects, metric, &uiv, &scientifisignal);
}

void RUN::DoLDAPrediction()
{
  uivector *py = ldamodel->getLastLDAPrediction()->getPredClasses();
  matrix *pfeatures = ldamodel->getLastLDAPrediction()->getPredFeatures();
  matrix *probpred = ldamodel->getLastLDAPrediction()->getProbPred();
  matrix *mvnpfd = ldamodel->getLastLDAPrediction()->getMVNProbDistrib();
  LDAPrediction(x, ldamodel->Model(), &pfeatures, &probpred, &mvnpfd, &py);
}

void RUN::DoLDAValidation()
{
  DelDVector(&ldamodel->Model()->sens);
  DelDVector(&ldamodel->Model()->spec);
  DelDVector(&ldamodel->Model()->ppv);
  DelDVector(&ldamodel->Model()->npv);
  DelDVector(&ldamodel->Model()->acc);

  initDVector(&ldamodel->Model()->sens);
  initDVector(&ldamodel->Model()->spec);
  initDVector(&ldamodel->Model()->ppv);
  initDVector(&ldamodel->Model()->npv);
  initDVector(&ldamodel->Model()->acc);

  if(vt == LOO_){ // Leave One Out
    LDALOOCV(x, uiv,
                      &ldamodel->Model()->sens,
                      &ldamodel->Model()->spec,
                      &ldamodel->Model()->ppv,
                      &ldamodel->Model()->npv,
                      &ldamodel->Model()->acc,
                      QThread::idealThreadCount(), &scientifisignal);
  }
  else{ // Cross Validation
    LDARandomGroupsCV(x, uiv,
                      ngroup, niter,
                      &ldamodel->Model()->sens,
                      &ldamodel->Model()->spec,
                      &ldamodel->Model()->ppv,
                      &ldamodel->Model()->npv,
                      &ldamodel->Model()->acc,
                      QThread::idealThreadCount(), &scientifisignal);
  }
}

void RUN::DoLDA()
{
  LDA(x, uiv, ldamodel->Model());
}

void RUN::DoMLRPrediction()
{
  if(y != 0 && y->row > 0 && y->col > 0){
    MLRPredictY(x, y, mlrmodel->Model(),
                mlrmodel->getLastMLRPrediction()->YDipVarPointer(),
                NULL,
                mlrmodel->getLastMLRPrediction()->R2YPointer(),
                mlrmodel->getLastMLRPrediction()->SDECPointer());
  }
  else{
    MLRPredictY(x, NULL, mlrmodel->Model(),
                mlrmodel->getLastMLRPrediction()->YDipVarPointer(),
                NULL,
                NULL,
                NULL);
  }
}

void RUN::DoMLRValidation()
{
  DelDVector(&mlrmodel->Model()->q2y);
  DelDVector(&mlrmodel->Model()->sdep);
  DelDVector(&mlrmodel->Model()->bias);
  DelMatrix(&mlrmodel->Model()->predicted_y);
  DelMatrix(&mlrmodel->Model()->r2q2scrambling);

  initDVector(&mlrmodel->Model()->q2y);
  initDVector(&mlrmodel->Model()->sdep);
  initDVector(&mlrmodel->Model()->bias);
  initMatrix(&mlrmodel->Model()->predicted_y);
  initMatrix(&mlrmodel->Model()->r2q2scrambling);

  MODELINPUT minpt;
  minpt.mx = &x;
  minpt.my = &y;
  minpt.nlv = 0;
  minpt.xautoscaling = 0;
  minpt.yautoscaling = 0;

  if(vt == LOO_){ // Leave One Out
    LeaveOneOut(&minpt, _MLR_, &mlrmodel->Model()->predicted_y, &mlrmodel->Model()->pred_residuals, QThread::idealThreadCount(), &scientifisignal, 0);
  }
  else{
    BootstrapRandomGroupsCV(&minpt, ngroup, niter, _MLR_, &mlrmodel->Model()->predicted_y, &mlrmodel->Model()->pred_residuals, QThread::idealThreadCount(), &scientifisignal, 0);
  }

  MLRRegressionStatistics(y, mlrmodel->Model()->predicted_y, &mlrmodel->Model()->q2y, &mlrmodel->Model()->sdep, &mlrmodel->Model()->bias);

  if(yscrambling == true){
    ValidationArg varg;
    if(vt == LOO_){
      varg.vtype = LOO;
    }
    else{
      varg.vtype = BootstrapRGCV;
      varg.rgcv_group = ngroup;
      varg.rgcv_iterations = niter;
    }
    YScrambling(&minpt, _PLS_, varg, block, &mlrmodel->Model()->r2q2scrambling, QThread::idealThreadCount(), &scientifisignal);
  }
}

void RUN::DoMLR()
{
  MLR(x, y, mlrmodel->Model(), &scientifisignal);
}


void RUN::DoPLSPrediction()
{

  // we go from 1 because for 0 component no value can be calculated.
  PLSYPredictorAllLV(x, plsmod->Model(), plsmod->getLastPLSPrediction()->XPredScoresPointer(),plsmod->getLastPLSPrediction()->YDipVarPointer());

  if(y != 0 && y->col > 0){ // calculate the R2 for the prediction
    PLSRegressionStatistics(y, plsmod->getLastPLSPrediction()->getYDipVar(), plsmod->getLastPLSPrediction()->R2YPointer(), plsmod->getLastPLSPrediction()->SDECPointer(), NULL);
  }
}

void RUN::DoPLSValidation()
{
  DelMatrix(&plsmod->Model()->q2y);
  DelMatrix(&plsmod->Model()->sdep);
  DelMatrix(&plsmod->Model()->bias);
  DelMatrix(&plsmod->Model()->predicted_y);
  DelMatrix(&plsmod->Model()->pred_residuals);

  initMatrix(&plsmod->Model()->q2y);
  initMatrix(&plsmod->Model()->sdep);
  initMatrix(&plsmod->Model()->bias);
  initMatrix(&plsmod->Model()->predicted_y);
  initMatrix(&plsmod->Model()->pred_residuals);

  MODELINPUT minpt;
  minpt.mx = &x;
  minpt.my = &y;
  minpt.nlv = plsmod->getNPC();
  minpt.xautoscaling = plsmod->getXScaling();
  minpt.yautoscaling = plsmod->getYScaling();

  if(vt == LOO_){ // Leave One Out
    LeaveOneOut(&minpt, _PLS_, &plsmod->Model()->predicted_y, &plsmod->Model()->pred_residuals, QThread::idealThreadCount(), &scientifisignal, 0);
  }
  else{
    BootstrapRandomGroupsCV(&minpt, ngroup, niter, _PLS_, &plsmod->Model()->predicted_y, &plsmod->Model()->pred_residuals, QThread::idealThreadCount(), &scientifisignal, 0);
  }
  if(algtype == PLS_)
    PLSRegressionStatistics(y, plsmod->Model()->predicted_y, &plsmod->Model()->q2y, &plsmod->Model()->sdep, &plsmod->Model()->bias);
  else
    PLSDiscriminantAnalysisStatistics(y, plsmod->Model()->predicted_y, &plsmod->Model()->roc_validation, &plsmod->Model()->roc_auc_validation, &plsmod->Model()->precision_recall_validation, &plsmod->Model()->precision_recall_ap_validation);

  if(yscrambling == true){
    DelMatrix(&plsmod->Model()->yscrambling);
    initMatrix(&plsmod->Model()->yscrambling);
    ValidationArg varg;
    if(vt == LOO_){
      varg.vtype = LOO;
    }
    else{
      varg.vtype = BootstrapRGCV;
      varg.rgcv_group = ngroup;
      varg.rgcv_iterations = niter;
    }
    YScrambling(&minpt, _PLS_, varg, block, &plsmod->Model()->yscrambling, QThread::idealThreadCount(), &scientifisignal);
  }
}

void RUN::DoPLS()
{
  PLS(x, y, pc, xscaling, yscaling, plsmod->Model(), &scientifisignal);
  if(algtype == PLS_)
    PLSRegressionStatistics(y, plsmod->Model()->recalculated_y, &plsmod->Model()->r2y_model, &plsmod->Model()->sdec, NULL);
  else
    PLSDiscriminantAnalysisStatistics(y, plsmod->Model()->recalculated_y, &plsmod->Model()->roc_model, &plsmod->Model()->roc_auc_model, &plsmod->Model()->precision_recall_model, &plsmod->Model()->precision_recall_ap_model);
}

void RUN::DoPCAPrediction()
{
  PCAScorePredictor(x,
                    pcamod->Model(),
                    pcamod->getNPC(),
                    pcamod->getLastPCAPrediction()->PredScoresPointer());
}

void RUN::DoPCA()
{
  PCA(x, xscaling, pc, pcamod->Model(), &scientifisignal);
}

QFuture< void > RUN::RunClusterValidation()
{
  return QtConcurrent::run(this, &RUN::DoClusterValidation);
}

QFuture< void > RUN::RunClustering()
{
  return QtConcurrent::run(this, &RUN::DoClustering);
}

QFuture< void > RUN::RunRandomSelection()
{
  return QtConcurrent::run(this, &RUN::DoRandomSelection);
}

QFuture< void > RUN::RunMaxDisSelection()
{
  return QtConcurrent::run(this, &RUN::DoMaxDisSelection);
}

QFuture< void > RUN::RunMDCSelection()
{
  return QtConcurrent::run(this, &RUN::DoMDCSelection);
}

QFuture< void > RUN::RunLDAPrediction()
{
  return QtConcurrent::run(this, &RUN::DoLDAPrediction);
}

QFuture< void > RUN::RunLDAValidation()
{
  return QtConcurrent::run(this, &RUN::DoLDAValidation);
}

QFuture< void > RUN::RunLDA()
{
  return QtConcurrent::run(this, &RUN::DoLDA);
}

QFuture< void > RUN::RunMLRPrediction()
{
  return QtConcurrent::run(this, &RUN::DoMLRPrediction);
}

QFuture< void > RUN::RunMLRValidation()
{
  return QtConcurrent::run(this, &RUN::DoMLRValidation);
}

QFuture< void > RUN::RunMLR()
{
  return QtConcurrent::run(this, &RUN::DoMLR);
}

QFuture< void > RUN::RunPLSPrediction()
{
  return QtConcurrent::run(this, &RUN::DoPLSPrediction);
}

QFuture< void > RUN::RunPLSValidation(int algtype_)
{
  algtype = algtype_;
  return QtConcurrent::run(this, &RUN::DoPLSValidation);
}

QFuture< void > RUN::RunPLS(int algtype_)
{
  algtype = algtype_;
  return QtConcurrent::run(this, &RUN::DoPLS);
}

QFuture< void > RUN::RunPCAPrediction()
{
  return QtConcurrent::run(this, &RUN::DoPCAPrediction);
}

QFuture< void > RUN::RunPCA()
{
  return QtConcurrent::run(this, &RUN::DoPCA);
}

void RUN::setNMaxClusters(int nmaxclusters_)
{
  nmaxclusters = nmaxclusters_;
}

void RUN::setNMaxObjects(int nmaxobjects_)
{
  nmaxobjects = nmaxobjects_;
}

void RUN::setObjectSelectionType(int objselectiontype_)
{
  objselectiontype = objselectiontype_;
}

void RUN::setLinkType(int linktype_)
{
  linktype = linktype_;
}

void RUN::setClusteringAlgorithm(int clusteralgoritm_)
{
  clusteralgoritm = clusteralgoritm_;
}

void RUN::setNumberOfCluster(uint nclusters_)
{
  nclusters = nclusters_;
}

void RUN::setNumberMaxOfObject(uint maxnobjects_)
{
  maxnobjects = maxnobjects_;
}

void RUN::setNumberOfObject(uint nobjects_)
{
  nobjects = nobjects_;
}

void RUN::setMetric(int metric_)
{
  if(metric_ == EUCLIDEANDISTANCE){
    metric = 0;
  }
  else if(metric_ == MANHATTANDISTANCE){
    metric = 1;
  }
  else{
    metric = 2;
  }
}

void RUN::setDendogramVector(strvector* dendogram_)
{
  dendogram = dendogram_;
}

void RUN::setDVector(dvector* dv_)
{
  dv = dv_;
}

void RUN::setUIVector(uivector* uiv_)
{
  uiv = uiv_;
}

void RUN::setMatrix(matrix* m_)
{
  m = m_;
}

void RUN::setThreshold(double threshold_)
{
  threshold = threshold_;
}

void RUN::setModelYScrambling(bool yscrambling_)
{
  yscrambling = yscrambling_;
}

void RUN::setModelYScramblingBlock(int block_)
{
  block = block_;
}

void RUN::setNumberOfIterations(int niter_)
{
  niter = niter_;
}

void RUN::setNumberOfGroups(int ngroup_)
{
  ngroup = ngroup_;
}

void RUN::setValidationType(int vt_)
{
  vt = vt_;
}

void RUN::setNumberPC(int pc_)
{
  pc = pc_;
}

void RUN::setYScalingType(int yscaling_)
{
  yscaling = yscaling_;
}
void RUN::setXScalingType(int xscaling_)
{
  xscaling = xscaling_;
}

void RUN::setLDAModel(LDAModel* ldamodel_)
{
  ldamodel = ldamodel_;
}

void RUN::setMLRModel(MLRModel* mlrmodel_)
{
  mlrmodel = mlrmodel_;
}


void RUN::setPLSModel(PLSModel* plsmod_)
{
  plsmod = plsmod_;
}

void RUN::setPCAModel(PCAModel * pcamod_)
{
  pcamod = pcamod_;
}

void RUN::setYArray(array* ay_)
{
  ay = ay_;
}

void RUN::setXArray(array* ax_)
{
  ax = ax_;
}

void RUN::setYMatrix(matrix* y_)
{
  y = y_;
}

void RUN::setXMatrix(matrix* x_)
{
  x = x_;
}

void RUN::Test()
{
  qDebug() << " XSCALING " << xscaling << " YSCALING " << yscaling << " PC " << pc << " VT " << vt << " GROUP " << ngroup << " ITER " << niter;
}

void RUN::AbortRun()
{
  scientifisignal = SIGSCIENTIFICSTOP;
//   QThreadPool::globalInstance()->waitForDone();
}

RUN::RUN()
{
  scientifisignal = SIGSCIENTIFICRUN;

  pc = vt = ngroup = niter = block = nclusters = clusteralgoritm = -1;
  xscaling = yscaling = 0;
  yscrambling = false;
  m = 0;
  uiv = 0;
  x = 0;
  y = 0;
  ax = 0;
  ay = 0;
  uiv = NULL;
}
