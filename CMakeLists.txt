cmake_minimum_required(VERSION 3.15.0 FATAL_ERROR)

project(coil LANGUAGES C CXX VERSION 1.0)

set(COIL_EXAMPLES OFF CACHE BOOL "Add examples")
set(COIL_RUNTIME_TESTS OFF CACHE BOOL "Add CMake runtime tests")
set(COIL_COMPILATION_TESTS OFF CACHE BOOL "Run CMake compilation tests")

set(COIL_COMPILE_TIME OFF CACHE BOOL "Configure the project for compilation performance tests")
set(COIL_COMPILE_TIME_TRACE OFF CACHE BOOL "Generate trace files for Clang")
set(COIL_COMPILE_TIME_WITH_COIL OFF CACHE BOOL "Whether to use coil library for compilation performance test")
set(COIL_COMPILE_TIME_WITH_MANUAL OFF CACHE BOOL "Whether to use manually-written bindings for compilation performance test")

add_library(coil
    "include/coil/detail/CallContext.h"
    "include/coil/detail/FunctionWrapper.h"
    "include/coil/detail/FunctorCaller.h"
    "include/coil/detail/FuncTraits.h"
    "include/coil/detail/StringWrapper.h"

    "include/coil/AnyArgView.h"
    "include/coil/AnyFunctor.h"
    "include/coil/ArgValue.h"
    "include/coil/Bind.h"
    "include/coil/Bindings.h"
    "include/coil/Coil.h"
    "include/coil/CommandCollection.h"
    "include/coil/Context.h"
    "include/coil/DefaultLexer.h"
    "include/coil/ExecutionInput.h"
    "include/coil/ExecutionResult.h"
    "include/coil/Expected.h"
    "include/coil/Extern.h"
    "include/coil/NamedArgs.h"
    "include/coil/Overloaded.h"
    "include/coil/Property.h"
    "include/coil/TypeName.h"
    "include/coil/Types.h"
    "include/coil/TypeSerializer.h"
    "include/coil/Utils.h"
    "include/coil/Variable.h"

    "src/Coil.cpp"
)
add_library(coil::coil ALIAS coil)

target_include_directories(coil
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

target_compile_features(coil PUBLIC cxx_std_17)
set_target_properties(coil PROPERTIES CXX_EXTENSIONS OFF)

if (${COIL_EXAMPLES})
    add_subdirectory(examples)
endif()
if (${COIL_RUNTIME_TESTS})
    enable_testing()
    add_subdirectory(tests/runtime)
endif()
if (${COIL_COMPILATION_TESTS})
    add_subdirectory(tests/compilation)
endif()
if(${COIL_COMPILE_TIME})
    add_subdirectory(tests/compilation_performance)
endif()
