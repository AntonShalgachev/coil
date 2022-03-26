#pragma once

#include "CallContext.h"
#include "FunctorCaller.h"

namespace coil::detail
{
    // std::any and std::unique_ptr produce too much compile-time overhead, so implement a basic solution for that

    class AnyStorageBase
    {
    public:
        AnyStorageBase();
        virtual ~AnyStorageBase();
        virtual void invoke(CallContext& context) = 0;
    };

    template<typename Func>
    class AnyStorage : public AnyStorageBase
    {
    public:
        static_assert(std::is_same_v<std::decay_t<Func>, Func>, "Internal: Func should be a decayed type");

        AnyStorage(Func func) : m_func(std::move(func)) {}

        void invoke(CallContext& context) override
        {
            using ArgsTraits = typename detail::FuncTraits<Func>::ArgsTraits;

            using UserArgTypes = typename ArgsTraits::UserArgumentTypes;
            using UserArgIndicesType = typename UserArgTypes::IndicesType;
            using NonUserArgsIndicesType = typename ArgsTraits::NonUserArgsIndices;

            unpackAndInvoke(m_func, context, NonUserArgsIndicesType{}, UserArgTypes{}, UserArgIndicesType{});
        }

    private:
        Func m_func;
    };

    // TODO rename to 'FunctorDescriptor'
    struct AnyFunctor
    {
    public:
        template<typename Func>
        AnyFunctor(Func func) : m_storage(new AnyStorage<std::decay_t<Func>>(std::move(func)))
        {
            using UnqualifiedFunc = std::decay_t<Func>;

            static_assert(detail::FuncTraits<UnqualifiedFunc>::isFunc, "Func should be a functor object");
            static_assert(!std::is_member_function_pointer_v<UnqualifiedFunc>, "Func shouldn't be a member function");

            m_arity = detail::FuncTraits<UnqualifiedFunc>::ArgsTraits::UserArgumentTypes::size;
        }

        AnyFunctor(AnyFunctor const& rhs) = delete;
        AnyFunctor(AnyFunctor&& rhs)
        {
            using namespace std;
            swap(rhs.m_storage, m_storage);
            swap(rhs.m_arity, m_arity);
        }

        AnyFunctor& operator=(AnyFunctor const& rhs) = delete;
        AnyFunctor& operator=(AnyFunctor&& rhs)
        {
            destroy();

            using namespace std;
            swap(rhs.m_storage, m_storage);
            swap(rhs.m_arity, m_arity);

            return *this;
        }

        ~AnyFunctor()
        {
            destroy();
        }

        void destroy()
        {
            if (m_storage)
                delete m_storage;

            m_storage = nullptr;
        }

        void invokeTrampoline(detail::CallContext& context)
        {
            return m_storage->invoke(context);
        }

        std::size_t arity() const { return m_arity; }

    private:
        AnyStorageBase* m_storage = nullptr;
        std::size_t m_arity;
    };
}
