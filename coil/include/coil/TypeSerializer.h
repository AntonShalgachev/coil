#pragma once

#include "TypeName.h"
#include "Expected.h"
#include "Utils.h"
#include "ArgValue.h"

#include <string>
#include <sstream>
#include <cctype>

#include <algorithm>
#include <optional>
#include <charconv>

namespace coil
{
    template<typename T>
    Unexpected<std::string> makeSerializationError(ArgValue const& input, std::string_view details = {})
    {
        std::string_view typeName = TypeName<T>::name();

        if (details.empty())
            return makeUnexpected(formatString("Unable to convert '%.*s' to type '%.*s'", input.value.length(), input.value.data(), typeName.length(), typeName.data()));
        else
            return makeUnexpected(formatString("Unable to convert '%.*s' to type '%.*s': %.*s", input.value.length(), input.value.data(), typeName.length(), typeName.data(), details.length(), details.data()));
    }

    template<typename T>
    Unexpected<std::string> makeSerializationError(ArgValue const& input, std::size_t expectedSubvalues)
    {
        return makeSerializationError<T>(input, formatString("Expected %d subvalues, got %d", expectedSubvalues, input.subvalues.size()));
    }

    template<typename T, typename = void>
    struct HasCoutOperator : std::false_type {};
    template<typename T>
    struct HasCoutOperator<T, std::void_t<decltype(std::declval<std::ostream>() << std::declval<T>())>> : std::true_type {};

    template<typename T, typename = void>
    struct HasCinOperator : std::false_type {};
    template<typename T>
    struct HasCinOperator<T, std::void_t<decltype(std::declval<std::istream>() >> std::declval<T>())>> : std::true_type {};

    //////////////////////////////////////

    template<typename T, typename = void>
    struct TypeSerializer
    {
        static_assert(!std::is_void_v<T>, "Void isn't a valid conversion type");

        static Expected<T, std::string> fromString(ArgValue const& input);

        static std::string toString(T const& value);
    };

    template<typename T, typename V>
    coil::Expected<T, std::string> coil::TypeSerializer<T, V>::fromString(ArgValue const& input)
    {
        static_assert(HasCinOperator<T>::value, "T should have operator>>, or TypeSerializer has to be specialized for type T");

        std::stringstream ss;
        ss << input.value;

        T value{};
        ss >> value;

        if (ss.eof() && !ss.fail())
            return value;

        return makeSerializationError<T>(input);
    }

    template<typename T, typename V>
    std::string coil::TypeSerializer<T, V>::toString(T const& value)
    {
        static_assert(HasCoutOperator<T>::value, "T should have operator<<, or TypeSerializer has to be specialized for type T");

        std::stringstream ss;
        ss << value;

        return ss.str();
    }

    //////////////////////////////////////

    template<typename T>
    struct TypeSerializer<T, std::enable_if_t<std::is_arithmetic_v<T>>>
    {
        static Expected<T, std::string> fromString(ArgValue const& input);

        static std::string toString(T const& value);
    };

    template<typename T>
    coil::Expected<T, std::string> TypeSerializer<T, std::enable_if_t<std::is_arithmetic_v<T>>>::fromString(ArgValue const& input)
    {
        auto begin = input.value.data();
        auto end = input.value.data() + input.value.length();

        T value{};
        std::from_chars_result result = std::from_chars(begin, end, value);
        if (result.ptr == end)
            return value;

        return makeSerializationError<T>(input);
    }

    template<typename T>
    std::string TypeSerializer<T, std::enable_if_t<std::is_arithmetic_v<T>>>::toString(T const& value)
    {
        return std::to_string(value);
    }

    //////////////////////////////////////

    template<>
    struct TypeSerializer<bool>
    {
        static Expected<bool, std::string> fromString(ArgValue const& input);
        static std::string toString(bool const& value);
    };

    //////////////////////////////////////

    template<class Elem, class Traits, class Alloc>
    struct TypeSerializer<std::basic_string<Elem, Traits, Alloc>>
    {
        static Expected<std::basic_string<Elem, Traits, Alloc>, std::string> fromString(ArgValue const& input);

        static std::string toString(std::basic_string<Elem, Traits, Alloc> const& value);
    };

    template<class Elem, class Traits, class Alloc>
    coil::Expected<std::basic_string<Elem, Traits, Alloc>, std::string> coil::TypeSerializer<std::basic_string<Elem, Traits, Alloc>>::fromString(ArgValue const& input)
    {
        return std::basic_string<Elem, Traits, Alloc>{ input.value };
    }

    template<class Elem, class Traits, class Alloc>
    std::string coil::TypeSerializer<std::basic_string<Elem, Traits, Alloc>>::toString(std::basic_string<Elem, Traits, Alloc> const& value)
    {
        return value;
    }

    //////////////////////////////////////

    template<class Elem, class Traits>
    struct TypeSerializer<std::basic_string_view<Elem, Traits>>
    {
        static Expected<std::basic_string_view<Elem, Traits>, std::string> fromString(ArgValue const& input);

        static std::string toString(std::basic_string_view<Elem, Traits> const& value);
    };

    template<class Elem, class Traits>
    coil::Expected<std::basic_string_view<Elem, Traits>, std::string> coil::TypeSerializer<std::basic_string_view<Elem, Traits>>::fromString(ArgValue const& input)
    {
        return input.value;
    }

    template<class Elem, class Traits>
    std::string coil::TypeSerializer<std::basic_string_view<Elem, Traits>>::toString(std::basic_string_view<Elem, Traits> const& value)
    {
        return std::string{ value };
    }

    //////////////////////////////////////

    template<typename T>
    struct TypeSerializer<std::optional<T>>
    {
        static Expected<std::optional<T>, std::string> fromString(ArgValue const& input);

        static std::string toString(std::optional<T> const& value);
    };

    template<typename T>
    coil::Expected<std::optional<T>, std::string> coil::TypeSerializer<std::optional<T>>::fromString(ArgValue const& input)
    {
        if (input.value.empty())
            return std::optional<T>{};

        Expected<T, std::string> innerValue = TypeSerializer<T>::fromString(input.value);
        if (innerValue)
            return std::optional<T>{*innerValue};

        return makeSerializationError<std::optional<T>>(input, std::move(innerValue).error());
    }

    template<typename T>
    std::string coil::TypeSerializer<std::optional<T>>::toString(std::optional<T> const& value)
    {
        if (!value.has_value())
            return {};

        return TypeSerializer<T>::toString(value.value());
    }

    //////////////////////////////////////

    template<typename T>
    struct TypeSerializer<std::vector<T>>
    {
        static Expected<std::vector<T>, std::string> fromString(ArgValue const& input);

        // TODO implement toString
    };

    template<typename T>
    coil::Expected<std::vector<T>, std::string> coil::TypeSerializer<std::vector<T>>::fromString(ArgValue const& input)
    {
        std::vector<T> result;
        result.reserve(input.subvalues.size());

        for (std::string_view subvalue : input.subvalues)
        {
            Expected<T, std::string> expectedArg = TypeSerializer<T>::fromString(subvalue);
            if (!expectedArg)
                return makeSerializationError<std::vector<T>>(input, std::move(expectedArg).error());

            result.push_back(*std::move(expectedArg));
        }

        return result;
    }
}
