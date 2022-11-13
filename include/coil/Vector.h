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
        Vector(size_t capacity = 0);
        Vector(T const* begin, T const* end);

        Vector(Vector const& rhs);
        Vector(Vector&& rhs);

        ~Vector();

        Vector& operator=(Vector const& rhs);
        Vector& operator=(Vector&& rhs) noexcept;

        void reserve(size_t newCapacity);
        void resize(size_t newSize);

        void pushBack(T item);
        void popBack();

        void clear();

        T* data();
        T const* data() const;
        size_t size() const;
        size_t capacity() const;
        bool empty() const;

        T* begin();
        T const* begin() const;
        T* end();
        T const* end() const;

        T& front();
        T const& front() const;
        T& back();
        T const& back() const;

        T const& operator[](size_t index) const;
        T& operator[](size_t index);

        bool operator==(Vector const& rhs) const;

    private:
        void grow(size_t newCapacity);

    private:
        Buffer m_buffer;
    };
}

template<typename T>
coil::Vector<T>::Vector(T const* begin, T const* end) : Vector(end - begin)
{
    COIL_ASSERT(capacity() >= static_cast<size_t>((end - begin)));
    COIL_ASSERT(empty());

    for (T const* it = begin; it != end; it++)
        m_buffer.constructNext<T>(*it);
}

template<typename T>
coil::Vector<T>::Vector(size_t capacity /*= 0*/) : m_buffer(capacity, sizeof(T))
{

}

template<typename T>
coil::Vector<T>::Vector(Vector const& rhs) : Vector(rhs.begin(), rhs.end())
{

}

template<typename T>
coil::Vector<T>::Vector(Vector&& rhs) = default;

template<typename T>
coil::Vector<T>::~Vector()
{
    clear();
}

template<typename T>
coil::Vector<T>& coil::Vector<T>::operator=(Vector const& rhs)
{
    Vector temp{ rhs };
    return (*this = coil::move(temp));
}

template<typename T>
coil::Vector<T>& coil::Vector<T>::operator=(Vector&& rhs) noexcept = default;

template<typename T>
void coil::Vector<T>::reserve(size_t newCapacity)
{
    if (newCapacity > capacity())
        grow(newCapacity);
}

template<typename T>
void coil::Vector<T>::resize(size_t newSize)
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

template<typename T>
void coil::Vector<T>::pushBack(T item)
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

template<typename T>
void coil::Vector<T>::popBack()
{
    COIL_ASSERT(!empty());

    m_buffer.destructLast<T>();
}

template<typename T>
void coil::Vector<T>::clear()
{
    while (m_buffer.size() > 0)
        m_buffer.destructLast<T>();
}

template<typename T>
T* coil::Vector<T>::data() { return begin(); }
template<typename T>
T const* coil::Vector<T>::data() const { return begin(); }
template<typename T>
size_t coil::Vector<T>::size() const { return m_buffer.size(); }
template<typename T>
size_t coil::Vector<T>::capacity() const { return m_buffer.capacity(); }
template<typename T>
bool coil::Vector<T>::empty() const { return size() == 0; }

template<typename T>
T* coil::Vector<T>::begin() { return m_buffer.get<T>(0); }
template<typename T>
T const* coil::Vector<T>::begin() const { return m_buffer.get<T>(0); }
template<typename T>
T* coil::Vector<T>::end() { return m_buffer.get<T>(size()); }
template<typename T>
T const* coil::Vector<T>::end() const { return m_buffer.get<T>(size()); }

template<typename T>
T& coil::Vector<T>::front() { COIL_ASSERT(!empty()); return (*this)[0]; }
template<typename T>
T const& coil::Vector<T>::front() const { COIL_ASSERT(!empty()); return (*this)[0]; }
template<typename T>
T& coil::Vector<T>::back() { COIL_ASSERT(!empty()); return (*this)[size() - 1]; }
template<typename T>
T const& coil::Vector<T>::back() const { COIL_ASSERT(!empty()); return (*this)[size() - 1]; }

template<typename T>
T const& coil::Vector<T>::operator[](size_t index) const
{
    COIL_ASSERT(index < m_buffer.size());
    return *m_buffer.get<T>(index);
}

template<typename T>
T& coil::Vector<T>::operator[](size_t index)
{
    COIL_ASSERT(index < m_buffer.size());
    return *m_buffer.get<T>(index);
}

template<typename T>
bool coil::Vector<T>::operator==(Vector const& rhs) const
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

template<typename T>
void coil::Vector<T>::grow(size_t newCapacity)
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
