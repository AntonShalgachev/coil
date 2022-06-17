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

        return overloaded(get, set);
    }

    template<typename T>
    std::vector<AnyFunctor> variable(T const* var)
    {
        auto get = [var]() -> T const& { return *var; };
        auto set = [var](Context context, T) -> T const& {
            context.reportError("Cannot write to a read-only variable");
            return *var;
        };

        return overloaded(get, set);
    }
}
