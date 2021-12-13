cmake_minimum_required(VERSION 3.12.0 FATAL_ERROR)

project(coil LANGUAGES C CXX VERSION 1.0)

set(CMAKE_TESTS OFF CACHE BOOL "Add CMake tests")
set(RUN_CMAKE_COMPILATION_TEST OFF CACHE BOOL "Run compilation test in CMake")

set(TEST_COMP_PERF OFF CACHE BOOL "Configure the project for compilation performance tests")
set(TEST_COMP_PERF_USE_COIL OFF CACHE BOOL "Whether to use coil library for compilation performance test")
set(TEST_COMP_PERF_USE_SOL OFF CACHE BOOL "Whether to use sol2 library for compilation performance test")

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
    if (${TEST_COMP_PERF_USE_SOL})
        add_subdirectory(liblua)
    endif()
elseif(${TEST_RUNTIME_PERF})
    add_subdirectory(tests/runtime_performance)
    add_subdirectory(liblua)
else()
    add_subdirectory(examples)
endif()

if(${CMAKE_TESTS})
    enable_testing()
    add_subdirectory(tests/cmake_tests)
endif()
