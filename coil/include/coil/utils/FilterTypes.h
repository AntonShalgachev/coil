#pragma once

#include "Types.h"

namespace coil::utils
{
    template<typename FilteredTypes, template<typename> typename Pred, typename TypeList, typename = void>
    struct FilterTypesImpl;

    template<template<typename> typename Pred, typename Head, typename... Tail, typename... FilteredTs>
    struct FilterTypesImpl<Types<FilteredTs...>, Pred, Types<Head, Tail...>, std::enable_if_t<Pred<Head>::value>> : FilterTypesImpl<Types<FilteredTs..., Head>, Pred, Types<Tail...>> {};

    template<template<typename> typename Pred, typename Head, typename... Tail, typename... FilteredTs>
    struct FilterTypesImpl<Types<FilteredTs...>, Pred, Types<Head, Tail...>, std::enable_if_t<!Pred<Head>::value>> : FilterTypesImpl<Types<FilteredTs...>, Pred, Types<Tail...>> {};

    template<typename FilteredTypes, template<typename> typename Pred>
    struct FilterTypesImpl<FilteredTypes, Pred, Types<>>
    {
        using Types = FilteredTypes;
    };

    template<template<typename> typename Pred, typename TypeList>
    struct FilterTypes : FilterTypesImpl<Types<>, Pred, TypeList> {};

    template<template<typename> typename Pred, typename TypeList>
    using FilterTypesT = typename FilterTypes<Pred, TypeList>::Types;
}
