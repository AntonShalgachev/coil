#pragma once

#include "detail/Utility.h" // TODO remove
#include "detail/New.h"

#include <stddef.h>
#include <assert.h>

namespace coil
{
    // TODO move some non-template parts into cpp file

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
            assign(rhs.m_items, rhs.m_size);
        }

        Vector(Vector&& rhs)
        {
            rhs.swap(*this);
        }

        ~Vector()
        {
            deallocate();
        }

        Vector& operator=(Vector const& rhs)
        {
            Vector temp{ rhs };
            temp.swap(*this);
            return *this;
        }

        Vector& operator=(Vector&& rhs) noexcept
        {
            rhs.swap(*this);
            return *this;
        }

        void reserve(size_t capacity)
        {
            if (capacity > m_capacity)
                grow(capacity);
        }

        void resize(size_t size)
        {
            if (size > m_capacity)
                grow(size);
            assert(size <= m_capacity);

            for (size_t i = m_size; i < size; i++)
                new (NewTag{}, m_items + i) T();

            m_size = size;
        }

        void pushBack(T item)
        {
            if (m_size + 1 > m_capacity)
                grow(m_size + 1); // TODO think about grow strategy

            new (NewTag{}, m_items + m_size) T(Move(item));
            m_size++;
        }

        void popBack()
        {
            assert(!empty());

            m_items[m_size - 1].~T();
            m_size--;
        }

        void clear()
        {
            deallocate();
        }

        T* data() { return m_items; }
        T const* data() const { return m_items; }
        size_t size() const { return m_size; }
        size_t capacity() const { return m_capacity; }
        bool empty() const { return size() == 0; }

        T* begin() { return m_items; }
        T const* begin() const { return m_items; }
        T* end() { return m_items + m_size; }
        T const* end() const { return m_items + m_size; }

        T& front() { assert(!empty()); return m_items[0]; }
        T const& front() const { assert(!empty()); return m_items[0]; }
        T& back() { assert(!empty()); return m_items[m_size - 1]; }
        T const& back() const { assert(!empty()); return m_items[m_size - 1]; }

        T const& operator[](size_t index) const
        {
            assert(index < m_size);
            return m_items[index];
        }
        T& operator[](size_t index)
        {
            assert(index < m_size);
            return m_items[index];
        }

        friend bool operator==(Vector const& lhs, Vector const& rhs)
        {
            if (lhs.m_size != rhs.m_size)
                return false;
            size_t size = lhs.m_size;
            for (size_t i = 0; i < size; i++)
                if (lhs[i] != rhs[i])
                    return false;
            return true;
        }

    private:
        void grow(size_t capacity)
        {
            T* items = static_cast<T*>(operator new(capacity * sizeof(T)));

            if (m_items)
            {
                for (size_t i = 0; i < m_size; i++)
                {
                    new (NewTag{}, items + i) T(Move(m_items[i]));
                    m_items[i].~T();
                }
                operator delete(m_items);
            }

            m_items = items;
            m_capacity = capacity;
        }

        void assign(T const* items, size_t size)
        {
            deallocate();
            grow(size);

            assert(m_items);
            assert(m_capacity >= size);
            for (size_t i = 0; i < size; i++)
                new (NewTag{}, m_items + i) T(items[i]);
            m_size = size;
        }

        void deallocate()
        {
            for (size_t i = 0; i < m_size; i++)
                m_items[i].~T();
            m_size = 0;

            if (m_items)
                operator delete(m_items);
            m_items = nullptr;
            m_capacity = 0;
        }

        void swap(Vector& rhs) noexcept
        {
            coil::exchange(m_items, rhs.m_items);
            coil::exchange(m_size, rhs.m_size);
            coil::exchange(m_capacity, rhs.m_capacity);
        }

    private:
        T* m_items = nullptr;
        size_t m_size = 0;
        size_t m_capacity = 0;
    };
}
