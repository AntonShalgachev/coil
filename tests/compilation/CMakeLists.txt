function(validate_compilation SOURCE_FILE EXPECTED_RESULT EXPECTED_OUTPUT)
    try_compile(COMPILATION_RESULT
        ${CMAKE_CURRENT_SOURCE_DIR}/build
        SOURCES
            ${CMAKE_CURRENT_SOURCE_DIR}/${SOURCE_FILE}
            ${CMAKE_SOURCE_DIR}/src/Coil.cpp # TODO make prettier
        CMAKE_FLAGS
            "-DCMAKE_CXX_STANDARD=17"
            "-DINCLUDE_DIRECTORIES=${PROJECT_SOURCE_DIR}/include"
        OUTPUT_VARIABLE COMPILATION_OUTPUT
    )

    set(COMPILATION_OUTPUT_OK TRUE)
    string(FIND "${COMPILATION_OUTPUT}" "${EXPECTED_OUTPUT}" FIND_RESULT)
    if(${FIND_RESULT} EQUAL -1)
        set(COMPILATION_OUTPUT_OK FALSE)
    endif()

    set(COMPILATION_RESULT_OK FALSE)
    if(COMPILATION_RESULT STREQUAL EXPECTED_RESULT)
        set(COMPILATION_RESULT_OK TRUE)
    endif()

    if(COMPILATION_RESULT_OK AND COMPILATION_OUTPUT_OK)
        message(STATUS "${SOURCE_FILE}: Passed")
    else()
        message(FATAL_ERROR "${COMPILATION_OUTPUT}\n${SOURCE_FILE}: FAILED. Expected: ${EXPECTED_RESULT}, actual: ${COMPILATION_RESULT}, expected output: '${EXPECTED_OUTPUT}'")
    endif()
endfunction()

message(STATUS "")
message(STATUS "Performing compilation tests...")

validate_compilation(Valid.cpp TRUE "")
validate_compilation(DirectMemberFunctionAssignment.cpp FALSE "Func can only be a member function if C isn't void")
validate_compilation(DirectVariableAssignment.cpp FALSE "Func should be a functor object")
# TODO add fail tests for coil::property, coil::variable, coil::bind

message(STATUS "All tests finished")
message(STATUS "")
