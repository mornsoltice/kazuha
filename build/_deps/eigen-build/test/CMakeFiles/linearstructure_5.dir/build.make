# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/soltice/Development/kazuha

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/soltice/Development/kazuha/build

# Include any dependencies generated for this target.
include _deps/eigen-build/test/CMakeFiles/linearstructure_5.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include _deps/eigen-build/test/CMakeFiles/linearstructure_5.dir/compiler_depend.make

# Include the progress variables for this target.
include _deps/eigen-build/test/CMakeFiles/linearstructure_5.dir/progress.make

# Include the compile flags for this target's objects.
include _deps/eigen-build/test/CMakeFiles/linearstructure_5.dir/flags.make

_deps/eigen-build/test/CMakeFiles/linearstructure_5.dir/linearstructure.cpp.o: _deps/eigen-build/test/CMakeFiles/linearstructure_5.dir/flags.make
_deps/eigen-build/test/CMakeFiles/linearstructure_5.dir/linearstructure.cpp.o: _deps/eigen-src/test/linearstructure.cpp
_deps/eigen-build/test/CMakeFiles/linearstructure_5.dir/linearstructure.cpp.o: _deps/eigen-build/test/CMakeFiles/linearstructure_5.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/soltice/Development/kazuha/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object _deps/eigen-build/test/CMakeFiles/linearstructure_5.dir/linearstructure.cpp.o"
	cd /home/soltice/Development/kazuha/build/_deps/eigen-build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _deps/eigen-build/test/CMakeFiles/linearstructure_5.dir/linearstructure.cpp.o -MF CMakeFiles/linearstructure_5.dir/linearstructure.cpp.o.d -o CMakeFiles/linearstructure_5.dir/linearstructure.cpp.o -c /home/soltice/Development/kazuha/build/_deps/eigen-src/test/linearstructure.cpp

_deps/eigen-build/test/CMakeFiles/linearstructure_5.dir/linearstructure.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/linearstructure_5.dir/linearstructure.cpp.i"
	cd /home/soltice/Development/kazuha/build/_deps/eigen-build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/soltice/Development/kazuha/build/_deps/eigen-src/test/linearstructure.cpp > CMakeFiles/linearstructure_5.dir/linearstructure.cpp.i

_deps/eigen-build/test/CMakeFiles/linearstructure_5.dir/linearstructure.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/linearstructure_5.dir/linearstructure.cpp.s"
	cd /home/soltice/Development/kazuha/build/_deps/eigen-build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/soltice/Development/kazuha/build/_deps/eigen-src/test/linearstructure.cpp -o CMakeFiles/linearstructure_5.dir/linearstructure.cpp.s

# Object files for target linearstructure_5
linearstructure_5_OBJECTS = \
"CMakeFiles/linearstructure_5.dir/linearstructure.cpp.o"

# External object files for target linearstructure_5
linearstructure_5_EXTERNAL_OBJECTS =

_deps/eigen-build/test/linearstructure_5: _deps/eigen-build/test/CMakeFiles/linearstructure_5.dir/linearstructure.cpp.o
_deps/eigen-build/test/linearstructure_5: _deps/eigen-build/test/CMakeFiles/linearstructure_5.dir/build.make
_deps/eigen-build/test/linearstructure_5: _deps/eigen-build/test/CMakeFiles/linearstructure_5.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/soltice/Development/kazuha/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable linearstructure_5"
	cd /home/soltice/Development/kazuha/build/_deps/eigen-build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/linearstructure_5.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
_deps/eigen-build/test/CMakeFiles/linearstructure_5.dir/build: _deps/eigen-build/test/linearstructure_5
.PHONY : _deps/eigen-build/test/CMakeFiles/linearstructure_5.dir/build

_deps/eigen-build/test/CMakeFiles/linearstructure_5.dir/clean:
	cd /home/soltice/Development/kazuha/build/_deps/eigen-build/test && $(CMAKE_COMMAND) -P CMakeFiles/linearstructure_5.dir/cmake_clean.cmake
.PHONY : _deps/eigen-build/test/CMakeFiles/linearstructure_5.dir/clean

_deps/eigen-build/test/CMakeFiles/linearstructure_5.dir/depend:
	cd /home/soltice/Development/kazuha/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/soltice/Development/kazuha /home/soltice/Development/kazuha/build/_deps/eigen-src/test /home/soltice/Development/kazuha/build /home/soltice/Development/kazuha/build/_deps/eigen-build/test /home/soltice/Development/kazuha/build/_deps/eigen-build/test/CMakeFiles/linearstructure_5.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : _deps/eigen-build/test/CMakeFiles/linearstructure_5.dir/depend

