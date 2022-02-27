set(PROJECT_NAME libcoil)

set(ALL_FILES
    "include/coil/Types.h"
    "include/coil/Utils.h"
    "include/coil/utils/MemberFunctionFunctor.h"
    "include/coil/utils/VariableWrapper.h"
    

    "include/coil/Bindings.h"
    "include/coil/ExecutionResult.h"
    "include/coil/ExecutionInput.h"
    "include/coil/AnyArgView.h"
    "include/coil/Context.h"
    "include/coil/NamedArgs.h"
    "include/coil/TypeSerializer.h"
    "include/coil/VariadicConsumer.h"
    "include/coil/CommandCollection.h"

    "include/coil/detail/FunctorCaller.h"
    "include/coil/detail/CallContext.h"
    "include/coil/detail/FuncTraits.h"
    "include/coil/detail/StringWrapper.h"
    
    "include/coil/DefaultLexer.h"
    "include/coil/Expected.h"
    "include/coil/TypeName.h"
    "include/coil/Property.h"
    "include/coil/ArgValue.h"
)

add_library(${PROJECT_NAME} INTERFACE ${ALL_FILES})

target_include_directories(${PROJECT_NAME}
    INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include;"
)

target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_17)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_EXTENSIONS OFF)
