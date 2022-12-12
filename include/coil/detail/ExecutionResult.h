#pragma once

#include "ExecutionInput.h"
#include "Optional.h"
#include "String.h"
#include "Vector.h"

namespace coil
{
    struct ExecutionResult
    {
        ExecutionInput input;
        Vector<String> errors;
        Optional<String> returnValue;
        String output; // TODO use a custom string class to avoid reallocations when appending
    };
}
