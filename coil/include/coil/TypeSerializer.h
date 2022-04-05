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
    namespace errors
    {
        template<typename T>
        Unexpected<std::string> serializationError(ArgValue const& input, std::string_view details = {})
        {
            std::string_view typeName = TypeName<T>::name();

            std::stringstream representationStream;
            std::string_view prefix = "";
            for (std::string_view subvalue : input.subvalues)
            {
                representationStream << prefix << subvalue;
                prefix = " ";
            }

            std::string representation = representationStream.str();

            if (details.empty())
                return makeUnexpected(formatString("Unable to convert '%s' to type '%.*s'", representation.c_str(), typeName.length(), typeName.data()));
            else
                return makeUnexpected(formatString("Unable to convert '%s' to type '%.*s': %.*s", representation.c_str(), typeName.length(), typeName.data(), details.length(), details.data()));
        }

        template<typename T>
        Unexpected<std::string> wrongSubvaluesSize(ArgValue const& input, std::size_t expectedSubvalues)
        {
            return serializationError<T>(input, formatString("Expected %d subvalues, got %d", expectedSubvalues, input.subvalues.size()));
        }
    }

    //////////////////////////////////////

    template<typename T, typename = void>
    struct TypeSerializer;

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
        if (input.subvalues.size() != 1)
            return errors::wrongSubvaluesSize<T>(input, 1);

        auto inputValue = input.subvalues[0];
        auto begin = inputValue.data();
        auto end = inputValue.data() + inputValue.length();

        T value{};
        std::from_chars_result result = std::from_chars(begin, end, value);
        if (result.ptr == end)
            return value;

        return errors::serializationError<T>(input);
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

    template<>
    struct TypeSerializer<char const*>
    {
        static std::string toString(char const* const& value);
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
        if (input.subvalues.size() != 1)
            return errors::wrongSubvaluesSize<std::basic_string<Elem, Traits, Alloc>>(input, 1);

        return std::basic_string<Elem, Traits, Alloc>{ input.subvalues[0] };
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
        if (input.subvalues.size() != 1)
            return errors::wrongSubvaluesSize<std::basic_string_view<Elem, Traits>>(input, 1);

        return input.subvalues[0];
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
        if (input.subvalues.empty() || input.subvalues[0].empty())
            return std::optional<T>{};

        Expected<T, std::string> innerValue = TypeSerializer<T>::fromString(input.subvalues[0]);
        if (innerValue)
            return std::optional<T>{*innerValue};

        return errors::serializationError<std::optional<T>>(input, std::move(innerValue).error());
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
                return errors::serializationError<std::vector<T>>(input, std::move(expectedArg).error());

            result.push_back(*std::move(expectedArg));
        }

        return result;
    }
}
