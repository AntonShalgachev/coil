set(PROJECT_NAME compilation_performance)

find_package(PythonInterp)

set(GENERATED_FILES)
foreach(INDEX RANGE 0 199)
    list(APPEND GENERATED_FILES "generated_output/ClassWithBindings${INDEX}.h" "generated_output/ClassWithBindings${INDEX}.cpp")
endforeach()

set(GENERATOR_DEPENDENCIES
    "scripts/generate_classes/generate_classes.py"
    "scripts/generate_classes/Class.h.template"
    "scripts/generate_classes/Class.cpp.template"
)

add_custom_command(
    OUTPUT  ${GENERATED_FILES}
    COMMAND ${PYTHON_EXECUTABLE} "${CMAKE_CURRENT_SOURCE_DIR}/scripts/generate_classes/generate_classes.py" 200 "${CMAKE_CURRENT_SOURCE_DIR}/scripts/generate_classes" "${CMAKE_CURRENT_BINARY_DIR}/generated_output"
    DEPENDS ${GENERATOR_DEPENDENCIES}
    COMMENT "Generating test classes"
)

add_executable(${PROJECT_NAME}
    "Common.cpp"
    "Common.h"
    "main.cpp"
    "pch.h"
    ${GENERATED_FILES}
)

target_include_directories(${PROJECT_NAME} PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}"
)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_EXTENSIONS OFF)

if(${COIL_COMPILATION_TIME_BENCHMARK_PCH})
    target_precompile_headers(${PROJECT_NAME} PRIVATE "pch.h")
endif()

set(COMPILE_OPTIONS ${BASE_COMPILE_OPTIONS})
if(MSVC)
    list(APPEND COMPILE_OPTIONS /W4 /FC /permissive-)
endif()

target_compile_options(${PROJECT_NAME} PRIVATE
    ${COMPILE_OPTIONS}
)

if(${COIL_COMPILATION_TIME_BENCHMARK_WITH_MANUAL})
    target_compile_definitions(${PROJECT_NAME} PRIVATE USE_MANUAL=1)
endif()

if(${COIL_COMPILATION_TIME_BENCHMARK_WITH_COIL})
    target_compile_definitions(${PROJECT_NAME} PRIVATE USE_COIL=1)
endif()

if(${COIL_COMPILATION_TIME_BENCHMARK_EXTERN_TEMPLATES})
    target_compile_definitions(${PROJECT_NAME} PRIVATE HAS_EXTERN_TEMPLATES=1)
else()
    target_compile_definitions(${PROJECT_NAME} PRIVATE HAS_EXTERN_TEMPLATES=0)
endif()

set_target_properties(${PROJECT_NAME} PROPERTIES
    VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
)

target_link_libraries(${PROJECT_NAME}
    coil::coil
)
