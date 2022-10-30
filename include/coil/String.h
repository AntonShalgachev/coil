#pragma once

#include "Vector.h"

#include "Hash.h"

#include <stddef.h>

namespace coil
{
    class StringView;

    class String
    {
    public:
        String(char const* str = "");
        String(StringView str);
        String(char const* str, size_t length);

        size_t size() const;
        bool empty() const;
        void reserve(size_t capacity);
        char* cStr();
        char const* cStr() const;
        char* data();
        char const* data() const;
        char& back();
        char const& back() const;

        void resize(size_t size);
        void append(char const* str, size_t length);

        char const* begin() const;
        char const* end() const;

        String& operator+=(char rhs);
        String& operator+=(char const* rhs);
        String& operator+=(String const& rhs);
        String& operator+=(StringView const& rhs);

        bool operator==(String const& rhs) const;
        bool operator==(StringView const& rhs) const;
        bool operator==(char const* rhs) const;

        operator StringView() const;

    private:
        Vector<char> m_chars;
    };

    String operator+(String lhs, char rhs);
    String operator+(String lhs, char const* rhs);
    String operator+(String lhs, String const& rhs);
    String operator+(String lhs, StringView const& rhs);

    template<>
    struct Hash<String>
    {
        size_t operator()(String const& value);
    };
}
