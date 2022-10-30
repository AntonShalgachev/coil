#pragma once

#include <algorithm>
#include <functional>
#include <optional>
#include <vector>
#include <ostream>

#include "coil/Coil.h"

namespace coil
{
    template<typename T>
    struct TypeName<std::optional<T>>
    {
        static StringView name()
        {
            static String result = "std::optional<" + String{TypeName<T>::name()} + ">";
            return result;
        }
    };
    template<typename T>
    struct TypeName<std::vector<T>>
    {
        static StringView name()
        {
            static String result = "std::vector<" + String{TypeName<T>::name()} + ">";
            return result;
        }
    };

    inline std::ostream& operator<<(std::ostream& os, StringView const& value)
    {
        return os << std::string_view{ value.data(), value.length() };
    }

    inline std::ostream& operator<<(std::ostream& os, coil::ExecutionInput const& input)
    {
        os << "'" << input.name << "'"
           << ", [";

        auto delim = "";
        for (auto const& arg : input.arguments)
        {
            os << delim << arg.str();
            delim = ", ";
        }

        os << "], [";

        delim = "";
        for (auto const& pair : input.namedArguments)
        {
            os << delim << "'" << pair.key() << "':" << pair.value().str() << "";
            delim = ", ";
        }

        os << "]";

        return os;
    }

    template<typename T, typename E>
    std::ostream& operator<<(std::ostream& os, Expected<T, E> const& expected)
    {
        if (expected)
            return os << expected.value();

        return os << "'" << expected.error() << "'";
    }

    template<typename E>
    std::ostream& operator<<(std::ostream& os, Unexpected<E> const& unexpected)
    {
        return os << "'" << unexpected.value() << "'";
    }

    inline bool operator==(ExecutionInput const& lhs, ExecutionInput const& rhs)
    {
        auto tie = [](ExecutionInput const& value)
        {
            return std::tie(value.name, value.arguments, value.namedArguments);
        };

        return tie(lhs) == tie(rhs);
    }
}

inline bool containsError(coil::Vector<coil::String> const& errors, coil::StringView value)
{
    return std::find(errors.begin(), errors.end(), value) != errors.end();
}

template<typename T>
coil::Vector<T> convertVector(std::vector<T> input)
{
    coil::Vector<T> output;
    output.reserve(input.size());
    for (T& value : std::move(input))
        output.pushBack(coil::move(value));
    return output;
}

inline coil::Value createVectorValue(std::vector<coil::StringView> stdSubvalues)
{
    return coil::Value{ convertVector(coil::move(stdSubvalues)) };
}
