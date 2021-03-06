#pragma once

#include "Context.h"
#include "Overloaded.h"

namespace coil
{
    template<typename T>
    std::vector<AnyFunctor> variable(T* var)
    {
        auto get = [var]() -> T const& { return *var; };
        auto set = [var](T val) -> T const& {
            *var = std::move(val);
            return *var;
        };

        return overloaded(std::move(get), std::move(set));
    }

    template<typename T>
    std::vector<AnyFunctor> variable(T const* var)
    {
        auto get = [var]() -> T const& { return *var; };
        auto set = [var](Context context, T) -> T const& {
            context.reportError("This variable is read-only");
            return *var;
        };

        return overloaded(std::move(get), std::move(set));
    }
}
