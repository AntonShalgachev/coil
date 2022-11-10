#pragma once

#include "Config.h"

#include <stdarg.h>

namespace coil
{
    class String;

    COIL_PRINTF_LIKE(1, 2) String sprintf(char const* format, ...);
    String vsprintf(char const* format, va_list args);
}
