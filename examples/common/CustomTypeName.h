#pragma once

#include "coil/TypeName.h"

#include <typeinfo>

// TypeName<T>::name should return the type name as a StringView. They are useful, for
// example, in the error messages to make them more readable
//
// The default implementation here uses RTTI to get the type name, but other
// methods can be used as well. For example, for enums `magic_enum` can be used, and
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
}
