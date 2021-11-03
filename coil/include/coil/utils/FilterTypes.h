#pragma once

namespace utils
{
    template<typename FilteredTypes, template<typename> typename Pred, typename Types, typename = void>
    struct FilterTypesImpl;

    template<template<typename> typename Pred, typename Head, typename... Tail, typename... FilteredTs>
    struct FilterTypesImpl<utils::Types<FilteredTs...>, Pred, utils::Types<Head, Tail...>, std::enable_if_t<Pred<Head>::value>> : public FilterTypesImpl<utils::Types<FilteredTs..., Head>, Pred, utils::Types<Tail...>> {};

    template<template<typename> typename Pred, typename Head, typename... Tail, typename... FilteredTs>
    struct FilterTypesImpl<utils::Types<FilteredTs...>, Pred, utils::Types<Head, Tail...>, std::enable_if_t<!Pred<Head>::value>> : public FilterTypesImpl<utils::Types<FilteredTs...>, Pred, utils::Types<Tail...>> {};

    template<typename FilteredTypes, template<typename> typename Pred>
    struct FilterTypesImpl<FilteredTypes, Pred, utils::Types<>>
    {
        using Types = FilteredTypes;
    };

    template<template<typename> typename Pred, typename Types>
    struct FilterTypes : public FilterTypesImpl<utils::Types<>, Pred, Types> {};

    template<template<typename> typename Pred, typename Types>
    using FilterTypesT = typename FilterTypes<Pred, Types>::Types;
}
