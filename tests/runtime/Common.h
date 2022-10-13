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
        static std::string_view name()
        {
            static std::string result = "std::optional<" + std::string{TypeName<T>::name()} + ">";
            return result;
        }
    };
    template<typename T>
    struct TypeName<std::vector<T>>
    {
        static std::string_view name()
        {
            static std::string result = "std::vector<" + std::string{TypeName<T>::name()} + ">";
            return result;
        }
    };

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
            os << delim << "'" << pair.first << "':" << pair.second.str() << "";
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

inline bool containsError(std::vector<std::string> const& errors, std::string const& value)
{
    return std::find(errors.begin(), errors.end(), value) != errors.end();
}
