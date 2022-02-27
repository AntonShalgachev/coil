#pragma once
#include "coil/Context.h"
#include "coil/Types.h"
#include "coil/VariadicConsumer.h"

#include <type_traits>

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

    template<typename... Args>
    struct ArgsTraits : ArgsCounters<Args...>
    {
        using UserArgumentTypes = Types<Args...>;
        using NonUserArgsIndices = std::index_sequence<>;
    };

    template<typename... Tail>
    struct ArgsTraits<Context, Tail...> : ArgsCounters<Tail...>
    {
        using UserArgumentTypes = Types<Tail...>;
        using NonUserArgsIndices = std::index_sequence<0>;
    };

    template<bool IsConst, typename R, typename... Args>
    struct BaseFuncTraits
    {
    public:
        static constexpr bool isFunc = true;

        using ReturnType = R;
        using ArgumentTypes = Types<Args...>;
        using ArgsTraits = ArgsTraits<Args...>;
        static constexpr bool isConst = IsConst;
    };

    // General types
    template<typename Func>
    struct FuncTraitsImpl
    {
        static constexpr bool isFunc = false;
    };

    // Free functions
    template<typename R, typename... Args>
    struct FuncTraitsImpl<R(*)(Args...)> : public BaseFuncTraits<false, R, Args...> {};
    template<typename R, typename... Args>
    struct FuncTraitsImpl<R(*)(Args...) noexcept> : public BaseFuncTraits<false, R, Args...> {};

    // Pointer to member function
#define COIL_MEMBER_FUNCTION_SPECIALIZATION(QUALIFIERS, IS_CONST) \
    template<typename R, typename T, typename... Args> \
    struct FuncTraitsImpl<R(T::*)(Args...) QUALIFIERS> : public BaseFuncTraits<IS_CONST, R, Args...> {}

    COIL_MEMBER_FUNCTION_SPECIALIZATION(, false);
    COIL_MEMBER_FUNCTION_SPECIALIZATION(volatile, false);
    COIL_MEMBER_FUNCTION_SPECIALIZATION(&, false);
    COIL_MEMBER_FUNCTION_SPECIALIZATION(volatile&, false);
    COIL_MEMBER_FUNCTION_SPECIALIZATION(&&, false);
    COIL_MEMBER_FUNCTION_SPECIALIZATION(volatile&&, false);
    COIL_MEMBER_FUNCTION_SPECIALIZATION(noexcept, false);
    COIL_MEMBER_FUNCTION_SPECIALIZATION(volatile noexcept, false);
    COIL_MEMBER_FUNCTION_SPECIALIZATION(&noexcept, false);
    COIL_MEMBER_FUNCTION_SPECIALIZATION(volatile& noexcept, false);
    COIL_MEMBER_FUNCTION_SPECIALIZATION(&& noexcept, false);
    COIL_MEMBER_FUNCTION_SPECIALIZATION(volatile&& noexcept, false);

    COIL_MEMBER_FUNCTION_SPECIALIZATION(const, true);
    COIL_MEMBER_FUNCTION_SPECIALIZATION(const volatile, true);
    COIL_MEMBER_FUNCTION_SPECIALIZATION(const&, true);
    COIL_MEMBER_FUNCTION_SPECIALIZATION(const volatile&, true);
    COIL_MEMBER_FUNCTION_SPECIALIZATION(const&&, true);
    COIL_MEMBER_FUNCTION_SPECIALIZATION(const volatile&&, true);
    COIL_MEMBER_FUNCTION_SPECIALIZATION(const noexcept, true);
    COIL_MEMBER_FUNCTION_SPECIALIZATION(const volatile noexcept, true);
    COIL_MEMBER_FUNCTION_SPECIALIZATION(const& noexcept, true);
    COIL_MEMBER_FUNCTION_SPECIALIZATION(const volatile& noexcept, true);
    COIL_MEMBER_FUNCTION_SPECIALIZATION(const&& noexcept, true);
    COIL_MEMBER_FUNCTION_SPECIALIZATION(const volatile&& noexcept, true);

#undef COIL_MEMBER_FUNCTION_SPECIALIZATION

    template<typename Func, typename = void>
    struct FuncTraits : FuncTraitsImpl<Func> {};

    // TODO support qualified operator()
    // TODO use C++20 concepts
    template<typename Func>
    struct FuncTraits<Func, std::void_t<decltype(&Func::operator())>> : public FuncTraitsImpl<decltype(&Func::operator())> {};
}
