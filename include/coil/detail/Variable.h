#pragma once

#include "Context.h"
#include "Overloaded.h"
#include "Utility.h"

namespace coil
{
    template<typename T>
    Vector<AnyFunctor> variable(T* var)
    {
        auto get = [var]() -> T const& { return *var; };
        auto set = [var](T val) -> T const& {
            *var = coil::move(val);
            return *var;
        };

        return overloaded(coil::move(get), coil::move(set));
    }

    template<typename T>
    Vector<AnyFunctor> variable(T const* var)
    {
        auto get = [var]() -> T const& { return *var; };
        auto set = [var](Context context, T) -> T const& {
            context.reportError("This variable is read-only");
            return *var;
        };

        return overloaded(coil::move(get), coil::move(set));
    }
}
