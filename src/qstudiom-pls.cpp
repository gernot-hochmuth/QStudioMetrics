//QStudiom-pls
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>

#include "DATAIO.h"

#include <vector>
#include <getopt.h>
#include <cstring>
using namespace std;

#include "scientific.h"

void help(char **argv)
{
  std::cout << "Usage" << endl;
  std::cout << "Make a model: " << argv[0] <<" -model -x <xinput file>  -y <yinput file>" << " -o <output file> -c <N° of LV> -xa(autoscaling for x matrix) -ya(autoscaling for y matrix)\n"  <<std::endl;
  std::cout << "Make a prediction: " << argv[0] <<" -predict -dm <input model> -x <xinput file> -o <output file> -c <N° of LV>\n" << std::endl;
  std::cout << "Make the cross validation: " << argv[0] <<" -cv -x  <xinput file>  -y <yinput file> -dm <input path model> -g <N° of groups> -i <N° iterations> -c <N° of LV> -nth <N° threads>\n" << std::endl;

  std::cout << "Calculate beta coefficients: " << argv[0] << " -betas -x  <xinput file>  -y <yinput file> -dm <input path model>  -c <N° of LV> -xa [0, 1, 2, 3, 4, 5] -ya [0, 1, 2, 3, 4, 5]\n" << std::endl;
  std::cout << "Autoscaling type:" << std::endl;
  std::cout << " 0 = no scaling" << std::endl;
  std::cout << " 1 = SDEV autoscaling" << std::endl;
  std::cout << " 2 = RMS scaling" << std::endl;
  std::cout << " 3 = Pareto scaling" << std::endl;
  std::cout << " 4 = Range scaling" << std::endl;
  std::cout << " 5 = Level scalign" << std::endl;

  std::cout << "\n\t ---------------------------------------------------------------------------- " << std::endl;
  std::cout << "\t | "<< argv[0] << " was writen by Giuseppe Marco Randazzo <gmrandazzo@gmail.com>  |" << std::endl;
  std::cout << "\t ---------------------------------------------------------------------------- \n" << std::endl;
}

int main(int argc, char **argv)
{
  if(argc <= 1){
    help(argv);
  }
  else{
    size_t npc = 0, ngroups = 0, iterations = 20, xautoscaling = 0 , yautoscaling = 0, nthreads = 1;
    string xinputdata, yinputdata, pathmodel, outputfile, xsep, ysep;
    bool genmodel, genbetas, makeprediction, makecrossvalidation;
    genmodel = genbetas = makeprediction = makecrossvalidation = false;
    xsep = ysep = ";";

    for(int i = 0; i < argc; i++){
      if(strcmp(argv[i], "-model") == 0 || strcmp(argv[i], "-m") == 0){
        genmodel = true;
      }
      if(strcmp(argv[i], "-betas") == 0 || strcmp(argv[i], "-m") == 0){
        genbetas = true;
      }

      if(strcmp(argv[i], "-predict") == 0 || strcmp(argv[i], "-p") == 0){
        makeprediction = true;
      }

      if(strcmp(argv[i], "-cross-validation") == 0 || strcmp(argv[i], "-cv") == 0){
        makecrossvalidation = true;
      }

      if(strcmp(argv[i], "-xdata") == 0 || strcmp(argv[i], "-x") == 0){
        if(i+1 < argc){
          xinputdata = argv[i+1];
        }
      }

      if(strcmp(argv[i], "-ydata") == 0 || strcmp(argv[i], "-y") == 0){
        if(i+1 < argc){
          yinputdata = argv[i+1];
        }
      }

      if(strcmp(argv[i], "-out") == 0 || strcmp(argv[i], "-o") == 0){
        if(i+1 < argc){
          outputfile = argv[i+1];
        }
      }

      if(strcmp(argv[i], "-c") == 0){
        if(i+1 < argc)
          npc = atoi(argv[i+1]);
      }

      if(strcmp(argv[i], "-g") == 0){
        if(i+1 < argc)
          ngroups = atoi(argv[i+1]);
      }

      if(strcmp(argv[i], "-i") == 0){
        if(i+1 < argc)
          iterations = atoi(argv[i+1]);
      }

      if(strcmp(argv[i], "-data-model") == 0 || strcmp(argv[i], "-dm") == 0){
        if(i+1 < argc)
          pathmodel = argv[i+1];
      }

      if(strcmp(argv[i], "-xa") == 0){
        if(i+1 < argc)
          xautoscaling = atoi(argv[i+1]);
      }

      if(strcmp(argv[i], "-ya") == 0){
        if(i+1 < argc)
          yautoscaling = atoi(argv[i+1]);
      }

      if(strcmp(argv[i], "-sx") == 0){
        if(i+1 < argc)
          xsep = argv[i+1];
      }

      if(strcmp(argv[i], "-sy") == 0){
        if(i+1 < argc)
          ysep = argv[i+1];
      }

      if(strcmp(argv[i], "-s") == 0){
        if(i+1 < argc)
          xsep = ysep = argv[i+1];
      }

      if(strcmp(argv[i], "-nth") == 0){
        if(i+1 < argc)
          nthreads = atoi (argv[i+1]);
      }
    }

    if(genmodel == true && !xinputdata.empty() && !yinputdata.empty() && !outputfile.empty() && npc > 0){
      matrix *xdata, *ydata;

      initMatrix(&xdata);
      initMatrix(&ydata);

      DATAIO::ImportMatrix((char*)xinputdata.c_str(), xsep, xdata);
      DATAIO::ImportMatrix((char*)yinputdata.c_str(), ysep, ydata);

      PLSMODEL *m;
      NewPLSModel(&m);

      PLS(xdata, ydata, npc, xautoscaling, yautoscaling, m, NULL);
      PLSRSquared(xdata, ydata, m, npc, &(m->r2y_model), &(m->sdec));

      DATAIO::WritePLSModel((char*)outputfile.c_str(), m);

      DelPLSModel(&m);
      DelMatrix(&xdata);
      DelMatrix(&ydata);
    }
    else if(genbetas == true && !xinputdata.empty() && !yinputdata.empty() && npc > 0){
      matrix *xdata, *ydata;
      dvector *betas;
      initMatrix(&xdata);
      initMatrix(&ydata);

      DATAIO::ImportMatrix((char*)xinputdata.c_str(), xsep, xdata);
      DATAIO::ImportMatrix((char*)yinputdata.c_str(), ysep, ydata);

      PLSMODEL *m;
      NewPLSModel(&m);

      PLS(xdata, ydata, npc, xautoscaling, yautoscaling, m, NULL);
      initDVector(&betas);
      PLSBetasCoeff(m, npc, &betas);

      for(size_t i = 0; i < betas->size; i++){
        cout << betas->data[i] << endl;
      }


      if(!pathmodel.empty()){
        string betasfile = pathmodel+"/betas.txt";
        DATAIO::WriteDvector((char*)betasfile.c_str(), betas);
      }

      DelDVector(&betas);
      DelPLSModel(&m);
      DelMatrix(&xdata);
      DelMatrix(&ydata);
    }
    else if(makeprediction == true && !pathmodel.empty() && !xinputdata.empty() && !outputfile.empty() && npc > 0){
      matrix *xdata;
      initMatrix(&xdata);

      DATAIO::ImportMatrix((char*)xinputdata.c_str(), xsep, xdata);


      PLSMODEL *m;
      NewPLSModel(&m);
      DATAIO::ImportPLSModel((char*)pathmodel.c_str(), m);

      matrix *xscores, *y;
      initMatrix(&xscores);
      initMatrix(&y);

      PLSScorePredictor(xdata, m,  npc, &xscores);
      PLSYPredictor(xscores, m, npc, &y);

      DATAIO::MakeDir((char*)outputfile.c_str());
      string ptscores = outputfile+"/T-Scores-Pred.txt";
      string ypred = outputfile+"/Y-Pred.txt";
      DATAIO::WriteMatrix((char*)ptscores.c_str(), xscores);
      DATAIO::WriteMatrix((char*)ypred.c_str(), y);

      DelMatrix(&y);
      DelMatrix(&xscores);
      DelPLSModel(&m);
      DelMatrix(&xdata);
    }
    else if(makecrossvalidation == true && !xinputdata.empty() && !yinputdata.empty() && ngroups > 0 && npc > 0){
      matrix *xdata, *ydata;
      matrix *q2y, *sdep, *bias, *pred, *predresiduals;
      matrix *q2y_consistency, *sdep_consistency, *bias_consistency;

      initMatrix(&xdata);
      initMatrix(&ydata);
      DATAIO::ImportMatrix((char*)xinputdata.c_str(), xsep, xdata);
      DATAIO::ImportMatrix((char*)yinputdata.c_str(), ysep, ydata);


      initMatrix(&q2y);
      initMatrix(&sdep);
      initMatrix(&bias);
      initMatrix(&pred);
      initMatrix(&predresiduals);
      initMatrix(&q2y_consistency);
      initMatrix(&sdep_consistency);
      initMatrix(&bias_consistency);

//       PrintMatrix(xdata);
//       PrintMatrix(ydata);

      PLSRandomGroupsCV(xdata, ydata, xautoscaling, yautoscaling,
                         npc, ngroups, iterations,
                        &q2y, &sdep, &bias, &pred, &predresiduals, nthreads, NULL);

      //PLSYScrambling(xdata, ydata, xautoscaling, yautoscaling, npc, iterations, &q2y_consistency, &sdep_consistency, nthreads, NULL);


      if(!pathmodel.empty()){
        string q2yfile = pathmodel+"/Validated_q2y.txt";
        string sdepfile = pathmodel+"/Validated_sdep.txt";
        DATAIO::WriteMatrix((char*)q2yfile.c_str(), q2y);
        DATAIO::WriteMatrix((char*)sdepfile.c_str(), sdep);
      }

      cout.setf(ios_base::right,ios_base::adjustfield);
      cout.setf(ios::fixed,ios::floatfield);

      cout << "Cross Validated Q^2" << endl;
      for(size_t i = 0; i < q2y->row; i++){
        for(size_t j = 0; j < q2y->col; j++){
          if(j == 0)
            cout << "PC " << i+1 << ": " << setw(3) << getMatrixValue(q2y, i, j);
          else if(j == q2y->col-1)
            cout << setw(10) << getMatrixValue(q2y, i, j);
          else
            cout << setw(10) << getMatrixValue(q2y, i, j);
        }
        cout << endl;
      }

      cout << "SDEP" << endl;
      for(size_t i = 0; i < sdep->row; i++){
        for(size_t j = 0; j < sdep->col; j++){
          if(j == 0)
            cout << "PC " << i+1 << ": " << setw(3) << getMatrixValue(sdep, i, j);
          else if(j == sdep->col-1)
            cout << setw(10) << getMatrixValue(sdep, i, j);
          else
            cout << setw(10) << getMatrixValue(sdep, i, j);
        }
        cout << endl;
      }

      cout << "BIAS" << endl;
      for(size_t i = 0; i < bias->row; i++){
        for(size_t j = 0; j < bias->col; j++){
          if(j == 0)
            cout << "PC " << i+1 << ": " << setw(3) << getMatrixValue(bias, i, j);
          else if(j == bias->col-1)
            cout << setw(10) << getMatrixValue(bias, i, j);
          else
            cout << setw(10) << getMatrixValue(bias, i, j);
        }
        cout << endl;
      }

      cout << "YScrambling Q^2" << endl;
      for(size_t i = 0; i < q2y_consistency->row; i++){
        for(size_t j = 0; j < q2y_consistency->col; j++){
          if(j == 0)
            cout << "PC " << i+1 << ": " << setw(3) << getMatrixValue(q2y_consistency, i, j);
          else if(j == q2y_consistency->col-1)
            cout << setw(10) << getMatrixValue(q2y_consistency, i, j) << endl;
          else
            cout << setw(10) << getMatrixValue(q2y_consistency, i, j);
        }
        cout << endl;
      }

      cout << "YScrambling SDEP" << endl;
      for(size_t i = 0; i < sdep_consistency->row; i++){
        for(size_t j = 0; j < sdep_consistency->col; j++){
          if(j == 0)
            cout << "PC " << i+1 << ": " << setw(3) << getMatrixValue(sdep_consistency, i, j);
          else if(j == sdep_consistency->col-1)
            cout << setw(10) << getMatrixValue(sdep_consistency, i, j) << endl;
          else
            cout << setw(10) << getMatrixValue(sdep_consistency, i, j);
        }
        cout << endl;
      }

      DelMatrix(&bias_consistency);
      DelMatrix(&q2y_consistency);
      DelMatrix(&sdep_consistency);
      DelMatrix(&q2y);
      DelMatrix(&bias);
      DelMatrix(&pred);
      DelMatrix(&predresiduals);
      DelMatrix(&sdep);
      DelMatrix(&xdata);
      DelMatrix(&ydata);
    }
    else{
      cout << "Error!" << endl;
      help(argv);
    }
  }
  return 0;

}