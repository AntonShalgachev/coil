#pragma once

#include "TypeName.h"
#include "detail/Utility.h"
#include "StringView.h"

namespace coil
{
    template<typename... Args>
    struct Types
    {
        static size_t constexpr size = sizeof...(Args);
        using IndicesType = MakeIndexSequence<size>;

        static Vector<StringView> names()
        {
            if constexpr (size > 0)
            {
                static StringView data[size] = { TypeName<Args>::name()... };
                return Vector<StringView> { data, size };
            }
            else
            {
                return Vector<StringView>{};
            }
        }
    };
}
