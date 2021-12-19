set(PROJECT_NAME cmake_tests)

set(ALL_FILES
    "LexerTests.cpp"
    "ExpectedTests.cpp"
    "BindingsTests.cpp"
    "TypeSerializerTests.cpp"
)

add_executable(${PROJECT_NAME} ${ALL_FILES})

target_link_libraries(${PROJECT_NAME}
    libcoil
    gtest_main
)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_EXTENSIONS OFF)

set(COMPILE_OPTIONS)
if(MSVC)
    set(COMPILE_OPTIONS /W4 /FC)
endif()
target_compile_options(${PROJECT_NAME} PRIVATE
    ${COMPILE_OPTIONS}
)

include(CTest)
enable_testing()

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        release-1.11.0
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
message(STATUS "Fetching googletest from GitHub...")
FetchContent_MakeAvailable(googletest)

add_test(NAME ${PROJECT_NAME}
         COMMAND ${PROJECT_NAME})
