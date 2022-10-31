#include "coil/Buffer.h"

#include <string.h>

coil::Buffer::Buffer(size_t count, size_t chunkSize)
    : m_ptr(count * chunkSize > 0 ? new char[count * chunkSize] : nullptr)
    , m_count(count)
    , m_chunkSize(chunkSize)
{
    COIL_ASSERT(chunkSize > 0);
}

coil::Buffer::Buffer(Buffer const& rhs) : Buffer(rhs.m_count, rhs.m_chunkSize)
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

    Buffer temp{ rhs };
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

size_t coil::Buffer::count() const
{
    return m_count;
}

size_t coil::Buffer::size() const
{
    return m_size;
}

bool coil::Buffer::empty() const
{
    // TODO rework: empty() should be synonymous to size() == 0
    return internalBufferSize() == 0;
}

void coil::Buffer::resize(size_t newSize)
{
    COIL_ASSERT(newSize <= m_count);
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
    COIL_ASSERT(size <= internalBufferSize());

    memcpy(m_ptr, ptr, size);
}

size_t coil::Buffer::internalBufferSize() const
{
    return m_count * m_chunkSize;
}

void coil::Buffer::swap(Buffer& rhs) noexcept
{
    coil::exchange(m_ptr, rhs.m_ptr);
    coil::exchange(m_count, rhs.m_count);
    coil::exchange(m_chunkSize, rhs.m_chunkSize);

    coil::exchange(m_size, rhs.m_size);

#if COIL_CONFIG_ENABLE_ASSERTS
    coil::exchange(m_constructedObjectsCount, rhs.m_constructedObjectsCount);
#endif
}
