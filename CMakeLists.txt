cmake_minimum_required(VERSION 3.10)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)

####################################################
# Options
####################################################

option(WITH_TESTS "Build with tests" ON)
option(WITH_INSTALL "Install the project" ON)

####################################################
# Project version from git tags
####################################################

execute_process(COMMAND git describe --dirty
                WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                OUTPUT_VARIABLE PROJECT_VERSION_FULL
                OUTPUT_STRIP_TRAILING_WHITESPACE)

execute_process(COMMAND git describe --tags --abbrev=0
                WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                OUTPUT_VARIABLE PROJECT_VERSION_SHORT
                OUTPUT_STRIP_TRAILING_WHITESPACE)

# Retrive the v from the short version string
string(SUBSTRING ${PROJECT_VERSION_SHORT} 1 -1 PROJECT_VERSION_SHORT)
string(SUBSTRING ${PROJECT_VERSION_FULL} 1 -1 PROJECT_VERSION_FULL)

message(STATUS "Project version: ${PROJECT_VERSION_FULL} (${PROJECT_VERSION_SHORT})")

####################################################
# Project Configuration
####################################################

# Set the project name
project(github-demo VERSION ${PROJECT_VERSION_SHORT})

# Add an executable
add_executable(main main.cpp)

if (WITH_TESTS)
    # Add test executable
    add_executable(test test.cpp)
endif()

if (WITH_INSTALL)
    set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-${PROJECT_VERSION}")
    # Install the executable
    install(TARGETS main DESTINATION bin)
endif()