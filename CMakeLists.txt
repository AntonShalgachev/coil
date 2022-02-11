cmake_minimum_required(VERSION 3.12.0 FATAL_ERROR)

project(coil LANGUAGES C CXX VERSION 1.0)

set(CMAKE_RUNTIME_TESTS OFF CACHE BOOL "Add CMake runtime tests")
set(CMAKE_COMPILATION_TESTS OFF CACHE BOOL "Run CMake compilation tests")

set(TEST_COMP_PERF OFF CACHE BOOL "Configure the project for compilation performance tests")
set(TEST_COMP_PERF_USE_COIL OFF CACHE BOOL "Whether to use coil library for compilation performance test")
set(TEST_COMP_PERF_USE_MANUAL OFF CACHE BOOL "Whether to use manually-written bindings for compilation performance test")

set(TEST_RUNTIME_PERF OFF CACHE BOOL "Configure the project for runtime performance tests")

set(CMAKE_CONFIGURATION_TYPES
    "Debug"
    "Release"
    "RelWithDebInfo"
    "MinSizeRel"
    CACHE STRING "" FORCE
)

if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
    set(OLD_FLAGS ${CMAKE_CXX_FLAGS})
    string(REGEX REPLACE "/W[0-4]" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    message(STATUS "CMAKE_CXX_FLAGS changed from '${OLD_FLAGS}' to '${CMAKE_CXX_FLAGS}'")
endif()

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_subdirectory(coil)

if (${TEST_COMP_PERF})
    add_subdirectory(tests/compilation_performance)
elseif(${TEST_RUNTIME_PERF})
    add_subdirectory(tests/runtime_performance)
    add_subdirectory(tests/liblua)
elseif(${CMAKE_RUNTIME_TESTS})
    enable_testing()
    add_subdirectory(tests/cmake_tests/runtime)
elseif(${CMAKE_COMPILATION_TESTS})
    add_subdirectory(tests/cmake_tests/compilation)
else()
    add_subdirectory(examples)
endif()
