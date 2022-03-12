#pragma once

#include "CallContext.h"

#include <any>

namespace coil::detail
{
    // TODO rename to 'FunctorDescriptor'
    struct AnyFunctor
    {
    public:
        using TrampolineT = void(*)(std::any&, detail::CallContext&);

        AnyFunctor(std::any functor, TrampolineT trampoline, std::size_t arity)
            : m_functor(std::move(functor))
            , m_trampoline(trampoline)
            , m_arity(arity)
        {

        }

        void invokeTrampoline(detail::CallContext& context)
        {
            return m_trampoline(m_functor, context);
        }

        std::size_t arity() const { return m_arity; }

    private:
        std::any m_functor;
        TrampolineT m_trampoline;
        std::size_t m_arity;
    };

    template<typename Func>
    AnyFunctor createAnyFunctor(Func&& func)
    {
        using UnqualifiedFunc = std::decay_t<Func>;

        static_assert(detail::FuncTraits<UnqualifiedFunc>::isFunc, "Func should be a functor object");
        static_assert(!std::is_member_function_pointer_v<UnqualifiedFunc>, "Func shouldn't be a member function");

        std::size_t arity = detail::FuncTraits<UnqualifiedFunc>::ArgsTraits::UserArgumentTypes::size;
        return AnyFunctor{ UnqualifiedFunc{ std::forward<Func>(func) }, &detail::functorTrampoline<UnqualifiedFunc>, arity };
    }
}
