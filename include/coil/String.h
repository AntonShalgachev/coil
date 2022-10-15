#pragma once

#include <vector>

namespace coil
{
    class StringView;

    class String
    {
    public:
        String();
        String(char const* str);
        String(StringView str);
        String(char const* str, std::size_t length);

        std::size_t size() const;
        bool empty() const;
        void reserve(std::size_t capacity);
        char* cStr();
        char const* cStr() const;
        char* data();
        char const* data() const;
        char& back();
        char const& back() const;

        void resize(std::size_t size);
        void append(char const* str, std::size_t length);

        String& operator+=(char rhs);
        String& operator+=(char const* rhs);
        String& operator+=(String const& rhs);
        String& operator+=(StringView const& rhs);

        friend String operator+(String lhs, char rhs);
        friend String operator+(String lhs, char const* rhs);
        friend String operator+(String lhs, String const& rhs);
        friend String operator+(String lhs, StringView const& rhs);

        bool operator==(String const& rhs) const;
        bool operator==(StringView const& rhs) const;
        bool operator==(char const* rhs) const;

        operator StringView() const;

    private:
        std::vector<char> m_chars;
    };

    String toString(int value);
    String toString(long value);
    String toString(long long value);
    String toString(unsigned value);
    String toString(unsigned long value);
    String toString(unsigned long long value);
    String toString(float value);
    String toString(double value);
    String toString(long double value);
}
