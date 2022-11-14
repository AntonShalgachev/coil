cmake_minimum_required(VERSION 3.15.0 FATAL_ERROR)

project(coil LANGUAGES C CXX VERSION 1.0)

set(COIL_CATCH_EXCEPTIONS OFF CACHE BOOL "Configure Coil to catch exceptions in commands")
set(COIL_ENABLE_ASSERTS OFF CACHE BOOL "Configure Coil to enable asserts")
set(COIL_TYPE_NAME_USE_INTEGER_ALIAS OFF CACHE BOOL "Configure Coil to use type aliases as integer type names (e.g. 'uint64' instead of 'unsigned long')")

set(COIL_EXAMPLES OFF CACHE BOOL "Coil examples")
set(COIL_RUNTIME_TESTS OFF CACHE BOOL "Coil runtime tests")
set(COIL_COMPILATION_TESTS OFF CACHE BOOL "Run Coil compilation tests within CMake")

set(COIL_COMPILATION_TIME_BENCHMARK OFF CACHE BOOL "Coil compilation time benchmark")
set(COIL_COMPILATION_TIME_BENCHMARK_TRACE OFF CACHE BOOL "Generate Clang trace files for Coil compilation time benchmark")
set(COIL_COMPILATION_TIME_BENCHMARK_WITH_COIL OFF CACHE BOOL "Use Coil library for compilation time benchmark")
set(COIL_COMPILATION_TIME_BENCHMARK_WITH_MANUAL OFF CACHE BOOL "Use manually-written bindings for compilation time benchmark")
set(COIL_COMPILATION_TIME_BENCHMARK_PCH OFF CACHE BOOL "Enable PCH for the compilation time benchmark")
set(COIL_COMPILATION_TIME_BENCHMARK_EXTERN_TEMPLATES OFF CACHE BOOL "Implement frequently-instantiated templates in a single cpp file (Common.cpp)")

add_library(coil
    # TODO sort

    "include/coil/detail/Algorithm.h"
    "include/coil/detail/CallContext.h"
    "include/coil/detail/Functional.h"
    "include/coil/detail/FunctionWrapper.h"
    "include/coil/detail/FunctorCaller.h"
    "include/coil/detail/FuncTraits.h"
    "include/coil/detail/StrToX.h"
    "include/coil/detail/StringConv.h"
    "include/coil/detail/TypeTraits.h"
    "include/coil/detail/Utility.h"
    "include/coil/detail/New.h"
    "include/coil/detail/Sequence.h"

    "include/coil/Assert.h"
    "include/coil/AnyFunctor.h"
    "include/coil/Bind.h"
    "include/coil/Bindings.h"
    "include/coil/Buffer.h"
    "include/coil/Coil.h"
    "include/coil/Config.h"
    "include/coil/Context.h"
    "include/coil/DefaultLexer.h"
    "include/coil/ExecutionInput.h"
    "include/coil/ExecutionResult.h"
    "include/coil/Expected.h"
    "include/coil/Unexpected.h"
    "include/coil/Extern.h"
    "include/coil/Lexer.h"
    "include/coil/NamedArgs.h"
    "include/coil/Overloaded.h"
    "include/coil/Property.h"
    "include/coil/String.h"
    "include/coil/StringView.h"
    "include/coil/TypeName.h"
    "include/coil/Types.h"
    "include/coil/TypeSerializer.h"
    "include/coil/Utils.h"
    "include/coil/Value.h"
    "include/coil/Variable.h"
    "include/coil/Vector.h"
    "include/coil/Optional.h"
    "include/coil/UnorderedMap.h"
    "include/coil/UniquePtr.h"
    "include/coil/Hash.h"
    "include/coil/StdLibCompat.h"

    "src/Coil.cpp"
    "src/String.cpp"
    "src/StringConv.cpp"
    "src/StringView.cpp"
    "src/StrToX.cpp"
    "src/New.cpp"
    "src/DefaultLexer.cpp"
    "src/Buffer.cpp"
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

if (${COIL_CATCH_EXCEPTIONS})
    target_compile_definitions(coil PUBLIC COIL_CONFIG_CATCH_EXCEPTIONS=1)
endif()

if (${COIL_ENABLE_ASSERTS})
    target_compile_definitions(coil PUBLIC COIL_CONFIG_ENABLE_ASSERTS=1)
endif()

if (${COIL_TYPE_NAME_USE_INTEGER_ALIAS})
    target_compile_definitions(coil PUBLIC COIL_CONFIG_TYPE_NAME_USE_INTEGER_ALIAS=1)
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
    set(BASE_COMPILE_OPTIONS)
    if (COIL_COMPILATION_TIME_BENCHMARK_TRACE AND CMAKE_CXX_COMPILER_ID MATCHES "Clang")
        message(STATUS "Compiling with ftime-trace")
        list(APPEND BASE_COMPILE_OPTIONS -ftime-trace -ftime-trace-granularity=0)
    endif()
    
    target_compile_options(coil PRIVATE ${BASE_COMPILE_OPTIONS})

    add_subdirectory(tests/compilation_performance)
endif()
