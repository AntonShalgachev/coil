#pragma once

#include <vector>
#include <string>
#include <unordered_map>

namespace coil
{
    struct ExecutionInput
    {
        std::string_view target;
        std::string_view name;
        std::vector<std::string_view> arguments;
        std::unordered_map<std::string_view, std::string_view> namedArguments;

        void setTargetAndName(std::string_view t, std::string_view n)
        {
            target = t;
            name = n;
        }

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
