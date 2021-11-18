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

    template<typename T>
    struct TypeName<std::vector<T>>
    {
        static std::string_view name()
        {
            using namespace std::literals::string_literals;
            static std::string typeName = "std::vector<"s + std::string{ TypeName<T>::name() } +">"s;
            return typeName;
        }
    };

    template<typename T>
    struct TypeName<std::optional<T>>
    {
        static std::string_view name()
        {
            using namespace std::literals::string_literals;
            static std::string typeName = "std::optional<"s + std::string{ TypeName<T>::name() } +">"s;
            return typeName;
        }
    };
}
