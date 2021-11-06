#pragma once

#include "coil/ExecutionInput.h"
#include "coil/ExecutionResult.h"

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