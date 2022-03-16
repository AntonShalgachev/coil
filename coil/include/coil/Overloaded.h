#pragma once

namespace coil
{
    template<typename... Func>
    std::vector<detail::AnyFunctor> overloaded(Func... funcs)
    {
        // No move list-initialization in vector? Really, C++?
        std::vector<detail::AnyFunctor> functors;
        (functors.push_back(detail::AnyFunctor{ std::move(funcs) }), ...);
        return functors;
    }
}
