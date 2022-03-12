#pragma once

namespace coil
{
    template<typename... Func>
    std::vector<detail::AnyFunctor> overloaded(Func&&... funcs)
    {
        return { detail::createAnyFunctor(std::forward<Func>(funcs))... };
    }
}
