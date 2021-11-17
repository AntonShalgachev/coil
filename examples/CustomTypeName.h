#pragma once

#include "coil/TypeName.h"
#include <string_view>

namespace coil
{
    template<typename T>
    struct TypeName<T>
    {
        static std::string_view name()
        {
            return typeid(T).name();
        }
    };

    template<>
    struct TypeName<std::string>
    {
        static std::string_view name()
        {
            return "std::string";
        }
    };

    template<>
    struct TypeName<std::string_view>
    {
        static std::string_view name()
        {
            return "std::string_view";
        }
    };
}
