#pragma once

#include "coil/ExecutionInput.h"
#include "coil/ExecutionResult.h"
#include "coil/Expected.h"

namespace coil::detail
{
    struct CallContext
    {
        CallContext(ExecutionInput const& input);

        ExecutionInput const& input;
        ExecutionResult result;

        std::ostream& out();

        void reportError(std::string error);

        bool hasErrors() const;
    };
}
