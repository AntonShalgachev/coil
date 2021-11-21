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

    template<typename EnumT>
    struct TypeSerializer<EnumT, std::enable_if_t<std::is_enum_v<EnumT>>>
    {
        template<typename OnError>
        static EnumT fromString(std::string_view str, [[maybe_unused]] OnError&& onError)
        {
            // This makes enum names case-insensitive
            auto pred = [](unsigned char a, unsigned char b) { return std::tolower(a) == std::tolower(b); };
            std::optional<EnumT> optionalValue = magic_enum::enum_cast<EnumT>(str, std::move(pred));

            if (optionalValue.has_value())
                return optionalValue.value();

            std::string names = utils::flatten(magic_enum::enum_names<EnumT>(), "'");

            reportConversionError<EnumT>(std::forward<OnError>(onError), str, utils::formatString("Possible values are [%s]", names.c_str()));
            return EnumT{};
        }

        static std::string_view toString(EnumT const& value)
        {
            return magic_enum::enum_name(value);
        }
    };
}
