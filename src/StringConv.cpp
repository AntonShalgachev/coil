#include "coil/detail/StringConv.h"

#include "coil/Utils.h"
#include "coil/String.h"

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
    return coil::sprintf("%f", value);
}

coil::String coil::toString(double value)
{
    return coil::sprintf("%f", value);
}

coil::String coil::toString(long double value)
{
    return coil::sprintf("%Lf", value);
}
