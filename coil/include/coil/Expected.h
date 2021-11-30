#pragma once

#include <variant>

namespace coil
{
    template <class E>
    class BadExpectedAccess : public std::exception
    {
    public:
        explicit BadExpectedAccess(E e) : m_value(std::move(e)) {}

        char const* what() const noexcept override { return "Bad expected access"; }

        E const& error() const& { return m_value; }
        E& error()& { return m_value; }
        E&& error()&& { return std::move(m_value); }

    private:
        E m_value;
    };

    namespace detail
    {
        template<typename T>
        class Unexpected
        {
            static_assert(!std::is_void_v<T>, "T shouldn't be void");

        public:
            Unexpected(T value) : m_value(std::move(value)) {}

            T const& value() const& { return m_value; }
            T& value()& { return m_value; }
            T&& value()&& { return std::move(m_value); }

            template<typename U>
            operator Unexpected<U>() const&
            {
                static_assert(std::is_convertible_v<T const&, U>, "U should be convertible to T");
                return Unexpected<U>{m_value};
            }

            template<typename U>
            operator Unexpected<U>()&
            {
                static_assert(std::is_convertible_v<T&, U>, "U should be convertible to T");
                return Unexpected<U>{m_value};
            }

            template<typename U>
            operator Unexpected<U>()&&
            {
                static_assert(std::is_convertible_v<T&&, U>, "U should be convertible to T");
                return Unexpected<U>{std::move(m_value)};
            }

        private:
            T m_value;
        };
    }

    template<typename T>
    detail::Unexpected<T> makeUnexpected(T value)
    {
        return detail::Unexpected<std::decay_t<T>>(value);
    }

    template<typename T, typename E>
    class Expected
    {
    public:
        using ExpectedType = std::conditional_t<std::is_void_v<T>, std::monostate, T>;

        template<typename U = T, typename = std::enable_if_t<!std::is_void_v<U>>>
        Expected(U value) : m_data(std::move(value)) {}

        template<typename U = T, typename = std::enable_if_t<std::is_void_v<U>>>
        Expected() : m_data(std::monostate{}) {}

        template<typename U>
        Expected(detail::Unexpected<U> error) : m_data(std::move(error))
        {
            static_assert(std::is_convertible_v<U&&, E>, "U should be convertible to E");
        }

        bool hasValue() const
        {
            return m_data.index() == 0;
        }

        E const& error() const& { return std::get<detail::Unexpected<E>>(m_data).value(); }
        E& error()& { return std::get<detail::Unexpected<E>>(m_data).value(); }
        E&& error() && { return std::get<detail::Unexpected<E>>(std::move(m_data)).value(); }

        template<typename U = T, typename = std::enable_if_t<!std::is_void_v<U>>>
        ExpectedType const& value() const&
        {
            if (!hasValue())
                throw BadExpectedAccess<E>(error());
            return std::get<ExpectedType>(m_data);
        }

        template<typename U = T, typename = std::enable_if_t<!std::is_void_v<U>>>
        ExpectedType& value()&
        {
            if (!hasValue())
                throw BadExpectedAccess<E>(error());
            return std::get<ExpectedType>(m_data);
        }

        template<typename U = T, typename = std::enable_if_t<!std::is_void_v<U>>>
        ExpectedType&& value() &&
        {
            if (!hasValue())
                throw BadExpectedAccess<E>(error());
            return std::get<ExpectedType>(std::move(m_data));
        }

        operator bool() const
        {
            return hasValue();
        }

        template<typename U = T, typename = std::enable_if_t<!std::is_void_v<U>>>
        ExpectedType const& operator*() const& { return value(); }
        template<typename U = T, typename = std::enable_if_t<!std::is_void_v<U>>>
        ExpectedType& operator*()& { return value(); }
        template<typename U = T, typename = std::enable_if_t<!std::is_void_v<U>>>
        ExpectedType&& operator*() && { return std::move(value()); }

        template<typename U = T, typename = std::enable_if_t<!std::is_void_v<U>>>
        ExpectedType const* operator->() const { return &value(); }
        template<typename U = T, typename = std::enable_if_t<!std::is_void_v<U>>>
        ExpectedType* operator->() { return &value(); }

        template<typename E2>
        operator Expected<ExpectedType, E2>() const&
        {
            if (hasValue()) return value();
            return error();
        }

        template<typename E2>
        operator Expected<ExpectedType, E2>()&
        {
            if (hasValue()) return value();
            return error();
        }

        template<typename E2>
        operator Expected<ExpectedType, E2>() &&
        {
            if (hasValue()) return std::move(value());
            return error();
        }

    private:
        std::variant<ExpectedType, detail::Unexpected<E>> m_data;
    };
}
