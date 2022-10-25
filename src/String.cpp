#include "coil/String.h"

#include "coil/StringView.h"
#include "coil/Assert.h"

#include <string.h>

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
    COIL_ASSERT(str);

    resize(length);
    memcpy(m_chars.data(), str, length);
    COIL_ASSERT(m_chars.back() == '\0');
}

size_t coil::String::size() const
{
    COIL_ASSERT(!m_chars.empty());
    return m_chars.size() - 1;
}

bool coil::String::empty() const
{
    return size() == 0;
}

void coil::String::reserve(size_t capacity)
{
    COIL_ASSERT(m_chars.back() == '\0');
    m_chars.reserve(capacity + 1);
    COIL_ASSERT(m_chars.back() == '\0');
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
    COIL_ASSERT(!empty());
    return m_chars[size() - 1];
}

void coil::String::resize(size_t size)
{
    if (!m_chars.empty())
        COIL_ASSERT(m_chars.back() == '\0');
    m_chars.resize(size + 1);
    m_chars[size] = '\0';
    COIL_ASSERT(m_chars.back() == '\0');
}

char const& coil::String::back() const
{
    COIL_ASSERT(!empty());
    return m_chars[size() - 1];
}

void coil::String::append(char const* str, size_t length)
{
    COIL_ASSERT(m_chars.back() == '\0');

    size_t oldSize = size();
    resize(oldSize + length);

    memcpy(m_chars.data() + oldSize, str, length);
    COIL_ASSERT(m_chars.back() == '\0');
}

char const* coil::String::begin() const
{
    COIL_ASSERT(!m_chars.empty());
    return m_chars.data();
}

char const* coil::String::end() const
{
    COIL_ASSERT(!m_chars.empty());
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

size_t coil::Hash<coil::String>::operator()(String const& value)
{
    return Hash<StringView>{}(value);
}
