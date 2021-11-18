#pragma once

#include <array>

#include "coil/TypeName.h"

namespace coil::utils
{
	template<typename... Args>
	struct Types
	{
		static std::size_t constexpr size = sizeof...(Args);
		using IndicesType = std::make_index_sequence<size>;

        static auto names()
        {
            return std::array<std::string_view, size>{ TypeName<Args>::name()... };
        }
	};
}
