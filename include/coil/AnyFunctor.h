#pragma once

#include "detail/CallContext.h"
#include "detail/FunctionWrapper.h"
#include "detail/FunctorCaller.h"

namespace coil
{
    // std::any and std::unique_ptr produce too much compile-time overhead, so implement a basic solution for that

    namespace detail
    {
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
        coil::detail::AnyStorage<FuncWrapper>::AnyStorage(FuncWrapper func) : m_funcWrapper(std::move(func))
        {
        }

        template<typename FuncWrapper>
        void coil::detail::AnyStorage<FuncWrapper>::invoke(CallContext& context)
        {
            using ArgsTraits = typename FuncWrapper::ArgsTraits;

            using UserArgTypes = typename ArgsTraits::UserArgumentTypes;
            using UserArgIndicesType = typename UserArgTypes::IndicesType;
            using NonUserArgsIndicesType = typename ArgsTraits::NonUserArgsIndices;

            unpackAndInvoke(m_funcWrapper, context, NonUserArgsIndicesType{}, UserArgTypes{}, UserArgIndicesType{});
        }
    }

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
        std::vector<std::string_view> const& parameterTypes() const;
        std::string_view returnType() const;

    private:
        void destroy();

    private:
        detail::AnyStorageBase* m_storage = nullptr;
        std::vector<std::string_view> m_parameterTypes;
        std::string_view m_returnType;
    };

    template<typename FunctionWrapper>
    coil::AnyFunctor::AnyFunctor(FunctionWrapper func) : m_parameterTypes(FunctionWrapper::ArgsTraits::UserArgumentTypes::names()), m_returnType(func.returnType)
    {
        m_storage = new detail::AnyStorage<FunctionWrapper>(std::move(func));
    }
}
