#pragma once

#include "detail/Utility.h"

#include <string>
#include <vector>

namespace coil
{
    template<typename... Args>
    std::string formatString(char const* format, Args... args)
    {
        std::size_t size = static_cast<std::size_t>(std::snprintf(nullptr, 0, format, args...)) + 1;

        static std::vector<char> buf;
        if (buf.size() < size)
            buf.resize(size);

        std::snprintf(buf.data(), size, format, Forward<Args>(args)...);

        return std::string(buf.begin(), buf.begin() + size - 1);
    }
}
