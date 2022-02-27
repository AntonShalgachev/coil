#pragma once

#include <string_view>
#include <sstream>

namespace utils
{
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
