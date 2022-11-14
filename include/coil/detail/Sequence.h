#pragma once

#include <stddef.h>

namespace coil
{
    template<typename Type, Type... Is>
    struct IntegerSequence
    {
    };

    template<size_t... Is>
    using IndexSequence = IntegerSequence<size_t, Is...>;

#if defined(__clang__) || defined(_MSC_VER)
    template<size_t size>
    using MakeIndexSequence = __make_integer_seq<IntegerSequence, size_t, size>;
#elif defined(__GNUC__) && __has_builtin(__make_integer_seq)
    template<size_t size>
    using MakeIndexSequence = __make_integer_seq<IntegerSequence, size_t, size>;
#elif defined(__GNUC__)
    template<size_t size>
    using MakeIndexSequence = IntegerSequence<size_t, __integer_pack(size)...>;
#endif
}
