set(PROJECT_NAME examples)

add_executable(${PROJECT_NAME}
    "main.cpp"
    
    "common/CustomTypeName.h"
    "common/EnumToString.h"
    "common/ExamplesCommon.cpp"
    "common/ExamplesCommon.h"
    "common/FlagVariableWrapper.h"
    
	"errors/ErrorsExample.cpp"
	"errors/ErrorsExample.h"
    "basic/BasicExample.cpp"
    "basic/BasicExample.h"
    "common/Utils.h"
    "enums/EnumsExample.cpp"
    "enums/EnumsExample.h"
    "named/NamedExample.cpp"
    "named/NamedExample.h"
    "usertypes/UsertypesExample.cpp"
    "usertypes/UsertypesExample.h"
    "variables/VariablesExample.cpp"
    "variables/VariablesExample.h"
    "variadic/VariadicExample.cpp"
    "variadic/VariadicExample.h"
    "compound/CompoundExample.cpp"
    "compound/CompoundExample.h"
)

target_include_directories(${PROJECT_NAME} PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
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

set_target_properties(${PROJECT_NAME} PROPERTIES
    VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
)

target_link_libraries(${PROJECT_NAME}
    coil::coil
)
