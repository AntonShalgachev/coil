#pragma once

#include "Hash.h"

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

        StringView substr(size_t offset, size_t length) const;

        char const* begin() const;
        char const* end() const;

        char const& operator[](size_t index) const;

    private:
        char const* m_str = nullptr;
        size_t m_length = 0;
    };

    bool operator==(StringView const& lhs, StringView const& rhs);
    bool operator!=(StringView const& lhs, StringView const& rhs);

    template<>
    struct Hash<StringView>
    {
        size_t operator()(StringView const& value);
    };
}
