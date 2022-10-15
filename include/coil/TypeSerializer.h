#pragma once

#include "Expected.h"
#include "TypeName.h"
#include "Utils.h"
#include "Value.h"
#include "String.h"
#include "detail/Utility.h"

#include <charconv>
#include <optional>

namespace coil
{
    namespace errors
    {
        template<typename T>
        Unexpected<String> createGenericError(Value const& input, StringView details = {})
        {
            static_assert(std::is_convertible_v<decltype(TypeName<T>::name()), StringView>, "TypeName<T>::name() has to be convertible to StringView");
            StringView typeName = TypeName<T>::name();

            String representation = input.str();

            if (details.empty())
                return makeUnexpected(sprintf("Unable to convert '%s' to type '%.*s'", representation.cStr(), typeName.length(), typeName.data()));

            return makeUnexpected(sprintf("Unable to convert '%s' to type '%.*s': %.*s", representation.cStr(), typeName.length(), typeName.data(), details.length(), details.data()));
        }

        template<typename T>
        Unexpected<String> createMismatchedSubvaluesError(Value const& input, std::size_t expectedSubvalues)
        {
            return createGenericError<T>(input, sprintf("Expected %d subvalues, got %d", expectedSubvalues, input.subvalues.size()));
        }
    }

    //////////////////////////////////////

    template<typename T, typename = void>
    struct TypeSerializer;

    //////////////////////////////////////

    template<typename T>
    struct TypeSerializer<T, std::enable_if_t<std::is_arithmetic_v<T>>>
    {
        static Expected<T, String> fromString(Value const& input);

        static String toString(T const& value);
    };

    template<typename T>
    coil::Expected<T, String> TypeSerializer<T, std::enable_if_t<std::is_arithmetic_v<T>>>::fromString(Value const& input)
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
    coil::String TypeSerializer<T, std::enable_if_t<std::is_arithmetic_v<T>>>::toString(T const& value)
    {
        return coil::toString(value);
    }

    //////////////////////////////////////

    template<>
    struct TypeSerializer<bool>
    {
        static Expected<bool, String> fromString(Value const& input);
        static String toString(bool const& value);
    };

    //////////////////////////////////////

    template<>
    struct TypeSerializer<char const*>
    {
        static String toString(char const* const& value);
    };

    //////////////////////////////////////

    template<>
    struct TypeSerializer<String>
    {
        static Expected<String, String> fromString(Value const& input);
        static String toString(String const& value);
    };

    //////////////////////////////////////

    template<>
    struct TypeSerializer<StringView>
    {
        static Expected<StringView, String> fromString(Value const& input);
        static String toString(StringView const& value);
    };

    //////////////////////////////////////

    template<typename T>
    struct TypeSerializer<std::optional<T>>
    {
        static Expected<std::optional<T>, String> fromString(Value const& input);

        static String toString(std::optional<T> const& value);
    };

    template<typename T>
    coil::Expected<std::optional<T>, String> coil::TypeSerializer<std::optional<T>>::fromString(Value const& input)
    {
        if (input.subvalues.empty() || input.subvalues[0].empty())
            return std::optional<T>{};

        auto innerValue = TypeSerializer<T>::fromString(input.subvalues[0]);
        if (innerValue)
            return std::optional<T>{*innerValue};

        return errors::createGenericError<std::optional<T>>(input, Move(innerValue).error());
    }

    template<typename T>
    coil::String coil::TypeSerializer<std::optional<T>>::toString(std::optional<T> const& value)
    {
        if (!value.has_value())
            return {};

        return TypeSerializer<T>::toString(value.value());
    }

    //////////////////////////////////////

    template<typename T>
    struct TypeSerializer<std::vector<T>>
    {
        static Expected<std::vector<T>, String> fromString(Value const& input);

        static String toString(std::vector<T> const& value);
    };

    template<typename T>
    coil::Expected<std::vector<T>, String> coil::TypeSerializer<std::vector<T>>::fromString(Value const& input)
    {
        std::vector<T> result;
        result.reserve(input.subvalues.size());

        for (StringView subvalue : input.subvalues)
        {
            auto expectedArg = TypeSerializer<T>::fromString(subvalue);
            if (!expectedArg)
                return errors::createGenericError<std::vector<T>>(input, Move(expectedArg).error());

            result.push_back(*Move(expectedArg));
        }

        return result;
    }

    template<typename T>
    coil::String coil::TypeSerializer<std::vector<T>>::toString(std::vector<T> const& value)
    {
        String result = "{";
        StringView separator = "";

        for (T const& element : value)
        {
            result += separator;
            result += TypeSerializer<T>::toString(element);
            separator = ", ";
        }
        result += "}";

        return result;
    }

    //////////////////////////////////////

    template<typename T>
    struct TypeSerializer<T*>
    {
        static String toString(T* const& value);
    };

    template<typename T>
    coil::String coil::TypeSerializer<T*>::toString(T* const& value)
    {
        if (!value)
            return "null";

        using TS = TypeSerializer<std::remove_cv_t<std::remove_reference_t<T>>>;
        static_assert(std::is_convertible_v<decltype(TS::toString(*value)), coil::String>, "TypeSerializer<T>::toString() should be convertible to String");

        return TS::toString(*value);
    }
}
