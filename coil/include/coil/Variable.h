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

extern template auto coil::variable<int>(int* var);
extern template auto coil::variable<short>(short* var);
extern template auto coil::variable<bool>(bool* var);
extern template auto coil::variable<unsigned>(unsigned* var);
extern template auto coil::variable<float>(float* var);
extern template auto coil::variable<double>(double* var);
