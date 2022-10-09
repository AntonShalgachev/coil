#pragma once

#include "AnyFunctor.h"
#include "ExecutionResult.h"
#include "Expected.h"
#include "Lexer.h"
#include "Utils.h"
#include "detail/FuncTraits.h"
#include "detail/FunctorCaller.h"
#include "detail/StringWrapper.h"
#include "detail/Utility.h"

#include <functional>
#include <string>
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
            std::vector<AnyFunctor> functors;
        };

        using StringWrapper = BasicStringWrapper<std::string>;

        Bindings();

        void setLexer(std::unique_ptr<Lexer> lexer);

        BindingProxy<Bindings> operator[](std::string_view name);

        template<typename Func>
        Bindings::Command const& add(std::string_view name, Func func)
        {
            static_assert(detail::FuncTraits<Func>::isFunc, "Func should be a functor object");
            using FunctionWrapper = typename detail::FuncTraits<Func>::FunctionWrapperType;
            return add(name, AnyFunctor{FunctionWrapper{Move(func)}});
        }

        Bindings::Command const& add(std::string_view name, AnyFunctor anyFunctor);
        Bindings::Command const& add(std::string_view name, std::vector<AnyFunctor> anyFunctors);

        void remove(std::string_view name);

        Command const* get(std::string_view name) const;

        void clear();

        std::vector<std::string_view> const& commands() const;

        ExecutionResult execute(std::string_view command);
        ExecutionResult execute(ExecutionInput input);

    private:
        void execute(detail::CallContext& context);

        std::unique_ptr<Lexer> m_lexer;

        std::unordered_map<StringWrapper, Command> m_commands;
        std::vector<std::string_view> m_commandNames;
    };

    template<typename BindingsT>
    class BindingProxy
    {
    public:
        BindingProxy(BindingsT& bindings, std::string_view name) : m_bindings(bindings), m_name(name) {}

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
        BindingProxy& operator=(std::vector<AnyFunctor> anyFunctors)
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
        std::string_view m_name;
    };
}
