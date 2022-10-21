set(PROJECT_NAME cmake_tests)

add_executable(${PROJECT_NAME}
    "Common.h"

    "BindingsTests.cpp"
    "ExpectedTests.cpp"
    "LexerTests.cpp"
    "PropertyTests.cpp"
    "TypeSerializerTests.cpp"
    "VectorTests.cpp"
)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_EXTENSIONS OFF)
if(MSVC)
  target_compile_options(${PROJECT_NAME} PRIVATE /W4 /WX)
else()
  target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()

set(COMPILE_OPTIONS)
if(MSVC)
    set(COMPILE_OPTIONS /W4 /FC /permissive-)
endif()
target_compile_options(${PROJECT_NAME} PRIVATE
    ${COMPILE_OPTIONS}
)

include(CTest)
enable_testing()

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest
    GIT_TAG        e2239ee6043f73722e7aa812a459f54a28552929 # 1.11.0
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
    "VectorTests"
)

target_link_libraries(${PROJECT_NAME}
    coil::coil
    gtest_main
)

foreach(TEST_NAME ${TEST_NAMES})
    add_test(NAME ${TEST_NAME}
             COMMAND ${PROJECT_NAME} --gtest_filter=${TEST_NAME}*)
endforeach()
