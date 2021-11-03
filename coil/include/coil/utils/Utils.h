#pragma once

#include <vector>
#include <memory>
#include <string>
#include <sstream>

namespace utils
{
	template<typename... Args>
	std::string formatString(char const* format, Args... args)
	{
		std::size_t size = static_cast<std::size_t>(std::snprintf(nullptr, 0, format, args...)) + 1;

		auto buf = std::make_unique<char[]>(size);
		std::snprintf(buf.get(), size, format, std::forward<Args>(args)...);

		return std::string(buf.get(), buf.get() + size - 1);
	}

	std::string flatten(std::vector<std::string> const& strings, std::string decorator = "", std::string separator = ", ");
}