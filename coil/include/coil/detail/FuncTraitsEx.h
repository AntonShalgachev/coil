#pragma once
#include "coil/Context.h"
#include "coil/NamedArgs.h"
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
    template<>
    struct ArgCountTraits<NamedArgs>
    {
        static constexpr std::size_t min = 0;
        static constexpr bool isUnlimited = false;
        static constexpr std::size_t max = 0;
    };

    template<typename T>
    struct NonUserArgTraits
    {
        static constexpr bool isContext = std::is_same_v<T, Context>;
        static constexpr bool isNamedArgs = std::is_same_v<T, NamedArgs>;
    };

    template<typename T>
    constexpr bool isUserArg = !NonUserArgTraits<T>::isContext && !NonUserArgTraits<T>::isNamedArgs;

    template<typename, typename... Args>
    struct UserArgumentsGetter
    {
        using Types = utils::Types<Args...>;
    };

    template<typename Head, typename... Tail>
    struct UserArgumentsGetter<std::enable_if_t<isUserArg<std::decay_t<Head>>>, Head, Tail...>
    {
        using Types = utils::Types<Head, Tail...>;
    };
    template<typename Head, typename... Tail>
    struct UserArgumentsGetter<std::enable_if_t<!isUserArg<std::decay_t<Head>>>, Head, Tail...> : UserArgumentsGetter<void, Tail...> {};

    //////////////////////////////////////////////////////////////////////////

    template<typename Types>
    struct ArgsTraits;

    template<typename T, typename... Tail>
    struct ArgsTraits<utils::Types<T*, Tail...>>
    {
        using UserArgumentTypes = typename UserArgumentsGetter<void, Tail...>::Types;

        static constexpr bool hasExplicitTarget = true;
        using ExplicitTargetType = T;

        static constexpr std::size_t minArgs = (ArgCountTraits<std::decay_t<Tail>>::min + ... + 0);
        static constexpr bool isUnlimited = (ArgCountTraits<std::decay_t<Tail>>::isUnlimited || ...);
        static constexpr std::size_t maxArgs = (ArgCountTraits<std::decay_t<Tail>>::max + ... + 0);
        static_assert(maxArgs >= minArgs || isUnlimited, "For finite arguments maxArgs should not be less than minArgs");

        static constexpr bool hasContext = (NonUserArgTraits<std::decay_t<Tail>>::isContext || ...);
        static constexpr bool hasNamedArgs = (NonUserArgTraits<std::decay_t<Tail>>::isNamedArgs || ...);

        template<bool IsMethod>
        using NonUserArgsIndices = utils::TrueIndicesT<IsMethod || hasExplicitTarget, hasContext, hasNamedArgs>;
    };

    template<typename Head, typename... Tail>
    struct ArgsTraits<utils::Types<Head, Tail...>>
    {
        using UserArgumentTypes = typename UserArgumentsGetter<void, Head, Tail...>::Types;

        static constexpr bool hasExplicitTarget = false;
        using ExplicitTargetType = void;

        static constexpr std::size_t minArgs = ArgCountTraits<std::decay_t<Head>>::min + (ArgCountTraits<std::decay_t<Tail>>::min + ... + 0);
        static constexpr bool isUnlimited = ArgCountTraits<std::decay_t<Head>>::isUnlimited || (ArgCountTraits<std::decay_t<Tail>>::isUnlimited || ...);
        static constexpr std::size_t maxArgs = ArgCountTraits<std::decay_t<Head>>::max + (ArgCountTraits<std::decay_t<Tail>>::max + ... + 0);
        static_assert(maxArgs >= minArgs || isUnlimited, "For finite arguments maxArgs should not be less than minArgs");

        static constexpr bool hasContext = NonUserArgTraits<std::decay_t<Head>>::isContext || (NonUserArgTraits<std::decay_t<Tail>>::isContext || ...);
        static constexpr bool hasNamedArgs = NonUserArgTraits<std::decay_t<Head>>::isNamedArgs || (NonUserArgTraits<std::decay_t<Tail>>::isNamedArgs || ...);

        template<bool IsMethod>
        using NonUserArgsIndices = utils::TrueIndicesT<IsMethod || hasExplicitTarget, hasContext, hasNamedArgs>;
    };

    template<>
    struct ArgsTraits<utils::Types<>>
    {
        using UserArgumentTypes = utils::Types<>;

        static constexpr bool hasExplicitTarget = false;
        using ExplicitTargetType = void;

        static constexpr std::size_t minArgs = 0;
        static constexpr bool isUnlimited = false;
        static constexpr std::size_t maxArgs = 0;

        static constexpr bool hasContext = false;
        static constexpr bool hasNamedArgs = false;

        template<bool IsMethod>
        using NonUserArgsIndices = utils::TrueIndicesT<IsMethod || hasExplicitTarget, hasContext, hasNamedArgs>;
    };

    //////////////////////////////////////////////////////////////////////////

    template<typename Func>
    struct FuncTraitsEx : public utils::FuncTraits<Func>
    {
        using Base = utils::FuncTraits<Func>;
        using ArgsTraits = ArgsTraits<typename Base::ArgumentTypes>;
    };
}