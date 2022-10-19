#pragma once

#include "Context.h"
#include "Overloaded.h"
#include "detail/Utility.h"

namespace coil
{
    template<typename T>
    Vector<AnyFunctor> variable(T* var)
    {
        auto get = [var]() -> T const& { return *var; };
        auto set = [var](T val) -> T const& {
            *var = Move(val);
            return *var;
        };

        return overloaded(Move(get), Move(set));
    }

    template<typename T>
    Vector<AnyFunctor> variable(T const* var)
    {
        auto get = [var]() -> T const& { return *var; };
        auto set = [var](Context context, T) -> T const& {
            context.reportError("This variable is read-only");
            return *var;
        };

        return overloaded(Move(get), Move(set));
    }
}
