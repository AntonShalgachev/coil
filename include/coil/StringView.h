#pragma once

#include <stddef.h>

namespace coil
{
    class StringView
    {
    public:
        StringView();
        StringView(char const* str);
        StringView(char const* str, size_t length);

        size_t length() const;
        bool empty() const;
        char const* data() const;

        StringView substr(size_t offset) const;
        StringView substr(size_t offset, size_t length) const;

        char const* begin() const;
        char const* end() const;

        char const& operator[](size_t index) const;

        friend bool operator==(StringView const& lhs, StringView const& rhs);
        friend bool operator!=(StringView const& lhs, StringView const& rhs);

    private:
        char const* m_str = nullptr;
        size_t m_length = 0;
    };
}
