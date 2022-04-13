#pragma once

#include "coil/detail/FuncTraits.h"
#include "coil/detail/AnyFunctor.h"

namespace coil
{
    template<typename FuncPointer, typename C, typename... Args>
    struct MemberFunctionFunctor
    {
    public:
        MemberFunctionFunctor(FuncPointer func, C* obj, Types<Args...>) : m_func(func), m_obj(obj) {}

        decltype(auto) operator()(Args... args)
        {
            return (m_obj->*m_func)(std::move(args)...);
        }

    private:
        FuncPointer m_func = nullptr;
        C* m_obj = nullptr;
    };

    template<typename FuncPointer, typename C>
    detail::AnyFunctor bind(FuncPointer func, C* obj)
    {
        using Traits = detail::FuncTraits<FuncPointer>;
        static_assert(!std::is_const_v<C> || Traits::isConst, "Can't bind a const object to a non-constant member function");

        auto functor = MemberFunctionFunctor{ func, obj, typename Traits::ArgumentTypes{} };
        using FunctionWrapper = typename detail::FuncTraits<decltype(functor)>::FunctionWrapperType;
        return detail::AnyFunctor{ FunctionWrapper{ std::move(functor) } };
    }
}
