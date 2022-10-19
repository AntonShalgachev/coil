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
        Optional() : m_hasValue(false), m_empty({})
        {

        }
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

        friend bool operator==(Optional const& lhs, Optional const& rhs)
        {
            if (lhs.m_hasValue != rhs.m_hasValue)
                return false;

            if (lhs.m_hasValue && rhs.m_hasValue)
                return lhs.m_value == rhs.m_value;

            return true;
        }

        friend bool operator==(Optional const& lhs, T const& rhs)
        {
            return lhs.m_hasValue && lhs.m_value == rhs;
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
