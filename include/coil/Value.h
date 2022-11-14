#pragma once

#include "Expected.h"
#include "String.h"
#include "StringView.h"
#include "TypeName.h"
#include "Vector.h"
#include "detail/Functional.h"

namespace coil
{
    template<typename T, typename>
    struct TypeSerializer;

    struct Value
    {
        Value();
        Value(StringView value);
        Value(char const* value);
        Value(Vector<StringView> subvalues);

        bool operator==(Value const& rhs) const;
        bool operator!=(Value const& rhs) const;

        template<typename T>
        Expected<T, String> get() const
        {
            return TypeSerializer<T, void>::fromString(*this);
        }

        String str() const;

        Vector<StringView> subvalues;
    };

    struct NamedValue
    {
        StringView key;
        Value value;

        bool operator==(NamedValue const& rhs) const;
        bool operator!=(NamedValue const& rhs) const;
    };

    template<>
    struct TypeSerializer<Value, void>
    {
        static Expected<ReferenceWrapper<Value const>, coil::String> fromString(Value const& value);
        static coil::String toString(Value const& value);
    };

    template<>
    struct TypeName<Value>
    {
        static coil::StringView name()
        {
            return "coil::Value";
        }
    };
}
