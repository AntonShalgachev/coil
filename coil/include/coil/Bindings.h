#pragma once

#include <string>
#include <functional>
#include <unordered_map>
#include <any>

#include "utils/FuncTraits.h"
#include "utils/Utils.h"
#include "detail/FunctorCaller.h"
#include "ExecutionResult.h"
#include "utils/MemberFunctionFunctor.h"
#include "utils/VariableWrapper.h"
#include "utils/TypeId.h"
#include "BindingProxy.h"
#include "DefaultLexer.h"
#include "Expected.h"
#include "GeneralizedString.h"

namespace coil
{
	class Bindings
	{
    public:
        using GeneralizedString = BasicGeneralizedString<std::string>;

        auto operator[](GeneralizedString name)
        {
            return BindingProxy<Bindings, GeneralizedString>(*this, std::move(name));
        }

        template<typename T, typename Func, typename ObjectPointerT>
        void bind(GeneralizedString name, Func&& func, ObjectPointerT obj)
        {
            using Traits = utils::FuncTraits<Func>;
            using ObjectT = std::remove_pointer_t<ObjectPointerT>;
            using ObjectReferenceT = std::add_lvalue_reference_t<ObjectT>;
 
            static_assert(!std::is_void_v<typename Traits::ObjectType>, "Func must be a pointer to member function");
            static_assert(std::is_pointer_v<ObjectPointerT>, "Object must be a pointer"); // To make it obvious that we don't make a copy of this object
            static_assert(std::is_same_v<typename Traits::ObjectType, std::decay_t<ObjectT>>, "Object must have the same type as the function's object type");
            if constexpr (std::is_const_v<ObjectT>)
                static_assert(Traits::isConst, "Can't call non-const method on a const object");

            return bind<T>(std::move(name), utils::MemberFunctionFunctor<Func, ObjectReferenceT>(std::forward<Func>(func), *obj));
        }

        template<typename Func, typename ObjectPointerT>
        void bind(GeneralizedString name, Func&& func, ObjectPointerT obj)
        {
            return bind<void>(std::move(name), std::forward<Func>(func), obj);
        }

        template<typename AnyT>
        void bind(GeneralizedString name, AnyT&& anything)
        {
            return bind<void, AnyT>(std::move(name), std::forward<AnyT>(anything));
        }

        template<typename T, typename AnyT>
        void bind(GeneralizedString name, AnyT&& anything)
		{
            using DecayedAnyT = std::decay_t<AnyT>;
            if constexpr (utils::FuncTraits<DecayedAnyT>::isFunc)
            {
                return bindFunc<T>(std::move(name), std::forward<AnyT>(anything));
            }
            else if constexpr (std::is_member_object_pointer_v<DecayedAnyT>)
            {
                // TODO disallow variadic args (e.g. vector, optional)
                static_assert(!std::is_void_v<T>, "Pointer to member variable should be bound to non-void type");
                return bindMemberVariable<T>(std::move(name), std::forward<AnyT>(anything));
            }
            else if constexpr (std::is_pointer_v<AnyT> && !std::is_function_v<AnyT>)
            {
                // TODO disallow variadic args (e.g. vector, optional)
                return bindVariable<T>(std::move(name), std::forward<AnyT>(anything));
            }
            else
            {
                // TODO add more descriptive message for various types:
                // rvalue, reference to variable, objects without operator()
                static_assert(sizeof(AnyT) == -1, "Unsupported type AnyT");
            }
        }

        void unbind(std::string_view name) { return unbind<void>(name); }

        template<typename T>
        void unbind(std::string_view name)
		{
			if (name.empty())
				return;

            if (auto it = m_functors.find(utils::typeId<T>()); it != m_functors.end())
                it->second.erase(name);
        }

        void unbindAll() { return unbindAll<void>(); }

        template<typename T>
        void unbindAll()
        {
            if (auto it = m_functors.find(utils::typeId<T>()); it != m_functors.end())
                it->second.clear();
        }

        template<typename T>
        void addObject(GeneralizedString name, T* object)
		{
            // TODO allow const objects
			static_assert(!std::is_const_v<T>, "T shouldn't be const");

			if (name.getView().empty())
				return;

            m_objects.insert_or_assign(std::move(name), AnyObject{ object, &Bindings::objectTrampoline<T> });
        }

        void removeObject(std::string_view name)
        {
            if (name.empty())
                return;

            m_objects.erase(name);
        }

        void removeAllObjects() { m_objects.clear(); }

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
        template<typename T, typename Func>
        void bindFunc(GeneralizedString name, Func&& func)
        {
            // TODO assert that user parameters of Func are either values or const-references
            // TODO assert that Context parameter is non-const reference and is at second optional position
            // TODO assert that variadic args are at the end of the function

            static_assert(!std::is_const_v<T>, "T shouldn't be const");
            static_assert(!std::is_pointer_v<T>, "T shouldn't be a pointer");

            using UnqualifiedFunc = std::decay_t<Func>;
            using FuncTraits = detail::FuncTraitsEx<UnqualifiedFunc>;

            if constexpr (std::is_void_v<T>)
                static_assert(!std::is_member_function_pointer_v<UnqualifiedFunc>, "Func shouldn't be a member function");

            if constexpr (FuncTraits::hasTarget)
            {
                static_assert(!std::is_void_v<T>, "Can't have explicit target for bindings without target");
                static_assert(!std::is_same_v<T, typename FuncTraits::ObjectType>, "Explicit target shouldn't be used on member functions of the same type");
                static_assert(std::is_same_v<T, std::decay_t<typename FuncTraits::ExplicitTargetType>>, "Explicit target should be either T* or T const*");
            }

            if (name.getView().empty())
                return;

            UnqualifiedFunc unqualifiedFunc{ std::move(func) };

            auto& typeFunctors = m_functors[utils::typeId<T>()];
            typeFunctors.insert_or_assign(std::move(name), AnyFunctor{ std::move(unqualifiedFunc), &Bindings::functorTrampoline<T, UnqualifiedFunc> });
        }

        template<typename T, typename R>
        void bindMemberVariable(GeneralizedString name, R T::* var)
        {
            return bindFunc<T>(std::move(name), utils::MemberVariableWrapper{ var });
        }

        template<typename T, typename R>
        void bindVariable(GeneralizedString name, R* var)
        {
            return bindFunc<T>(std::move(name), utils::VariableWrapper{ var });
        }

        struct AnyObject
        {
            using TrampolineT = void(Bindings::*)(std::any const&, detail::CallContext&);

            AnyObject(std::any object, TrampolineT trampoline)
                : m_object(std::move(object))
                , m_trampoline(trampoline)
            {

            }

            void invokeTrampoline(Bindings* self, detail::CallContext& context) const
            {
                std::invoke(m_trampoline, self, m_object, context);
            }

        private:
            std::any m_object;
            TrampolineT m_trampoline;
        };

        struct AnyFunctor
        {
        public:
            using TrampolineT = void(Bindings::*)(std::any const&, std::any&, detail::CallContext&);

            AnyFunctor(std::any functor, TrampolineT trampoline)
                : functor(std::move(functor))
                , m_trampoline(trampoline)
            {

            }

            void invokeTrampoline(Bindings* self, std::any const& anyObject, detail::CallContext& context)
            {
                std::invoke(m_trampoline, self, anyObject, functor, context);
            }

        private:
            std::any functor;
            TrampolineT m_trampoline;
        };

        template<typename T>
        void objectTrampoline(std::any const& anyObject, detail::CallContext& context)
        {
            auto&& functionName = context.input.functionName;

            auto& typeFunctors = m_functors.at(utils::typeId<T>());
            if (auto it = typeFunctors.find(functionName); it != typeFunctors.end())
                return it->second.invokeTrampoline(this, anyObject, context);

            auto&& typeName = TypeName<T>::name();
            if constexpr (std::is_void_v<T>)
                context.result.errors.push_back(utils::formatString("No function '%.*s' is registered", functionName.size(), functionName.data()));
            else
                context.result.errors.push_back(utils::formatString("No function '%.*s' is registered for type '%.*s'", functionName.size(), functionName.data(), typeName.size(), typeName.data()));
        }

        template<typename T, typename FuncT>
        void functorTrampoline([[maybe_unused]] std::any const& anyObject, std::any& anyFunctor, detail::CallContext& context)
        {
            FuncT* functor = std::any_cast<FuncT>(&anyFunctor);

            T* object = nullptr;
            if constexpr (!std::is_void_v<T>)
                object = std::any_cast<T*>(anyObject);

            detail::FunctorCaller<FuncT>::template call<T>(*functor, context, object);
        }

        void execute(detail::CallContext& context)
        {
            if (context.input.functionName.empty())
            {
                context.result.errors.push_back("No function name is specified");
                return;
            }

            auto&& objectName = context.input.objectName;

            if (objectName.empty())
                return objectTrampoline<void>({}, context);

            auto it = m_objects.find(objectName);
            if (it == m_objects.end())
            {
                context.result.errors.push_back(utils::formatString("Object '%.*s' is not registered", objectName.size(), objectName.data()));
                return;
            }

            AnyObject& obj = it->second;
            obj.invokeTrampoline(this, context);
        }

        std::unordered_map<GeneralizedString, AnyObject> m_objects;
        std::unordered_map<utils::TypeIdT, std::unordered_map<GeneralizedString, AnyFunctor>> m_functors;
        DefaultLexer m_defaultLexer;
	};
}
