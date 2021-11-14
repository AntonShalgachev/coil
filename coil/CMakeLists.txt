set(PROJECT_NAME libcoil)

set(ALL_FILES
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

    "include/coil/Bindings.h"
    "include/coil/ExecutionResult.h"
    "include/coil/ExecutionInput.h"
    "include/coil/VariadicArg.h"
    "include/coil/Context.h"
    "include/coil/NamedArgs.h"
    "include/coil/TypeSerializer.h"

    "include/coil/detail/FunctorCaller.h"
    "include/coil/detail/CallContext.h"
    "include/coil/detail/FuncTraitsEx.h"
    "include/coil/detail/ArgumentTraits.h"
    "include/coil/BindingProxy.h"
    "include/coil/DefaultLexer.h"
    
)

add_library(${PROJECT_NAME} INTERFACE ${ALL_FILES})

target_include_directories(${PROJECT_NAME}
    INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include;"
)

target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_17)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_EXTENSIONS OFF)
