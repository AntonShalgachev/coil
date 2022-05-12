set(PROJECT_NAME examples)

set(ALL_FILES
    "main.cpp"
    
    "common/ExamplesCommon.h"
    "common/ExamplesCommon.cpp"
    "common/CustomTypeName.h"
    "common/EnumToString.h"
    "common/FlagVariableWrapper.h"
    
    "basic/BasicExample.h"
    "basic/BasicExample.cpp"
    "variadic/VariadicExample.h"
    "variadic/VariadicExample.cpp"
    "variables/VariablesExample.h"
    "variables/VariablesExample.cpp"
    "named/NamedExample.h"
    "named/NamedExample.cpp"
    "enums/EnumsExample.h"
    "enums/EnumsExample.cpp"
	"errors/ErrorsExample.h"
	"errors/ErrorsExample.cpp"
    "usertypes/UsertypesExample.h"
    "usertypes/UsertypesExample.cpp"
    "common/Utils.h"
)

add_executable(${PROJECT_NAME} ${ALL_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_EXTENSIONS OFF)

set(COMPILE_OPTIONS)
if(MSVC)
    set(COMPILE_OPTIONS /W4 /FC /permissive-)
endif()

target_compile_options(${PROJECT_NAME} PRIVATE
    ${COMPILE_OPTIONS}
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
)

target_link_libraries(${PROJECT_NAME}
    coil::coil
)
