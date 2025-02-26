cmake_minimum_required(VERSION 3.10)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)

# Set options
option(WITH_TESTS "Build with tests" ON)

# Set the project name
project(github-demo)

# Add an executable
add_executable(main main.cpp)

if (WITH_TESTS)
    # Add test executable
    add_executable(test test.cpp)
endif()