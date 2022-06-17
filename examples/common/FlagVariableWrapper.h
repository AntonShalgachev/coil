#pragma once

#include "coil/Overloaded.h"

template<typename E>
auto flags(E* var)
{
    auto get = [var]() { return *var; };
    auto set = [var](std::vector<E> const& args) {
        using UT = std::underlying_type_t<E>;

        auto newValue = UT{0};
        for (auto arg : args)
            newValue = static_cast<UT>(newValue) | static_cast<UT>(arg);
        *var = static_cast<E>(newValue);

        return *var;
    };

    return coil::overloaded(std::move(get), std::move(set));
}
