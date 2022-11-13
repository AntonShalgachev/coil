#pragma once

#include "AnyFunctor.h"
#include "detail/FuncTraits.h"
#include "detail/Utility.h"

namespace coil
{
    namespace detail
    {
        template<typename Func>
        AnyFunctor createAnyFunctor(Func func)
        {
            static_assert((detail::FuncTraits<Func>::isFunc), "Funcs should be functor objects");
            return AnyFunctor{typename detail::FuncTraits<Func>::FunctionWrapperType{coil::move(func)}};
        }

        inline AnyFunctor createAnyFunctor(AnyFunctor anyFunctor)
        {
            return anyFunctor;
        }
    }

    template<typename... Funcs>
    Vector<AnyFunctor> overloaded(Funcs... funcs)
    {
        Vector<AnyFunctor> functors;
        (functors.pushBack(detail::createAnyFunctor(coil::move(funcs))), ...);
        return functors;
    }
}
