#pragma once

#include "../Context.h"
#include "../TypeName.h"
#include "../TypeSerializer.h"
#include "../Types.h"
#include "../String.h"
#include "../StringView.h"
#include "../Optional.h"
#include "FuncTraits.h"
#include "Utility.h"
#include "Sequence.h"
#include "TypeTraits.h"

namespace coil::detail
{
    template<typename... Args>
    struct ArgsTraitsImpl
    {
        using UserArgumentTypes = Types<Args...>;
        using NonUserArgsIndices = IndexSequence<>;
    };

    template<typename... Tail>
    struct ArgsTraitsImpl<Context, Tail...>
    {
        using UserArgumentTypes = Types<Tail...>;
        using NonUserArgsIndices = IndexSequence<0>;
    };

    template<typename... Args>
    class FunctionWrapper final
    {
    public:
        using ArgsTraits = ArgsTraitsImpl<DecayT<Args>...>;

        template<typename Func, typename C = void>
        FunctionWrapper(Func func, C* obj = nullptr) : returnType(TypeName<DecayT<RemovePointerT<typename FuncTraits<Func>::ReturnType>>>::name())
        {
            m_func = new Func(coil::move(func));
            m_obj = const_cast<RemoveCvT<C>*>(obj); // this pointer would be casted back to C* in typedCall

            m_callFunc = &FunctionWrapper<Args...>::template typedCall<Func, C>;
            m_destroyFunc = &FunctionWrapper<Args...>::template typedDestroy<Func>;
        }
        ~FunctionWrapper();

        FunctionWrapper(FunctionWrapper const& rhs) = delete;
        FunctionWrapper(FunctionWrapper<Args...>&& rhs);

        FunctionWrapper& operator=(FunctionWrapper const& rhs) = delete;
        FunctionWrapper& operator=(FunctionWrapper&& rhs) = delete;

        Optional<String> invoke(Args... args);

        StringView returnType;

    private:
        using CallFuncPtr = Optional<String> (FunctionWrapper::*)(Args... args);
        using DestroyFuncPtr = void (FunctionWrapper::*)();

        template<typename Func, typename C>
        Optional<String> typedCall(Args... args)
        {
            Func& func = *static_cast<Func*>(m_func);
            [[maybe_unused]] C* obj = static_cast<C*>(m_obj);
            using R = typename FuncTraits<Func>::ReturnType;
            if constexpr (IsVoidV<R>)
            {
                if constexpr (IsVoidV<C>)
                    func(coil::move(args)...);
                else
                    (obj->*func)(coil::move(args)...);
                return {};
            }
            else
            {
                if constexpr (IsVoidV<C>)
                    return TypeSerializer<R>::toString(func(coil::move(args)...));
                else
                    return TypeSerializer<R>::toString((obj->*func)(coil::move(args)...));
            }
        }

        template<typename Func>
        void typedDestroy()
        {
            if (m_func)
                delete static_cast<Func*>(m_func);
            m_func = nullptr;
        }

    private:
        void* m_func = nullptr;
        void* m_obj = nullptr;
        CallFuncPtr m_callFunc = nullptr;
        DestroyFuncPtr m_destroyFunc = nullptr;
    };

    template<typename... Args>
    FunctionWrapper<Args...>::FunctionWrapper(FunctionWrapper<Args...>&& rhs) : returnType(rhs.returnType)
    {
        m_func = rhs.m_func;
        rhs.m_func = nullptr;

        m_obj = rhs.m_obj;
        m_callFunc = rhs.m_callFunc;
        m_destroyFunc = rhs.m_destroyFunc;
    }

    template<typename... Args>
    coil::detail::FunctionWrapper<Args...>::~FunctionWrapper()
    {
        (this->*m_destroyFunc)();
    }

    template<typename... Args>
    Optional<String> FunctionWrapper<Args...>::invoke(Args... args)
    {
        return (this->*m_callFunc)(coil::move(args)...);
    }
}
