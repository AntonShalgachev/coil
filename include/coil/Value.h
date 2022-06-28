#pragma once

#include "Expected.h"

#include <string>
#include <string_view>
#include <vector>

namespace coil
{
    template<typename T, typename>
    struct TypeSerializer;

    struct Value
    {
        Value();
        Value(std::string_view value);
        Value(std::vector<std::string_view> subvalues);

        bool operator==(Value const& rhs) const;

        template<typename T>
        Expected<T, std::string> get() const
        {
            return TypeSerializer<T, void>::fromString(*this);
        }

        std::string str() const;

        std::vector<std::string_view> subvalues;
    };

    std::ostream& operator<<(std::ostream& os, Value const& rhs);

    template<>
    struct TypeSerializer<Value, void>
    {
        static Expected<Value, std::string> fromString(Value const& value)
        {
            return value; // TODO prevent a copy
        }
    };
}
