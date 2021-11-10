#pragma once

#include "TypeSerializer.h"
#include <string_view>
#include <vector>

namespace coil
{
    namespace detail
    {
        struct OnErrorFlag
        {
        public:
            void operator()(std::string error)
            {
                m_flag = true;
            }

            operator bool() const
            {
                return m_flag;
            }

        private:
            bool m_flag = false;
        };

        struct OnErrorContainer
        {
            void operator()(std::string error)
            {
                errors.push_back(std::move(error));
            }

            operator bool() const
            {
                return errors.empty();
            }

            std::vector<std::string> errors;
        };
    }

    // TODO Rename class to contain "view" in it
    class VariadicArg
    {
    public:
        VariadicArg(std::string_view value) : m_value(value) {}

        template<typename T>
        std::optional<T> tryGet() const
        {
            detail::OnErrorFlag errorFlag;
            auto val = TypeSerializer<T>::fromString(m_value, errorFlag);
            if (errorFlag)
                return {};

            return val;
        }

        template<typename T>
        bool is() const
        {
            return tryGet<T>().has_value();
        }

        template<typename T>
        T as() const
        {
            detail::OnErrorContainer onError;
            auto val = TypeSerializer<T>::fromString(m_value, onError);
            if (!onError)
                throw std::invalid_argument(utils::flatten(onError.errors));

            return val;
        }

        std::string_view const& getRaw() const { return m_value; }

    private:
        std::string_view m_value;
    };

    template<>
    struct TypeSerializer<VariadicArg>
    {
        template<typename OnError>
        static VariadicArg fromString(std::string_view str, OnError&&)
        {
            return VariadicArg(str);
        }

        static std::string toString(VariadicArg const& value)
        {
            return std::string{ value.getRaw() };
        }
    };
}
