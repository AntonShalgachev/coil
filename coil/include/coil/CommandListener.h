#pragma once

#include <string>
#include <functional>
#include <unordered_map>
#include <stdexcept>

#include "utils/FuncTraits.h"
#include "utils/Utils.h"
#include "detail/FunctorCaller.h"
#include "ExecutionResult.h"
#include "utils/MemberFunctionFunctor.h"
#include "utils/VariableWrapper.h"
#include "utils/TypeId.h"
#include <any>

namespace cmdapi
{
	class CommandListener
	{
	public:
        template<typename T, typename Func, typename ObjectPointerT>
        bool bind(std::string name, Func&& func, ObjectPointerT obj)
        {
            using Traits = utils::FuncTraits<Func>;
            using ObjectT = std::remove_pointer_t<ObjectPointerT>;
            using ObjectReferenceT = std::add_lvalue_reference_t<ObjectT>;
 
            static_assert(!std::is_void_v<Traits::ObjectType>, "Func must be a pointer to member function");
            static_assert(std::is_pointer_v<ObjectPointerT>, "Object must be a pointer"); // To make it obvious that we don't make a copy of this object
            static_assert(std::is_same_v<Traits::ObjectType, std::decay_t<ObjectT>>, "Object must have the same type as the function's object type");
            if constexpr (std::is_const_v<ObjectT>)
                static_assert(Traits::isConst, "Can't call non-const method on a const object");

            return bind<T>(std::move(name), utils::MemberFunctionFunctor<Func, ObjectReferenceT>(std::forward<Func>(func), *obj));
        }

        template<typename Func, typename ObjectPointerT>
        bool bind(std::string name, Func&& func, ObjectPointerT obj)
        {
            return bind<void>(std::move(name), std::forward<Func>(func), obj);
        }

        template<typename AnyT>
        bool bind(std::string name, AnyT&& anything)
        {
            return bind<void, AnyT>(std::move(name), std::forward<AnyT>(anything));
        }

        template<typename T, typename AnyT>
        bool bind(std::string name, AnyT&& anything)
		{
            using DecayedAnyT = std::decay_t<AnyT>;
            if constexpr (utils::FuncTraits<DecayedAnyT>::isFunc)
            {
                return bindFunc<T>(std::move(name), std::forward<AnyT>(anything));
            }
            else if constexpr (std::is_member_object_pointer_v<DecayedAnyT>)
            {
                static_assert(!std::is_void_v<T>, "Pointer to member variable should be bound to non-void type");
                return bindMemberVariable<T>(std::move(name), std::forward<AnyT>(anything));
            }
            else if constexpr (std::is_pointer_v<AnyT> && !std::is_function_v<AnyT>)
            {
                static_assert(std::is_void_v<T>, "Pointer to variable shouldn't be bound to non-void type");
                return bindVariable(std::move(name), std::forward<AnyT>(anything));
            }
            else
            {
                static_assert(false, "Unsupported type AnyT");
            }
        }

        template<typename T, typename Func>
        bool bindFunc(std::string name, Func&& func)
        {
            // Possible Func arguments:
            // [Target [const]*], [Context&], Args...

            // TODO assert that user parameters of Func are either values or const-references
            // TODO assert that Context parameter is non-const reference and is at second optional position

            static_assert(!std::is_const_v<T>, "T shouldn't be const");
            static_assert(!std::is_pointer_v<T>, "T shouldn't be a pointer");

            using UnqualifiedFunc = std::decay_t<Func>;
            using FuncTraits = detail::FuncTraitsEx<UnqualifiedFunc>;

            if constexpr (std::is_void_v<T>)
            {
                static_assert(!std::is_member_function_pointer_v<UnqualifiedFunc>, "Func shouldn't be a member function");
            }

            using ExplicitTargetTrait = typename FuncTraits::ExplicitTargetTraits;
            if constexpr (ExplicitTargetTrait::isPresent)
            {
                static_assert(!std::is_same_v<T, FuncTraits::ObjectType>, "Explicit target shouldn't be used on member functions of the same type");
                static_assert(!std::is_void_v<T>, "Can't have explicit target for bindings without target");
                using SpecifiedExplicitTarget = std::decay_t<std::remove_pointer_t<ExplicitTargetTrait::Type>>;
                static_assert(std::is_same_v<T, SpecifiedExplicitTarget>, "Explicit target should match the given type T");
            }

            if (name.empty())
                return false;

            UnqualifiedFunc unqualifiedFunc{ std::move(func) };

            auto& typeFunctors = m_functors[utils::typeId<T>()];
            typeFunctors.insert_or_assign(std::move(name), AnyFunctor::create<T, UnqualifiedFunc>(std::move(unqualifiedFunc)));

            return true;
        }

        template<typename T, typename R>
        bool bindMemberVariable(std::string name, R T::* var)
        {
            return bindFunc<T>(std::move(name), utils::MemberVariableWrapper{ var });
        }

        template<typename R>
        bool bindVariable(std::string name, R* var)
        {
            return bindFunc<void>(std::move(name), utils::VariableWrapper{ var });
        }

		bool unbind(std::string const& name);

        template<typename T>
        bool unbind(std::string const& name)
		{
			if (name.empty())
				return false;

            if (auto it = m_functors.find(utils::typeId<T>()); it != m_functors.end())
                it->second.erase(name);

			return true;
        }

		void unbindAll();

        template<typename T>
        void unbindAll()
        {
            if (auto it = m_functors.find(utils::typeId<T>()); it != m_functors.end())
                it->second.clear();
        }

        template<typename T>
        bool addObject(std::string name, T* object)
		{
            // TODO allow const objects
			static_assert(!std::is_const_v<T>, "T shouldn't be const");

			if (name.empty())
				return false;

            m_objects.insert_or_assign(std::move(name), object);

			return true;
        }

        bool removeObject(std::string const& name);

        void removeAllObjects();

        ExecutionResult execute(std::string command);

	private:
        struct AnyObject
        {
            using TrampolineT = void(CommandListener::*)(std::any const&, detail::CallContext&);

            template<typename T>
            AnyObject(T* object)
                : object(object)
                , trampoline(&CommandListener::objectTrampoline<T>)
            {

            }

            void invokeTrampoline(CommandListener* self, detail::CallContext& context) const
            {
                std::invoke(trampoline, self, object, context);
            }

            std::any object;
            TrampolineT trampoline;
        };

        struct AnyFunctor
        {
            using TrampolineT = void(CommandListener::*)(std::any const&, std::any&, detail::CallContext&);

            template<typename T, typename Func>
            AnyFunctor(Func&& func, utils::Types<T>)
                : functor(std::forward<Func>(func))
                , trampoline(&CommandListener::functorTrampoline<T, Func>)
            {

            }

            template<typename T, typename Func>
            static AnyFunctor create(Func&& func)
            {
                return AnyFunctor(std::forward<Func>(func), utils::Types<T>{});
            }

            void invokeTrampoline(CommandListener* self, std::any const& anyObject, detail::CallContext& context)
            {
                std::invoke(trampoline, self, anyObject, functor, context);
            }

            std::any functor;
            TrampolineT trampoline;
        };

        template<typename T>
        void objectTrampoline(std::any const& anyObject, detail::CallContext& context)
        {
            auto& typeFunctors = m_functors[utils::typeId<T>()];

            auto it = typeFunctors.find(context.name);
            if (it == typeFunctors.end())
            {
                if constexpr (std::is_void_v<T>)
                    context.result.errors.push_back(utils::formatString("No function '%s' is registered", context.name.c_str()));
                else
                    context.result.errors.push_back(utils::formatString("No function '%s' is registered for type '%s'", context.name.c_str(), utils::Types<T>::name().c_str()));

                return;
            }

            AnyFunctor& anyFunctor = it->second;

            anyFunctor.invokeTrampoline(this, anyObject, context);
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

		void execute(detail::CallContext& context);

        std::unordered_map<std::string, AnyObject> m_objects;
        std::unordered_map<utils::TypeIdT, std::unordered_map<std::string, AnyFunctor>> m_functors;
	};
}
