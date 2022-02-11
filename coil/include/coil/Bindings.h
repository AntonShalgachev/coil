#pragma once

#include <string>
#include <functional>
#include <unordered_map>
#include <any>

#include "utils/FuncTraits.h"
#include "utils/Utils.h"
#include "detail/FunctorCaller.h"
#include "ExecutionResult.h"
#include "utils/TypeId.h"
#include "DefaultLexer.h"
#include "Expected.h"
#include "detail/StringWrapper.h"

namespace coil
{
    using StringWrapper = BasicStringWrapper<std::string>;

    template<typename BindingsT>
    class BindingProxy;
    class CommandCollection;

	class Bindings
	{
    public:
        BindingProxy<Bindings> operator[](std::string_view name);

        template<typename Func>
        void add(std::vector<std::string_view> const& path, Func&& func)
        {
            using UnqualifiedFunc = std::decay_t<Func>;
            using FuncTraits = detail::FuncTraitsEx<UnqualifiedFunc>;
            using ArgsTraits = typename FuncTraits::ArgsTraits;

            static_assert(FuncTraits::isFunc, "Func should be a functor object");
            static_assert(!std::is_member_function_pointer_v<UnqualifiedFunc>, "Func shouldn't be a member function");

            Node* targetNode = &m_root;
            for (auto const& pathPart : path)
            {
                auto& subtree = targetNode->children[pathPart];
                if (!subtree)
                    subtree = std::make_unique<Node>();

                targetNode = subtree.get();
            }

            targetNode->functor = AnyFunctor{ UnqualifiedFunc{ std::move(func) }, &Bindings::functorTrampoline<UnqualifiedFunc> };
        }

        void remove(std::vector<std::string_view> const& path)
        {
            Node* targetNode = &m_root;
            for (auto const& pathPart : path)
            {
                auto it = targetNode->children.find(pathPart);
                if (it == targetNode->children.end())
                {
                    // TODO report error?
                    return;
                }

                if (!it->second)
                {
                    // TODO report error?
                    return;
                }

                targetNode = it->second.get();
            }

            targetNode->functor = {};
        }

        void clear()
        {
            m_root.children.clear();
            m_root.functor = {};
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

        template<typename FuncT>
        static void functorTrampoline(std::any& anyFunctor, detail::CallContext& context)
        {
            FuncT* functor = std::any_cast<FuncT>(&anyFunctor);

            if (!functor)
            {
                context.result.errors.push_back("Internal error");
                return;
            }

            using FuncTraits = detail::FuncTraitsEx<FuncT>;
            using ArgsTraits = typename FuncTraits::ArgsTraits;

            if (!validateArguments(ArgsTraits::minArgs, ArgsTraits::isUnlimited, ArgsTraits::maxArgs, context))
                return;

            using UserArgTypes = typename ArgsTraits::UserArgumentTypes;
            using UserArgIndicesType = typename UserArgTypes::IndicesType;
            using NonUserArgsIndicesType = typename ArgsTraits::NonUserArgsIndices;

            detail::unpackAndInvoke(*functor, context, NonUserArgsIndicesType{}, UserArgTypes{}, UserArgIndicesType{});
        }

        void execute(detail::CallContext& context)
        {
            if (context.input.categoryPath.empty() || context.input.categoryPath.back().empty())
            {
                context.result.errors.push_back("No function name is specified");
                return;
            }

            auto reportMissingCommand = [](detail::CallContext& context)
            {
                std::string flatPath = utils::flatten(context.input.categoryPath, "", ".");
                context.result.errors.push_back(utils::formatString("No function '%s' is registered", flatPath.c_str()));
            };

            Node* targetNode = &m_root;
            for (auto const& pathPart : context.input.categoryPath)
            {
                auto it = targetNode->children.find(pathPart);
                if (it == targetNode->children.end())
                {
                    reportMissingCommand(context);
                    return;
                }

                if (!it->second)
                {
                    context.result.errors.push_back("Internal error");
                    return;
                }

                targetNode = it->second.get();
            }

            if (!targetNode->functor)
            {
                reportMissingCommand(context);
                return;
            }

            targetNode->functor->invokeTrampoline(context);
        }

        DefaultLexer m_defaultLexer;

        struct Node
        {
            std::optional<AnyFunctor> functor;
            std::unordered_map<StringWrapper, std::unique_ptr<Node>> children;
        };

        Node m_root;
	};

    template<typename BindingsT>
    class BindingProxy
    {
    public:
        BindingProxy(BindingsT& bindings, std::vector<std::string_view> partialPath) : m_bindings(bindings), m_partialPath(std::move(partialPath)) {}

        BindingProxy operator[](std::string_view name) const& = delete;
        BindingProxy operator[](std::string_view name) &
        {
            std::vector<std::string_view> newPartialPath = m_partialPath;
            newPartialPath.push_back(name);
            return BindingProxy{ m_bindings, std::move(newPartialPath) };
        }
        BindingProxy operator[](std::string_view name) &&
        {
            std::vector<std::string_view> newPartialPath = std::move(m_partialPath);
            newPartialPath.push_back(name);
            return BindingProxy{ m_bindings, std::move(newPartialPath) };
        }

        template<typename AnyT>
        BindingProxy& operator=(AnyT&& anything) const& = delete;
        template<typename AnyT>
        BindingProxy& operator=(AnyT&& anything) &
        {
            m_bindings.add(m_partialPath, std::forward<AnyT>(anything));
            return *this;
        }
        template<typename AnyT>
        BindingProxy& operator=(AnyT&& anything) &&
        {
            m_bindings.add(std::move(m_partialPath), std::forward<AnyT>(anything));
            return *this;
        }
        BindingProxy& operator=(std::nullptr_t)
        {
            m_bindings.remove(m_partialPath);
            return *this;
        }
        // TODO support empty braces along with nullptr

    private:
        BindingsT& m_bindings;
        std::vector<std::string_view> m_partialPath;
    };

    inline BindingProxy<Bindings> Bindings::operator[](std::string_view name)
    {
        return BindingProxy<Bindings>{ *this, { name } };
    }
}
