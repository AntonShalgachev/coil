#pragma once

#include "ExecutionInput.h"
#include "coil/String.h"

#include <optional>
#include <vector>

namespace coil
{
    struct ExecutionResult
    {
        ExecutionInput input;
        std::vector<String> errors;
        std::optional<String> returnValue;
        String output; // TODO use a custom string class to avoid reallocations when appending
    };
}
