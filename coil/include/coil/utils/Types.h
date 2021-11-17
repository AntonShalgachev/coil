#pragma once

#include "Utils.h"

namespace coil::utils
{
	namespace detail
	{
        // TODO move out of detail, remove RTTI and allow specializations
		template<typename T>
		struct TypeInfo
		{
			static std::string_view name()
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
			std::vector<std::string_view> names = { detail::TypeInfo<Args>::name() ... };

			return flatten(names);
		}
	};
}
