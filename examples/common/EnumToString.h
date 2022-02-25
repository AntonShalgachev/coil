#pragma once

#include <ostream>
#include <istream>
#include <string>
#include <optional>

#include "coil/TypeSerializer.h"

#include "magic_enum.hpp"

namespace coil
{
    // It's up to a user to implement TypeSerializer for enums
    // For this demo I use magic_enum to automatically convert any enum to/from string
    // But other custom solutions are also possible to implement

    template<typename E>
    struct TypeSerializer<E, std::enable_if_t<std::is_enum_v<E>>>
    {
        static Expected<E, std::string> fromString(ArgValue const& input)
        {
            // Allow 0 for the flag enums which don't define a "None" flag
            if (input.value == "0")
                return static_cast<E>(0);

            // This makes enum names case-insensitive
            auto pred = [](unsigned char a, unsigned char b) { return std::tolower(a) == std::tolower(b); };
            std::optional<E> optionalValue = magic_enum::enum_cast<E>(input.value, std::move(pred));

            if (optionalValue.has_value())
                return optionalValue.value();

            std::string names = utils::flatten(magic_enum::enum_names<E>(), "'");

            return reportConversionError<E>(input, utils::formatString("Possible values are [%s]", names.c_str()));
        }

        static auto toString(E const& value)
        {
            // not optimal for non-flags enum types, since magic_enum::flags::enum_name returns std::string,
            // but other solutions are possible (e.g. using different specialization for non-flag enum types)
            return magic_enum::flags::enum_name(value);
        }
    };
}
