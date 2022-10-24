#pragma once

#include "AnyFunctor.h"
#include "String.h"
#include "StringView.h"
#include "UnorderedMap.h"
#include "UniquePtr.h"
#include "detail/FuncTraits.h"
#include "detail/Utility.h"

namespace coil
{
    class BindingProxy;
    struct ExecutionResult;
    class Lexer;

    class Bindings
    {
    public:
        struct Command
        {
            StringView name;
            Vector<AnyFunctor> functors;
        };

        Bindings();
        Bindings(Bindings&& rhs);
        ~Bindings();

        Bindings& operator=(Bindings&& rhs);

        void setLexer(UniquePtr<Lexer> lexer);

        BindingProxy operator[](StringView name);

        template<typename Func>
        Bindings::Command const& add(StringView name, Func func)
        {
            static_assert(detail::FuncTraits<Func>::isFunc, "Func should be a functor object");
            using FunctionWrapper = typename detail::FuncTraits<Func>::FunctionWrapperType;
            return add(name, AnyFunctor{FunctionWrapper{Move(func)}});
        }

        Bindings::Command const& add(StringView name, AnyFunctor anyFunctor);
        Bindings::Command const& add(StringView name, Vector<AnyFunctor> anyFunctors);

        void remove(StringView name);

        Command const* get(StringView name) const;

        void clear();

        ExecutionResult execute(StringView command);
        ExecutionResult execute(ExecutionInput input);

    private:
        void execute(detail::CallContext& context);

        UniquePtr<Lexer> m_lexer;

        UnorderedMap<String, Command> m_commands;
    };

    class BindingProxy
    {
    public:
        BindingProxy(Bindings& bindings, StringView name);

        template<typename Func>
        BindingProxy& operator=(Func func)
        {
            static_assert(detail::FuncTraits<Func>::isFunc, "Func should be a functor object");
            using FunctionWrapper = typename detail::FuncTraits<Func>::FunctionWrapperType;
            return operator=(AnyFunctor{FunctionWrapper{Move(func)}});
        }
        BindingProxy& operator=(AnyFunctor anyFunctor);
        BindingProxy& operator=(Vector<AnyFunctor> anyFunctors);
        BindingProxy& operator=(nullptr_t);

    private:
        Bindings& m_bindings;
        StringView m_name;
    };
}
