set(PROJECT_NAME libcoil)

################################################################################
# Source groups
################################################################################
set(ALL_FILES
    "src/CommandListener.cpp"
    
    "include/coil/utils/FuncTraits.h"
    "include/coil/utils/Types.h"
    "include/coil/utils/Utils.h"
    "include/coil/utils/MemberFunctionFunctor.h"
    "include/coil/utils/VariableWrapper.h"
    "include/coil/utils/TypeId.h"
    "include/coil/utils/FilterTypes.h"
    "include/coil/utils/TrueIndices.h"
    "include/coil/utils/TypeListTraits.h"
    "include/coil/utils/ElementSelector.h"

    "include/coil/CommandListener.h"
    "include/coil/ExecutionResult.h"
    "include/coil/ExecutionInput.h"
    "include/coil/VariadicArg.h"
    "include/coil/Context.h"
    "include/coil/NamedArgs.h"
    "include/coil/Converter.h"

    "include/coil/detail/FunctorCaller.h"
    "include/coil/detail/CallContext.h"
    "include/coil/detail/FuncTraitsEx.h"
    "include/coil/detail/ArgumentTraits.h"
)

add_library(${PROJECT_NAME} STATIC ${ALL_FILES})

set (VS2017 OFF)
if (CMAKE_CXX_COMPILER MATCHES ".*Visual Studio.*2017.*")
    message(STATUS "Visual Studio 2017 in use: '${CMAKE_CXX_COMPILER}'")
    set (VS2017 ON)
endif()

# add_executable(${PROJECT_NAME} ${ALL_FILES})

################################################################################
# Include directories
################################################################################
target_include_directories(${PROJECT_NAME}
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include;"
    PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include/coil;"
)

################################################################################
# Compile and link options
################################################################################
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
