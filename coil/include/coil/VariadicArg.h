#pragma once

#include "detail/Converter.h"

namespace cmdapi
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

    class VariadicArg
    {
    public:
        VariadicArg() = default;
        VariadicArg(std::string value) : m_value(value) {}

        template<typename T>
        VariadicArg(T const& value) : m_value(detail::Converter<T>::toString(value)) {}

        template<typename T>
        bool is() const
        {
            detail::OnErrorFlag errorFlag;
            detail::Converter<T>::fromString(m_value, errorFlag);
            return errorFlag;
        }

        template<typename T>
        T as() const
        {
            detail::OnErrorContainer onError;
            auto val = detail::Converter<T>::fromString(m_value, onError);
            if (!onError)
                throw std::invalid_argument(utils::flatten(onError.errors));

            return val;
        }

        std::string const& getRaw() const { return m_value; }

        friend std::istream& operator>>(std::istream& is, VariadicArg& self)
        {
            is >> self.m_value;
            return is;
        }

        friend std::ostream& operator<<(std::ostream& os, VariadicArg const& self)
        {
            os << self.m_value;
            return os;
        }

    private:
        std::string m_value;
    };
}
