#pragma once

// Description: If this option is set, Coil would catch and report exceptions which were thrown in the command
// CMake option: COIL_CATCH_EXCEPTIONS
#ifndef COIL_CONFIG_CATCH_EXCEPTIONS
    #define COIL_CONFIG_CATCH_EXCEPTIONS 0
#endif

// Description: If this option is set, asserts would be enabled
// CMake option: COIL_ENABLE_ASSERTS
#ifndef COIL_CONFIG_ENABLE_ASSERTS
    #define COIL_CONFIG_ENABLE_ASSERTS 0
#endif

// Description: If this option is set, coil::TypeName would use aliases for the type names ()
// CMake option: COIL_TYPE_NAME_USE_ALIAS
#ifndef COIL_CONFIG_TYPE_NAME_USE_ALIAS
    #define COIL_CONFIG_TYPE_NAME_USE_ALIAS 0
#endif
