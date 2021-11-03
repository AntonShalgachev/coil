#pragma once

#include "ExecutionInput.h"
#include "ExecutionResult.h"

namespace coil
{
    namespace detail
    {
        struct CallContext
        {
            ExecutionInput input;
            ExecutionResult result;
        };
    }
}