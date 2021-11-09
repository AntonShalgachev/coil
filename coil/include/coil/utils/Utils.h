#pragma once

#include <vector>
#include <memory>
#include <string>
#include <sstream>

namespace coil::utils
{
	template<typename... Args>
	std::string formatString(char const* format, Args... args)
	{
		std::size_t size = static_cast<std::size_t>(std::snprintf(nullptr, 0, format, args...)) + 1;

		auto buf = std::make_unique<char[]>(size);
		std::snprintf(buf.get(), size, format, std::forward<Args>(args)...);

		return std::string(buf.get(), buf.get() + size - 1);
	}

    template<typename StringVectorLike>
    std::string flatten(StringVectorLike const& strings, std::string_view decorator = "", std::string_view separator = ", ")
    {
        std::string_view currentSeparator = "";
        std::stringstream ss;

        for (auto const& value : strings)
        {
            ss << currentSeparator << decorator << value << decorator;
            currentSeparator = separator;
        }

        return ss.str();
    }

}