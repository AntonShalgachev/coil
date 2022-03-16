#pragma once

#include <string>
#include <functional>
#include <unordered_map>

#include "detail/FuncTraits.h"
#include "Utils.h"
#include "detail/FunctorCaller.h"
#include "ExecutionResult.h"
#include "DefaultLexer.h"
#include "Expected.h"
#include "detail/StringWrapper.h"
#include "detail/AnyFunctor.h"

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
        void add(std::string_view name, Func func)
        {
            // No move list-initialization in vector? Really, C++?
            std::vector<detail::AnyFunctor> functors;
            functors.push_back(detail::AnyFunctor{ std::move(func) });
            m_commands.insert_or_assign(name, std::move(functors));
        }

        void add(std::string_view name, std::vector<detail::AnyFunctor> anyFunctors)
        {
            m_commands.insert_or_assign(name, std::move(anyFunctors));
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
            detail::CallContext context{ input };
            execute(context);
            return std::move(context).result;
        }

    private:
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
                context.result.errors.push_back(formatString("No function '%.*s' is registered", context.input.name.size(), context.input.name.data()));
                return;
            }

            auto& functors = it->second;

            for (auto& functor : functors)
                if (functor.arity() == context.input.arguments.size())
                    return functor.invokeTrampoline(context);

            std::stringstream argsCount;
            
            for (std::size_t i = 0; i < functors.size(); i++)
            {
                if (i > 0 && i != functors.size() - 1)
                    argsCount << ", ";
                if (i > 0 && i == functors.size() - 1)
                    argsCount << " or ";

                argsCount << functors[i].arity();
            }   

            std::string const expectedStr = argsCount.str();
            std::size_t const actualArgsCount = context.input.arguments.size();
            auto error = formatString("Wrong number of arguments to '%.*s': expected %s, got %d", context.input.name.size(), context.input.name.data(), expectedStr.c_str(), actualArgsCount);
            context.reportError(std::move(error));
        }

        DefaultLexer m_defaultLexer;

        std::unordered_map<StringWrapper, std::vector<detail::AnyFunctor>> m_commands;
    };

    template<typename BindingsT>
    class BindingProxy
    {
    public:
        BindingProxy(BindingsT& bindings, std::string_view name) : m_bindings(bindings), m_name(name) {}

        template<typename AnyT>
        BindingProxy& operator=(AnyT anything)
        {
            m_bindings.add(m_name, std::move(anything));
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
