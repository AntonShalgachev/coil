#pragma once

#include <string_view>
#include <vector>

namespace coil
{
    // TODO rename class?
    struct ArgValue
    {
        ArgValue();
        ArgValue(std::string_view value);
        ArgValue(std::vector<std::string_view> subvalues);

        bool operator==(ArgValue const& rhs) const;

        std::string str() const;

        std::vector<std::string_view> subvalues;
    };

    std::ostream& operator<<(std::ostream& os, ArgValue const& rhs);
}
