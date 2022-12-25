#pragma once

#include "AnyFunctor.h"
#include "FuncTraits.h"
#include "TypeTraits.h"

namespace coil
{
    template<typename FuncPointer, typename C>
    AnyFunctor bind(FuncPointer func, C* obj)
    {
        using Traits = detail::FuncTraits<FuncPointer>;
        static_assert(!IsConstV<C> || Traits::isConst, "Can't bind a const object to a non-constant member function");

        using FunctionWrapper = typename Traits::FunctionWrapperType;
        return AnyFunctor{FunctionWrapper{func, obj}};
    }
}
