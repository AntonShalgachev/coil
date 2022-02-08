#pragma once

#include <vector>
#include <string>
#include <unordered_map>

namespace coil
{
    struct ExecutionInput
    {
        std::string_view objectName;
        std::vector<std::string_view> categoryPath;
        std::vector<std::string_view> arguments;
        std::vector<std::pair<std::string_view, std::string_view>> namedArguments;

        void reset()
        {
            objectName = {};
            categoryPath.resize(0);
            arguments.resize(0);
            namedArguments.resize(0);
        }

        void setTargetAndName(std::string_view object, std::string_view function)
        {
            objectName = object;
            categoryPath.push_back(function);
        }

        auto tie() const
        {
            return std::tie(objectName, categoryPath, arguments, namedArguments);
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
