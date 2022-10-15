#pragma once

#include "coil/TypeName.h"
#include "coil/String.h"

#include "magic_enum.hpp"

#include <optional>
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
        static StringView name()
        {
            return typeid(T).name();
        }
    };

    template<typename T>
    struct TypeName<T&>
    {
        static StringView name()
        {
            static String name = String{TypeName<T>::name()} + "&";
            return name;
        }
    };

    template<typename T>
    struct TypeName<T const>
    {
        static StringView name()
        {
            static String name = String{TypeName<T>::name()} + " const";
            return name;
        }
    };

    template<typename T>
    struct TypeName<std::vector<T>>
    {
        static StringView name()
        {
            static String typeName = "std::vector<" + String{TypeName<T>::name()} + ">";
            return typeName;
        }
    };

    template<typename T>
    struct TypeName<std::optional<T>>
    {
        static StringView name()
        {
            static String typeName = "std::optional<" + String{TypeName<T>::name()} + ">";
            return typeName;
        }
    };

    template<typename E>
    struct TypeName<E, std::enable_if_t<std::is_enum_v<E>>>
    {
        static StringView name()
        {
            std::string_view res = magic_enum::enum_type_name<E>();
            return { res.data(), res.size() };
        }
    };
}
