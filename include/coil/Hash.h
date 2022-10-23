#pragma once

#include "stddef.h"

namespace coil
{
    template<typename T>
    struct Hash
    {
        static_assert(sizeof(T) < 0, "No specialization of Hash for type T");
        size_t operator()(T const& value);
    };
}
