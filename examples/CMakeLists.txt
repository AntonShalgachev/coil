set(PROJECT_NAME examples)

set(ALL_FILES
    "main_tmp.cpp"
)

set (VS2017 OFF)
if (CMAKE_CXX_COMPILER MATCHES ".*Visual Studio.*2017.*")
    message(STATUS "Visual Studio 2017 in use: '${CMAKE_CXX_COMPILER}'")
    set (VS2017 ON)
endif()

add_executable(${PROJECT_NAME} ${ALL_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR};"
    "${CMAKE_CURRENT_SOURCE_DIR}/include;"
)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_EXTENSIONS OFF)

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

target_compile_options(${PROJECT_NAME} PRIVATE
    ${COMPILE_OPTIONS}
)

if (${VS2017})
    message(STATUS "Adding _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS")
    target_compile_definitions(${PROJECT_NAME} PUBLIC _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS)
endif()

set_target_properties(${PROJECT_NAME} PROPERTIES
    VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
)

target_link_libraries(${PROJECT_NAME}
    libcoil
)
