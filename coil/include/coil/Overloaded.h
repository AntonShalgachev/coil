#pragma once

#include <vector>

#include "detail/AnyFunctor.h"
#include "detail/FuncTraits.h"

namespace coil
{
    template<typename... Funcs>
    std::vector<detail::AnyFunctor> overloaded(Funcs... funcs)
    {
        // No move list-initialization in vector? Really, C++?
        std::vector<detail::AnyFunctor> functors;
        (functors.push_back(detail::AnyFunctor{ typename detail::FuncTraits<Funcs>::FunctionWrapperType{ std::move(funcs) } }), ...);
        return functors;
    }
}
