#include "coil/StringView.h"

#include "coil/Assert.h"

#include <string.h>

coil::StringView::StringView(char const* str) : StringView(str, strlen(str))
{

}

coil::StringView::StringView(char const* str, size_t length) : m_str(str), m_length(length)
{
    COIL_ASSERT(m_str);
}

size_t coil::StringView::length() const
{
    return m_length;
}

int coil::StringView::slength() const
{
    return static_cast<int>(length());
}

bool coil::StringView::empty() const
{
    return length() == 0;
}

char const* coil::StringView::data() const
{
    COIL_ASSERT(m_str);
    return m_str;
}

coil::StringView coil::StringView::substr(size_t offset, size_t length) const
{
    COIL_ASSERT(offset <= m_length);
    COIL_ASSERT(length <= m_length);
    COIL_ASSERT(offset + length <= m_length);
    return StringView{ m_str + offset, length };
}

char const* coil::StringView::begin() const
{
    COIL_ASSERT(m_str);
    return m_str;
}

char const* coil::StringView::end() const
{
    COIL_ASSERT(m_str);
    return m_str + m_length;
}

char const& coil::StringView::operator[](size_t index) const
{
    COIL_ASSERT(index < m_length);
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

size_t coil::Hash<coil::StringView>::operator()(StringView const& value)
{
    // djb2 from http://www.cse.yorku.ca/~oz/hash.html

    size_t hash = 5381;

    for (char c : value)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}
