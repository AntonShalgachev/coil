#pragma once
#include "coil/Context.h"
#include "coil/NamedArgs.h"

namespace coil::detail
{
    template<typename Types, bool HasTarget, typename ExplicitTargetT, bool HasContext, bool HasNamedArgs>
    struct ArgumentTraitsImpl {};

    template<typename T, typename... Args, bool HasTarget, typename ExplicitTargetT, bool HasContext, bool HasNamedArgs>
    struct ArgumentTraitsImpl<utils::Types<T*, Args...>, HasTarget, ExplicitTargetT, HasContext, HasNamedArgs> : public ArgumentTraitsImpl<utils::Types<Args...>, true, T, HasContext, HasNamedArgs> {};

    template<typename... Args, bool HasTarget, typename ExplicitTargetT, bool HasContext, bool HasNamedArgs>
    struct ArgumentTraitsImpl<utils::Types<Context, Args...>, HasTarget, ExplicitTargetT, HasContext, HasNamedArgs> : public ArgumentTraitsImpl<utils::Types<Args...>, HasTarget, ExplicitTargetT, true, HasNamedArgs> {};

    template<typename... Args, bool HasTarget, typename ExplicitTargetT, bool HasContext, bool HasNamedArgs>
    struct ArgumentTraitsImpl<utils::Types<Context&, Args...>, HasTarget, ExplicitTargetT, HasContext, HasNamedArgs> : public ArgumentTraitsImpl<utils::Types<Args...>, HasTarget, ExplicitTargetT, true, HasNamedArgs> {};

    template<typename... Args, bool HasTarget, typename ExplicitTargetT, bool HasContext, bool HasNamedArgs>
    struct ArgumentTraitsImpl<utils::Types<Context const&, Args...>, HasTarget, ExplicitTargetT, HasContext, HasNamedArgs> : public ArgumentTraitsImpl<utils::Types<Args...>, HasTarget, ExplicitTargetT, true, HasNamedArgs> {};

    template<typename... Args, bool HasTarget, typename ExplicitTargetT, bool HasContext, bool HasNamedArgs>
    struct ArgumentTraitsImpl<utils::Types<NamedArgs, Args...>, HasTarget, ExplicitTargetT, HasContext, HasNamedArgs> : public ArgumentTraitsImpl<utils::Types<Args...>, HasTarget, ExplicitTargetT, HasContext, true> {};

    template<typename... Args, bool HasTarget, typename ExplicitTargetT, bool HasContext, bool HasNamedArgs>
    struct ArgumentTraitsImpl<utils::Types<NamedArgs&, Args...>, HasTarget, ExplicitTargetT, HasContext, HasNamedArgs> : public ArgumentTraitsImpl<utils::Types<Args...>, HasTarget, ExplicitTargetT, HasContext, true> {};

    template<typename... Args, bool HasTarget, typename ExplicitTargetT, bool HasContext, bool HasNamedArgs>
    struct ArgumentTraitsImpl<utils::Types<NamedArgs const&, Args...>, HasTarget, ExplicitTargetT, HasContext, HasNamedArgs> : public ArgumentTraitsImpl<utils::Types<Args...>, HasTarget, ExplicitTargetT, HasContext, true> {};

    template<typename... Args, bool HasTarget, typename ExplicitTargetT, bool HasContext, bool HasNamedArgs>
    struct ArgumentTraitsImpl<utils::Types<Args...>, HasTarget, ExplicitTargetT, HasContext, HasNamedArgs>
    {
        using UserArgumentTypes = utils::Types<Args...>;
        using ExplicitTargetType = ExplicitTargetT;
        static bool constexpr hasTarget = HasTarget;
        static bool constexpr hasContext = HasContext;
        static bool constexpr hasNamedArgs = HasNamedArgs;
    };

    template<typename Func>
    struct FuncTraitsEx : public utils::FuncTraits<Func>
    {
    private:
        using Base = utils::FuncTraits<Func>;
        using ArgumentTraits = ArgumentTraitsImpl<typename Base::ArgumentTypes, false, void, false, false>;

    public:
        using UserArgumentTypes = typename ArgumentTraits::UserArgumentTypes;
        using ExplicitTargetType = typename ArgumentTraits::ExplicitTargetType;
        static bool constexpr hasTarget = ArgumentTraits::hasTarget;
        static bool constexpr hasContext = ArgumentTraits::hasContext;
        static bool constexpr hasNamedArgs = ArgumentTraits::hasNamedArgs;
    };
}