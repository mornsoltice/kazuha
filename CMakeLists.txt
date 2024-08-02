cmake_minimum_required(VERSION 3.30)
project(kazuha VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)

# Include directories
include_directories(include)
include_directories(/usr/include/eigen3) # Adjust this path if necessary

# Add Eigen
find_package(Eigen3 3.3 REQUIRED NO_MODULE)
include_directories(${EIGEN3_INCLUDE_DIR})

# Fetch
include(FetchContent)

# Add GoogleTest
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip
)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)

# Find and link OpenMP
find_package(OpenMP REQUIRED)
if(OpenMP_CXX_FOUND)
    message("OpenMP found")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif()

# Library
add_library(kazuha SHARED
    src/kazuha.cpp
    src/entanglement.cpp
    src/superposition.cpp  
    src/entropy.cpp
    src/qft.cpp
)

# Example executable
add_executable(example examples/example.cpp)
target_link_libraries(example kazuha)

# Entanglement example executable
add_executable(entanglement_example examples/example_advanced_entanglement.cpp)
target_link_libraries(entanglement_example kazuha ${OpenMP_CXX_LIBRARIES})

# Superposition example executable
add_executable(superposition_example examples/example_superposition.cpp)
target_link_libraries(superposition_example kazuha)

# Entropy Executable
add_executable(entropy_example examples/example_entropy.cpp)
target_link_libraries(entropy_example kazuha)

# QFT Executable
add_executable(qft_example examples/example_qft.cpp)
target_link_libraries(qft_example kazuha)


# Test Executable
add_executable(test_kazuha tests/test_kazuha.cpp)
target_link_libraries(test_kazuha kazuha gtest gtest_main)
gtest_discover_tests(test_kazuha)


