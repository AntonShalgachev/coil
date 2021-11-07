#pragma once

#include <ostream>
#include <istream>
#include <string>
#include <optional>

#include "magic_enum.hpp"

template<typename EnumT, typename = std::enable_if_t<std::is_enum_v<EnumT>>>
std::istream& operator>>(std::istream& is, EnumT& value)
{
    std::string stringValue;
    is >> stringValue;

    // TODO somehow notify caller of possible values of EnumT

    std::optional<EnumT> optionalValue = magic_enum::enum_cast<EnumT>(stringValue, [](unsigned char a, unsigned char b)
    {
        return std::tolower(a) == std::tolower(b);
    });

    if (optionalValue.has_value())
        value = optionalValue.value();
    else
        is.setstate(std::ios_base::failbit);

    return is;
}

template<typename EnumT, typename = std::enable_if_t<std::is_enum_v<EnumT>>>
std::ostream& operator<<(std::ostream& os, EnumT const& value)
{
    os << magic_enum::enum_name(value);
    return os;
}
