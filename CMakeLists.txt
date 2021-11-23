cmake_minimum_required(VERSION 3.12.0 FATAL_ERROR)

project(coil LANGUAGES C CXX VERSION 1.0)

set(COIL_COMPILATION_PERFORMANCE OFF CACHE BOOL "Configure the project for compilation performance tests")
set(COIL_COMPILATION_PERFORMANCE_USE_SOL OFF CACHE BOOL "Whether to use sol2 library for compilation performance test")

set(CMAKE_CONFIGURATION_TYPES
    "Debug"
    "Release"
    CACHE STRING "" FORCE
)

if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
    set(OLD_FLAGS ${CMAKE_CXX_FLAGS})
    string(REGEX REPLACE "/W[0-4]" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    message(STATUS "CMAKE_CXX_FLAGS changed from '${OLD_FLAGS}' to '${CMAKE_CXX_FLAGS}'")
endif()

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_subdirectory(coil)
add_subdirectory(liblua)

if (${COIL_COMPILATION_PERFORMANCE})
    add_subdirectory(tests/compilation_performance)
else()
    add_subdirectory(examples)
endif()
