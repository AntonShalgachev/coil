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
        String output;
    };
}
