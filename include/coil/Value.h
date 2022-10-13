#pragma once

#include "Expected.h"
#include "TypeName.h"
#include "detail/Functional.h"

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

    template<>
    struct TypeSerializer<Value, void>
    {
        static Expected<ReferenceWrapper<Value const>, std::string> fromString(Value const& value);
        static std::string toString(Value const& value);
    };

    template<>
    struct TypeName<Value>
    {
        static std::string_view name()
        {
            return "coil::Value";
        }
    };
}
