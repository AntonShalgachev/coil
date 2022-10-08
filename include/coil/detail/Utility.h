#pragma once

#include "TypeTraits.h"

namespace coil
{
    template <class T>
    constexpr RemoveReferenceT<T>&& Move(T&& arg) noexcept
    {
        return static_cast<RemoveReferenceT<T>&&>(arg);
    }
}
