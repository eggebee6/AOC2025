cmake_minimum_required(VERSION 3.18)

# Set compiler info
set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set project info
project(AOC2025 VERSION 0.0.1)

set(AOC_NAME "AOC2025")
set(AOC_DESCRIPTION "Advent of Code 2025")

# Check compiler versions
if(CMAKE_CXX_COMPILER STREQUAL "GNU" AND CMAKE_CXX_COMPILER_VERSION VERSION_LESS "14.1.0")
  message(FATAL_ERROR "Invalid g++ version")
elseif(CMAKE_C_COMPILER STREQUAL "GNU" AND CMAKE_C_COMPILER_VERSION VERSION_LESS "14.1.0")
  message(FATAL_ERROR "Invalid gcc version")
endif()

# Set compiler options
set(CMAKE_C_FLAGS "--coverage -Wall -fmessage-length=0")
set(CMAKE_C_OUTPUT_EXTENSION_REPLACE ON)

set(CMAKE_CXX_FLAGS "--coverage -Wall -fmessage-length=0 -fpermissive")
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE ON)

# Add debug definitions
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  add_compile_definitions(DEBUG=1)
endif()

# Set directory variables
set(AOC_SOURCE_DIR "${CMAKE_SOURCE_DIR}/src")
set(AOC_TEST_DIR "${CMAKE_SOURCE_DIR}/test")
set(AOC_EXAMPLE_DIR "${CMAKE_SOURCE_DIR}/examples")
set(AOC_CMAKE_DIR "${CMAKE_SOURCE_DIR}/cmake")
set(AOC_CONFIG_DIR "${CMAKE_SOURCE_DIR}/config")
set(AOC_EXTERNAL_DIR "${CMAKE_SOURCE_DIR}/external")
set(AOC_DOCS_DIR "${CMAKE_SOURCE_DIR}/docs")
set(AOC_OUTPUT_DIR "${CMAKE_SOURCE_DIR}/output")

set(AOC_RUNTIME_OUTPUT_DIR "${AOC_OUTPUT_DIR}/bin")
set(AOC_ARCHIVE_OUTPUT_DIR "${AOC_OUTPUT_DIR}/lib")
set(AOC_LIBRARY_OUTPUT_DIR "${AOC_OUTPUT_DIR}/lib")
set(AOC_HEADER_OUTPUT_DIR "${AOC_OUTPUT_DIR}/include")

set(AOC_TEST_OUTPUT_DIR "${AOC_OUTPUT_DIR}/test")
set(AOC_EXAMPLES_OUTPUT_DIR "${AOC_OUTPUT_DIR}/examples")
set(AOC_DOCS_OUTPUT_DIR "${AOC_OUTPUT_DIR}/docs")

# Set options
option(BUILD_TESTS "Build tests" ON)
option(BUILD_EXAMPLES "Build examples" OFF)

# Display build info
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

# Find packages
find_package(
  Python
  OPTIONAL
  COMPONENTS Interpreter
)

# Include dependencies
include(FetchContent)

# Add source directory
add_subdirectory(${AOC_SOURCE_DIR})

# Add documentation directory
add_subdirectory(${AOC_DOCS_DIR})
