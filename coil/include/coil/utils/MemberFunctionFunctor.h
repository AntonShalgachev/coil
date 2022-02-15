#pragma once

// TODO rename file

#include <type_traits>

namespace coil::utils
{
    template<typename FuncPointer, typename C, typename... Args>
	struct MemberFunctionFunctor
	{
    public:
        MemberFunctionFunctor(FuncPointer func, C* obj) : m_func(func), m_obj(obj) {}

        decltype(auto) operator()(Args... args)
        {
            return (m_obj->*m_func)(std::move(args)...);
        }

    private:
        FuncPointer m_func = nullptr;
        C* m_obj = nullptr;
	};
}

namespace coil
{
    // TODO implement for every const/volatile/except/ref combination

    template<typename C, typename R, typename... Args>
    auto bind(R(C::* func)(Args...), C* obj)
    {
        static_assert(!std::is_const_v<C>, "Can't bind non-const method on a const object");
        return utils::MemberFunctionFunctor<R(C::*)(Args...), C, Args...>{ func, obj };
    }
    template<typename C, typename R, typename... Args>
    auto bind(R(C::* func)(Args...) const, C const* obj)
    {
        return utils::MemberFunctionFunctor<R(C::*)(Args...) const, C const, Args...>{ func, obj };
    }
}
