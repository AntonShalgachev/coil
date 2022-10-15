#pragma once

#include <cstdarg>

namespace coil
{
    class String;

    String sprintf(char const* format, ...);
    String vsprintf(char const* format, std::va_list args);
}
