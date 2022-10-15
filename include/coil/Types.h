#pragma once

#include "TypeName.h"
#include "detail/Utility.h"
#include "StringView.h"

#include <vector>

namespace coil
{
    template<typename... Args>
    struct Types
    {
        static std::size_t constexpr size = sizeof...(Args);
        using IndicesType = MakeIndexSequence<size>;

        static std::vector<StringView> const& names()
        {
            static std::vector<StringView> data = {TypeName<Args>::name()...};
            return data;
        }
    };
}
