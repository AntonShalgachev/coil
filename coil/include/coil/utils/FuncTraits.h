#pragma once

#include "Types.h"
#include <type_traits>

namespace coil::utils
{
	template<typename R, typename T, bool IsConst, typename... Args>
	struct BaseFuncTraits
    {
    public:
        static constexpr bool isFunc = true;

		using ReturnType = R;
		using ObjectType = T; // void if free/static function, T if it's a method of type T
		using ArgumentTypes = Types<Args...>;

        template<typename U>
        static const bool isMethodOfType = !std::is_void_v<U> && std::is_same_v<ObjectType, U>;

		static constexpr bool isConst = IsConst;
	};

    // General types
    template<typename T, typename = void>
    struct FuncTraits
    {
        static constexpr bool isFunc = false;
    };

    // TODO support qualified operator()
    template<typename T>
    struct FuncTraits<T, std::void_t<decltype(&T::operator())>>
        : public FuncTraits<decltype(&T::operator())> {};

    // Free functions
    template<typename R, typename... Args>
    struct FuncTraits<R(*)(Args...), void> : public BaseFuncTraits<R, void, false, Args...> {};
    template<typename R, typename... Args>
    struct FuncTraits<R(*)(Args...) noexcept, void> : public BaseFuncTraits<R, void, false, Args...> {};

	// Pointer to member function
#define COIL_MEMBER_FUNCTION_SPECIALIZATION(QUALIFIERS, IS_CONST) \
    template<typename R, typename T, typename... Args> \
    struct FuncTraits<R(T::*)(Args...) QUALIFIERS, void> : public BaseFuncTraits<R, T, IS_CONST, Args...> {}

    COIL_MEMBER_FUNCTION_SPECIALIZATION(, false);
    COIL_MEMBER_FUNCTION_SPECIALIZATION(volatile, false);
    COIL_MEMBER_FUNCTION_SPECIALIZATION(&, false);
    COIL_MEMBER_FUNCTION_SPECIALIZATION(volatile&, false);
    COIL_MEMBER_FUNCTION_SPECIALIZATION(&&, false);
    COIL_MEMBER_FUNCTION_SPECIALIZATION(volatile&&, false);
    COIL_MEMBER_FUNCTION_SPECIALIZATION(noexcept, false);
    COIL_MEMBER_FUNCTION_SPECIALIZATION(volatile noexcept, false);
    COIL_MEMBER_FUNCTION_SPECIALIZATION(& noexcept, false);
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
    COIL_MEMBER_FUNCTION_SPECIALIZATION(const && noexcept, true);
    COIL_MEMBER_FUNCTION_SPECIALIZATION(const volatile&& noexcept, true);

#undef COIL_MEMBER_FUNCTION_SPECIALIZATION
}
