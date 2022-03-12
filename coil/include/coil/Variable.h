#pragma once

#include "Overloaded.h"

namespace coil
{
    // TODO support const variables

    template<typename T>
    auto variable(T* var)
    {
        auto get = [var]() -> T const& { return *var; };
        auto set = [var](T val) -> T const&
        {
            *var = std::move(val);
            return *var;
        };

        return overloaded(get, set);
    }
}
