set(PROJECT_NAME cmake_tests)

set(ALL_FILES
    "Common.h"

    "LexerTests.cpp"
    "ExpectedTests.cpp"
    "BindingsTests.cpp"
    "TypeSerializerTests.cpp"
    "PropertyTests.cpp"
)

add_executable(${PROJECT_NAME} ${ALL_FILES})

target_link_libraries(${PROJECT_NAME}
    coil::coil
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

set(TEST_NAMES
    "LexerTests"
    "ExpectedTests"
    "BindingsTests"
    "TypeSerializerTests"
    "PropertyTests"
)

foreach(TEST_NAME ${TEST_NAMES})
    add_test(NAME ${TEST_NAME}
             COMMAND ${PROJECT_NAME} --gtest_filter=${TEST_NAME}*)
endforeach()
