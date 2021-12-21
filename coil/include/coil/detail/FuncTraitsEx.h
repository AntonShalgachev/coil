#pragma once
#include "coil/Context.h"
#include "coil/NamedArgs.h"
#include "coil/utils/TrueIndices.h"

namespace coil::detail
{
    // template<typename Types, bool HasTarget, typename ExplicitTargetT, bool HasContext, bool HasNamedArgs>
    // struct ArgumentTraitsImpl {};

    template<bool HasTarget, typename ExplicitTargetT, bool HasContext, bool HasNamedArgs, typename... Args>
    struct ArgumentTraitsImpl
    {
        using UserArgumentTypes = utils::Types<Args...>;
        using ExplicitTargetType = ExplicitTargetT;
        static bool constexpr hasTarget = HasTarget;
        static bool constexpr hasContext = HasContext;
        static bool constexpr hasNamedArgs = HasNamedArgs;
    };

    template<bool HasTarget, typename ExplicitTargetT, bool HasContext, bool HasNamedArgs, typename T, typename... Args>
    struct ArgumentTraitsImpl<HasTarget, ExplicitTargetT, HasContext, HasNamedArgs, T*, Args...> : public ArgumentTraitsImpl<true, T, HasContext, HasNamedArgs, Args...> {};

    template<bool HasTarget, typename ExplicitTargetT, bool HasContext, bool HasNamedArgs, typename... Args>
    struct ArgumentTraitsImpl<HasTarget, ExplicitTargetT, HasContext, HasNamedArgs, Context, Args...> : public ArgumentTraitsImpl<HasTarget, ExplicitTargetT, true, HasNamedArgs, Args...> {};

    template<bool HasTarget, typename ExplicitTargetT, bool HasContext, bool HasNamedArgs, typename... Args>
    struct ArgumentTraitsImpl<HasTarget, ExplicitTargetT, HasContext, HasNamedArgs, Context&, Args...> : public ArgumentTraitsImpl<HasTarget, ExplicitTargetT, true, HasNamedArgs, Args...> {};

    template<bool HasTarget, typename ExplicitTargetT, bool HasContext, bool HasNamedArgs, typename... Args>
    struct ArgumentTraitsImpl<HasTarget, ExplicitTargetT, HasContext, HasNamedArgs, Context const&, Args...> : public ArgumentTraitsImpl<HasTarget, ExplicitTargetT, true, HasNamedArgs, Args...> {};

    template<bool HasTarget, typename ExplicitTargetT, bool HasContext, bool HasNamedArgs, typename... Args>
    struct ArgumentTraitsImpl<HasTarget, ExplicitTargetT, HasContext, HasNamedArgs, NamedArgs, Args...> : public ArgumentTraitsImpl<HasTarget, ExplicitTargetT, HasContext, true, Args...> {};

    template<bool HasTarget, typename ExplicitTargetT, bool HasContext, bool HasNamedArgs, typename... Args>
    struct ArgumentTraitsImpl<HasTarget, ExplicitTargetT, HasContext, HasNamedArgs, NamedArgs&, Args...> : public ArgumentTraitsImpl<HasTarget, ExplicitTargetT, HasContext, true, Args...> {};

    template<bool HasTarget, typename ExplicitTargetT, bool HasContext, bool HasNamedArgs, typename... Args>
    struct ArgumentTraitsImpl<HasTarget, ExplicitTargetT, HasContext, HasNamedArgs, NamedArgs const&, Args...> : public ArgumentTraitsImpl<HasTarget, ExplicitTargetT, HasContext, true, Args...> {};

    //////////////////////////////////////////////////////////////////////////

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

    template<std::size_t currentMin, bool isUnlimited, std::size_t currentMax, typename... Args>
    struct VariadicArgsTraitsImpl;

    template<std::size_t currentMin, bool isUnlimited, std::size_t currentMax, typename Head, typename... Tail>
    struct VariadicArgsTraitsImpl<currentMin, isUnlimited, currentMax, Head, Tail...> : VariadicArgsTraitsImpl<currentMin + ArgCountTraits<std::decay_t<Head>>::min, isUnlimited || ArgCountTraits<std::decay_t<Head>>::isUnlimited, currentMax + ArgCountTraits<std::decay_t<Head>>::max, Tail...> {};

    template<std::size_t currentMin, bool currentIsUnlimited, std::size_t currentMax>
    struct VariadicArgsTraitsImpl<currentMin, currentIsUnlimited, currentMax>
    {
        static_assert(currentMax >= currentMin || currentIsUnlimited, "For unlimited arguments currentMax should not be less than currentMin");

        static constexpr std::size_t minArgs = currentMin;
        static constexpr bool isUnlimited = currentIsUnlimited;
        static constexpr std::size_t maxArgs = currentMax;
    };

    //////////////////////////////////////////////////////////////////////////

    template<typename Types>
    struct ArgsTraits;

    template<typename... Args>
    struct ArgsTraits<utils::Types<Args...>>
    {
        using VariadicTraits = VariadicArgsTraitsImpl<0, false, 0, Args...>;
        static constexpr std::size_t minArgs = VariadicTraits::minArgs;
        static constexpr bool isUnlimited = VariadicTraits::isUnlimited;
        static constexpr std::size_t maxArgs = VariadicTraits::maxArgs;

        using ArgumentTraits = ArgumentTraitsImpl<false, void, false, false, Args...>;
        using UserArgumentTypes = typename ArgumentTraits::UserArgumentTypes;
        using ExplicitTargetType = typename ArgumentTraits::ExplicitTargetType;
        static bool constexpr hasTarget = ArgumentTraits::hasTarget;
        static bool constexpr hasContext = ArgumentTraits::hasContext;
        static bool constexpr hasNamedArgs = ArgumentTraits::hasNamedArgs;

        template<bool IsMethod>
        using NonUserArgsIndices = utils::TrueIndicesT<IsMethod || hasTarget, hasContext, hasNamedArgs>;
    };

    //////////////////////////////////////////////////////////////////////////

    template<typename Func>
    struct FuncTraitsEx : public utils::FuncTraits<Func>
    {
        using Base = utils::FuncTraits<Func>;
        using ArgsTraits = ArgsTraits<typename Base::ArgumentTypes>;
    };
}