#pragma once

#include "coil/TypeSerializer.h"

#include <string>
#include <string_view>
#include <vector>
#include <optional>
#include <ostream>

// This file contains:
// * Serializers for some standard C++ containres: std::string, std::string_view, std::vector, std::optional
// * stream operators for coil::String and coil::StringView
// * helper functions to convert between std and coil containers
// 

// std::string
namespace coil
{
    template<>
    struct TypeSerializer<std::string>
    {
        static Expected<std::string, String> fromString(Value const& input);
        static String toString(std::string const& value);
    };
}
COIL_CREATE_TYPE_NAME_DECLARATION(std::string); // shorthand for types without additional template parameters

// std::string_view
namespace coil
{
    template<>
    struct TypeSerializer<std::string_view>
    {
        static Expected<std::string_view, String> fromString(Value const& input);
        static String toString(std::string_view const& value);
    };
}
COIL_CREATE_TYPE_NAME_DECLARATION(std::string_view); // shorthand for types without additional template parameters

// std::vector
namespace coil
{
    template<typename T>
    struct TypeSerializer<std::vector<T>>
    {
        static Expected<std::vector<T>, String> fromString(Value const& input)
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

        static String toString(std::vector<T> const& value)
        {
            String result = "[";
            StringView separator = "";

            for (T const& element : value)
            {
                result += separator;
                result += TypeSerializer<T>::toString(element);
                separator = ", ";
            }
            result += "]";

            return result;
        }
    };

    template<typename T>
    struct TypeName<std::vector<T>>
    {
        static StringView name()
        {
            static String typeName = "vector<" + String{ TypeName<T>::name() } + ">";
            return typeName;
        }
    };
}

// std::optional
namespace coil
{
    template<typename T>
    struct TypeSerializer<std::optional<T>>
    {
        static Expected<std::optional<T>, String> fromString(Value const& input)
        {
            if (input.subvalues.empty() || input.subvalues[0].empty())
                return std::optional<T>{};

            auto innerValue = TypeSerializer<T>::fromString(input.subvalues[0]);
            if (innerValue)
                return std::optional<T>{coil::move(innerValue).value()};

            return errors::createGenericError<std::optional<T>>(input, coil::move(innerValue).error());
        }

        static String toString(std::optional<T> const& value)
        {
            if (!value.has_value())
                return {};

            return TypeSerializer<T>::toString(value.value());
        }
    };

    template<typename T>
    struct TypeName<std::optional<T>>
    {
        static StringView name()
        {
            static String typeName = "optional<" + String{ TypeName<T>::name() } + ">";
            return typeName;
        }
    };
}

// stream operators
namespace coil
{
    std::ostream& operator<<(std::ostream& os, coil::String const& str);
    std::ostream& operator<<(std::ostream& os, coil::StringView const& str);
}
