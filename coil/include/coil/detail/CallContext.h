#pragma once

#include "coil/ExecutionInput.h"
#include "coil/ExecutionResult.h"

namespace coil::detail
{
    struct CallContext
    {
        CallContext(ExecutionInput const& input) : input(input) {}

        ExecutionInput const& input;
        ExecutionResult result;
    };
}