#pragma once

#include "TypeSerializer.h"
#include <string_view>
#include <vector>
#include "Expected.h"

namespace coil
{
    // TODO it's not a "view" anymore
    class AnyArgView
    {
    public:
        AnyArgView(ArgValue value) : m_value(std::move(value)) {}

        template<typename T>
        Expected<T, std::string> get() const
        {
            return TypeSerializer<T>::fromString(m_value);
        }

        // TODO rename?
        ArgValue const& getRaw() const { return m_value; }

    private:
        ArgValue m_value;
    };

    template<>
    struct TypeSerializer<AnyArgView>
    {
        static Expected<AnyArgView, std::string> fromString(ArgValue value)
        {
            return AnyArgView(std::move(value));
        }

        static std::string toString(AnyArgView const& value)
        {
            return std::string{ value.getRaw().value };
        }
    };
}
