#pragma once

#include "coil/TypeName.h"

#include <optional>
#include <string>
#include <string_view>
#include <typeinfo>
#include <vector>

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

    template<typename T>
    struct TypeName<T&>
    {
        static std::string_view name()
        {
            static std::string name = std::string{TypeName<T>::name()} + "&";
            return name;
        }
    };

    template<typename T>
    struct TypeName<T const>
    {
        static std::string_view name()
        {
            static std::string name = std::string{TypeName<T>::name()} + " const";
            return name;
        }
    };

    template<typename T>
    struct TypeName<std::vector<T>>
    {
        static std::string_view name()
        {
            using namespace std::literals::string_literals;
            static std::string typeName = "std::vector<"s + std::string{TypeName<T>::name()} + ">"s;
            return typeName;
        }
    };

    template<typename T>
    struct TypeName<std::optional<T>>
    {
        static std::string_view name()
        {
            using namespace std::literals::string_literals;
            static std::string typeName = "std::optional<"s + std::string{TypeName<T>::name()} + ">"s;
            return typeName;
        }
    };
}
