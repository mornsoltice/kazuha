cmake_minimum_required(VERSION 3.10)
project(kazuha VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_library(kazuha SHARED src/kazuha.cpp)

add_executable(example examples/example.cpp)
target_link_libraries(example kazuha)
