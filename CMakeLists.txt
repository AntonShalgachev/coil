cmake_minimum_required(VERSION 3.12.0 FATAL_ERROR)

project(coil LANGUAGES C CXX VERSION 1.0)

set(COIL_EXAMPLES ON CACHE BOOL "Add examples")
set(COIL_RUNTIME_TESTS OFF CACHE BOOL "Add CMake runtime tests")
set(COIL_COMPILATION_TESTS OFF CACHE BOOL "Run CMake compilation tests")

set(COIL_RUNTIME_PERFORMANCE OFF CACHE BOOL "Configure the project for runtime performance tests")
set(COIL_COMPILE_TIME OFF CACHE BOOL "Configure the project for compilation performance tests")
set(COIL_COMPILE_TIME_WITH_COIL OFF CACHE BOOL "Whether to use coil library for compilation performance test")
set(COIL_COMPILE_TIME_WITH_MANUAL OFF CACHE BOOL "Whether to use manually-written bindings for compilation performance test")

# TODO move to examples/tests/etc.
set(CMAKE_CONFIGURATION_TYPES
    "Debug"
    "Release"
    "RelWithDebInfo"
    "MinSizeRel"
    CACHE STRING "" FORCE
)

# TODO find a cleaner way to do it
if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
    set(OLD_FLAGS ${CMAKE_CXX_FLAGS})
    string(REGEX REPLACE "/W[0-4]" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    message(STATUS "CMAKE_CXX_FLAGS changed from '${OLD_FLAGS}' to '${CMAKE_CXX_FLAGS}'")
endif()

# TODO move to examples/tests/etc.
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_subdirectory(coil)

if (${COIL_EXAMPLES})
    add_subdirectory(examples)
endif()
if (${COIL_RUNTIME_TESTS})
    enable_testing()
    add_subdirectory(tests/cmake_tests/runtime)
endif()
if (${COIL_COMPILATION_TESTS})
    add_subdirectory(tests/cmake_tests/compilation)
endif()
if (${COIL_RUNTIME_PERFORMANCE})
    add_subdirectory(tests/runtime_performance)
endif()
if(${COIL_COMPILE_TIME})
    add_subdirectory(tests/compilation_performance)
endif()
