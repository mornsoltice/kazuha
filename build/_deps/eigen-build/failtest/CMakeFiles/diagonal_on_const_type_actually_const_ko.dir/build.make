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
include _deps/eigen-build/failtest/CMakeFiles/diagonal_on_const_type_actually_const_ko.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include _deps/eigen-build/failtest/CMakeFiles/diagonal_on_const_type_actually_const_ko.dir/compiler_depend.make

# Include the progress variables for this target.
include _deps/eigen-build/failtest/CMakeFiles/diagonal_on_const_type_actually_const_ko.dir/progress.make

# Include the compile flags for this target's objects.
include _deps/eigen-build/failtest/CMakeFiles/diagonal_on_const_type_actually_const_ko.dir/flags.make

_deps/eigen-build/failtest/CMakeFiles/diagonal_on_const_type_actually_const_ko.dir/diagonal_on_const_type_actually_const.cpp.o: _deps/eigen-build/failtest/CMakeFiles/diagonal_on_const_type_actually_const_ko.dir/flags.make
_deps/eigen-build/failtest/CMakeFiles/diagonal_on_const_type_actually_const_ko.dir/diagonal_on_const_type_actually_const.cpp.o: _deps/eigen-src/failtest/diagonal_on_const_type_actually_const.cpp
_deps/eigen-build/failtest/CMakeFiles/diagonal_on_const_type_actually_const_ko.dir/diagonal_on_const_type_actually_const.cpp.o: _deps/eigen-build/failtest/CMakeFiles/diagonal_on_const_type_actually_const_ko.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/soltice/Development/kazuha/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object _deps/eigen-build/failtest/CMakeFiles/diagonal_on_const_type_actually_const_ko.dir/diagonal_on_const_type_actually_const.cpp.o"
	cd /home/soltice/Development/kazuha/build/_deps/eigen-build/failtest && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _deps/eigen-build/failtest/CMakeFiles/diagonal_on_const_type_actually_const_ko.dir/diagonal_on_const_type_actually_const.cpp.o -MF CMakeFiles/diagonal_on_const_type_actually_const_ko.dir/diagonal_on_const_type_actually_const.cpp.o.d -o CMakeFiles/diagonal_on_const_type_actually_const_ko.dir/diagonal_on_const_type_actually_const.cpp.o -c /home/soltice/Development/kazuha/build/_deps/eigen-src/failtest/diagonal_on_const_type_actually_const.cpp

_deps/eigen-build/failtest/CMakeFiles/diagonal_on_const_type_actually_const_ko.dir/diagonal_on_const_type_actually_const.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/diagonal_on_const_type_actually_const_ko.dir/diagonal_on_const_type_actually_const.cpp.i"
	cd /home/soltice/Development/kazuha/build/_deps/eigen-build/failtest && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/soltice/Development/kazuha/build/_deps/eigen-src/failtest/diagonal_on_const_type_actually_const.cpp > CMakeFiles/diagonal_on_const_type_actually_const_ko.dir/diagonal_on_const_type_actually_const.cpp.i

_deps/eigen-build/failtest/CMakeFiles/diagonal_on_const_type_actually_const_ko.dir/diagonal_on_const_type_actually_const.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/diagonal_on_const_type_actually_const_ko.dir/diagonal_on_const_type_actually_const.cpp.s"
	cd /home/soltice/Development/kazuha/build/_deps/eigen-build/failtest && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/soltice/Development/kazuha/build/_deps/eigen-src/failtest/diagonal_on_const_type_actually_const.cpp -o CMakeFiles/diagonal_on_const_type_actually_const_ko.dir/diagonal_on_const_type_actually_const.cpp.s

# Object files for target diagonal_on_const_type_actually_const_ko
diagonal_on_const_type_actually_const_ko_OBJECTS = \
"CMakeFiles/diagonal_on_const_type_actually_const_ko.dir/diagonal_on_const_type_actually_const.cpp.o"

# External object files for target diagonal_on_const_type_actually_const_ko
diagonal_on_const_type_actually_const_ko_EXTERNAL_OBJECTS =

_deps/eigen-build/failtest/diagonal_on_const_type_actually_const_ko: _deps/eigen-build/failtest/CMakeFiles/diagonal_on_const_type_actually_const_ko.dir/diagonal_on_const_type_actually_const.cpp.o
_deps/eigen-build/failtest/diagonal_on_const_type_actually_const_ko: _deps/eigen-build/failtest/CMakeFiles/diagonal_on_const_type_actually_const_ko.dir/build.make
_deps/eigen-build/failtest/diagonal_on_const_type_actually_const_ko: _deps/eigen-build/failtest/CMakeFiles/diagonal_on_const_type_actually_const_ko.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/soltice/Development/kazuha/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable diagonal_on_const_type_actually_const_ko"
	cd /home/soltice/Development/kazuha/build/_deps/eigen-build/failtest && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/diagonal_on_const_type_actually_const_ko.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
_deps/eigen-build/failtest/CMakeFiles/diagonal_on_const_type_actually_const_ko.dir/build: _deps/eigen-build/failtest/diagonal_on_const_type_actually_const_ko
.PHONY : _deps/eigen-build/failtest/CMakeFiles/diagonal_on_const_type_actually_const_ko.dir/build

_deps/eigen-build/failtest/CMakeFiles/diagonal_on_const_type_actually_const_ko.dir/clean:
	cd /home/soltice/Development/kazuha/build/_deps/eigen-build/failtest && $(CMAKE_COMMAND) -P CMakeFiles/diagonal_on_const_type_actually_const_ko.dir/cmake_clean.cmake
.PHONY : _deps/eigen-build/failtest/CMakeFiles/diagonal_on_const_type_actually_const_ko.dir/clean

_deps/eigen-build/failtest/CMakeFiles/diagonal_on_const_type_actually_const_ko.dir/depend:
	cd /home/soltice/Development/kazuha/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/soltice/Development/kazuha /home/soltice/Development/kazuha/build/_deps/eigen-src/failtest /home/soltice/Development/kazuha/build /home/soltice/Development/kazuha/build/_deps/eigen-build/failtest /home/soltice/Development/kazuha/build/_deps/eigen-build/failtest/CMakeFiles/diagonal_on_const_type_actually_const_ko.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : _deps/eigen-build/failtest/CMakeFiles/diagonal_on_const_type_actually_const_ko.dir/depend

