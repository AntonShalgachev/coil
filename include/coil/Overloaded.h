#pragma once

#include "AnyFunctor.h"
#include "detail/FuncTraits.h"

#include <vector>

namespace coil
{
    namespace detail
    {
        template<typename Func>
        AnyFunctor createAnyFunctor(Func func)
        {
            static_assert((detail::FuncTraits<Func>::isFunc), "Funcs should be functor objects");
            return AnyFunctor{typename detail::FuncTraits<Func>::FunctionWrapperType{std::move(func)}};
        }

        inline AnyFunctor createAnyFunctor(AnyFunctor anyFunctor)
        {
            return anyFunctor;
        }
    }

    template<typename... Funcs>
    std::vector<AnyFunctor> overloaded(Funcs... funcs)
    {
        // No move list-initialization in vector? Really, C++?
        std::vector<AnyFunctor> functors;
        (functors.push_back(detail::createAnyFunctor(std::move(funcs))), ...);
        return functors;
    }
}
