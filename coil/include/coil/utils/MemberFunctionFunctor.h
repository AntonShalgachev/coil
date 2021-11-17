#pragma once

#include "Types.h"
#include "FuncTraits.h"

namespace coil::utils
{
	namespace detail
	{
		template<typename Func, typename ObjectReferenceT, typename Types>
		struct MemberFunctionFunctorImpl {};

		template<typename Func, typename ObjectReferenceT, typename... Args>
		struct MemberFunctionFunctorImpl<Func, ObjectReferenceT, Types<Args...>>
		{
			using R = typename FuncTraits<Func>::ReturnType;

			static_assert(std::is_lvalue_reference_v<ObjectReferenceT>, "ObjectReferenceT should be an L-value reference type");

			MemberFunctionFunctorImpl(Func&& func, ObjectReferenceT obj) : func(std::forward<Func>(func)), obj(obj) {}

			R operator()(Args... args)
			{
				return std::invoke(func, obj, std::forward<Args>(args)...);
			}

			Func func;
			ObjectReferenceT obj;
		};

		template<typename Func, typename ObjectReferenceT>
		using MemberFunctionFunctorImplT = MemberFunctionFunctorImpl<Func, ObjectReferenceT, typename FuncTraits<Func>::ArgumentTypes>;
	}

	template<typename Func, typename ObjectReferenceT>
	struct MemberFunctionFunctor : public detail::MemberFunctionFunctorImplT<Func, ObjectReferenceT>
	{
		using Base = detail::MemberFunctionFunctorImplT<Func, ObjectReferenceT>;
		using Base::Base;
	};
}
