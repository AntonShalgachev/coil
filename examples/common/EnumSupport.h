#pragma once

#include "Utils.h"
#include "coil/StdLibCompat.h" // for std->coil string conversion
#include "coil/CoilFwd.h"

#include "magic_enum.hpp"

#include <optional>
#include <string>

namespace coil
{
    // It's up to a user to implement TypeSerializer for enums
    // For this demo I use magic_enum to automatically convert any enum to/from string
    // But other custom solutions are also possible to implement

    template<typename E>
    struct TypeSerializer<E, std::enable_if_t<std::is_enum_v<E>>>
    {
        static Expected<E, coil::String> fromString(Value const& input)
        {
            if (input.subvalues.size() != 1)
                return errors::createMismatchedSubvaluesError<E>(input, 1);

            // You can also remove this block so that enums can only be deserialized using their names
            if (auto integerValue = TypeSerializer<std::underlying_type_t<E>>::fromString(input))
                return static_cast<E>(*integerValue);

            // This makes enum names case-insensitive
            auto pred = [](unsigned char a, unsigned char b) { return std::tolower(a) == std::tolower(b); };
            std::optional<E> optionalValue = magic_enum::enum_cast<E>(coil::toStdStringView(input.subvalues[0]), std::move(pred));

            if (optionalValue.has_value())
                return optionalValue.value();

            std::string names = ::utils::flatten(magic_enum::enum_names<E>(), "'");
            return errors::createGenericError<E>(input, sprintf("Possible values are [%s]", names.c_str()));
        }

        static coil::String toString(E const& value)
        {
            return coil::fromStdString(magic_enum::enum_name(value));
        }
    };

    template<typename E>
    struct TypeName<E, std::enable_if_t<std::is_enum_v<E>>>
    {
        static StringView name()
        {
            return coil::fromStdStringView(magic_enum::enum_type_name<E>());
        }
    };
}
