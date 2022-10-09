#pragma once

#include "TypeTraits.h"

#include <cstddef>

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

    template<typename Type, Type... Is>
    struct IntegerSequence {};

    template<std::size_t... Is>
    using IndexSequence = IntegerSequence<std::size_t, Is...>;

#if defined(__clang__) || defined(_MSC_VER)
    template <std::size_t size>
    using MakeIndexSequence = __make_integer_seq<IntegerSequence, std::size_t, size>;
#elif defined(__GNUC__) && __has_builtin(__make_integer_seq)
    template <std::size_t size>
    using MakeIndexSequence = __make_integer_seq<IntegerSequence, std::size_t, size>;
#elif defined(__GNUC__)
    template <std::size_t size>
    using MakeIndexSequence = IntegerSequence<std::size_t, __integer_pack(size)...>;
#endif
}
