#pragma once

#include "detail/TypeTraits.h"
#include "detail/Utility.h"
#include "detail/New.h"
#include "Assert.h"

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
            return Unexpected<U>{m_value};
        }

        template<typename U>
        operator Unexpected<U>() &
        {
            return Unexpected<U>{m_value};
        }

        template<typename U>
        operator Unexpected<U>() &&
        {
            return Unexpected<U>{Move(m_value)};
        }

    private:
        T m_value;
    };

    template<typename T>
    Unexpected<T> makeUnexpected(T value)
    {
        return Unexpected<RemoveCvT<RemoveReferenceT<T>>>(Move(value));
    }

    template<typename T, typename E>
    class Expected
    {
        static_assert(!IsVoidV<T>, "T can't be void");
        static_assert(!IsVoidV<E>, "E can't be void");

    public:
        Expected(T value) : m_expected(Move(value)), m_hasValue(true) {}

        template<typename U>
        Expected(Unexpected<U> error) : m_unexpected(Move(error)), m_hasValue(false)
        {
            
        }

        Expected(Expected<T, E> const& rhs)
        {
            constructFrom(rhs);
        }

        Expected(Expected<T, E>&& rhs) noexcept
        {
            constructFrom(Move(rhs));
        }

        ~Expected() // not virtual
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
            COIL_ASSERT(!hasValue());
            return m_unexpected.value();
        }
        E& error() &
        {
            COIL_ASSERT(!hasValue());
            return m_unexpected.value();
        }
        E&& error() &&
        {
            COIL_ASSERT(!hasValue());
            return Move(m_unexpected).value();
        }

        template<typename T2, typename E2>
        bool operator==(Expected<T2, E2> const& rhs) const
        {
            static_assert(!IsVoidV<T2>, "Can't compare T with void");

            if (hasValue() && rhs.hasValue())
                return value() == rhs.value();

            if (!hasValue() && !rhs.hasValue())
                return error() == rhs.error();

            return false;
        }

        template<typename T2>
        bool operator==(T2 const& rhs) const
        {
            return hasValue() && value() == rhs;
        }

        T const& value() const&
        {
            COIL_ASSERT(hasValue());
            return m_expected;
        }

        T& value()&
        {
            COIL_ASSERT(hasValue());
            return m_expected;
        }

        T&& value()&&
        {
            COIL_ASSERT(hasValue());
            return Move(*this).m_expected;
        }

        T const& operator*() const&
        {
            return value();
        }
        T& operator*()&
        {
            return value();
        }
        T&& operator*()&&
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

        template<typename E2>
        bool operator==(Unexpected<E2> const& rhs) const
        {
            return !hasValue() && error() == rhs.value();
        }

    protected:
        void constructFrom(Expected<T, E> const& rhs)
        {
            m_hasValue = rhs.m_hasValue;
            if (rhs.m_hasValue)
                new (NewTag{}, &m_expected) T(rhs.m_expected);
            else
                new (NewTag{}, &m_unexpected) Unexpected<E>(rhs.m_unexpected);
        }

        void constructFrom(Expected<T, E>&& rhs)
        {
            m_hasValue = rhs.m_hasValue;
            if (rhs.m_hasValue)
                new (NewTag{}, &m_expected) T(Move(rhs.m_expected));
            else
                new (NewTag{}, &m_unexpected) Unexpected<E>(Move(rhs.m_unexpected));
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
}
