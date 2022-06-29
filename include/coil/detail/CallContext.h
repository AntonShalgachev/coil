#pragma once

#include "../ExecutionInput.h"
#include "../ExecutionResult.h"
#include "../Expected.h"

namespace coil::detail
{
    struct CallContext
    {
        CallContext(ExecutionInput const& input);

        ExecutionInput const& input;
        ExecutionResult result;

        std::ostream& log();

        void reportError(std::string error);

        bool hasErrors() const;
    };
}
