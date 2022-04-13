#pragma once

#include "CallContext.h"
#include "FunctorCaller.h"
#include "FunctionWrapper.h"

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

    template<typename FuncWrapper>
    class AnyStorage : public AnyStorageBase
    {
    public:
        AnyStorage(FuncWrapper func);

        void invoke(CallContext& context) override;

    private:
        FuncWrapper m_funcWrapper;
    };

    template<typename FuncWrapper>
    coil::detail::AnyStorage<FuncWrapper>::AnyStorage(FuncWrapper func) : m_funcWrapper(std::move(func)) {}

    template<typename FuncWrapper>
    void coil::detail::AnyStorage<FuncWrapper>::invoke(CallContext& context)
    {
        using ArgsTraits = typename FuncWrapper::ArgsTraits;

        using UserArgTypes = typename ArgsTraits::UserArgumentTypes;
        using UserArgIndicesType = typename UserArgTypes::IndicesType;
        using NonUserArgsIndicesType = typename ArgsTraits::NonUserArgsIndices;

        unpackAndInvoke(m_funcWrapper, context, NonUserArgsIndicesType{}, UserArgTypes{}, UserArgIndicesType{});
    }

    // TODO get rid of AnyStorage by having pointers to template functions
    // TODO rename to 'FunctorDescriptor'
    struct AnyFunctor
    {
    public:
        template<typename FunctionWrapper>
        AnyFunctor(FunctionWrapper func);

        AnyFunctor(AnyFunctor const& rhs) = delete;
        AnyFunctor(AnyFunctor&& rhs);

        AnyFunctor& operator=(AnyFunctor const& rhs) = delete;
        AnyFunctor& operator=(AnyFunctor&& rhs) = delete;

        ~AnyFunctor();
        void invokeTrampoline(detail::CallContext& context);

        std::size_t arity() const;

    private:
        void destroy();

    private:
        AnyStorageBase* m_storage = nullptr;
        std::size_t m_arity;
    };

    template<typename FunctionWrapper>
    coil::detail::AnyFunctor::AnyFunctor(FunctionWrapper func)
    {
        m_storage = new AnyStorage<FunctionWrapper>(std::move(func));
        m_arity = FunctionWrapper::ArgsTraits::UserArgumentTypes::size;
    }

}
