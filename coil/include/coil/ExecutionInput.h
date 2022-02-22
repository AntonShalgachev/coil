#pragma once

#include <vector>
#include <string>
#include <unordered_map>

namespace coil
{
    struct ExecutionInput
    {
        std::string_view name;
        std::vector<std::string_view> arguments;
        std::vector<std::pair<std::string_view, std::string_view>> namedArguments;

        void reset()
        {
            name = {};
            arguments.resize(0);
            namedArguments.resize(0);
        }

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
