cmake_minimum_required(VERSION 3.30.1)
set(CMAKE_MODULE_PATH "/home/soltice/Development/kazuha/build/_deps/eigen-src/cmake")
project(CheckFortran Fortran)
file(WRITE "${CMAKE_CURRENT_BINARY_DIR}/result.cmake"
  "set(CMAKE_Fortran_COMPILER \"${CMAKE_Fortran_COMPILER}\")\n"
  
  )