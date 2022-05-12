#pragma once

#include <vector>

#include "AnyFunctor.h"
#include "detail/FuncTraits.h"

namespace coil
{
    template<typename... Funcs>
    std::vector<AnyFunctor> overloaded(Funcs... funcs)
    {
        static_assert((detail::FuncTraits<Funcs>::isFunc && ...), "Funcs should be functor objects");
        // No move list-initialization in vector? Really, C++?
        std::vector<AnyFunctor> functors;
        (functors.push_back(AnyFunctor{ typename detail::FuncTraits<Funcs>::FunctionWrapperType{ std::move(funcs) } }), ...);
        return functors;
    }
}