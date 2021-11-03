#pragma once

#include "Types.h"
#include <type_traits>

namespace utils
{
	template<typename R, typename T, bool IsConst, typename... Args>
	struct BaseFuncTraits
    {
    public:
        static constexpr bool isFunc = true;

		using ReturnType = R;
		using ObjectType = T; // void if free/static function, T if it's a method of type T
		using ArgumentTypes = Types<Args...>;

        template<typename T>
        static const bool isMethodOfType = !std::is_void_v<T> && std::is_same_v<ObjectType, T>;

		static constexpr bool isConst = IsConst;
	};

    // General types
    template<typename T, typename = void>
    struct FuncTraits
    {
        static constexpr bool isFunc = false;
    };

    template<typename T>
    struct FuncTraits<T, std::void_t<decltype(&T::operator())>>
        : public FuncTraits<decltype(&T::operator())> {};

	// Free functions
	template<typename R, typename... Args>
    struct FuncTraits<R(*)(Args...), void> : public BaseFuncTraits<R, void, false, Args...> {};

	// Pointer to member function
	template<typename R, typename T, typename... Args>
	struct FuncTraits<R(T::*)(Args...), void> : public BaseFuncTraits<R, T, false, Args...> {};
	template<typename R, typename T, typename... Args>
	struct FuncTraits<R(T::*)(Args...) const, void> : public BaseFuncTraits<R, T, true, Args...> {};
}
