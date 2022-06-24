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
            return AnyFunctor{typename detail::FuncTraits<Func>::FunctionWrapperType{std::move(func)}};
        }

        inline AnyFunctor createAnyFunctor(AnyFunctor anyFunctor)
        {
            return anyFunctor; // TODO check if RVO applies here
        }
    }

    template<typename... Funcs>
    std::vector<AnyFunctor> overloaded(Funcs... funcs)
    {
        static_assert((detail::FuncTraits<Funcs>::isFunc && ...), "Funcs should be functor objects");
        // No move list-initialization in vector? Really, C++?
        std::vector<AnyFunctor> functors;
        (functors.push_back(detail::createAnyFunctor(std::move(funcs))), ...);
        return functors;
    }
}
