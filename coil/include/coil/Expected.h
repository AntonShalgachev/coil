#pragma once

#include <exception>

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
    class ExpectedBase
    {
        static_assert(!std::is_void_v<E>, "E can't be void");

    public:
        ExpectedBase(T value) : m_expected(std::move(value)), m_hasValue(true) {}

        template<typename U>
        ExpectedBase(Unexpected<U> error) : m_unexpected(std::move(error)), m_hasValue(false)
        {
            static_assert(std::is_convertible_v<U&&, E>, "U should be convertible to E");
        }

        ExpectedBase(ExpectedBase<T, E> const& rhs)
        {
            constructFrom(rhs);
        }

        ExpectedBase(ExpectedBase<T, E>&& rhs) noexcept
        {
            constructFrom(std::move(rhs));
        }

        ~ExpectedBase() // not virtual
        {
            destruct();
        }

        ExpectedBase<T, E>& operator=(ExpectedBase<T, E> const& rhs)
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

        ExpectedBase<T, E>& operator=(ExpectedBase<T, E>&& rhs) noexcept
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

        operator bool() const
        {
            return hasValue();
        }

        E const& error() const& { return m_unexpected.value(); }
        E& error()& { return m_unexpected.value(); }
        E&& error()&& { return std::move(m_unexpected).value(); }

        template<typename E2>
        bool operator==(Unexpected<E2> const& rhs) const
        {
            return !hasValue() && error() == rhs.value();
        }

    protected:
        void constructFrom(ExpectedBase<T, E> const& rhs)
        {
            m_hasValue = rhs.m_hasValue;
            if (rhs.m_hasValue)
                new (std::addressof(m_expected)) T(rhs.m_expected);
            else
                new (std::addressof(m_unexpected)) Unexpected<E>(rhs.m_unexpected);
        }

        void constructFrom(ExpectedBase<T, E>&& rhs)
        {
            m_hasValue = rhs.m_hasValue;
            if (rhs.m_hasValue)
                new (std::addressof(m_expected)) T(std::move(rhs.m_expected));
            else
                new (std::addressof(m_unexpected)) Unexpected<E>(std::move(rhs.m_unexpected));
        }

        void destruct()
        {
            if (m_hasValue)
                m_expected.~T();
            else
                m_unexpected.~Unexpected<E>();
        }

        union
        {
            T m_expected;
            Unexpected<E> m_unexpected;
        };
        bool m_hasValue = true;
    };

    template<typename T, typename E>
    class Expected final : public ExpectedBase<T, E>
    {
    public:
        using Base = ExpectedBase<T, E>;

        using Base::Base;
        using Base::operator bool;
        using Base::operator==;

        Expected(T value) : Base(std::move(value)) {}

        Expected(Expected<T, E> const& rhs) : Base(rhs)
        {
            
        }

        Expected(Expected<T, E>&& rhs) noexcept : Base(std::move(rhs))
        {
            
        }

        ~Expected() {}; // not default to enable explicit instantiation

        Expected<T, E>& operator=(Expected<T, E> const& rhs)
        {
            return static_cast<Expected<T, E>&>(Base::operator=(rhs));
        }

        Expected<T, E>& operator=(Expected<T, E>&& rhs) noexcept
        {
            return static_cast<Expected<T, E>&>(Base::operator=(std::move(rhs)));
        }

        template<typename T2, typename E2>
        bool operator==(Expected<T2, E2> const& rhs) const
        {
            static_assert(!std::is_void_v<T2>, "Can't compare T with void");

            if (this->hasValue() && rhs.hasValue())
                return value() == rhs.value();

            if (!this->hasValue() && !rhs.hasValue())
                return this->error() == rhs.error();

            return false;
        }

        template<typename T2>
        bool operator==(T2 const& rhs) const
        {
            return this->hasValue() && value() == rhs;
        }

        T const& value() const&
        {
            if (!this->hasValue())
                throw BadExpectedAccess<E>(this->error());
            return this->m_expected;
        }

        T& value()&
        {
            if (!this->hasValue())
                throw BadExpectedAccess<E>(this->error());
            return this->m_expected;
        }

        T&& value()&&
        {
            if (!this->hasValue())
                throw BadExpectedAccess<E>(std::move(*this).error());
            return std::move(*this).m_expected;
        }

        T const& operator*() const& { return value(); }
        T& operator*()& { return value(); }
        T&& operator*()&& { return std::move(*this).value(); }

        T const* operator->() const { return &value(); }
        T* operator->() { return &value(); }
    };

    template<typename E>
    class Expected<void, E> final : public ExpectedBase<detail::dummy, E>
    {
    public:
        using Base = ExpectedBase<detail::dummy, E>;

        using Base::Base;
        using Base::operator bool;
        using Base::operator==;

        Expected() : Base(detail::dummy{}) {}

        Expected(Expected<void, E> const& rhs) : Base(rhs)
        {
            constructFrom(rhs);
        }

        Expected(Expected<void, E>&& rhs) noexcept : Base(std::move(rhs))
        {
            constructFrom(std::move(rhs));
        }

        ~Expected() {}; // not default to enable explicit instantiation

        Expected<void, E>& operator=(Expected<void, E> const& rhs)
        {
            return static_cast<Expected<void, E>&>(Base::operator=(rhs));
        }

        Expected<void, E>& operator=(Expected<void, E>&& rhs) noexcept
        {
            return static_cast<Expected<void, E>&>(Base::operator=(std::move(rhs)));
        }

        template<typename E2>
        bool operator==(Expected<void, E2> const& rhs) const
        {
            if (this->hasValue() && rhs.hasValue())
                return true;

            if (!this->hasValue() && !rhs.hasValue())
                return this->error() == rhs.error();

            return false;
        }
    };
}
