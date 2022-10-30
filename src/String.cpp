#include "coil/String.h"

#include "coil/StringView.h"
#include "coil/Assert.h"

#include <string.h>

coil::String::String(char const* str) : String(str, strlen(str))
{

}

coil::String::String(StringView str) : String(str.data(), str.length())
{

}

coil::String::String(char const* str, size_t length)
{
    resize(length);

    COIL_ASSERT(str);
    m_buffer.copy(str, length);

    validateIsNullTerminated();
}

size_t coil::String::size() const
{
    if (m_buffer.size() > 0)
        return m_buffer.size() - 1;
    return 0;
}

bool coil::String::empty() const
{
    return size() == 0;
}

void coil::String::reserve(size_t capacity)
{
    validateIsNullTerminated();

    size_t requiredBufferSize = capacity + 1;

    if (requiredBufferSize > m_buffer.count())
    {
        Buffer buffer{ requiredBufferSize, sizeof(char) };
        buffer.copy(m_buffer.data(), size());
        *buffer.get(size()) = '\0';
        buffer.resize(m_buffer.size());
        m_buffer = Move(buffer);
    }

    validateIsNullTerminated();
}

char* coil::String::cStr()
{
    return m_buffer.data();
}

char const* coil::String::cStr() const
{
    return m_buffer.data();
}

char* coil::String::data()
{
    return m_buffer.data();
}

char const* coil::String::data() const
{
    return m_buffer.data();
}

char& coil::String::back()
{
    COIL_ASSERT(!empty());
    return *m_buffer.get(size() - 1);
}

char const& coil::String::back() const
{
    COIL_ASSERT(!empty());
    return *m_buffer.get(size() - 1);
}

void coil::String::resize(size_t newSize)
{
    validateIsNullTerminated();

    reserve(newSize);
    COIL_ASSERT(m_buffer.count() >= newSize + 1);

    m_buffer.resize(newSize + 1);
    *m_buffer.get(newSize) = '\0';

    COIL_ASSERT(m_buffer.size() == newSize + 1);

    validateIsNullTerminated();
}

void coil::String::append(char const* str, size_t length)
{
    validateIsNullTerminated();

    size_t oldSize = size();
    resize(oldSize + length);
    memcpy(m_buffer.data() + oldSize, str, length);

    validateIsNullTerminated();
}

char const* coil::String::begin() const
{
    COIL_ASSERT(!m_buffer.empty());
    return m_buffer.data();
}

char const* coil::String::end() const
{
    COIL_ASSERT(!m_buffer.empty());
    return m_buffer.data() + size();
}

coil::String& coil::String::operator+=(char rhs)
{
    append(&rhs, 1);
    return *this;
}

coil::String& coil::String::operator+=(char const* rhs)
{
    append(rhs, strlen(rhs));
    return *this;
}

coil::String& coil::String::operator+=(String const& rhs)
{
    append(rhs.cStr(), rhs.size());
    return *this;
}

coil::String& coil::String::operator+=(StringView const& rhs)
{
    append(rhs.data(), rhs.length());
    return *this;
}

bool coil::String::operator==(String const& rhs) const
{
    return StringView{ *this } == StringView{ rhs };
}

bool coil::String::operator==(StringView const& rhs) const
{
    return StringView{ *this } == rhs;
}

bool coil::String::operator==(char const* rhs) const
{
    return StringView{ *this } == StringView{ rhs };
}

coil::String::operator coil::StringView() const
{
    return StringView{ cStr(), size()};
}

void coil::String::validateIsNullTerminated()
{
    if (!m_buffer.empty())
    {
        COIL_ASSERT(*end() == '\0');
    }
}

coil::String coil::operator+(String lhs, char rhs)
{
    return lhs += rhs;
}

coil::String coil::operator+(String lhs, char const* rhs)
{
    return lhs += rhs;
}

coil::String coil::operator+(String lhs, String const& rhs)
{
    return lhs += rhs;
}

coil::String coil::operator+(String lhs, StringView const& rhs)
{
    return lhs += rhs;
}

size_t coil::Hash<coil::String>::operator()(String const& value)
{
    return Hash<StringView>{}(value);
}
