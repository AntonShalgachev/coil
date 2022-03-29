#pragma once

#include "coil/Coil.h"

#include <optional>
#include <vector>

namespace coil
{
    template<>
    struct TypeName<int>
    {
        static std::string_view name() { return "int"; }
    };
    template<typename T>
    struct TypeName<std::optional<T>>
    {
        static std::string_view name()
        {
            static std::string result = "std::optional<" + std::string{ TypeName<T>::name() } + ">";
            return result;
        }
    };
    template<typename T>
    struct TypeName<std::vector<T>>
    {
        static std::string_view name()
        {
            static std::string result = "std::vector<" + std::string{ TypeName<T>::name() } + ">";
            return result;
        }
    };

    inline std::ostream& operator<<(std::ostream& os, coil::ArgValue const& input)
    {
        os << "'" << input.value << "'";

        if (input.subvalues.size() != 1 || input.subvalues[0] != input.value)
        {
            os << "(";

            auto prefix = "";
            for (std::string_view subvalue : input.subvalues)
            {
                os << prefix << "'" << subvalue << "'";
                prefix = ", ";
            }

            os << ")";
        }

        return os;
    }

    inline std::ostream& operator<<(std::ostream& os, coil::ExecutionInput const& input)
    {
        os << "'" << input.name << "'" << ", [";

        auto delim = "";
        for (auto const& arg : input.arguments)
        {
            os << delim << arg;
            delim = ", ";
        }

        os << "], [";

        delim = "";
        for (auto const& pair : input.namedArguments)
        {
            os << delim << "'" << pair.first << "':" << pair.second << "";
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
}
