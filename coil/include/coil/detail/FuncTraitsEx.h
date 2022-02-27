#pragma once
#include "coil/Context.h"
#include "coil/utils/Types.h"
#include "coil/VariadicConsumer.h"

namespace coil::detail
{
    template<typename... Args>
    struct ArgsCounters
    {
        static constexpr std::size_t minArgs = (VariadicConsumer<std::decay_t<Args>>::minArgs + ... + 0);
        static constexpr bool isUnlimited = (VariadicConsumer<std::decay_t<Args>>::isUnlimitedArgs || ... || false);
        static constexpr std::size_t maxArgs = (VariadicConsumer<std::decay_t<Args>>::maxArgs + ... + 0);
        static_assert(maxArgs >= minArgs || isUnlimited, "For finite arguments maxArgs should not be less than minArgs");
    };

    template<typename Types>
    struct ArgsTraits;

    template<typename... Tail>
    struct ArgsTraits<utils::Types<Context, Tail...>> : ArgsCounters<Tail...>
    {
        using UserArgumentTypes = utils::Types<Tail...>;
        using NonUserArgsIndices = std::index_sequence<0>;
    };

    template<typename... Args>
    struct ArgsTraits<utils::Types<Args...>> : ArgsCounters<Args...>
    {
        using UserArgumentTypes = utils::Types<Args...>;
        using NonUserArgsIndices = std::index_sequence<>;
    };

    //////////////////////////////////////////////////////////////////////////

    template<typename Func>
    struct FuncTraitsEx : public utils::FuncTraits<Func>
    {
        using Base = utils::FuncTraits<Func>;
        using ArgsTraits = ArgsTraits<typename Base::ArgumentTypes>;
    };
}