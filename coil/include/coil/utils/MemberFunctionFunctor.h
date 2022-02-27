#pragma once

// TODO rename file

#include "coil/detail/FuncTraits.h"

namespace coil::utils
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
}

namespace coil
{
    template<typename FuncPointer, typename C>
    auto bind(FuncPointer func, C* obj)
    {
        using Traits = detail::FuncTraits<FuncPointer>;
        static_assert(!std::is_const_v<C> || Traits::isConst, "Can't bind a const object to a non-constant member function");
        return utils::MemberFunctionFunctor{ func, obj, typename Traits::ArgumentTypes{} };
    }
}
