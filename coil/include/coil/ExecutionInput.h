#pragma once

#include <vector>
#include <string>
#include <unordered_map>

namespace coil
{
    struct ExecutionInput
    {
        std::string target;
        std::string name;
        std::vector<std::string> arguments;
        std::unordered_map<std::string, std::string> namedArguments;

        auto tie() const
        {
            return std::tie(target, name, arguments, namedArguments);
        }

        bool operator==(ExecutionInput const& rhs)
        {
            return tie() == rhs.tie();
        }

        bool operator!=(ExecutionInput const& rhs)
        {
            return !(*this == rhs);
        }
    };
}
