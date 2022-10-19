#pragma once

#include <stdarg.h>

namespace coil
{
    class String;

    String sprintf(char const* format, ...);
    String vsprintf(char const* format, va_list args);
}
