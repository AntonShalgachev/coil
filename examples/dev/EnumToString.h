#pragma once

#include <ostream>
#include <istream>
#include <string>
#include <optional>

#define USE_MAGIC_ENUM

#ifdef USE_MAGIC_ENUM
#include "magic_enum.hpp"
#endif

#ifndef USE_MAGIC_ENUM
namespace enum_util
{
    template<typename EnumT>
    std::vector<std::string_view> const& getEnumNames();

    template<typename EnumT>
    std::optional<EnumT> stringToEnum(std::string_view value)
    {
        std::vector<std::string_view> const& names = getEnumNames<EnumT>();

        for (std::size_t i = 0; i < names.size(); i++)
        {
            std::string_view name = names[i];
            if (name == value)
                return static_cast<EnumT>(i);
        }

        return {};
    }

    template<typename EnumT>
    std::string_view enumToString(EnumT value)
    {
        std::vector<std::string_view> const& names = getEnumNames<EnumT>();

        std::size_t index = static_cast<std::size_t>(value);
        if (index < names.size())
            return names.at(index);

        return {};
    }
}
#endif

namespace coil
{
    template<typename EnumT>
    struct Converter<EnumT, std::enable_if_t<std::is_enum_v<EnumT>>>
    {
        template<typename OnError>
        static EnumT fromString(std::string_view str, [[maybe_unused]] OnError&& onError)
        {
#ifdef USE_MAGIC_ENUM
            auto pred = [](unsigned char a, unsigned char b) { return std::tolower(a) == std::tolower(b); };
            std::optional<EnumT> optionalValue = magic_enum::enum_cast<EnumT>(str, std::move(pred));
#else
            std::optional<EnumT> optionalValue = enum_util::stringToEnum<EnumT>(str);
#endif

            if (optionalValue.has_value())
                return optionalValue.value();

#ifdef USE_MAGIC_ENUM
            std::string names = utils::flatten(magic_enum::enum_names<EnumT>(), "'");
#else
            std::string names = utils::flatten(enum_util::getEnumNames<EnumT>(), "'");
#endif

            reportConversionError<EnumT>(std::forward<OnError>(onError), str, utils::formatString("Possible values are [%s]", names.c_str()));
            return EnumT{};
        }

        static std::string_view toString(EnumT const& value)
        {
#ifdef USE_MAGIC_ENUM
            return magic_enum::enum_name(value);
#else
            return enum_util::enumToString(value);
#endif
        }
    };
}
