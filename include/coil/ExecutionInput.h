#pragma once

#include "AnyArgView.h"

#include <string>
#include <unordered_map>
#include <vector>

namespace coil
{
    struct ExecutionInput
    {
        std::string_view name;
        std::vector<AnyArgView> arguments;
        std::vector<std::pair<std::string_view, AnyArgView>> namedArguments;

        void reset()
        {
            name = {};
            arguments.clear();
            namedArguments.clear();
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
