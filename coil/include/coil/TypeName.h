#pragma once

#include <string_view>

// TODO move basic names here

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

    template<>
    struct TypeName<bool>
    {
        static std::string_view name() { return "bool"; }
    };
}
