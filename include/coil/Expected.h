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
        Expected(T value);
        template<typename U>
        Expected(Unexpected<U> error); // TODO make it non-templated
        Expected(Expected<T, E> const& rhs);
        Expected(Expected<T, E>&& rhs) noexcept;

        ~Expected();

        Expected<T, E>& operator=(Expected<T, E> const& rhs);
        Expected<T, E>& operator=(Expected<T, E>&& rhs) noexcept;

        bool hasValue() const;
        operator bool() const;

        E const& error() const&;
        E& error() &;
        E&& error()&&;

        template<typename T2, typename E2>
        bool operator==(Expected<T2, E2> const& rhs) const;

        template<typename T2>
        bool operator==(T2 const& rhs) const;

        T const& value() const&;
        T& value()&;
        T&& value()&&;

        T const& operator*() const&;
        T& operator*()&;
        T&& operator*()&&;

        T const* operator->() const;
        T* operator->();

        template<typename E2>
        bool operator==(Unexpected<E2> const& rhs) const;

    protected:
        void constructFrom(Expected<T, E> const& rhs);
        void constructFrom(Expected<T, E>&& rhs);
        void destruct();

        union
        {
            T m_expected;
            Unexpected<E> m_unexpected;
        };
        bool m_hasValue = true;
    };

}

//////////////////////////////////////////////////////////////////////////

template<typename T, typename E>
coil::Expected<T, E>::Expected(T value) : m_expected(coil::move(value)), m_hasValue(true)
{

}

template<typename T, typename E>
template<typename U>
coil::Expected<T, E>::Expected(Unexpected<U> error) : m_unexpected(coil::move(error)), m_hasValue(false)
{

}

template<typename T, typename E>
coil::Expected<T, E>::Expected(Expected<T, E> const& rhs)
{
    constructFrom(rhs);
}

template<typename T, typename E>
coil::Expected<T, E>::Expected(Expected<T, E>&& rhs) noexcept
{
    constructFrom(coil::move(rhs));
}

template<typename T, typename E>
coil::Expected<T, E>::~Expected()
{
    destruct();
}

template<typename T, typename E>
coil::Expected<T, E>& coil::Expected<T, E>::operator=(Expected<T, E> const& rhs)
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

template<typename T, typename E>
coil::Expected<T, E>& coil::Expected<T, E>::operator=(Expected<T, E>&& rhs) noexcept
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

template<typename T, typename E>
bool coil::Expected<T, E>::hasValue() const
{
    return m_hasValue;
}

template<typename T, typename E>
coil::Expected<T, E>::operator bool() const
{
    return hasValue();
}

template<typename T, typename E>
E const& coil::Expected<T, E>::error() const&
{
    COIL_ASSERT(!hasValue());
    return m_unexpected.value();
}

template<typename T, typename E>
E& coil::Expected<T, E>::error()&
{
    COIL_ASSERT(!hasValue());
    return m_unexpected.value();
}

template<typename T, typename E>
E&& coil::Expected<T, E>::error()&&
{
    COIL_ASSERT(!hasValue());
    return coil::move(m_unexpected).value();
}

template<typename T, typename E>
template<typename T2, typename E2>
bool coil::Expected<T, E>::operator==(Expected<T2, E2> const& rhs) const
{
    static_assert(!IsVoidV<T2>, "Can't compare T with void");

    if (hasValue() && rhs.hasValue())
        return value() == rhs.value();

    if (!hasValue() && !rhs.hasValue())
        return error() == rhs.error();

    return false;
}

template<typename T, typename E>
template<typename T2>
bool coil::Expected<T, E>::operator==(T2 const& rhs) const
{
    return hasValue() && value() == rhs;
}

template<typename T, typename E>
T const& coil::Expected<T, E>::value() const&
{
    COIL_ASSERT(hasValue());
    return m_expected;
}

template<typename T, typename E>
T& coil::Expected<T, E>::value()&
{
    COIL_ASSERT(hasValue());
    return m_expected;
}

template<typename T, typename E>
T&& coil::Expected<T, E>::value()&&
{
    COIL_ASSERT(hasValue());
    return coil::move(*this).m_expected;
}

template<typename T, typename E>
T const& coil::Expected<T, E>::operator*() const&
{
    return value();
}

template<typename T, typename E>
T& coil::Expected<T, E>::operator*()&
{
    return value();
}

template<typename T, typename E>
T&& coil::Expected<T, E>::operator*()&&
{
    return coil::move(*this).value();
}

template<typename T, typename E>
T const* coil::Expected<T, E>::operator->() const
{
    return &value();
}

template<typename T, typename E>
T* coil::Expected<T, E>::operator->()
{
    return &value();
}

template<typename T, typename E>
template<typename E2>
bool coil::Expected<T, E>::operator==(Unexpected<E2> const& rhs) const
{
    return !hasValue() && error() == rhs.value();
}

template<typename T, typename E>
void coil::Expected<T, E>::constructFrom(Expected<T, E> const& rhs)
{
    m_hasValue = rhs.m_hasValue;
    if (rhs.m_hasValue)
        new (NewTag{}, &m_expected) T(rhs.m_expected);
    else
        new (NewTag{}, &m_unexpected) Unexpected<E>(rhs.m_unexpected);
}

template<typename T, typename E>
void coil::Expected<T, E>::constructFrom(Expected<T, E>&& rhs)
{
    m_hasValue = rhs.m_hasValue;
    if (rhs.m_hasValue)
        new (NewTag{}, &m_expected) T(coil::move(rhs.m_expected));
    else
        new (NewTag{}, &m_unexpected) Unexpected<E>(coil::move(rhs.m_unexpected));
}

template<typename T, typename E>
void coil::Expected<T, E>::destruct()
{
    if (m_hasValue)
        m_expected.~T();
    else
        m_unexpected.~Unexpected<E>();
}
