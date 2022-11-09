#pragma once

#include "coil/TypeName.h"

#include "coil/StdLibCompat.h" // for std->coil string conversion

#include "magic_enum.hpp"

#include <typeinfo>

// TypeName<T>::name should return the type name as a StringView. They are useful, for
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
            return typeid(std::decay_t<T>).name();
        }
    };

    template<typename E>
    struct TypeName<E, std::enable_if_t<std::is_enum_v<E>>>
    {
        static StringView name()
        {
            return coil::fromStdStringView(magic_enum::enum_type_name<E>());
        }
    };
}
