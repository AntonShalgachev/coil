#pragma once

#include "../ExecutionInput.h"
#include "../ExecutionResult.h"
#include "../Expected.h"

namespace coil::detail
{
    struct CallContext
    {
        CallContext(ExecutionInput input);

        ExecutionInput input;
        ExecutionResult result;

        std::ostream& log();

        void reportError(std::string error);

        bool hasErrors() const;
    };
}
