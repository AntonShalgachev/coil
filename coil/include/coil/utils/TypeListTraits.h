#pragma once

namespace utils
{
    template<std::size_t HeadIndex, template<typename> typename Pred, typename Types, typename = void>
    struct TypeListTraitsImpl;

    template<std::size_t HeadIndex, template<typename> typename Pred, typename Head, typename... Tail>
    struct TypeListTraitsImpl<HeadIndex, Pred, utils::Types<Head, Tail...>, std::enable_if_t<Pred<Head>::value>>
    {
        static constexpr bool isPresent = true;
        static constexpr std::size_t index = HeadIndex;
        using Type = Head;
    };

    template<std::size_t HeadIndex, template<typename> typename Pred, typename Head, typename... Tail>
    struct TypeListTraitsImpl<HeadIndex, Pred, utils::Types<Head, Tail...>, std::enable_if_t<!Pred<Head>::value>> : public TypeListTraitsImpl<HeadIndex + 1, Pred, utils::Types<Tail...>> {};

    template<std::size_t HeadIndex, template<typename> typename Pred>
    struct TypeListTraitsImpl<HeadIndex, Pred, utils::Types<>>
    {
        static constexpr bool isPresent = false;
    };

    template<template<typename> typename Pred, typename Types>
    struct TypeListTraits : public TypeListTraitsImpl<0, Pred, Types> {};
}
