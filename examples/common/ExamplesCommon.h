#pragma once

#include "CustomTypeName.h"
#include "EnumTypeSerializer.h"
#include "coil/Coil.h"

#include <string_view>
#include <ostream>

namespace coil
{
    template<class Elem, class Traits, class Alloc>
    struct TypeSerializer<std::basic_string<Elem, Traits, Alloc>>
    {
        static Expected<std::basic_string<Elem, Traits, Alloc>, String> fromString(Value const& input);

        static String toString(std::basic_string<Elem, Traits, Alloc> const& value);
    };

    template<class Elem, class Traits, class Alloc>
    coil::Expected<std::basic_string<Elem, Traits, Alloc>, String> coil::TypeSerializer<std::basic_string<Elem, Traits, Alloc>>::fromString(Value const& input)
    {
        if (input.subvalues.size() != 1)
            return errors::createMismatchedSubvaluesError<std::basic_string<Elem, Traits, Alloc>>(input, 1);

        return std::basic_string<Elem, Traits, Alloc>{ input.subvalues[0].data(), input.subvalues[0].length() };
    }

    template<class Elem, class Traits, class Alloc>
    coil::String coil::TypeSerializer<std::basic_string<Elem, Traits, Alloc>>::toString(std::basic_string<Elem, Traits, Alloc> const& value)
    {
        return String{ value.c_str() };
    }

    //////////////////////////////////////

    template<class Elem, class Traits>
    struct TypeSerializer<std::basic_string_view<Elem, Traits>>
    {
        static Expected<std::basic_string_view<Elem, Traits>, String> fromString(Value const& input);

        static String toString(std::basic_string_view<Elem, Traits> const& value);
    };

    template<class Elem, class Traits>
    coil::Expected<std::basic_string_view<Elem, Traits>, String> coil::TypeSerializer<std::basic_string_view<Elem, Traits>>::fromString(Value const& input)
    {
        if (input.subvalues.size() != 1)
            return errors::createMismatchedSubvaluesError<std::basic_string_view<Elem, Traits>>(input, 1);

        return std::string_view{ input.subvalues[0].data(), input.subvalues[0].length() }; // WTF
    }

    template<class Elem, class Traits>
    coil::String coil::TypeSerializer<std::basic_string_view<Elem, Traits>>::toString(std::basic_string_view<Elem, Traits> const& value)
    {
        if (value.empty())
            return String{};

        assert(value.data());
        return String{ StringView{value.data(), value.size()} };
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
                return errors::createGenericError<std::vector<T>>(input, coil::move(expectedArg).error());

            result.push_back(*coil::move(expectedArg));
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

        return errors::createGenericError<std::optional<T>>(input, coil::move(innerValue).error());
    }

    template<typename T>
    coil::String coil::TypeSerializer<std::optional<T>>::toString(std::optional<T> const& value)
    {
        if (!value.has_value())
            return {};

        return TypeSerializer<T>::toString(value.value());
    }
}

namespace common
{
    void printSectionHeader(std::string_view header);
    void executeCommand(coil::Bindings& bindings, coil::StringView command);
}

std::ostream& operator<<(std::ostream& os, coil::String const& str);
std::ostream& operator<<(std::ostream& os, coil::StringView const& str);
