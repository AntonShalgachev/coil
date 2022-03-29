set(PROJECT_NAME libcoil)

set(ALL_FILES
    "include/coil/Types.h"
    "include/coil/Utils.h"
    "include/coil/Bind.h"
    "include/coil/Variable.h"

    "include/coil/Bindings.h"
    "include/coil/ExecutionResult.h"
    "include/coil/ExecutionInput.h"
    "include/coil/AnyArgView.h"
    "include/coil/Context.h"
    "include/coil/NamedArgs.h"
    "include/coil/TypeSerializer.h"
    "include/coil/CommandCollection.h"

    "include/coil/detail/FunctorCaller.h"
    "include/coil/detail/CallContext.h"
    "include/coil/detail/FuncTraits.h"
    "include/coil/detail/StringWrapper.h"
    "include/coil/detail/AnyFunctor.h"
    
    "include/coil/DefaultLexer.h"
    "include/coil/Expected.h"
    "include/coil/TypeName.h"
    "include/coil/Property.h"
    "include/coil/ArgValue.h"
    "include/coil/Overloaded.h"
    
    "include/coil/Coil.h"
    "include/coil/Extern.h"

    "src/Coil.cpp"
)

add_library(${PROJECT_NAME} ${ALL_FILES})

target_include_directories(${PROJECT_NAME}
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include;"
)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_EXTENSIONS OFF)
