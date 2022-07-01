#pragma once

#include "TypeName.h"

#include <vector>

namespace coil
{
    template<typename... Args>
    struct Types
    {
        static std::size_t constexpr size = sizeof...(Args);
        using IndicesType = std::make_index_sequence<size>;

        static std::vector<std::string_view> const& names()
        {
            static std::vector<std::string_view> data = {TypeName<Args>::name()...};
            return data;
        }
    };
}
