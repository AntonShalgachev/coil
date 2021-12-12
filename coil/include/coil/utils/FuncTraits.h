#pragma once

#include "Types.h"
#include <type_traits>

namespace coil::utils
{
    template<typename R, typename T, bool IsObject, bool IsConst, typename... Args>
    struct BaseFuncTraits
    {
    public:
        static constexpr bool isFunc = true;

        using ReturnType = R;
        using ObjectType = T; // void if free/static function, T if it's a method of type T
        using ArgumentTypes = Types<Args...>;

        static constexpr bool isConst = IsConst;
        static constexpr bool isObject = IsObject;
        static const bool isMethod = !isObject && !std::is_void_v<ObjectType>;

        template<typename U>
        static const bool isMethodOfType = !isObject && !std::is_void_v<U> && std::is_same_v<ObjectType, U>;
    };

    // General types
    template<typename T, bool IsObject>
    struct FuncTraitsImpl
    {
        static constexpr bool isFunc = false;
    };

    // Free functions
    template<typename R, typename... Args, bool IsObject>
    struct FuncTraitsImpl<R(*)(Args...), IsObject> : public BaseFuncTraits<R, void, IsObject, false, Args...> {};
    template<typename R, typename... Args, bool IsObject>
    struct FuncTraitsImpl<R(*)(Args...) noexcept, IsObject> : public BaseFuncTraits<R, void, IsObject, false, Args...> {};

    // Pointer to member function
#define COIL_MEMBER_FUNCTION_SPECIALIZATION(QUALIFIERS, IS_CONST) \
    template<typename R, typename T, typename... Args, bool IsObject> \
    struct FuncTraitsImpl<R(T::*)(Args...) QUALIFIERS, IsObject> : public BaseFuncTraits<R, T, IsObject, IS_CONST, Args...> {}

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

    template<typename T, typename = void>
    struct FuncTraits : FuncTraitsImpl<T, false> {};

    // TODO support qualified operator()
    template<typename T>
    struct FuncTraits<T, std::void_t<decltype(&T::operator())>> : public FuncTraitsImpl<decltype(&T::operator()), true> {};
}
