#pragma once

#include "Value.h"

#include <string>
#include <vector>

namespace coil
{
    struct ExecutionInput
    {
        std::string_view name;
        std::vector<Value> arguments;
        std::vector<std::pair<std::string_view, Value>> namedArguments;
    };
}
