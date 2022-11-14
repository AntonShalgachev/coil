#pragma once

namespace coil
{
    class String;
    class StringView;

    // similar to std::to_string
    String toString(int value);
    String toString(long value);
    String toString(long long value);
    String toString(unsigned value);
    String toString(unsigned long value);
    String toString(unsigned long long value);

    // similar to std::to_string, but with %g specifier and with almost-zero check
    String toString(float value);
    String toString(double value);
    String toString(long double value);

    bool fromString(StringView str, long& value);
    bool fromString(StringView str, long long& value);
    bool fromString(StringView str, unsigned long& value);
    bool fromString(StringView str, unsigned long long& value);
    bool fromString(StringView str, float& value);
    bool fromString(StringView str, double& value);
    bool fromString(StringView str, long double& value);

    bool fromString(StringView str, char& value);
    bool fromString(StringView str, signed char& value);
    bool fromString(StringView str, unsigned char& value);
    bool fromString(StringView str, short& value);
    bool fromString(StringView str, unsigned short& value);
    bool fromString(StringView str, int& value);
    bool fromString(StringView str, unsigned& value);
}
