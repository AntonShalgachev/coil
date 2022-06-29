#pragma once

#include "Value.h"

#include <string>
#include <unordered_map>
#include <vector>

namespace coil
{
    struct ExecutionInput
    {
        std::string_view name;
        std::vector<Value> arguments;
        std::vector<std::pair<std::string_view, Value>> namedArguments;

        auto tie() const
        {
            return std::tie(name, arguments, namedArguments);
        }

        bool operator==(ExecutionInput const& rhs) const
        {
            return tie() == rhs.tie();
        }

        bool operator!=(ExecutionInput const& rhs) const
        {
            return !(*this == rhs);
        }
    };
}
