#pragma once

#include "TypeSerializer.h"
#include <string_view>
#include <vector>
#include "Expected.h"

namespace coil
{
    class AnyArgView
    {
    public:
        AnyArgView(std::string_view value) : m_value(value) {}

        template<typename T>
        Expected<T, std::string> get() const
        {
            return TypeSerializer<T>::fromString(m_value);
        }

        std::string_view getRaw() const { return m_value; }

    private:
        std::string_view m_value;
    };

    template<>
    struct TypeSerializer<AnyArgView>
    {
        static Expected<AnyArgView, std::string> fromString(std::string_view str)
        {
            return AnyArgView(str);
        }

        static std::string toString(AnyArgView const& value)
        {
            return std::string{ value.getRaw() };
        }
    };
}
