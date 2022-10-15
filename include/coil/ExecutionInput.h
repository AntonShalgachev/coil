#pragma once

#include "Value.h"
#include "StringView.h"

#include <vector>

namespace coil
{
    struct ExecutionInput
    {
        StringView name;
        std::vector<Value> arguments;
        std::vector<std::pair<StringView, Value>> namedArguments;
    };
}
