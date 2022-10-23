#pragma once

#include "Value.h"
#include "StringView.h"
#include "Vector.h"

namespace coil
{
    // TODO make a simple struct, move to cpp file
    class NamedValue
    {
    public:
        NamedValue() = default;
        NamedValue(StringView key, Value value) : m_key(Move(key)), m_value(Move(value)) {}

        StringView const& key() const { return m_key; }
        Value const& value() const { return m_value; }

        bool operator==(NamedValue const& rhs) const
        {
            return m_key == rhs.m_key && m_value == rhs.m_value;
        }

        bool operator!=(NamedValue const& rhs) const
        {
            return !(*this == rhs);
        }

    private:
        StringView m_key;
        Value m_value;
    };

    struct ExecutionInput
    {
        StringView name;
        Vector<Value> arguments;
        Vector<NamedValue> namedArguments;
    };
}
