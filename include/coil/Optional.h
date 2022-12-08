#pragma once

#include "Assert.h"
#include "detail/New.h"
#include "detail/Utility.h"

namespace coil
{
    template<typename T>
    class Optional
    {
    public:
        Optional();
        Optional(T const& value);
        Optional(T&& value);

        Optional(Optional const& rhs);
        Optional(Optional&& rhs);

        ~Optional();

        Optional& operator=(Optional const& rhs);
        Optional& operator=(Optional&& rhs);

        bool hasValue() const;
        operator bool() const;

        T const& operator*() const;
        T& operator*();

        T const* operator->() const;
        T* operator->();

        bool operator==(Optional const& rhs) const;
        bool operator!=(Optional const& rhs) const;

        template<typename T2>
        bool operator==(T2 const& rhs) const;
        template<typename T2>
        bool operator!=(T2 const& rhs) const;

    private:
        void construct(T const& value);
        void construct(T&& value);
        void destroy();

    private:
        struct Dummy
        {
        };

        bool m_hasValue = false;
        union
        {
            Dummy m_empty;
            T m_value;
        };
    };
}

//////////////////////////////////////////////////////////////////////////

#ifdef _MSC_VER
    #pragma warning(push)
    #pragma warning(disable : 4702) // unreachable code
#endif
template<typename T>
coil::Optional<T>::Optional() : m_hasValue(false), m_empty({})
{
}
#ifdef _MSC_VER
    #pragma warning(pop)
#endif

template<typename T>
coil::Optional<T>::Optional(T const& value) : Optional()
{
    construct(value);
}

template<typename T>
coil::Optional<T>::Optional(T&& value) : Optional()
{
    construct(coil::move(value));
}

template<typename T>
coil::Optional<T>::Optional(Optional const& rhs) : Optional()
{
    if (rhs.m_hasValue)
        construct(rhs.m_value);
}

template<typename T>
coil::Optional<T>::Optional(Optional&& rhs) : Optional()
{
    if (rhs.m_hasValue)
        construct(coil::move(rhs.m_value));
}

template<typename T>
coil::Optional<T>::~Optional<T>()
{
    destroy();
}

template<typename T>
coil::Optional<T>& coil::Optional<T>::operator=(Optional const& rhs)
{
    if (m_hasValue && rhs.m_hasValue)
        m_value = rhs.m_value;
    else if (m_hasValue && !rhs.m_hasValue)
        destroy();
    else if (!m_hasValue && rhs.m_hasValue)
        construct(rhs.m_value);

    return *this;
}

template<typename T>
coil::Optional<T>& coil::Optional<T>::operator=(Optional&& rhs)
{
    if (m_hasValue && rhs.m_hasValue)
        m_value = coil::move(rhs.m_value);
    else if (m_hasValue && !rhs.m_hasValue)
        destroy();
    else if (!m_hasValue && rhs.m_hasValue)
        construct(coil::move(rhs.m_value));

    return *this;
}

template<typename T>
bool coil::Optional<T>::hasValue() const
{
    return m_hasValue;
}

template<typename T>
coil::Optional<T>::operator bool() const
{
    return m_hasValue;
}

template<typename T>
T const& coil::Optional<T>::operator*() const
{
    COIL_ASSERT(m_hasValue);
    return m_value;
}

template<typename T>
T& coil::Optional<T>::operator*()
{
    COIL_ASSERT(m_hasValue);
    return m_value;
}

template<typename T>
T const* coil::Optional<T>::operator->() const
{
    return &m_value;
}

template<typename T>
T* coil::Optional<T>::operator->()
{
    return &m_value;
}

template<typename T>
bool coil::Optional<T>::operator==(Optional const& rhs) const
{
    if (m_hasValue != rhs.m_hasValue)
        return false;

    if (m_hasValue && rhs.m_hasValue)
        return m_value == rhs.m_value;

    return true;
}

template<typename T>
bool coil::Optional<T>::operator!=(Optional const& rhs) const
{
    return !(*this == rhs);
}

template<typename T>
template<typename T2>
bool coil::Optional<T>::operator==(T2 const& rhs) const
{
    return m_hasValue && m_value == rhs;
}

template<typename T>
template<typename T2>
bool coil::Optional<T>::operator!=(T2 const& rhs) const
{
    return !(*this == rhs);
}

template<typename T>
void coil::Optional<T>::construct(T const& value)
{
    new (coil::NewTag{}, &m_value) T(value);
    m_hasValue = true;
}

template<typename T>
void coil::Optional<T>::construct(T&& value)
{
    new (coil::NewTag{}, &m_value) T(coil::move(value));
    m_hasValue = true;
}

template<typename T>
void coil::Optional<T>::destroy()
{
    if (m_hasValue)
        m_value.~T();

    m_empty = {};
    m_hasValue = false;
}
