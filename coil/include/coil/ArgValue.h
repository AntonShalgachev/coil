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
        ArgValue(std::string_view value, std::vector<std::string_view> subvalues = {}) : value(value), subvalues(std::move(subvalues)) {}

        bool operator==(ArgValue const& rhs) const
        {
            return value == rhs.value && subvalues == rhs.subvalues;
        }
        bool operator!=(ArgValue const& rhs) const
        {
            return !(*this == rhs);
        }

        // TODO rename fields?
        std::string_view value;
        // TODO don't allocate here?
        std::vector<std::string_view> subvalues;
    };
}
