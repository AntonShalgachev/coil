#pragma once

#include "detail/TypeTraits.h"
#include "detail/Utility.h"

#include <cassert>

namespace coil
{
    template<typename T>
    class Unexpected
    {
        static_assert(!IsVoidV<T>, "T shouldn't be void");

    public:
        Unexpected(T value) : m_value(Move(value)) {}

        T const& value() const&
        {
            return m_value;
        }
        T& value() &
        {
            return m_value;
        }
        T&& value() &&
        {
            return Move(m_value);
        }

        template<typename U>
        operator Unexpected<U>() const&
        {
            static_assert(IsConvertibleV<T const&, U>, "U should be convertible to T");
            return Unexpected<U>{m_value};
        }

        template<typename U>
        operator Unexpected<U>() &
        {
            static_assert(IsConvertibleV<T&, U>, "U should be convertible to T");
            return Unexpected<U>{m_value};
        }

        template<typename U>
        operator Unexpected<U>() &&
        {
            static_assert(IsConvertibleV<T&&, U>, "U should be convertible to T");
            return Unexpected<U>{Move(m_value)};
        }

    private:
        T m_value;
    };

    namespace detail
    {
        // aka std::monostate
        struct dummy
        {
        };
    }

    template<typename T>
    Unexpected<T> makeUnexpected(T value)
    {
        return Unexpected<RemoveCvT<RemoveReferenceT<T>>>(Move(value));
    }

    template<typename T, typename E>
    class ExpectedBase
    {
        static_assert(!IsVoidV<E>, "E can't be void");

    public:
        ExpectedBase(T value) : m_expected(Move(value)), m_hasValue(true) {}

        template<typename U>
        ExpectedBase(Unexpected<U> error) : m_unexpected(Move(error)), m_hasValue(false)
        {
            static_assert(IsConvertibleV<U&&, E>, "U should be convertible to E");
        }

        ExpectedBase(ExpectedBase<T, E> const& rhs)
        {
            constructFrom(rhs);
        }

        ExpectedBase(ExpectedBase<T, E>&& rhs) noexcept
        {
            constructFrom(Move(rhs));
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
                m_expected = Move(rhs).m_expected;
            }
            else if (!m_hasValue && !rhs.m_hasValue)
            {
                m_unexpected = Move(rhs).m_unexpected;
            }
            else
            {
                destruct();
                constructFrom(Move(rhs));
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

        E const& error() const&
        {
            assert(!hasValue());
            return m_unexpected.value();
        }
        E& error() &
        {
            assert(!hasValue());
            return m_unexpected.value();
        }
        E&& error() &&
        {
            assert(!hasValue());
            return Move(m_unexpected).value();
        }

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
                new (&m_expected) T(rhs.m_expected);
            else
                new (&m_unexpected) Unexpected<E>(rhs.m_unexpected);
        }

        void constructFrom(ExpectedBase<T, E>&& rhs)
        {
            m_hasValue = rhs.m_hasValue;
            if (rhs.m_hasValue)
                new (&m_expected) T(Move(rhs.m_expected));
            else
                new (&m_unexpected) Unexpected<E>(Move(rhs.m_unexpected));
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

        Expected(T value) : Base(Move(value)) {}

        Expected(Expected<T, E> const& rhs) : Base(rhs) {}

        Expected(Expected<T, E>&& rhs) noexcept : Base(Move(rhs)) {}

        ~Expected(){}; // not default to enable explicit instantiation

        Expected<T, E>& operator=(Expected<T, E> const& rhs)
        {
            return static_cast<Expected<T, E>&>(Base::operator=(rhs));
        }

        Expected<T, E>& operator=(Expected<T, E>&& rhs) noexcept
        {
            return static_cast<Expected<T, E>&>(Base::operator=(Move(rhs)));
        }

        template<typename T2, typename E2>
        bool operator==(Expected<T2, E2> const& rhs) const
        {
            static_assert(!IsVoidV<T2>, "Can't compare T with void");

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
            assert(this->hasValue());
            return this->m_expected;
        }

        T& value() &
        {
            assert(this->hasValue());
            return this->m_expected;
        }

        T&& value() &&
        {
            assert(this->hasValue());
            return Move(*this).m_expected;
        }

        T const& operator*() const&
        {
            return value();
        }
        T& operator*() &
        {
            return value();
        }
        T&& operator*() &&
        {
            return Move(*this).value();
        }

        T const* operator->() const
        {
            return &value();
        }
        T* operator->()
        {
            return &value();
        }
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

        Expected(Expected<void, E>&& rhs) noexcept : Base(Move(rhs))
        {
            constructFrom(Move(rhs));
        }

        ~Expected(){}; // not default to enable explicit instantiation

        Expected<void, E>& operator=(Expected<void, E> const& rhs)
        {
            return static_cast<Expected<void, E>&>(Base::operator=(rhs));
        }

        Expected<void, E>& operator=(Expected<void, E>&& rhs) noexcept
        {
            return static_cast<Expected<void, E>&>(Base::operator=(Move(rhs)));
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
