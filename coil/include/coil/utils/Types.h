#pragma once

#include "Utils.h"

namespace utils
{
	namespace detail
	{
		template<typename T>
		struct TypeInfo
		{
			static std::string name()
			{
				return typeid(T).name();
			}
		};
	}

	template<typename... Args>
	struct Types
	{
		static std::size_t constexpr size = sizeof...(Args);
		using IndicesType = std::make_index_sequence<size>;

		static std::string name()
		{
			std::vector<std::string> names = { detail::TypeInfo<Args>::name() ... };

			return utils::flatten(names);
		}
	};
}
