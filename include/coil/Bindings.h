#pragma once

#include "AnyFunctor.h"
#include "ExecutionResult.h"
#include "Expected.h"
#include "Lexer.h"
#include "Utils.h"
#include "String.h"
#include "StringView.h"
#include "detail/FuncTraits.h"
#include "detail/FunctorCaller.h"
#include "detail/StringWrapper.h"
#include "detail/Utility.h"

#include <memory>
#include <unordered_map>

namespace coil
{
    template<typename BindingsT>
    class BindingProxy;

    class Bindings
    {
    public:
        struct Command
        {
            StringView name;
            Vector<AnyFunctor> functors;
        };

        using StringWrapper = BasicStringWrapper<String>;

        Bindings();

        void setLexer(std::unique_ptr<Lexer> lexer);

        BindingProxy<Bindings> operator[](StringView name);

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

        std::unique_ptr<Lexer> m_lexer;

        std::unordered_map<StringWrapper, Command> m_commands;
    };

    // TODO remove
    template<typename BindingsT>
    class BindingProxy
    {
    public:
        BindingProxy(BindingsT& bindings, StringView name) : m_bindings(bindings), m_name(name) {}

        template<typename Func>
        BindingProxy& operator=(Func func)
        {
            static_assert(detail::FuncTraits<Func>::isFunc, "Func should be a functor object");
            using FunctionWrapper = typename detail::FuncTraits<Func>::FunctionWrapperType;
            return operator=(AnyFunctor{FunctionWrapper{Move(func)}});
        }
        BindingProxy& operator=(AnyFunctor anyFunctor)
        {
            m_bindings.add(m_name, Move(anyFunctor));
            return *this;
        }
        BindingProxy& operator=(Vector<AnyFunctor> anyFunctors)
        {
            m_bindings.add(m_name, Move(anyFunctors));
            return *this;
        }
        BindingProxy& operator=(std::nullptr_t)
        {
            m_bindings.remove(m_name);
            return *this;
        }

    private:
        BindingsT& m_bindings;
        StringView m_name;
    };
}
