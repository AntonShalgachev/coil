#pragma once

#include "Sequence.h"
#include "StringView.h"
#include "TypeName.h"

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
                StringView data[size] = {TypeName<Args>::name()...};
                return Vector<StringView>{data, data + size};
            }
            else
            {
                return Vector<StringView>{};
            }
        }
    };
}
