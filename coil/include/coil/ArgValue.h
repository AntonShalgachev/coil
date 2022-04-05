#pragma once

#include <string_view>
#include <vector>

namespace coil
{
    // TODO rename class?
    struct ArgValue
    {
        // TODO do we need these constructors?
        // TODO if yes, make constructors explicit
        ArgValue();
        ArgValue(std::string_view value);
        ArgValue(std::vector<std::string_view> subvalues);

        bool operator==(ArgValue const& rhs) const;

        std::string str() const;

        // TODO don't allocate here?
        std::vector<std::string_view> subvalues;
    };

    std::ostream& operator<<(std::ostream& os, ArgValue const& rhs);
}
