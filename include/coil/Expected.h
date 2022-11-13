#pragma once

#include "detail/TypeTraits.h"
#include "detail/Utility.h"
#include "detail/New.h"
#include "Assert.h"
#include "Unexpected.h"

namespace coil
{
    template<typename T, typename E>
    class Expected
    {
        static_assert(!IsVoidV<T>, "T can't be void");
        static_assert(!IsVoidV<E>, "E can't be void");

    public:
        Expected(T value) : m_expected(coil::move(value)), m_hasValue(true) {}

        template<typename U>
        Expected(Unexpected<U> error) : m_unexpected(coil::move(error)), m_hasValue(false)
        {
            
        }

        Expected(Expected<T, E> const& rhs)
        {
            constructFrom(rhs);
        }

        Expected(Expected<T, E>&& rhs) noexcept
        {
            constructFrom(coil::move(rhs));
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
                m_expected = coil::move(rhs).m_expected;
            }
            else if (!m_hasValue && !rhs.m_hasValue)
            {
                m_unexpected = coil::move(rhs).m_unexpected;
            }
            else
            {
                destruct();
                constructFrom(coil::move(rhs));
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
            return coil::move(m_unexpected).value();
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
            return coil::move(*this).m_expected;
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
            return coil::move(*this).value();
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
                new (NewTag{}, &m_expected) T(coil::move(rhs.m_expected));
            else
                new (NewTag{}, &m_unexpected) Unexpected<E>(coil::move(rhs.m_unexpected));
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
