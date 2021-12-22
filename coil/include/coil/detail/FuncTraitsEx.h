#pragma once
#include "coil/Context.h"
#include "coil/utils/TrueIndices.h"
#include "coil/utils/Types.h"

namespace coil::detail
{
    // TODO move to another file
    // TODO allow specialization
    template<typename T>
    struct ArgCountTraits
    {
        static constexpr std::size_t min = 1;
        static constexpr bool isUnlimited = false;
        static constexpr std::size_t max = 1;
    };
    template<typename T>
    struct ArgCountTraits<std::vector<T>>
    {
        static constexpr std::size_t min = 0;
        static constexpr bool isUnlimited = true;
        static constexpr std::size_t max = 0;
    };
    template<typename T>
    struct ArgCountTraits<std::optional<T>>
    {
        static constexpr std::size_t min = 0;
        static constexpr bool isUnlimited = false;
        static constexpr std::size_t max = 1;
    };
    template<>
    struct ArgCountTraits<Context>
    {
        static constexpr std::size_t min = 0;
        static constexpr bool isUnlimited = false;
        static constexpr std::size_t max = 0;
    };

    template<typename T>
    struct NonUserArgTraits
    {
        static constexpr bool isContext = std::is_same_v<T, Context>;
    };

    template<typename, typename... Args>
    struct UserArgumentsGetter
    {
        using Types = utils::Types<Args...>;
    };
    template<typename... Args>
    struct UserArgumentsGetter<void, Context, Args...>
    {
        using Types = utils::Types<Args...>;
    };
    template<typename... Args>
    struct UserArgumentsGetter<void, Context&, Args...>
    {
        using Types = utils::Types<Args...>;
    };
    template<typename... Args>
    struct UserArgumentsGetter<void, Context const&, Args...>
    {
        using Types = utils::Types<Args...>;
    };

    //////////////////////////////////////////////////////////////////////////

    template<typename... Args>
    struct ArgsCounters
    {
        static constexpr std::size_t minArgs = (ArgCountTraits<std::decay_t<Args>>::min + ... + 0);
        static constexpr bool isUnlimited = (ArgCountTraits<std::decay_t<Args>>::isUnlimited || ...);
        static constexpr std::size_t maxArgs = (ArgCountTraits<std::decay_t<Args>>::max + ... + 0);
        static_assert(maxArgs >= minArgs || isUnlimited, "For finite arguments maxArgs should not be less than minArgs");
    };

    template<typename Types>
    struct ArgsTraits;

    template<typename T, typename... Tail>
    struct ArgsTraits<utils::Types<T*, Tail...>> : ArgsCounters<Tail...>
    {
        using UserArgumentTypes = typename UserArgumentsGetter<void, Tail...>::Types;

        static constexpr bool hasExplicitTarget = true;
        using ExplicitTargetType = T;

        static constexpr bool hasContext = (NonUserArgTraits<std::decay_t<Tail>>::isContext || ...);

        template<bool IsMethod>
        using NonUserArgsIndices = utils::TrueIndicesT<IsMethod || hasExplicitTarget, hasContext>;
    };

    template<typename Head, typename... Tail>
    struct ArgsTraits<utils::Types<Head, Tail...>> : ArgsCounters<Head, Tail...>
    {
        using UserArgumentTypes = typename UserArgumentsGetter<void, Head, Tail...>::Types;

        static constexpr bool hasExplicitTarget = false;
        using ExplicitTargetType = void;

        static constexpr bool hasContext = NonUserArgTraits<std::decay_t<Head>>::isContext || (NonUserArgTraits<std::decay_t<Tail>>::isContext || ...);

        template<bool IsMethod>
        using NonUserArgsIndices = utils::TrueIndicesT<IsMethod || hasExplicitTarget, hasContext>;
    };

    template<>
    struct ArgsTraits<utils::Types<>> : ArgsCounters<>
    {
        using UserArgumentTypes = utils::Types<>;

        static constexpr bool hasExplicitTarget = false;
        using ExplicitTargetType = void;

        static constexpr bool hasContext = false;

        template<bool IsMethod>
        using NonUserArgsIndices = utils::TrueIndicesT<IsMethod || hasExplicitTarget, hasContext>;
    };

    //////////////////////////////////////////////////////////////////////////

    template<typename Func>
    struct FuncTraitsEx : public utils::FuncTraits<Func>
    {
        using Base = utils::FuncTraits<Func>;
        using ArgsTraits = ArgsTraits<typename Base::ArgumentTypes>;
    };
}