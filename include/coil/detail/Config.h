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

// Description: If this option is set, coil::TypeName would use aliases for some integer type names (e.g. "uint64" instead of "unsigned long")
// CMake option: COIL_TYPE_NAME_USE_ALIAS
#ifndef COIL_CONFIG_TYPE_NAME_USE_INTEGER_ALIAS
    #define COIL_CONFIG_TYPE_NAME_USE_INTEGER_ALIAS 0
#endif

#if defined(__clang__) || defined(__GNUC__)
    #define COIL_PRINTF_LIKE(formatIndex, firstArgIndex) __attribute__((__format__(__printf__, formatIndex, firstArgIndex)))
#else
    #define COIL_PRINTF_LIKE(formatIndex, firstArgIndex)
#endif
