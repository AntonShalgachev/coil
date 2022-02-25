#pragma once

#include "TypeName.h"
#include "Expected.h"
#include "utils/Utils.h"
#include "ArgValue.h"

#include <string>
#include <sstream>
#include <cctype>

#include <algorithm>
#include <optional>
#include <charconv>

namespace coil
{
    // TODO rename
    // TODO make inputString 'coil::ArgValue'
    template<typename T>
    static Unexpected<std::string> reportConversionError(std::string_view inputString, std::string_view details = {})
    {
        std::string_view typeName = TypeName<T>::name();

        if (details.empty())
            return makeUnexpected(utils::formatString("Unable to convert '%.*s' to type '%.*s'", inputString.length(), inputString.data(), typeName.length(), typeName.data()));
        else
            return makeUnexpected(utils::formatString("Unable to convert '%.*s' to type '%.*s': %.*s", inputString.length(), inputString.data(), typeName.length(), typeName.data(), details.length(), details.data()));
    }

    template<typename T>
    static Unexpected<std::string> makeSerializationError(ArgValue const& input, std::size_t expectedSubvalues)
    {
        return reportConversionError<T>(input.value, utils::formatString("Expected %d subvalues, got %d", expectedSubvalues, input.subvalues.size()));
    }

    template<typename T, typename = void>
    struct HasCoutOperator : std::false_type {};
    template<typename T>
    struct HasCoutOperator<T, std::void_t<decltype(std::declval<std::ostream>() << std::declval<T>())>> : std::true_type {};

    template<typename T, typename = void>
    struct HasCinOperator : std::false_type {};
    template<typename T>
    struct HasCinOperator<T, std::void_t<decltype(std::declval<std::istream>() >> std::declval<T>())>> : std::true_type {};

    template<typename T, typename = void>
    struct TypeSerializer
    {
        static_assert(!std::is_void_v<T>, "Void isn't a valid conversion type");
        
        // TODO rename `str` to `input`
        static Expected<T, std::string> fromString(ArgValue const& str)
        {
            static_assert(HasCinOperator<T>::value, "T should have operator>>, or TypeSerializer has to be specialized for type T");

            std::stringstream ss;
            ss << str.value;

            T value{};
            ss >> value;

            if (ss.eof() && !ss.fail())
                return value;

            return reportConversionError<T>(str.value);
        }

        static std::string toString([[maybe_unused]] T const& value)
        {
            static_assert(HasCoutOperator<T>::value, "T should have operator<<, or TypeSerializer has to be specialized for type T");

            std::stringstream ss;
            ss << value;

            return ss.str();
        }
    };

    template<typename T>
    struct TypeSerializer<T, std::enable_if_t<std::is_arithmetic_v<T>>>
    {
        static Expected<T, std::string> fromString(ArgValue const& str)
        {
            auto begin = str.value.data();
            auto end = str.value.data() + str.value.length();

            T value{};
            std::from_chars_result result = std::from_chars(begin, end, value);
            if (result.ptr == end)
                return value;

            return reportConversionError<T>(str.value);
        }

        static std::string toString(T value)
        {
            return std::to_string(value);
        }
    };

    template<>
    struct TypeSerializer<bool>
    {
        static Expected<bool, std::string> fromString(ArgValue const& str)
        {
            auto equalCaseInsensitive = [](std::string_view a, std::string_view b)
            {
                std::size_t const length = a.length();
                if (b.length() != length)
                    return false;

                for (std::size_t i = 0; i < a.length(); i++)
                    if (std::tolower(a[i]) != std::tolower(b[i]))
                        return false;

                return true;
            };

            if (str.value == "1")
                return true;
            if (str.value == "0")
                return false;

            if (equalCaseInsensitive(str.value, "true"))
                return true;
            if (equalCaseInsensitive(str.value, "false"))
                return false;

            return reportConversionError<bool>(str.value);
        }

        static std::string toString(bool value)
        {
            return value ? "true" : "false";
        }
    };

    template<>
    struct TypeSerializer<std::string>
    {
        static Expected<std::string, std::string> fromString(ArgValue const& str)
        {
            return std::string{ str.value };
        }

        static std::string toString(std::string const& value)
        {
            return value;
        }
    };

    template<>
    struct TypeSerializer<std::string_view>
    {
        static Expected<std::string_view, std::string> fromString(ArgValue const& str)
        {
            return str.value;
        }

        static std::string toString(std::string_view value)
        {
            return std::string{ value };
        }
    };

    template<typename T>
    struct TypeSerializer<std::optional<T>>
    {
        static Expected<std::optional<T>, std::string> fromString(ArgValue const& str)
        {
            if (str.value.empty())
                return {};

            return TypeSerializer<T>::fromString(str.value);
        }

        static std::string toString(std::optional<T> const& value)
        {
            if (!value.has_value())
                return {};

            return TypeSerializer<T>::toString(value.value());
        }
    };
}
