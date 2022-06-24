#pragma once

#include "AnyFunctor.h"
#include "detail/FuncTraits.h"

#include <vector>

namespace coil
{
    template<typename... Funcs>
    std::vector<AnyFunctor> overloaded(Funcs... funcs)
    {
        static_assert((detail::FuncTraits<Funcs>::isFunc && ...), "Funcs should be functor objects");
        // No move list-initialization in vector? Really, C++?
        std::vector<AnyFunctor> functors;
        (functors.push_back(AnyFunctor{typename detail::FuncTraits<Funcs>::FunctionWrapperType{std::move(funcs)}}), ...);
        return functors;
    }

    // TODO add a similar function for the member functions
    template<typename Signature>
    auto resolve(Signature* func)
    {
        return func;
    }
}
