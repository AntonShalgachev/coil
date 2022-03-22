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
        ArgValue(std::string_view value, std::vector<std::string_view> subvalues = {});

        bool operator==(ArgValue const& rhs) const;
        bool operator!=(ArgValue const& rhs) const;

        // TODO rename fields?
        std::string_view value;
        // TODO don't allocate here?
        std::vector<std::string_view> subvalues;
    };
}

extern template class std::vector<std::string_view>;
