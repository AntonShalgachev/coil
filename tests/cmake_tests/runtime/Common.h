#pragma once

#include "coil/TypeName.h"

#include <optional>

namespace coil
{
    template<>
    struct TypeName<bool>
    {
        static std::string_view name() { return "bool"; }
    };
    template<>
    struct TypeName<int>
    {
        static std::string_view name() { return "int"; }
    };
    template<typename T>
    struct TypeName<std::optional<T>>
    {
        static std::string_view name()
        {
            static std::string result = "std::optional<" + std::string{ TypeName<T>::name() } + ">";
            return result;
        }
    };
}
