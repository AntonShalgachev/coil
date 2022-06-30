#pragma once

#include "coil/TypeName.h"

#include "magic_enum.hpp"

#include <optional>
#include <string>
#include <string_view>
#include <typeinfo>
#include <vector>

// TypeName<T>::name should return the type name as a string. They are useful, for
// example, in the error messages to make them more readable
//
// The default implementation here uses RTTI to get the type name, but other
// methods can be used as well. For example, for enums `magic_enum` is used, and
// for specific types we might just want to make an explicit (full) specialization

namespace coil
{
    template<typename T, typename>
    struct TypeName
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

    template<typename E>
    struct TypeName<E, std::enable_if_t<std::is_enum_v<E>>>
    {
        static std::string_view name()
        {
            return magic_enum::enum_type_name<E>();
        }
    };
}
