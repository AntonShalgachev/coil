#pragma once

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

    template<typename T>
    class Unexpected
    {
        static_assert(!std::is_void_v<T>, "T shouldn't be void");

    public:
        Unexpected(T value) : m_value(std::move(value)) {}

        T const& value() const& { return m_value; }
        T& value()& { return m_value; }
        T&& value() && { return std::move(m_value); }

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
        operator Unexpected<U>() &&
        {
            static_assert(std::is_convertible_v<T&&, U>, "U should be convertible to T");
            return Unexpected<U>{std::move(m_value)};
        }

    private:
        T m_value;
    };

    namespace detail
    {
        struct dummy {}; // aka std::monostate
    }

    template<typename T>
    Unexpected<T> makeUnexpected(T value)
    {
        return Unexpected<std::decay_t<T>>(std::move(value));
    }

    template<typename T, typename E>
    class Expected
    {
    public:
        using ExpectedType = std::conditional_t<std::is_void_v<T>, detail::dummy, T>;

        template<typename U = T, typename = std::enable_if_t<!std::is_void_v<U>>>
        Expected(U value) : m_expected(std::move(value)), m_hasValue(true) {}

        template<typename U = T, typename = std::enable_if_t<std::is_void_v<U>>>
        Expected() : m_expected(ExpectedType{}), m_hasValue(true) {}

        template<typename U>
        Expected(Unexpected<U> error) : m_unexpected(std::move(error)), m_hasValue(false)
        {
            static_assert(std::is_convertible_v<U&&, E>, "U should be convertible to E");
        }

        Expected(Expected<T, E> const& rhs)
        {
            constructFrom(rhs);
        }

        Expected(Expected<T, E>&& rhs) noexcept
        {
            constructFrom(std::move(rhs));
        }

        ~Expected()
        {
            destruct();
        }

        Expected<T, E>& operator=(Expected<T, E> const& rhs)
        {
            if (m_hasValue && rhs.m_hasValue)
            {
                m_expected = rhs.m_expected;
            }
            else if (!m_hasValue && !rhs.m_hasValue)
            {
                m_unexpected = rhs.m_unexpected;
            }
            else
            {
                destruct();
                constructFrom(rhs);
            }

            return *this;
        }

        Expected<T, E>& operator=(Expected<T, E>&& rhs) noexcept
        {
            if (m_hasValue && rhs.m_hasValue)
            {
                m_expected = std::move(rhs).m_expected;
            }
            else if (!m_hasValue && !rhs.m_hasValue)
            {
                m_unexpected = std::move(rhs).m_unexpected;
            }
            else
            {
                destruct();
                constructFrom(std::move(rhs));
            }

            return *this;
        }

        bool hasValue() const
        {
            return m_hasValue;
        }

        E const& error() const& { return m_unexpected.value(); }
        E& error()& { return m_unexpected.value(); }
        E&& error() && { return std::move(m_unexpected.value()); }

        ExpectedType const& value() const&
        {
            if (!hasValue())
                throw BadExpectedAccess<E>(error());
            return m_expected;
        }

        ExpectedType& value()&
        {
            if (!hasValue())
                throw BadExpectedAccess<E>(error());
            return m_expected;
        }

        ExpectedType&& value() &&
        {
             if (!hasValue())
                 throw BadExpectedAccess<E>(error());
            return std::move(m_expected);
        }

        operator bool() const
        {
            return hasValue();
        }

        ExpectedType const& operator*() const& { return value(); }
        ExpectedType& operator*()& { return value(); }
        ExpectedType&& operator*() && { return std::move(value()); }

        ExpectedType const* operator->() const { return &value(); }
        ExpectedType* operator->() { return &value(); }

        template<typename T2, typename E2>
        bool operator==(Expected<T2, E2> const& rhs) const
        {
            static_assert(std::is_void_v<T> == std::is_void_v<T2>, "Can't compare void with non-void type");

            if constexpr (std::is_void_v<T>)
            {
                if (hasValue() && rhs.hasValue())
                    return true;
            }
            else
            {
                if (hasValue() && rhs.hasValue())
                    return value() == rhs.value();
            }

            if (!hasValue() && !rhs.hasValue())
                return error() == rhs.error();

            return false;
        }

        template<typename T2>
        bool operator==(T2 const& rhs) const
        {
            return hasValue() && value() == rhs;
        }

        template<typename E2>
        bool operator==(Unexpected<E2> const& rhs) const
        {
            return !hasValue() && error() == rhs.value();
        }

    private:
        void constructFrom(Expected<T, E> const& rhs)
        {
            m_hasValue = rhs.m_hasValue;
            if (rhs.m_hasValue)
                new (std::addressof(m_expected)) ExpectedType(rhs.m_expected);
            else
                new (std::addressof(m_unexpected)) Unexpected<E>(rhs.m_unexpected);
        }

        void constructFrom(Expected<T, E>&& rhs)
        {
            m_hasValue = rhs.m_hasValue;
            if (rhs.m_hasValue)
                new (std::addressof(m_expected)) ExpectedType(std::move(rhs.m_expected));
            else
                new (std::addressof(m_unexpected)) Unexpected<E>(std::move(rhs.m_unexpected));
        }

        void destruct()
        {
            if (m_hasValue)
                m_expected.~ExpectedType();
            else
                m_unexpected.~Unexpected<E>();
        }

        union
        {
            ExpectedType m_expected;
            Unexpected<E> m_unexpected;
        };
        bool m_hasValue = true;
    };
}
