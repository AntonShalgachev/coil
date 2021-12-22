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

        template<typename T, typename E>
        void reportError(coil::Expected<T, E> expected)
        {
            static_assert(std::is_convertible_v<decltype(expected.error()), std::string>, "Expected's error should be convertible to std::string");

            if (!expected)
                reportError(std::move(expected).error());
        }

        template<typename... Ts>
        void reportErrors(Ts&&... errors)
        {
            (reportError(std::forward<Ts>(errors)), ...);
        }

        bool hasErrors() const
        {
            return !result.errors.empty();
        }
    };
}
