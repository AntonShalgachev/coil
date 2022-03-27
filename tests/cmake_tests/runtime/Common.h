#pragma once

#include "coil/TypeName.h"

#include <optional>
#include <vector>

namespace coil
{
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
    template<typename T>
    struct TypeName<std::vector<T>>
    {
        static std::string_view name()
        {
            static std::string result = "std::vector<" + std::string{ TypeName<T>::name() } + ">";
            return result;
        }
    };
}
