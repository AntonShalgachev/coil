#include "coil/StringView.h"

#include <string.h>
#include <assert.h>

coil::StringView::StringView() : StringView("")
{

}

coil::StringView::StringView(char const* str) : StringView(str, strlen(str))
{

}

coil::StringView::StringView(char const* str, size_t length) : m_str(str), m_length(length)
{
    assert(m_str);
}

size_t coil::StringView::length() const
{
    return m_length;
}

bool coil::StringView::empty() const
{
    return length() == 0;
}

char const* coil::StringView::data() const
{
    assert(m_str);
    return m_str;
}

coil::StringView coil::StringView::substr(size_t offset) const
{
    assert(offset <= m_length);
    return substr(offset, m_length - offset);
}

coil::StringView coil::StringView::substr(size_t offset, size_t length) const
{
    assert(offset <= m_length);
    assert(length <= m_length);
    assert(offset + length <= m_length);
    return StringView{ m_str + offset, length };
}

char const* coil::StringView::begin() const
{
    assert(m_str);
    return m_str;
}

char const* coil::StringView::end() const
{
    assert(m_str);
    return m_str + m_length;
}

char const& coil::StringView::operator[](size_t index) const
{
    assert(index < m_length);
    return m_str[index];
}

bool coil::operator==(StringView const& lhs, StringView const& rhs)
{
    if (lhs.length() != rhs.length())
        return false;

    size_t size = lhs.length();

    return memcmp(lhs.data(), rhs.data(), size) == 0;
}

bool coil::operator!=(StringView const& lhs, StringView const& rhs)
{
    return !(lhs == rhs);
}
