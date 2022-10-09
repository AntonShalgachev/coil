#pragma once

#include "TypeName.h"
#include "detail/Utility.h"

#include <vector>

namespace coil
{
    template<typename... Args>
    struct Types
    {
        static std::size_t constexpr size = sizeof...(Args);
        using IndicesType = MakeIndexSequence<size>;

        static std::vector<std::string_view> const& names()
        {
            static std::vector<std::string_view> data = {TypeName<Args>::name()...};
            return data;
        }
    };
}
