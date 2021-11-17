#pragma once

#include "Utils.h"
#include "coil/TypeName.h"

namespace coil::utils
{
	template<typename... Args>
	struct Types
	{
		static std::size_t constexpr size = sizeof...(Args);
		using IndicesType = std::make_index_sequence<size>;

		static std::string name()
		{
			std::vector<std::string_view> names = { TypeName<Args>::name() ... };

			return flatten(names);
		}
	};
}
