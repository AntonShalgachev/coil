#include "coil/Buffer.h"

#include <string.h>

coil::Buffer::Buffer(size_t capacity, size_t chunkSize) : m_ptr(capacity * chunkSize > 0 ? new char[capacity * chunkSize] : nullptr), m_capacity(capacity), m_chunkSize(chunkSize)
{
    COIL_ASSERT(chunkSize > 0);
}

coil::Buffer::Buffer(Buffer const& rhs) : Buffer(rhs.m_capacity, rhs.m_chunkSize)
{
    COIL_ASSERT(rhs.m_constructedObjectsCount == 0);
    copy(rhs.m_ptr, rhs.m_size * m_chunkSize);
    m_size = rhs.m_size;
}

coil::Buffer::Buffer(Buffer&& rhs)
{
    rhs.swap(*this);
}

coil::Buffer::~Buffer()
{
    COIL_ASSERT(m_constructedObjectsCount == 0);

    if (m_ptr)
        delete[] m_ptr;
    m_ptr = nullptr;
}

coil::Buffer& coil::Buffer::operator=(Buffer const& rhs)
{
    COIL_ASSERT(rhs.m_constructedObjectsCount == 0);

    Buffer temp{rhs};
    temp.swap(*this);
    return *this;
}

coil::Buffer& coil::Buffer::operator=(Buffer&& rhs)
{
    rhs.swap(*this);
    return *this;
}

char* coil::Buffer::data()
{
    return m_ptr;
}

char const* coil::Buffer::data() const
{
    return m_ptr;
}

size_t coil::Buffer::capacity() const
{
    return m_capacity;
}

size_t coil::Buffer::capacityBytes() const
{
    return m_capacity * m_chunkSize;
}

size_t coil::Buffer::size() const
{
    return m_size;
}

void coil::Buffer::resize(size_t newSize)
{
    COIL_ASSERT(newSize <= m_capacity);
    m_size = newSize;
}

char* coil::Buffer::get(size_t index)
{
    return m_ptr + index;
}

char const* coil::Buffer::get(size_t index) const
{
    return m_ptr + index;
}

void coil::Buffer::copy(void const* ptr, size_t size)
{
    if (size == 0)
        return;

    COIL_ASSERT(ptr);
    COIL_ASSERT(size <= capacityBytes());

    memcpy(m_ptr, ptr, size);
}

void coil::Buffer::swap(Buffer& rhs) noexcept
{
    coil::exchange(m_ptr, rhs.m_ptr);
    coil::exchange(m_capacity, rhs.m_capacity);
    coil::exchange(m_chunkSize, rhs.m_chunkSize);

    coil::exchange(m_size, rhs.m_size);

#if COIL_CONFIG_ENABLE_ASSERTS
    coil::exchange(m_constructedObjectsCount, rhs.m_constructedObjectsCount);
#endif
}
