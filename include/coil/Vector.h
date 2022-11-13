#pragma once

#include "detail/Utility.h"
#include "detail/New.h"
#include "Assert.h"

#include "Buffer.h"

#include <stddef.h>

namespace coil
{
    template<typename T>
    class Vector
    {
    public:
        Vector() = default;

        Vector(T const* items, size_t size)
        {
            assign(items, size);
        }

        Vector(Vector const& rhs)
        {
            assign(rhs.data(), rhs.size());
        }

        Vector(Vector&& rhs) = default;

        ~Vector()
        {
            deallocate();
        }

        Vector& operator=(Vector const& rhs)
        {
            Vector temp{ rhs };
            return (*this = coil::move(temp));
        }

        Vector& operator=(Vector&& rhs) noexcept = default;

        void reserve(size_t newCapacity)
        {
            if (newCapacity > capacity())
                grow(newCapacity);
        }

        void resize(size_t newSize)
        {
            if (newSize > capacity())
                grow(newSize);

            COIL_ASSERT(capacity() >= newSize);

            while (size() > newSize)
                m_buffer.destructLast<T>();
            while (size() < newSize)
                m_buffer.constructNext<T>();

            COIL_ASSERT(size() == newSize);
        }

        void pushBack(T item)
        {
            size_t nextSize = size() + 1;
            if (nextSize > capacity())
            {
                size_t nextCapacity = size() * 3 / 2;
                if (nextSize > nextCapacity)
                    nextCapacity = nextSize;
                grow(nextCapacity);
            }

            COIL_ASSERT(capacity() >= nextSize);

            m_buffer.constructNext<T>(coil::move(item));
        }

        void popBack()
        {
            COIL_ASSERT(!empty());

            m_buffer.destructLast<T>();
        }

        void clear()
        {
            while (m_buffer.size() > 0)
                m_buffer.destructLast<T>();
        }

        T* data() { return begin(); }
        T const* data() const { return begin(); }
        size_t size() const { return m_buffer.size(); }
        size_t capacity() const { return m_buffer.capacity(); }
        bool empty() const { return size() == 0; }

        T* begin() { return m_buffer.get<T>(0); }
        T const* begin() const { return m_buffer.get<T>(0); }
        T* end() { return m_buffer.get<T>(size()); }
        T const* end() const { return m_buffer.get<T>(size()); }

        T& front() { COIL_ASSERT(!empty()); return (*this)[0]; }
        T const& front() const { COIL_ASSERT(!empty()); return (*this)[0]; }
        T& back() { COIL_ASSERT(!empty()); return (*this)[size() - 1]; }
        T const& back() const { COIL_ASSERT(!empty()); return (*this)[size() - 1]; }

        T const& operator[](size_t index) const
        {
            COIL_ASSERT(index < m_buffer.size());
            return *m_buffer.get<T>(index);
        }
        T& operator[](size_t index)
        {
            COIL_ASSERT(index < m_buffer.size());
            return *m_buffer.get<T>(index);
        }

        bool operator==(Vector const& rhs) const
        {
            Vector const& lhs = *this;
            if (lhs.size() != rhs.size())
                return false;

            size_t size = lhs.size();
            for (size_t i = 0; i < size; i++)
                if (lhs[i] != rhs[i])
                    return false;

            return true;
        }

    private:
        void grow(size_t newCapacity)
        {
            Buffer buffer{ newCapacity, sizeof(T) };

            for (size_t i = 0; i < m_buffer.size(); i++)
                buffer.constructNext<T>(coil::move(*m_buffer.get<T>(i)));

            COIL_ASSERT(m_buffer.size() == buffer.size());

            while (m_buffer.size() > 0)
                m_buffer.destructLast<T>();

            m_buffer = coil::move(buffer);

            COIL_ASSERT(m_buffer.capacity() == newCapacity);
        }

        void assign(T const* items, size_t size)
        {
            clear();

            if (size > capacity())
                grow(size);

            COIL_ASSERT(capacity() >= size);

            for (size_t i = 0; i < size; i++)
                m_buffer.constructNext<T>(items[i]);
        }

        void deallocate()
        {
            clear();
            m_buffer = Buffer{};
        }

    private:
        Buffer m_buffer;
    };
}
