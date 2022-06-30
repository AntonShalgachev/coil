#pragma once

#include "AnyFunctor.h"
#include "DefaultLexer.h"
#include "ExecutionResult.h"
#include "Expected.h"
#include "Utils.h"
#include "detail/FuncTraits.h"
#include "detail/FunctorCaller.h"
#include "detail/StringWrapper.h"

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
        using StringWrapper = BasicStringWrapper<std::string>;
        using LexerFunc = std::function<Expected<ExecutionInput, std::string>(std::string_view)>;

        void setLexer(LexerFunc lexer);

        BindingProxy<Bindings> operator[](std::string_view name);

        template<typename Func>
        void add(std::string_view name, Func func)
        {
            static_assert(detail::FuncTraits<Func>::isFunc, "Func should be a functor object");
            using FunctionWrapper = typename detail::FuncTraits<Func>::FunctionWrapperType;
            add(name, AnyFunctor{FunctionWrapper{std::move(func)}});
        }

        void add(std::string_view name, AnyFunctor anyFunctor);
        void add(std::string_view name, std::vector<AnyFunctor> anyFunctors);

        void remove(std::string_view name);

        void clear();

        std::vector<std::string_view> const& commands() const;

        ExecutionResult execute(std::string_view command);
        ExecutionResult execute(ExecutionInput input);

    private:
        void execute(detail::CallContext& context);

        LexerFunc m_lexer = DefaultLexer{};

        std::unordered_map<StringWrapper, std::vector<AnyFunctor>> m_commands;
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
            m_bindings.add(m_name, AnyFunctor{FunctionWrapper{std::move(func)}});
            return *this;
        }
        BindingProxy& operator=(AnyFunctor anyFunctor)
        {
            m_bindings.add(m_name, std::move(anyFunctor));
            return *this;
        }
        BindingProxy& operator=(std::vector<AnyFunctor> anyFunctors)
        {
            m_bindings.add(m_name, std::move(anyFunctors));
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
