#pragma once

#include "ExecutionInput.h"
#include "coil/String.h"
#include "coil/Vector.h"
#include "coil/Optional.h"

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
