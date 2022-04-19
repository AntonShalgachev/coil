#pragma once

#include "coil/detail/FuncTraits.h"
#include "coil/detail/AnyFunctor.h"

namespace coil
{
    template<typename FuncPointer, typename C>
    detail::AnyFunctor bind(FuncPointer func, C* obj)
    {
        using Traits = detail::FuncTraits<FuncPointer>;
        static_assert(!std::is_const_v<C> || Traits::isConst, "Can't bind a const object to a non-constant member function");

        using FunctionWrapper = typename Traits::FunctionWrapperType;
        return detail::AnyFunctor{ FunctionWrapper{ func, obj } };
    }
}
