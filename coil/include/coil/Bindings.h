#pragma once

#include <string>
#include <functional>
#include <unordered_map>
#include <any>

#include "detail/FuncTraitsEx.h"
#include "utils/Utils.h"
#include "detail/FunctorCaller.h"
#include "ExecutionResult.h"
#include "DefaultLexer.h"
#include "Expected.h"
#include "detail/StringWrapper.h"

namespace coil
{
    using StringWrapper = BasicStringWrapper<std::string>;

    template<typename BindingsT>
    class BindingProxy;

	class Bindings
	{
    public:
        BindingProxy<Bindings> operator[](std::string_view name);

        template<typename Func>
        void add(std::string_view name, Func&& func)
        {
            using UnqualifiedFunc = std::decay_t<Func>;

            static_assert(detail::FuncTraits<UnqualifiedFunc>::isFunc, "Func should be a functor object");
            static_assert(!std::is_member_function_pointer_v<UnqualifiedFunc>, "Func shouldn't be a member function");

            m_commands.insert_or_assign(name, AnyFunctor{ UnqualifiedFunc{ std::move(func) }, &detail::functorTrampoline<UnqualifiedFunc> });
        }

        void remove(std::string_view name)
        {
            m_commands.erase(name);
        }

        void clear()
        {
            m_commands.clear();
        }

        ExecutionResult execute(std::string_view command)
        {
            return execute(command, m_defaultLexer);
        }

        template<typename InputT, typename LexerT>
        ExecutionResult execute(InputT&& command, LexerT&& lexer)
        {
            static_assert(std::is_invocable_v<LexerT, InputT>, "LexerT should be invocable with InputT");

            auto input = lexer(std::forward<InputT>(command));
            if (!input)
            {
                ExecutionResult result;
                result.errors.push_back(std::string("Syntax error: ") + input.error());
                return result;
            }

            static_assert(std::is_convertible_v<decltype(*input), ExecutionInput const&>, "The result of invoking LexerT should be convertible to ExecutionInput const&");

            return execute(*input);
        }

        ExecutionResult execute(ExecutionInput const& input)
        {
            detail::CallContext context{input};
            execute(context);
            return std::move(context).result;
        }

    private:
        struct AnyFunctor
        {
        public:
            using TrampolineT = void(*)(std::any&, detail::CallContext&);

            AnyFunctor(std::any functor, TrampolineT trampoline)
                : functor(std::move(functor))
                , m_trampoline(trampoline)
            {

            }

            void invokeTrampoline(detail::CallContext& context)
            {
                m_trampoline(functor, context);
            }

        private:
            std::any functor;
            TrampolineT m_trampoline;
        };

        void execute(detail::CallContext& context)
        {
            if (context.input.name.empty())
            {
                context.result.errors.push_back("No function name is specified");
                return;
            }

            auto it = m_commands.find(context.input.name);
            if (it == m_commands.end())
            {
                context.result.errors.push_back(utils::formatString("No function '%.*s' is registered", context.input.name.size(), context.input.name.data()));
                return;
            }

            it->second.invokeTrampoline(context);
        }

        DefaultLexer m_defaultLexer;

        std::unordered_map<StringWrapper, AnyFunctor> m_commands;
	};

    template<typename BindingsT>
    class BindingProxy
    {
    public:
        BindingProxy(BindingsT& bindings, std::string_view name) : m_bindings(bindings), m_name(name) {}

        template<typename AnyT>
        BindingProxy& operator=(AnyT&& anything)
        {
            m_bindings.add(m_name, std::forward<AnyT>(anything));
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

    inline BindingProxy<Bindings> Bindings::operator[](std::string_view name)
    {
        return BindingProxy<Bindings>{ *this, { name } };
    }
}
