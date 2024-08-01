cmake_minimum_required(VERSION 3.30)
project(kazuha VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

# Add Eigen
include(FetchContent)
FetchContent_Declare(
  eigen
  GIT_REPOSITORY https://gitlab.com/libeigen/eigen.git
  GIT_TAG 3.4.0
)
FetchContent_MakeAvailable(eigen)

# Add GoogleTest
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip
)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)

add_library(kazuha SHARED src/kazuha.cpp)

add_executable(example examples/example.cpp)
target_link_libraries(example kazuha)

add_executable(test_kazuha tests/test_kazuha.cpp)
target_link_libraries(test_kazuha kazuha gtest gtest_main)
gtest_discover_tests(test_kazuha)
