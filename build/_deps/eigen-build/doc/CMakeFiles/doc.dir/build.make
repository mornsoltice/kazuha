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

# Utility rule file for doc.

# Include any custom commands dependencies for this target.
include _deps/eigen-build/doc/CMakeFiles/doc.dir/compiler_depend.make

# Include the progress variables for this target.
include _deps/eigen-build/doc/CMakeFiles/doc.dir/progress.make

_deps/eigen-build/doc/CMakeFiles/doc:
	cd /home/soltice/Development/kazuha/build/_deps/eigen-build/doc && doxygen
	cd /home/soltice/Development/kazuha/build/_deps/eigen-build/doc && doxygen Doxyfile-unsupported
	cd /home/soltice/Development/kazuha/build/_deps/eigen-build/doc && /usr/bin/cmake -E copy /home/soltice/Development/kazuha/build/_deps/eigen-build/doc/html/group__TopicUnalignedArrayAssert.html /home/soltice/Development/kazuha/build/_deps/eigen-build/doc/html/TopicUnalignedArrayAssert.html
	cd /home/soltice/Development/kazuha/build/_deps/eigen-build/doc && /usr/bin/cmake -E rename html eigen-doc
	cd /home/soltice/Development/kazuha/build/_deps/eigen-build/doc && /usr/bin/cmake -E remove eigen-doc/eigen-doc.tgz eigen-doc/unsupported/_formulas.log eigen-doc/_formulas.log
	cd /home/soltice/Development/kazuha/build/_deps/eigen-build/doc && /usr/bin/cmake -E tar cfz eigen-doc.tgz eigen-doc
	cd /home/soltice/Development/kazuha/build/_deps/eigen-build/doc && /usr/bin/cmake -E rename eigen-doc.tgz eigen-doc/eigen-doc.tgz
	cd /home/soltice/Development/kazuha/build/_deps/eigen-build/doc && /usr/bin/cmake -E rename eigen-doc html

doc: _deps/eigen-build/doc/CMakeFiles/doc
doc: _deps/eigen-build/doc/CMakeFiles/doc.dir/build.make
.PHONY : doc

# Rule to build all files generated by this target.
_deps/eigen-build/doc/CMakeFiles/doc.dir/build: doc
.PHONY : _deps/eigen-build/doc/CMakeFiles/doc.dir/build

_deps/eigen-build/doc/CMakeFiles/doc.dir/clean:
	cd /home/soltice/Development/kazuha/build/_deps/eigen-build/doc && $(CMAKE_COMMAND) -P CMakeFiles/doc.dir/cmake_clean.cmake
.PHONY : _deps/eigen-build/doc/CMakeFiles/doc.dir/clean

_deps/eigen-build/doc/CMakeFiles/doc.dir/depend:
	cd /home/soltice/Development/kazuha/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/soltice/Development/kazuha /home/soltice/Development/kazuha/build/_deps/eigen-src/doc /home/soltice/Development/kazuha/build /home/soltice/Development/kazuha/build/_deps/eigen-build/doc /home/soltice/Development/kazuha/build/_deps/eigen-build/doc/CMakeFiles/doc.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : _deps/eigen-build/doc/CMakeFiles/doc.dir/depend

