# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.11

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.11.3/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.11.3/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/marco/projects/QPlotly-1.0.0

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/marco/projects/QPlotly-1.0.0/build

# Include any dependencies generated for this target.
include CMakeFiles/libqplotly.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/libqplotly.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/libqplotly.dir/flags.make

moc_datapoint.cpp: ../datapoint.h
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/marco/projects/QPlotly-1.0.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating moc_datapoint.cpp"
	/usr/local/Cellar/qt/5.11.0/bin/moc @/Users/marco/projects/QPlotly-1.0.0/build/moc_datapoint.cpp_parameters

moc_datacurve.cpp: ../datacurve.h
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/marco/projects/QPlotly-1.0.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Generating moc_datacurve.cpp"
	/usr/local/Cellar/qt/5.11.0/bin/moc @/Users/marco/projects/QPlotly-1.0.0/build/moc_datacurve.cpp_parameters

moc_databar.cpp: ../databar.h
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/marco/projects/QPlotly-1.0.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Generating moc_databar.cpp"
	/usr/local/Cellar/qt/5.11.0/bin/moc @/Users/marco/projects/QPlotly-1.0.0/build/moc_databar.cpp_parameters

moc_qplotly.cpp: ../qplotly.h
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/marco/projects/QPlotly-1.0.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Generating moc_qplotly.cpp"
	/usr/local/Cellar/qt/5.11.0/bin/moc @/Users/marco/projects/QPlotly-1.0.0/build/moc_qplotly.cpp_parameters

CMakeFiles/libqplotly.dir/datapoint.cpp.o: CMakeFiles/libqplotly.dir/flags.make
CMakeFiles/libqplotly.dir/datapoint.cpp.o: ../datapoint.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/marco/projects/QPlotly-1.0.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/libqplotly.dir/datapoint.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/libqplotly.dir/datapoint.cpp.o -c /Users/marco/projects/QPlotly-1.0.0/datapoint.cpp

CMakeFiles/libqplotly.dir/datapoint.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libqplotly.dir/datapoint.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/marco/projects/QPlotly-1.0.0/datapoint.cpp > CMakeFiles/libqplotly.dir/datapoint.cpp.i

CMakeFiles/libqplotly.dir/datapoint.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libqplotly.dir/datapoint.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/marco/projects/QPlotly-1.0.0/datapoint.cpp -o CMakeFiles/libqplotly.dir/datapoint.cpp.s

CMakeFiles/libqplotly.dir/datacurve.cpp.o: CMakeFiles/libqplotly.dir/flags.make
CMakeFiles/libqplotly.dir/datacurve.cpp.o: ../datacurve.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/marco/projects/QPlotly-1.0.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/libqplotly.dir/datacurve.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/libqplotly.dir/datacurve.cpp.o -c /Users/marco/projects/QPlotly-1.0.0/datacurve.cpp

CMakeFiles/libqplotly.dir/datacurve.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libqplotly.dir/datacurve.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/marco/projects/QPlotly-1.0.0/datacurve.cpp > CMakeFiles/libqplotly.dir/datacurve.cpp.i

CMakeFiles/libqplotly.dir/datacurve.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libqplotly.dir/datacurve.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/marco/projects/QPlotly-1.0.0/datacurve.cpp -o CMakeFiles/libqplotly.dir/datacurve.cpp.s

CMakeFiles/libqplotly.dir/databar.cpp.o: CMakeFiles/libqplotly.dir/flags.make
CMakeFiles/libqplotly.dir/databar.cpp.o: ../databar.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/marco/projects/QPlotly-1.0.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/libqplotly.dir/databar.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/libqplotly.dir/databar.cpp.o -c /Users/marco/projects/QPlotly-1.0.0/databar.cpp

CMakeFiles/libqplotly.dir/databar.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libqplotly.dir/databar.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/marco/projects/QPlotly-1.0.0/databar.cpp > CMakeFiles/libqplotly.dir/databar.cpp.i

CMakeFiles/libqplotly.dir/databar.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libqplotly.dir/databar.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/marco/projects/QPlotly-1.0.0/databar.cpp -o CMakeFiles/libqplotly.dir/databar.cpp.s

CMakeFiles/libqplotly.dir/qplotly.cpp.o: CMakeFiles/libqplotly.dir/flags.make
CMakeFiles/libqplotly.dir/qplotly.cpp.o: ../qplotly.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/marco/projects/QPlotly-1.0.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/libqplotly.dir/qplotly.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/libqplotly.dir/qplotly.cpp.o -c /Users/marco/projects/QPlotly-1.0.0/qplotly.cpp

CMakeFiles/libqplotly.dir/qplotly.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libqplotly.dir/qplotly.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/marco/projects/QPlotly-1.0.0/qplotly.cpp > CMakeFiles/libqplotly.dir/qplotly.cpp.i

CMakeFiles/libqplotly.dir/qplotly.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libqplotly.dir/qplotly.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/marco/projects/QPlotly-1.0.0/qplotly.cpp -o CMakeFiles/libqplotly.dir/qplotly.cpp.s

CMakeFiles/libqplotly.dir/moc_datapoint.cpp.o: CMakeFiles/libqplotly.dir/flags.make
CMakeFiles/libqplotly.dir/moc_datapoint.cpp.o: moc_datapoint.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/marco/projects/QPlotly-1.0.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/libqplotly.dir/moc_datapoint.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/libqplotly.dir/moc_datapoint.cpp.o -c /Users/marco/projects/QPlotly-1.0.0/build/moc_datapoint.cpp

CMakeFiles/libqplotly.dir/moc_datapoint.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libqplotly.dir/moc_datapoint.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/marco/projects/QPlotly-1.0.0/build/moc_datapoint.cpp > CMakeFiles/libqplotly.dir/moc_datapoint.cpp.i

CMakeFiles/libqplotly.dir/moc_datapoint.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libqplotly.dir/moc_datapoint.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/marco/projects/QPlotly-1.0.0/build/moc_datapoint.cpp -o CMakeFiles/libqplotly.dir/moc_datapoint.cpp.s

CMakeFiles/libqplotly.dir/moc_datacurve.cpp.o: CMakeFiles/libqplotly.dir/flags.make
CMakeFiles/libqplotly.dir/moc_datacurve.cpp.o: moc_datacurve.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/marco/projects/QPlotly-1.0.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/libqplotly.dir/moc_datacurve.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/libqplotly.dir/moc_datacurve.cpp.o -c /Users/marco/projects/QPlotly-1.0.0/build/moc_datacurve.cpp

CMakeFiles/libqplotly.dir/moc_datacurve.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libqplotly.dir/moc_datacurve.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/marco/projects/QPlotly-1.0.0/build/moc_datacurve.cpp > CMakeFiles/libqplotly.dir/moc_datacurve.cpp.i

CMakeFiles/libqplotly.dir/moc_datacurve.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libqplotly.dir/moc_datacurve.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/marco/projects/QPlotly-1.0.0/build/moc_datacurve.cpp -o CMakeFiles/libqplotly.dir/moc_datacurve.cpp.s

CMakeFiles/libqplotly.dir/moc_databar.cpp.o: CMakeFiles/libqplotly.dir/flags.make
CMakeFiles/libqplotly.dir/moc_databar.cpp.o: moc_databar.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/marco/projects/QPlotly-1.0.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/libqplotly.dir/moc_databar.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/libqplotly.dir/moc_databar.cpp.o -c /Users/marco/projects/QPlotly-1.0.0/build/moc_databar.cpp

CMakeFiles/libqplotly.dir/moc_databar.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libqplotly.dir/moc_databar.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/marco/projects/QPlotly-1.0.0/build/moc_databar.cpp > CMakeFiles/libqplotly.dir/moc_databar.cpp.i

CMakeFiles/libqplotly.dir/moc_databar.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libqplotly.dir/moc_databar.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/marco/projects/QPlotly-1.0.0/build/moc_databar.cpp -o CMakeFiles/libqplotly.dir/moc_databar.cpp.s

CMakeFiles/libqplotly.dir/moc_qplotly.cpp.o: CMakeFiles/libqplotly.dir/flags.make
CMakeFiles/libqplotly.dir/moc_qplotly.cpp.o: moc_qplotly.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/marco/projects/QPlotly-1.0.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/libqplotly.dir/moc_qplotly.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/libqplotly.dir/moc_qplotly.cpp.o -c /Users/marco/projects/QPlotly-1.0.0/build/moc_qplotly.cpp

CMakeFiles/libqplotly.dir/moc_qplotly.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libqplotly.dir/moc_qplotly.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/marco/projects/QPlotly-1.0.0/build/moc_qplotly.cpp > CMakeFiles/libqplotly.dir/moc_qplotly.cpp.i

CMakeFiles/libqplotly.dir/moc_qplotly.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libqplotly.dir/moc_qplotly.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/marco/projects/QPlotly-1.0.0/build/moc_qplotly.cpp -o CMakeFiles/libqplotly.dir/moc_qplotly.cpp.s

CMakeFiles/libqplotly.dir/libqplotly_autogen/mocs_compilation.cpp.o: CMakeFiles/libqplotly.dir/flags.make
CMakeFiles/libqplotly.dir/libqplotly_autogen/mocs_compilation.cpp.o: libqplotly_autogen/mocs_compilation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/marco/projects/QPlotly-1.0.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/libqplotly.dir/libqplotly_autogen/mocs_compilation.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/libqplotly.dir/libqplotly_autogen/mocs_compilation.cpp.o -c /Users/marco/projects/QPlotly-1.0.0/build/libqplotly_autogen/mocs_compilation.cpp

CMakeFiles/libqplotly.dir/libqplotly_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libqplotly.dir/libqplotly_autogen/mocs_compilation.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/marco/projects/QPlotly-1.0.0/build/libqplotly_autogen/mocs_compilation.cpp > CMakeFiles/libqplotly.dir/libqplotly_autogen/mocs_compilation.cpp.i

CMakeFiles/libqplotly.dir/libqplotly_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libqplotly.dir/libqplotly_autogen/mocs_compilation.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/marco/projects/QPlotly-1.0.0/build/libqplotly_autogen/mocs_compilation.cpp -o CMakeFiles/libqplotly.dir/libqplotly_autogen/mocs_compilation.cpp.s

# Object files for target libqplotly
libqplotly_OBJECTS = \
"CMakeFiles/libqplotly.dir/datapoint.cpp.o" \
"CMakeFiles/libqplotly.dir/datacurve.cpp.o" \
"CMakeFiles/libqplotly.dir/databar.cpp.o" \
"CMakeFiles/libqplotly.dir/qplotly.cpp.o" \
"CMakeFiles/libqplotly.dir/moc_datapoint.cpp.o" \
"CMakeFiles/libqplotly.dir/moc_datacurve.cpp.o" \
"CMakeFiles/libqplotly.dir/moc_databar.cpp.o" \
"CMakeFiles/libqplotly.dir/moc_qplotly.cpp.o" \
"CMakeFiles/libqplotly.dir/libqplotly_autogen/mocs_compilation.cpp.o"

# External object files for target libqplotly
libqplotly_EXTERNAL_OBJECTS =

libqplotly.dylib: CMakeFiles/libqplotly.dir/datapoint.cpp.o
libqplotly.dylib: CMakeFiles/libqplotly.dir/datacurve.cpp.o
libqplotly.dylib: CMakeFiles/libqplotly.dir/databar.cpp.o
libqplotly.dylib: CMakeFiles/libqplotly.dir/qplotly.cpp.o
libqplotly.dylib: CMakeFiles/libqplotly.dir/moc_datapoint.cpp.o
libqplotly.dylib: CMakeFiles/libqplotly.dir/moc_datacurve.cpp.o
libqplotly.dylib: CMakeFiles/libqplotly.dir/moc_databar.cpp.o
libqplotly.dylib: CMakeFiles/libqplotly.dir/moc_qplotly.cpp.o
libqplotly.dylib: CMakeFiles/libqplotly.dir/libqplotly_autogen/mocs_compilation.cpp.o
libqplotly.dylib: CMakeFiles/libqplotly.dir/build.make
libqplotly.dylib: /usr/local/Cellar/qt/5.11.0/lib/QtWebEngine.framework/QtWebEngine
libqplotly.dylib: /usr/local/Cellar/qt/5.11.0/lib/QtWebEngineWidgets.framework/QtWebEngineWidgets
libqplotly.dylib: /usr/local/Cellar/qt/5.11.0/lib/QtPrintSupport.framework/QtPrintSupport
libqplotly.dylib: /usr/local/Cellar/qt/5.11.0/lib/QtWidgets.framework/QtWidgets
libqplotly.dylib: /usr/local/Cellar/qt/5.11.0/lib/QtWebEngineCore.framework/QtWebEngineCore
libqplotly.dylib: /usr/local/Cellar/qt/5.11.0/lib/QtWebChannel.framework/QtWebChannel
libqplotly.dylib: /usr/local/Cellar/qt/5.11.0/lib/QtPositioning.framework/QtPositioning
libqplotly.dylib: /usr/local/Cellar/qt/5.11.0/lib/QtQuick.framework/QtQuick
libqplotly.dylib: /usr/local/Cellar/qt/5.11.0/lib/QtGui.framework/QtGui
libqplotly.dylib: /usr/local/Cellar/qt/5.11.0/lib/QtQml.framework/QtQml
libqplotly.dylib: /usr/local/Cellar/qt/5.11.0/lib/QtNetwork.framework/QtNetwork
libqplotly.dylib: /usr/local/Cellar/qt/5.11.0/lib/QtCore.framework/QtCore
libqplotly.dylib: CMakeFiles/libqplotly.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/marco/projects/QPlotly-1.0.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Linking CXX shared library libqplotly.dylib"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/libqplotly.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/libqplotly.dir/build: libqplotly.dylib

.PHONY : CMakeFiles/libqplotly.dir/build

CMakeFiles/libqplotly.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/libqplotly.dir/cmake_clean.cmake
.PHONY : CMakeFiles/libqplotly.dir/clean

CMakeFiles/libqplotly.dir/depend: moc_datapoint.cpp
CMakeFiles/libqplotly.dir/depend: moc_datacurve.cpp
CMakeFiles/libqplotly.dir/depend: moc_databar.cpp
CMakeFiles/libqplotly.dir/depend: moc_qplotly.cpp
	cd /Users/marco/projects/QPlotly-1.0.0/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/marco/projects/QPlotly-1.0.0 /Users/marco/projects/QPlotly-1.0.0 /Users/marco/projects/QPlotly-1.0.0/build /Users/marco/projects/QPlotly-1.0.0/build /Users/marco/projects/QPlotly-1.0.0/build/CMakeFiles/libqplotly.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/libqplotly.dir/depend

