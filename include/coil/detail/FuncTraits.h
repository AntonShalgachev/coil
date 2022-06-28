#pragma once
#include "../Context.h"
#include "../Types.h"

#include <type_traits>

namespace coil::detail
{
    template<typename... Args>
    class FunctionWrapper;

    template<bool IsConst, typename R, typename... Args>
    struct BaseFuncTraits
    {
    public:
        static constexpr bool isFunc = true;

        using ReturnType = std::decay_t<R>;
        using FunctionWrapperType = FunctionWrapper<Args...>;
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
    struct FuncTraitsImpl<R (*)(Args...)> : public BaseFuncTraits<false, R, Args...>
    {
    };
    template<typename R, typename... Args>
    struct FuncTraitsImpl<R (*)(Args...) noexcept> : public BaseFuncTraits<false, R, Args...>
    {
    };

    // Pointer to member function
#define COIL_MEMBER_FUNCTION_SPECIALIZATION(QUALIFIERS, IS_CONST)                                     \
    template<typename R, typename T, typename... Args>                                                \
    struct FuncTraitsImpl<R (T::*)(Args...) QUALIFIERS> : public BaseFuncTraits<IS_CONST, R, Args...> \
    {                                                                                                 \
    }

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
    COIL_MEMBER_FUNCTION_SPECIALIZATION(&&noexcept, false);
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
    struct FuncTraits : FuncTraitsImpl<Func>
    {
    };

    template<typename Func>
    struct FuncTraits<Func, std::void_t<decltype(&Func::operator())>> : public FuncTraitsImpl<decltype(&Func::operator())>
    {
    };
}
