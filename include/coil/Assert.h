#pragma once

#include "Config.h"

#if COIL_CONFIG_ENABLE_ASSERTS

    #include <assert.h>
    #define COIL_ASSERT(...) assert(__VA_ARGS__)

#else

    #define COIL_ASSERT(...) ((void)0)

#endif
