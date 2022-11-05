#pragma once

#include "detail/Utility.h"
#include "detail/New.h"
#include "Assert.h"

namespace coil
{
    template<typename T>
    class Optional
    {
    public:

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4702) // unreachable code
#endif
        Optional() : m_hasValue(false), m_empty({})
        {

        }
#ifdef _MSC_VER
#pragma warning(pop)
#endif

        Optional(T const& value) : Optional()
        {
            construct(value);
        }
        Optional(T&& value) : Optional()
        {
            construct(coil::move(value));
        }

        Optional(Optional const& rhs) : Optional()
        {
            if (rhs.m_hasValue)
                construct(rhs.m_value);
        }

        Optional(Optional&& rhs) : Optional()
        {
            if (rhs.m_hasValue)
                construct(coil::move(rhs.m_value));
        }

        ~Optional()
        {
            destroy();
        }

        Optional& operator=(Optional const& rhs)
        {
            if (m_hasValue && rhs.m_hasValue)
                m_value = rhs.m_value;
            else if (m_hasValue && !rhs.m_hasValue)
                destroy();
            else if (!m_hasValue && rhs.m_hasValue)
                construct(rhs.m_value);

            return *this;
        }

        Optional& operator=(Optional&& rhs)
        {
            if (m_hasValue && rhs.m_hasValue)
                m_value = coil::move(rhs.m_value);
            else if (m_hasValue && !rhs.m_hasValue)
                destroy();
            else if (!m_hasValue && rhs.m_hasValue)
                construct(coil::move(rhs.m_value));

            return *this;
        }

        bool hasValue() const { return m_hasValue; }

        operator bool() const { return m_hasValue; }

        T const& operator*() const
        {
            COIL_ASSERT(m_hasValue);
            return m_value;
        }

        T& operator*()
        {
            COIL_ASSERT(m_hasValue);
            return m_value;
        }

        T const* operator->() const
        {
            return &m_value;
        }

        T* operator->()
        {
            return &m_value;
        }

        bool operator==(Optional const& rhs) const
        {
            if (m_hasValue != rhs.m_hasValue)
                return false;

            if (m_hasValue && rhs.m_hasValue)
                return m_value == rhs.m_value;

            return true;
        }

        bool operator!=(Optional const& rhs) const
        {
            return !(*this == rhs);
        }

        template<typename T2>
        bool operator==(T2 const& rhs) const
        {
            return m_hasValue && m_value == rhs;
        }

        template<typename T2>
        bool operator!=(T2 const& rhs) const
        {
            return !(*this == rhs);
        }

    private:
        void construct(T const& value)
        {
            new (coil::NewTag{}, &m_value) T(value);
            m_hasValue = true;
        }

        void construct(T&& value)
        {
            new (coil::NewTag{}, &m_value) T(coil::move(value));
            m_hasValue = true;
        }

        void destroy()
        {
            if (m_hasValue)
                m_value.~T();

            m_empty = {};
            m_hasValue = false;
        }

    private:
        struct Dummy {};

        bool m_hasValue = false;
        union
        {
            Dummy m_empty;
            T m_value;
        };
    };
}
