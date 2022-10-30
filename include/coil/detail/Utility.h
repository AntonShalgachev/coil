#pragma once

#include "TypeTraits.h"

#include <stddef.h>

namespace coil
{
    // TODO split into several headers?

    // TODO fix case
    template <typename T>
    constexpr RemoveReferenceT<T>&& Move(T&& arg) noexcept
    {
        return static_cast<RemoveReferenceT<T>&&>(arg);
    }

    // TODO fix case
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

    template<typename T>
    void exchange(T& lhs, T& rhs) noexcept
    {
        T temp = Move(lhs);
        lhs = Move(rhs);
        rhs = Move(temp);
    }

    template<typename Type, Type... Is>
    struct IntegerSequence {};

    template<size_t... Is>
    using IndexSequence = IntegerSequence<size_t, Is...>;

#if defined(__clang__) || defined(_MSC_VER)
    template <size_t size>
    using MakeIndexSequence = __make_integer_seq<IntegerSequence, size_t, size>;
#elif defined(__GNUC__) && __has_builtin(__make_integer_seq)
    template <size_t size>
    using MakeIndexSequence = __make_integer_seq<IntegerSequence, size_t, size>;
#elif defined(__GNUC__)
    template <size_t size>
    using MakeIndexSequence = IntegerSequence<size_t, __integer_pack(size)...>;
#endif
}
