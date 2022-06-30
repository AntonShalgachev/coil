#pragma once

#include "Expected.h"
#include "TypeName.h"
#include "Utils.h"
#include "Value.h"

#include <algorithm>
#include <cctype>
#include <charconv>
#include <optional>
#include <sstream>
#include <string>

namespace coil
{
    namespace errors
    {
        template<typename T>
        Unexpected<std::string> createGenericError(Value const& input, std::string_view details = {})
        {
            std::string_view typeName = TypeName<T>::name();

            std::string representation = input.str();

            if (details.empty())
                return makeUnexpected(formatString("Unable to convert '%s' to type '%.*s'", representation.c_str(), typeName.length(), typeName.data()));

            return makeUnexpected(formatString("Unable to convert '%s' to type '%.*s': %.*s", representation.c_str(), typeName.length(), typeName.data(), details.length(), details.data()));
        }

        template<typename T>
        Unexpected<std::string> createMismatchedSubvaluesError(Value const& input, std::size_t expectedSubvalues)
        {
            return createGenericError<T>(input, formatString("Expected %d subvalues, got %d", expectedSubvalues, input.subvalues.size()));
        }
    }

    //////////////////////////////////////

    template<typename T, typename = void>
    struct TypeSerializer;

    //////////////////////////////////////

    template<typename T>
    struct TypeSerializer<T, std::enable_if_t<std::is_arithmetic_v<T>>>
    {
        static Expected<T, std::string> fromString(Value const& input);

        static std::string toString(T const& value);
    };

    template<typename T>
    coil::Expected<T, std::string> TypeSerializer<T, std::enable_if_t<std::is_arithmetic_v<T>>>::fromString(Value const& input)
    {
        if (input.subvalues.size() != 1)
            return errors::createMismatchedSubvaluesError<T>(input, 1);

        auto inputValue = input.subvalues[0];
        auto begin = inputValue.data();
        auto end = inputValue.data() + inputValue.length();

        T value{};
        std::from_chars_result result = std::from_chars(begin, end, value);

        if (result.ec == std::errc::result_out_of_range)
            return errors::createGenericError<T>(input, "the value can't be represented in this type");

        if (result.ptr != end || result.ec != std::errc{})
            return errors::createGenericError<T>(input);

        return value;
    }

    template<typename T>
    std::string TypeSerializer<T, std::enable_if_t<std::is_arithmetic_v<T>>>::toString(T const& value)
    {
        std::stringstream ss;
        ss << value;
        return ss.str();
    }

    //////////////////////////////////////

    template<>
    struct TypeSerializer<bool>
    {
        static Expected<bool, std::string> fromString(Value const& input);
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
        static Expected<std::basic_string<Elem, Traits, Alloc>, std::string> fromString(Value const& input);

        static std::string toString(std::basic_string<Elem, Traits, Alloc> const& value);
    };

    template<class Elem, class Traits, class Alloc>
    coil::Expected<std::basic_string<Elem, Traits, Alloc>, std::string> coil::TypeSerializer<std::basic_string<Elem, Traits, Alloc>>::fromString(Value const& input)
    {
        if (input.subvalues.size() != 1)
            return errors::createMismatchedSubvaluesError<std::basic_string<Elem, Traits, Alloc>>(input, 1);

        return std::basic_string<Elem, Traits, Alloc>{input.subvalues[0]};
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
        static Expected<std::basic_string_view<Elem, Traits>, std::string> fromString(Value const& input);

        static std::string toString(std::basic_string_view<Elem, Traits> const& value);
    };

    template<class Elem, class Traits>
    coil::Expected<std::basic_string_view<Elem, Traits>, std::string> coil::TypeSerializer<std::basic_string_view<Elem, Traits>>::fromString(Value const& input)
    {
        if (input.subvalues.size() != 1)
            return errors::createMismatchedSubvaluesError<std::basic_string_view<Elem, Traits>>(input, 1);

        return input.subvalues[0];
    }

    template<class Elem, class Traits>
    std::string coil::TypeSerializer<std::basic_string_view<Elem, Traits>>::toString(std::basic_string_view<Elem, Traits> const& value)
    {
        return std::string{value};
    }

    //////////////////////////////////////

    template<typename T>
    struct TypeSerializer<std::optional<T>>
    {
        static Expected<std::optional<T>, std::string> fromString(Value const& input);

        static std::string toString(std::optional<T> const& value);
    };

    template<typename T>
    coil::Expected<std::optional<T>, std::string> coil::TypeSerializer<std::optional<T>>::fromString(Value const& input)
    {
        if (input.subvalues.empty() || input.subvalues[0].empty())
            return std::optional<T>{};

        auto innerValue = TypeSerializer<T>::fromString(input.subvalues[0]);
        if (innerValue)
            return std::optional<T>{*innerValue};

        return errors::createGenericError<std::optional<T>>(input, std::move(innerValue).error());
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
        static Expected<std::vector<T>, std::string> fromString(Value const& input);

        static std::string toString(std::vector<T> const& value);
    };

    template<typename T>
    coil::Expected<std::vector<T>, std::string> coil::TypeSerializer<std::vector<T>>::fromString(Value const& input)
    {
        std::vector<T> result;
        result.reserve(input.subvalues.size());

        for (std::string_view subvalue : input.subvalues)
        {
            auto expectedArg = TypeSerializer<T>::fromString(subvalue);
            if (!expectedArg)
                return errors::createGenericError<std::vector<T>>(input, std::move(expectedArg).error());

            result.push_back(*std::move(expectedArg));
        }

        return result;
    }

    template<typename T>
    std::string coil::TypeSerializer<std::vector<T>>::toString(std::vector<T> const& value)
    {
        std::stringstream ss;
        ss << '{';
        std::string_view separator = "";
        for (T const& element : value)
        {
            ss << separator << TypeSerializer<T>::toString(element);
            separator = ", ";
        }
        ss << '}';

        return ss.str();
    }

    //////////////////////////////////////

    template<typename T>
    struct TypeSerializer<T*>
    {
        static std::string toString(T* const& value);
    };

    template<typename T>
    std::string coil::TypeSerializer<T*>::toString(T* const& value)
    {
        if (!value)
            return "null";

        return TypeSerializer<std::decay_t<T>>::toString(*value);
    }
}
