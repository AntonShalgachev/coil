#pragma once

#include "Types.h"
#include <type_traits>

namespace coil::utils
{
    template<typename R, typename... Args>
    struct BaseFuncTraits
    {
    public:
        static constexpr bool isFunc = true;

        using ReturnType = R;
        using ArgumentTypes = Types<Args...>;
    };

    // General types
    template<typename Func>
    struct FuncTraitsImpl
    {
        static constexpr bool isFunc = false;
    };

    // Free functions
    template<typename R, typename... Args>
    struct FuncTraitsImpl<R(*)(Args...)> : public BaseFuncTraits<R, Args...> {};
    template<typename R, typename... Args>
    struct FuncTraitsImpl<R(*)(Args...) noexcept> : public BaseFuncTraits<R, Args...> {};

    // Pointer to member function
#define COIL_MEMBER_FUNCTION_SPECIALIZATION(QUALIFIERS) \
    template<typename R, typename T, typename... Args> \
    struct FuncTraitsImpl<R(T::*)(Args...) QUALIFIERS> : public BaseFuncTraits<R, Args...> {}

#pragma warning(push)
#pragma warning(disable: 4003) // to allow calling macro with no arguments

    COIL_MEMBER_FUNCTION_SPECIALIZATION();
    COIL_MEMBER_FUNCTION_SPECIALIZATION(volatile);
    COIL_MEMBER_FUNCTION_SPECIALIZATION(&);
    COIL_MEMBER_FUNCTION_SPECIALIZATION(volatile&);
    COIL_MEMBER_FUNCTION_SPECIALIZATION(&&);
    COIL_MEMBER_FUNCTION_SPECIALIZATION(volatile&&);
    COIL_MEMBER_FUNCTION_SPECIALIZATION(noexcept);
    COIL_MEMBER_FUNCTION_SPECIALIZATION(volatile noexcept);
    COIL_MEMBER_FUNCTION_SPECIALIZATION(&noexcept);
    COIL_MEMBER_FUNCTION_SPECIALIZATION(volatile& noexcept);
    COIL_MEMBER_FUNCTION_SPECIALIZATION(&& noexcept);
    COIL_MEMBER_FUNCTION_SPECIALIZATION(volatile&& noexcept);

    COIL_MEMBER_FUNCTION_SPECIALIZATION(const);
    COIL_MEMBER_FUNCTION_SPECIALIZATION(const volatile);
    COIL_MEMBER_FUNCTION_SPECIALIZATION(const&);
    COIL_MEMBER_FUNCTION_SPECIALIZATION(const volatile&);
    COIL_MEMBER_FUNCTION_SPECIALIZATION(const&&);
    COIL_MEMBER_FUNCTION_SPECIALIZATION(const volatile&&);
    COIL_MEMBER_FUNCTION_SPECIALIZATION(const noexcept);
    COIL_MEMBER_FUNCTION_SPECIALIZATION(const volatile noexcept);
    COIL_MEMBER_FUNCTION_SPECIALIZATION(const& noexcept);
    COIL_MEMBER_FUNCTION_SPECIALIZATION(const volatile& noexcept);
    COIL_MEMBER_FUNCTION_SPECIALIZATION(const&& noexcept);
    COIL_MEMBER_FUNCTION_SPECIALIZATION(const volatile&& noexcept);

#pragma warning(pop)

#undef COIL_MEMBER_FUNCTION_SPECIALIZATION

    template<typename Func, typename = void>
    struct FuncTraits : FuncTraitsImpl<Func> {};

    // TODO support qualified operator()
    template<typename Func>
    struct FuncTraits<Func, std::void_t<decltype(&Func::operator())>> : public FuncTraitsImpl<decltype(&Func::operator())> {};
}
