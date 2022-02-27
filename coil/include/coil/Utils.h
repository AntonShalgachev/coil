#pragma once

#include <vector>
#include <memory>
#include <string>

namespace coil
{
	template<typename... Args>
	std::string formatString(char const* format, Args... args)
	{
		std::size_t size = static_cast<std::size_t>(std::snprintf(nullptr, 0, format, args...)) + 1;

        // TODO use static std::vector<char>
		auto buf = std::make_unique<char[]>(size);
		std::snprintf(buf.get(), size, format, std::forward<Args>(args)...);

		return std::string(buf.get(), buf.get() + size - 1);
	}
}