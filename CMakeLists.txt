# top-level CMakeLists.txt file
cmake_minimum_required(VERSION 3.14)
project(cpp_assignment CXX)

# C++ standard specification
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# options
option(BUILD_TESTS "Build assignment tests." ON)
option(ENABLE_MEMCHECK "Configure project for memory checking." OFF)

# Helpers
include(cmake/MemCheck.cmake)

# Memory Check
if (ENABLE_MEMCHECK)
    enable_memcheck()
endif (ENABLE_MEMCHECK)

if (BUILD_TESTS)
    enable_testing()
    add_subdirectory(external)
endif (BUILD_TESTS)

# add_subdirectory(hw01)
add_subdirectory(hw02)
# add_subdirectory(hw03)
# ...
