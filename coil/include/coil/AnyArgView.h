#pragma once

#include "TypeSerializer.h"
#include <string_view>
#include <vector>
#include "Expected.h"

namespace coil
{
    namespace detail
    {
        struct ErrorContainer
        {
            void operator()(std::string e)
            {
                error = std::move(e);
            }

            std::optional<std::string> error;
        };
    }

    class AnyArgView
    {
    public:
        AnyArgView(std::string_view value) : m_value(value) {}

        template<typename T>
        Expected<T, std::string> get() const
        {
            detail::ErrorContainer onError;
            auto val = TypeSerializer<T>::fromString(m_value, onError);
            if (onError.error)
                return makeUnexpected(*std::move(onError).error);

            return val;
        }

        std::string_view getRaw() const { return m_value; }

    private:
        std::string_view m_value;
    };

    template<>
    struct TypeSerializer<AnyArgView>
    {
        template<typename OnError>
        static AnyArgView fromString(std::string_view str, OnError&&)
        {
            return AnyArgView(str);
        }

        static std::string toString(AnyArgView const& value)
        {
            return std::string{ value.getRaw() };
        }
    };
}
