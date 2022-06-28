#pragma once

#include "Utils.h"
#include "coil/TypeSerializer.h"

#include "magic_enum.hpp"

#include <istream>
#include <optional>
#include <ostream>
#include <string>

namespace coil
{
    // It's up to a user to implement TypeSerializer for enums
    // For this demo I use magic_enum to automatically convert any enum to/from string
    // But other custom solutions are also possible to implement

    template<typename E>
    struct TypeSerializer<E, std::enable_if_t<std::is_enum_v<E>>>
    {
        static Expected<E, std::string> fromString(AnyArgView const& input)
        {
            if (input.subvalues.size() != 1)
                return errors::wrongSubvaluesSize<E>(input, 1);

            auto value = input.subvalues[0];

            // You can also remove this block so that enums can only be deserialized using their names
            if (auto integerValue = TypeSerializer<std::underlying_type_t<E>>::fromString(input))
                return static_cast<E>(*integerValue);

            // This makes enum names case-insensitive
            auto pred = [](unsigned char a, unsigned char b) { return std::tolower(a) == std::tolower(b); };
            std::optional<E> optionalValue = magic_enum::enum_cast<E>(value, std::move(pred));

            if (optionalValue.has_value())
                return optionalValue.value();

            std::string names = ::utils::flatten(magic_enum::enum_names<E>(), "'");

            return errors::serializationError<E>(input, formatString("Possible values are [%s]", names.c_str()));
        }

        static std::string toString(E const& value)
        {
            return std::string{magic_enum::enum_name(value)};
        }
    };
}
