#pragma once

#include "coil/Overloaded.h"

#include "magic_enum.hpp"

// This files contains a utility function which enables working with flag enums
// 
// This function is similar to coil::variable, but instead of accepting the enum value, it accepts the
// vector of them. This allows the user to pass several flags which will be ORed automatically upon
// invocation. This enables the user to do the following:
// "some_flags"
// "some_flags Flag1"
// "some_flags Flag1|Flag2|Flag3"
// 
// See FlagsExample for an example

template<typename E>
auto flagsVariable(E* var)
{
    // Getters and setters return the string representation of the flags variable because the
    // TypeSerializer for enums (see examples\common\EnumToString.h) doesn't handle flags by default

    auto get = [var]() { return magic_enum::flags::enum_name(*var); };
    auto set = [var](std::vector<E> const& args) {
        using UT = std::underlying_type_t<E>;

        auto newValue = UT{0};
        for (auto arg : args)
            newValue = static_cast<UT>(newValue) | static_cast<UT>(arg);
        *var = static_cast<E>(newValue);

        return magic_enum::flags::enum_name(*var);
    };

    return coil::overloaded(std::move(get), std::move(set));
}
