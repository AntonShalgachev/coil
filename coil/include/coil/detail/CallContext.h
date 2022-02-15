#pragma once

#include "coil/ExecutionInput.h"
#include "coil/ExecutionResult.h"
#include "coil/Expected.h"

namespace coil::detail
{
    struct CallContext
    {
        CallContext(ExecutionInput const& input) : input(input) {}

        ExecutionInput const& input;
        ExecutionResult result;

        std::ostream& out() { return result.output; }

        void reportError(std::string error)
        {
            result.errors.push_back(std::move(error));
        }

        bool hasErrors() const
        {
            return !result.errors.empty();
        }
    };
}
