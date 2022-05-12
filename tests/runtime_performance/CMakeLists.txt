set(PROJECT_NAME runtime_performance)

add_executable(${PROJECT_NAME}
    "main.cpp"
)

target_include_directories(${PROJECT_NAME} PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR};"
    "${CMAKE_CURRENT_SOURCE_DIR}/include;"
)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_EXTENSIONS OFF)

set(COMPILE_OPTIONS)
if(MSVC)
    set(COMPILE_OPTIONS /W4 /FC /permissive- "/Zc:__cplusplus")
endif()
target_compile_options(${PROJECT_NAME} PRIVATE
    ${COMPILE_OPTIONS}
)

if(${COIL_COMPILATION_PERFORMANCE_USE_SOL})
    target_compile_definitions(${PROJECT_NAME} PRIVATE USE_SOL=1)
else()
    target_compile_definitions(${PROJECT_NAME} PRIVATE USE_SOL=0)
endif()

set_target_properties(${PROJECT_NAME} PROPERTIES
    VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
)

target_link_libraries(${PROJECT_NAME}
    coil::coil
)
