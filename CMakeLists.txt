cmake_minimum_required(VERSION 3.15.0 FATAL_ERROR)

project(coil LANGUAGES C CXX VERSION 1.0)

set(COIL_EXAMPLES OFF CACHE BOOL "Coil examples")
set(COIL_RUNTIME_TESTS OFF CACHE BOOL "Coil runtime tests")
set(COIL_COMPILATION_TESTS OFF CACHE BOOL "Run Coil compilation tests within CMake")

set(COIL_COMPILATION_TIME_BENCHMARK OFF CACHE BOOL "Coil compilation time benchmark")
set(COIL_COMPILATION_TIME_BENCHMARK_TRACE OFF CACHE BOOL "Generate Clang trace files for Coil compilation time benchmark")
set(COIL_COMPILATION_TIME_BENCHMARK_WITH_COIL OFF CACHE BOOL "Use Coil library for compilation time benchmark")
set(COIL_COMPILATION_TIME_BENCHMARK_WITH_MANUAL OFF CACHE BOOL "Use manually-written bindings for compilation time benchmark")

add_library(coil
    "include/coil/detail/CallContext.h"
    "include/coil/detail/FunctionWrapper.h"
    "include/coil/detail/FunctorCaller.h"
    "include/coil/detail/FuncTraits.h"
    "include/coil/detail/StringWrapper.h"

    "include/coil/AnyFunctor.h"
    "include/coil/Bind.h"
    "include/coil/Bindings.h"
    "include/coil/Coil.h"
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
    "include/coil/Value.h"
    "include/coil/Variable.h"

    "src/Coil.cpp"
)
add_library(coil::coil ALIAS coil)

target_include_directories(coil
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

target_compile_features(coil PUBLIC cxx_std_17)
set_target_properties(coil PROPERTIES CXX_EXTENSIONS OFF)
if(MSVC)
  target_compile_options(coil PRIVATE /W4 /WX)
else()
  target_compile_options(coil PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()

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
if(${COIL_COMPILATION_TIME_BENCHMARK})
    add_subdirectory(tests/compilation_performance)
endif()
