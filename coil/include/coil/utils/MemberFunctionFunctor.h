#pragma once

// TODO rename file

#include "Types.h"
#include "FuncTraits.h"

namespace coil::utils
{
	namespace detail
	{
		template<typename Func, typename ObjectReferenceT, typename Types>
		struct MemberFunctionFunctorImpl {};

        template<typename Func, typename T, typename... Args>
		struct MemberFunctionFunctorImpl<Func, T, Types<Args...>>
		{
			//static_assert(std::is_lvalue_reference_v<T>, "ObjectReferenceT should be an L-value reference type");

			MemberFunctionFunctorImpl(Func&& func, T* obj) : func(std::forward<Func>(func)), obj(obj) {}

			decltype(auto) operator()(Args... args)
			{
				return (obj->*func)(std::forward<Args>(args)...);
			}

			Func func;
			T* obj;
		};

		template<typename Func, typename ObjectReferenceT>
		using MemberFunctionFunctorImplT = MemberFunctionFunctorImpl<Func, ObjectReferenceT, typename FuncTraits<Func>::ArgumentTypes>;
	}

	template<typename Func, typename T>
	struct MemberFunctionFunctor : public detail::MemberFunctionFunctorImplT<Func, T>
	{
		using Base = detail::MemberFunctionFunctorImplT<Func, T>;
		using Base::Base;
	};
}

namespace coil
{
    template<typename Func, typename T>
	auto bind(Func&& func, T* obj)
    {
        using FuncTraits = utils::FuncTraits<Func>;

        static_assert(FuncTraits::isMethod, "Func must be a pointer to member function");
        static_assert(std::is_same_v<typename FuncTraits::ObjectType, std::decay_t<T>>, "Object must have the same type as the function's object type");
        static_assert(!std::is_const_v<T> || FuncTraits::isConst, "Can't call non-const method on a const object");

		return utils::MemberFunctionFunctor<Func, T>(std::forward<Func>(func), obj);
	}
}
