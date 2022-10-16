#include "coil/String.h"

#include "coil/StringView.h"

#include <string.h>
#include <assert.h>

coil::String::String() : String("")
{

}

coil::String::String(char const* str) : String(str, strlen(str))
{

}

coil::String::String(StringView str) : String(str.data(), str.length())
{

}

coil::String::String(char const* str, size_t length)
{
    resize(length);
    memcpy(m_chars.data(), str, length);
    assert(m_chars.back() == '\0');
}

size_t coil::String::size() const
{
    assert(!m_chars.empty());
    return m_chars.size() - 1;
}

bool coil::String::empty() const
{
    return size() == 0;
}

void coil::String::reserve(size_t capacity)
{
    assert(m_chars.back() == '\0');
    m_chars.reserve(capacity + 1);
    assert(m_chars.back() == '\0');
}

char* coil::String::cStr()
{
    return m_chars.data();
}

char const* coil::String::cStr() const
{
    return m_chars.data();
}

char* coil::String::data()
{
    return m_chars.data();
}

char const* coil::String::data() const
{
    return m_chars.data();
}

char& coil::String::back()
{
    assert(!empty());
    return m_chars[size() - 1];
}

void coil::String::resize(size_t size)
{
    if (!m_chars.empty())
        assert(m_chars.back() == '\0');
    m_chars.resize(size + 1);
    m_chars[size] = '\0';
    assert(m_chars.back() == '\0');
}

char const& coil::String::back() const
{
    assert(!empty());
    return m_chars[size() - 1];
}

void coil::String::append(char const* str, size_t length)
{
    assert(m_chars.back() == '\0');

    size_t oldSize = size();
    resize(oldSize + length);

    memcpy(m_chars.data() + oldSize, str, length);
    assert(m_chars.back() == '\0');
}

char const* coil::String::begin() const
{
    assert(!m_chars.empty());
    return m_chars.data();
}

char const* coil::String::end() const
{
    assert(!m_chars.empty());
    return &m_chars.back();
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
    return StringView{ cStr(), size() };
}
