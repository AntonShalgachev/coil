function(validate_compilation SOURCE_FILE EXPECTED_RESULT)
    try_compile(COMPILATION_RESULT
        ${CMAKE_CURRENT_SOURCE_DIR}/build
        SOURCES
            ${CMAKE_CURRENT_SOURCE_DIR}/${SOURCE_FILE}
            ${CMAKE_SOURCE_DIR}/src/Coil.cpp # TODO make prettier
            ${CMAKE_SOURCE_DIR}/src/String.cpp # TODO make prettier
            ${CMAKE_SOURCE_DIR}/src/StringView.cpp # TODO make prettier
            ${CMAKE_SOURCE_DIR}/src/StringConv.cpp # TODO make prettier
            ${CMAKE_SOURCE_DIR}/src/StdLib.cpp # TODO make prettier
            ${CMAKE_SOURCE_DIR}/src/New.cpp # TODO make prettier
            ${CMAKE_SOURCE_DIR}/src/DefaultLexer.cpp # TODO make prettier
            ${CMAKE_SOURCE_DIR}/src/Buffer.cpp # TODO make prettier
        CMAKE_FLAGS
            "-DCMAKE_CXX_STANDARD=17"
            "-DINCLUDE_DIRECTORIES=${PROJECT_SOURCE_DIR}/include"
        OUTPUT_VARIABLE COMPILATION_OUTPUT
    )

    set(COMPILATION_RESULT_OK FALSE)
    if(COMPILATION_RESULT STREQUAL EXPECTED_RESULT)
        set(COMPILATION_RESULT_OK TRUE)
    endif()

    if(COMPILATION_RESULT_OK)
        message(STATUS "${SOURCE_FILE}: Passed")
    else()
        message(FATAL_ERROR "${COMPILATION_OUTPUT}\n${SOURCE_FILE}: FAILED. Expected: ${EXPECTED_RESULT}, actual: ${COMPILATION_RESULT}")
    endif()
endfunction()

message(STATUS "")
message(STATUS "Performing compilation tests...")

validate_compilation(Valid.cpp TRUE)
validate_compilation(DirectMemberFunctionAssignment.cpp FALSE)
validate_compilation(DirectVariableAssignment.cpp FALSE)
validate_compilation(MemberVariableOnVoid.cpp FALSE)
# TODO add fail tests for coil::property, coil::variable, coil::bind

message(STATUS "All tests finished")
message(STATUS "")
