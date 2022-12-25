#pragma once

#include "ExecutionInput.h"
#include "ExecutionResult.h"

namespace coil
{
    class String;
}

namespace coil::detail
{
    struct CallContext
    {
        CallContext(ExecutionInput input);

        ExecutionInput input;
        ExecutionResult result;

        void reportError(coil::String error);

        bool hasErrors() const;
    };
}
