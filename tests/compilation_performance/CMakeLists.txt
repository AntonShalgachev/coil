set(PROJECT_NAME compilation_performance)

set(ALL_FILES
    "main.cpp"
    "Common.h"
    "Common.cpp"
    "pch.h"
)

set(GENERATED_FILES)
add_subdirectory(generated)

set (VS2017 OFF)
if (CMAKE_CXX_COMPILER MATCHES ".*Visual Studio.*2017.*")
    message(STATUS "Visual Studio 2017 in use: '${CMAKE_CXX_COMPILER}'")
    set (VS2017 ON)
endif()

add_executable(${PROJECT_NAME} ${ALL_FILES} ${GENERATED_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR};"
    "${CMAKE_CURRENT_SOURCE_DIR}/include;"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/lua"
)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_EXTENSIONS OFF)

target_precompile_headers(${PROJECT_NAME} PRIVATE "pch.h")

set(COMPILE_OPTIONS)
if(MSVC)
    set(COMPILE_OPTIONS /W4 /FC)

    if (NOT ${VS2017})
        message(STATUS "Adding /permissive-")
        list(APPEND COMPILE_OPTIONS
            /permissive-
        )
    endif()
endif()

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    message(STATUS "Clang in use")
    list(APPEND COMPILE_OPTIONS -ftime-trace)
endif()

target_compile_options(${PROJECT_NAME} PRIVATE
    ${COMPILE_OPTIONS}
)

if(${TEST_COMP_PERF_USE_SOL})
    target_compile_definitions(${PROJECT_NAME} PRIVATE USE_SOL=1)
endif()

if(${TEST_COMP_PERF_USE_COIL})
    target_compile_definitions(${PROJECT_NAME} PRIVATE USE_COIL=1)
endif()

if (${VS2017})
    message(STATUS "Adding _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS")
    target_compile_definitions(${PROJECT_NAME} PUBLIC _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS)
endif()

set_target_properties(${PROJECT_NAME} PROPERTIES
    VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
)

if (${TEST_COMP_PERF_USE_SOL})
    add_dependencies(${PROJECT_NAME} liblua)
endif()

set (LINK_LIBS libcoil)

if (${TEST_COMP_PERF_USE_SOL})
    list(APPEND LINK_LIBS liblua)
endif()

target_link_libraries(${PROJECT_NAME} ${LINK_LIBS})
