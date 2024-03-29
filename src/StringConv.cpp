#include "coil/detail/StringConv.h"

#include "coil/detail/String.h"
#include "coil/detail/StringView.h"
#include "coil/detail/Utils.h"

#include <errno.h>
#include <limits.h>
#include <stdlib.h>

namespace
{
    template<typename T>
    auto strtoxfunc = nullptr;
    template<>
    auto strtoxfunc<float> = &strtof;
    template<>
    auto strtoxfunc<double> = &strtod;
    template<>
    auto strtoxfunc<long double> = &strtold;
    template<>
    auto strtoxfunc<long> = &strtol;
    template<>
    auto strtoxfunc<unsigned long> = &strtoul;
    template<>
    auto strtoxfunc<long long> = &strtoll;
    template<>
    auto strtoxfunc<unsigned long long> = &strtoull;

    template<typename T>
    bool signedIntegerFromString(coil::StringView str, T& value)
    {
        if (str.empty())
            return false;

        coil::String strCopy = coil::String{str}; // make a C-string to avoid reimplementing strtoX functions

        char* end = nullptr;
        errno = 0;
        value = strtoxfunc<T>(strCopy.cStr(), &end, 10);
        if (errno)
            return false;
        return end == strCopy.end();
    }

    template<typename T>
    bool unsignedIntegerFromString(coil::StringView str, T& value)
    {
        if (str.empty())
            return false;

        if (str[0] == '-')
            return false;

        coil::String strCopy = coil::String{str}; // make a C-string to avoid reimplementing strtoX functions

        char* end = nullptr;
        errno = 0;
        value = strtoxfunc<T>(strCopy.cStr(), &end, 10);
        if (errno)
            return false;
        return end == strCopy.end();
    }

    template<typename T>
    bool floatFromString(coil::StringView str, T& value)
    {
        if (str.empty())
            return false;

        coil::String strCopy = coil::String{str}; // make a C-string to avoid reimplementing strtoX functions

        char* end = nullptr;
        errno = 0;
        value = strtoxfunc<T>(strCopy.cStr(), &end);
        if (errno)
            return false;
        return end == strCopy.end();
    }

    template<typename T>
    bool signedAliasFromString(coil::StringView str, T& value, long min, long max)
    {
        long result;
        if (!fromString(str, result))
            return false;
        if (result < min || result > max)
            return false;
        value = static_cast<T>(result);
        return true;
    }

    template<typename T>
    bool unsignedAliasFromString(coil::StringView str, T& value, unsigned long max)
    {
        unsigned long result;
        if (!fromString(str, result))
            return false;
        if (result > max)
            return false;
        value = static_cast<T>(result);
        return true;
    }
}

coil::String coil::toString(int value)
{
    return coil::sprintf("%d", value);
}

coil::String coil::toString(long value)
{
    return coil::sprintf("%ld", value);
}

coil::String coil::toString(long long value)
{
    return coil::sprintf("%lld", value);
}

coil::String coil::toString(unsigned value)
{
    return coil::sprintf("%u", value);
}

coil::String coil::toString(unsigned long value)
{
    return coil::sprintf("%lu", value);
}

coil::String coil::toString(unsigned long long value)
{
    return coil::sprintf("%llu", value);
}

coil::String coil::toString(float value)
{
    if (value > -1e-6 && value < 1e-6)
        return "0";

    return coil::sprintf("%g", value);
}

coil::String coil::toString(double value)
{
    if (value > -1e-6 && value < 1e-6)
        return "0";

    return coil::sprintf("%g", value);
}

coil::String coil::toString(long double value)
{
    if (value > -1e-6 && value < 1e-6)
        return "0";

    return coil::sprintf("%Lg", value);
}

bool coil::fromString(StringView str, long& value)
{
    return signedIntegerFromString(str, value);
}

bool coil::fromString(StringView str, long long& value)
{
    return signedIntegerFromString(str, value);
}

bool coil::fromString(StringView str, unsigned long& value)
{
    return unsignedIntegerFromString(str, value);
}

bool coil::fromString(StringView str, unsigned long long& value)
{
    return unsignedIntegerFromString(str, value);
}

bool coil::fromString(StringView str, float& value)
{
    return floatFromString(str, value);
}

bool coil::fromString(StringView str, double& value)
{
    return floatFromString(str, value);
}

bool coil::fromString(StringView str, long double& value)
{
    return floatFromString(str, value);
}

bool coil::fromString(StringView str, char& value)
{
    return signedAliasFromString(str, value, CHAR_MIN, CHAR_MAX);
}

bool coil::fromString(StringView str, signed char& value)
{
    return signedAliasFromString(str, value, SCHAR_MIN, SCHAR_MAX);
}

bool coil::fromString(StringView str, unsigned char& value)
{
    return unsignedAliasFromString(str, value, UCHAR_MAX);
}

bool coil::fromString(StringView str, short& value)
{
    return signedAliasFromString(str, value, SHRT_MIN, SHRT_MAX);
}

bool coil::fromString(StringView str, unsigned short& value)
{
    return unsignedAliasFromString(str, value, USHRT_MAX);
}

bool coil::fromString(StringView str, int& value)
{
    return signedAliasFromString(str, value, INT_MIN, INT_MAX);
}

bool coil::fromString(StringView str, unsigned& value)
{
    return unsignedAliasFromString(str, value, UINT_MAX);
}
