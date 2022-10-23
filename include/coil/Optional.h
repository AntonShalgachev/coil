#pragma once

#include "detail/Utility.h"
#include "detail/New.h"

#include "assert.h"

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
            construct(Move(value));
        }

        Optional(Optional&& rhs) : Optional()
        {
            rhs.swap(*this);
        }

        ~Optional()
        {
            destroy();
        }

        Optional& operator=(Optional&& rhs)
        {
            rhs.swap(*this);
            return *this;
        }

        bool hasValue() const { return m_hasValue; }

        operator bool() const { return m_hasValue; }

        T const& operator*() const
        {
            assert(m_hasValue);
            return m_value;
        }

        T& operator*()
        {
            assert(m_hasValue);
            return m_value;
        }

        bool operator==(Optional const& rhs) const
        {
            if (m_hasValue != rhs.m_hasValue)
                return false;

            if (m_hasValue && rhs.m_hasValue)
                return m_value == rhs.m_value;

            return true;
        }

        template<typename T2>
        bool operator==(T2 const& rhs) const
        {
            return m_hasValue && m_value == rhs;
        }

    private:
        void construct(T const& value)
        {
            new (coil::NewTag{}, &m_value) T(value);
            m_hasValue = true;
        }

        void construct(T&& value)
        {
            new (coil::NewTag{}, &m_value) T(Move(value));
            m_hasValue = true;
        }

        void destroy()
        {
            if (m_hasValue)
                m_value.~T();

            m_empty = {};
            m_hasValue = false;
        }

        void swap(Optional& rhs) noexcept
        {
            if (m_hasValue && rhs.m_hasValue)
            {
                coil::exchange(m_value, rhs.m_value);
            }
            else if (m_hasValue && !rhs.m_hasValue)
            {
                rhs.construct(Move(m_value));
                destroy();
            }
            else if (!m_hasValue && rhs.m_hasValue)
            {
                construct(Move(rhs.m_value));
                rhs.destroy();
            }
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
