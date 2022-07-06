#pragma once

// Description: If this option is set, Coil would catch and report exceptions which were thrown in the command
// CMake option: COIL_CATCH_EXCEPTIONS
#ifndef COIL_CONFIG_CATCH_EXCEPTIONS
    #define COIL_CONFIG_CATCH_EXCEPTIONS 0
#endif

// Description: If this option is set, the implementation of coil::TypeName for the basic types would be included
// CMake option: COIL_BASIC_TYPENAME
#ifndef COIL_CONFIG_BASIC_TYPENAME
    #define COIL_CONFIG_BASIC_TYPENAME 0
#endif
