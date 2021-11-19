#pragma once

#include <string_view>

namespace coil
{
    template<typename T, typename = void>
    struct TypeName
    {
        static std::string_view name()
        {
            return "unknown";
        }
    };
}
