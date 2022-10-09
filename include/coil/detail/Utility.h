#pragma once

#include "TypeTraits.h"

namespace coil
{
    template <typename T>
    constexpr RemoveReferenceT<T>&& Move(T&& arg) noexcept
    {
        return static_cast<RemoveReferenceT<T>&&>(arg);
    }

    template <typename T>
    constexpr T&& Forward(RemoveReferenceT<T>& arg) noexcept
    {
        return static_cast<T&&>(arg);
    }

    template <typename T>
    constexpr T&& Forward(RemoveReferenceT<T>&& arg) noexcept
    {
        return static_cast<T&&>(arg);
    }
}
