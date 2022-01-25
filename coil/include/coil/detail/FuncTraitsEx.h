#pragma once
#include "coil/Context.h"
#include "coil/utils/Types.h"
#include "coil/VariadicConsumer.h"

namespace coil::detail
{
    // VS2017 can't handle fold expressions directly inside ArgsCounters
    template<typename... Args>
    constexpr auto sumArgs(Args&&... args)
    {
        return (0 + ... + args);
    }
    template<typename... Args>
    constexpr bool orArgs(Args&&... args)
    {
        return (false || ... || args);
    }

    template<typename... Args>
    struct ArgsCounters
    {
        static constexpr std::size_t minArgs = sumArgs(VariadicConsumer<std::decay_t<Args>>::minArgs...);
        static constexpr bool isUnlimited = orArgs(VariadicConsumer<std::decay_t<Args>>::isUnlimitedArgs...);
        static constexpr std::size_t maxArgs = sumArgs(VariadicConsumer<std::decay_t<Args>>::maxArgs...);
        static_assert(maxArgs >= minArgs || isUnlimited, "For finite arguments maxArgs should not be less than minArgs");
    };

    template<bool HasExplicitTarget, typename T>
    struct NonUserArgsTraits
    {
        static constexpr bool hasExplicitTarget = HasExplicitTarget;
        using ExplicitTargetType = T;
    };

    template<typename Types>
    struct ArgsTraits;

    template<typename T, typename... Tail>
    struct ArgsTraits<utils::Types<T*, Tail...>> : ArgsCounters<Tail...>, NonUserArgsTraits<true, T>
    {
        using UserArgumentTypes = utils::Types<Tail...>;

        template<std::size_t... InitialIndices>
        using NonUserArgsIndices = std::index_sequence<InitialIndices..., 0>;
    };

    template<typename T, typename... Tail>
    struct ArgsTraits<utils::Types<T*, Context, Tail...>> : ArgsCounters<Tail...>, NonUserArgsTraits<true, T>
    {
        using UserArgumentTypes = utils::Types<Tail...>;

        template<std::size_t... InitialIndices>
        using NonUserArgsIndices = std::index_sequence<InitialIndices..., 0, 1>;
    };

    template<typename... Tail>
    struct ArgsTraits<utils::Types<Context, Tail...>> : ArgsCounters<Tail...>, NonUserArgsTraits<false, void>
    {
        using UserArgumentTypes = utils::Types<Tail...>;

        template<std::size_t... InitialIndices>
        using NonUserArgsIndices = std::index_sequence<InitialIndices..., 1>;
    };

    template<typename... Args>
    struct ArgsTraits<utils::Types<Args...>> : ArgsCounters<Args...>, NonUserArgsTraits<false, void>
    {
        using UserArgumentTypes = utils::Types<Args...>;

        template<std::size_t... InitialIndices>
        using NonUserArgsIndices = std::index_sequence<InitialIndices...>;
    };

    //////////////////////////////////////////////////////////////////////////

    template<typename Func>
    struct FuncTraitsEx : public utils::FuncTraits<Func>
    {
        using Base = utils::FuncTraits<Func>;
        using ArgsTraits = ArgsTraits<typename Base::ArgumentTypes>;
    };
}