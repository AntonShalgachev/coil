#pragma once

#include "ExecutionInput.h"
#include "coil/String.h"
#include "coil/Vector.h"

#include <optional>

namespace coil
{
    struct ExecutionResult
    {
        ExecutionInput input;
        Vector<String> errors;
        std::optional<String> returnValue;
        String output; // TODO use a custom string class to avoid reallocations when appending
    };
}
