#pragma once

#include "TypeTraits.h"

namespace coil
{
    template<typename T>
    constexpr RemoveReferenceT<T>&& move(T&& arg) noexcept
    {
        return static_cast<RemoveReferenceT<T>&&>(arg);
    }

    template<typename T>
    constexpr T&& forward(RemoveReferenceT<T>& arg) noexcept
    {
        return static_cast<T&&>(arg);
    }

    template<typename T>
    constexpr T&& forward(RemoveReferenceT<T>&& arg) noexcept
    {
        return static_cast<T&&>(arg);
    }

    template<typename T>
    void exchange(T& lhs, T& rhs) noexcept
    {
        T temp = coil::move(lhs);
        lhs = coil::move(rhs);
        rhs = coil::move(temp);
    }
}
