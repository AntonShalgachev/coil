#pragma once

#include <string>
#include <cstdarg>

namespace coil
{
    std::string sprintf(char const* format, ...);
    std::string vsprintf(char const* format, std::va_list args);
}
