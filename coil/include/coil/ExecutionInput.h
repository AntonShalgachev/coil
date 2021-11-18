#pragma once

#include <vector>
#include <string>
#include <unordered_map>

namespace coil
{
    struct ExecutionInput
    {
        std::string_view objectName;
        std::string_view functionName;
        std::vector<std::string_view> arguments;
        std::unordered_map<std::string_view, std::string_view> namedArguments;

        void setTargetAndName(std::string_view object, std::string_view function)
        {
            objectName = object;
            functionName = function;
        }

        auto tie() const
        {
            return std::tie(objectName, functionName, arguments, namedArguments);
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
