#pragma once

namespace coil::utils
{
    // indices where Bs are true
    template<typename IndexSequence, std::size_t Index, typename BoolSequence, typename = void>
    struct TrueIndicesImpl;

    template<std::size_t... Is, std::size_t Index, bool Head, bool... Tail>
    struct TrueIndicesImpl<std::index_sequence<Is...>, Index, std::integer_sequence<bool, Head, Tail...>, std::enable_if_t<Head>> : TrueIndicesImpl<std::index_sequence<Is..., Index>, Index + 1, std::integer_sequence<bool, Tail...>> {};

    template<std::size_t... Is, std::size_t Index, bool Head, bool... Tail>
    struct TrueIndicesImpl<std::index_sequence<Is...>, Index, std::integer_sequence<bool, Head, Tail...>, std::enable_if_t<!Head>> : TrueIndicesImpl<std::index_sequence<Is...>, Index + 1, std::integer_sequence<bool, Tail...>> {};

    template<typename IndexSequence, std::size_t Index>
    struct TrueIndicesImpl<IndexSequence, Index, std::integer_sequence<bool>>
    {
        using SequenceType = IndexSequence;
    };

    template<bool... Bs>
    struct TrueIndices : TrueIndicesImpl<std::index_sequence<>, 0, std::integer_sequence<bool, Bs...>> {};

    template<bool... Bs>
    using TrueIndicesT = typename TrueIndices<Bs...>::SequenceType;
}
