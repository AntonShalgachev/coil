#pragma once

#include "../Context.h"
#include "../TypeName.h"
#include "../TypeSerializer.h"
#include "../Types.h"
#include "FuncTraits.h"

#include <memory>
#include <optional>
#include <string>

namespace coil::detail
{
    template<typename... Args>
    struct ArgsTraitsImpl
    {
        using UserArgumentTypes = Types<Args...>;
        using NonUserArgsIndices = std::index_sequence<>;
    };

    template<typename... Tail>
    struct ArgsTraitsImpl<Context, Tail...>
    {
        using UserArgumentTypes = Types<Tail...>;
        using NonUserArgsIndices = std::index_sequence<0>;
    };

    template<typename... Args>
    class FunctionWrapper final
    {
    public:
        template<typename T>
        using SimpleDecay = std::remove_cv_t<std::remove_reference_t<T>>;
        using ArgsTraits = ArgsTraitsImpl<SimpleDecay<Args>...>;

        template<typename Func, typename C = void>
        FunctionWrapper(Func func, C* obj = nullptr)
        {
            static_assert(!std::is_member_function_pointer_v<Func> || !std::is_void_v<C>, "Func can only be a member function if C isn't void");

            m_func = new Func(std::move(func));
            m_obj = const_cast<std::remove_const_t<C>*>(obj); // this pointer would be casted back to C* in typedCall

            m_callFunc = &FunctionWrapper<Args...>::typedCall<Func, C>;
            m_destroyFunc = &FunctionWrapper<Args...>::typedDestroy<Func>;

            using R = typename FuncTraits<Func>::ReturnType;
            returnType = TypeName<SimpleDecay<std::remove_pointer_t<R>>>::name();
        }
        ~FunctionWrapper();

        FunctionWrapper(FunctionWrapper const& rhs) = delete;
        FunctionWrapper(FunctionWrapper<Args...>&& rhs);

        FunctionWrapper& operator=(FunctionWrapper const& rhs) = delete;
        FunctionWrapper& operator=(FunctionWrapper&& rhs) = delete;

        std::optional<std::string> invoke(Args... args);

        std::string_view returnType;

    private:
        using CallFuncPtr = std::optional<std::string> (FunctionWrapper::*)(Args... args);
        using DestroyFuncPtr = void (FunctionWrapper::*)();

        template<typename Func, typename C>
        std::optional<std::string> typedCall(Args... args)
        {
            Func& func = *static_cast<Func*>(m_func);
            [[maybe_unused]] C* obj = static_cast<C*>(m_obj);
            using R = typename FuncTraits<Func>::ReturnType;
            if constexpr (std::is_void_v<R>)
            {
                if constexpr (std::is_void_v<C>)
                    func(std::move(args)...);
                else
                    (obj->*func)(std::move(args)...);
                return {};
            }
            else
            {
                if constexpr (std::is_void_v<C>)
                    return TypeSerializer<R>::toString(func(std::move(args)...));
                else
                    return TypeSerializer<R>::toString((obj->*func)(std::move(args)...));
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
    FunctionWrapper<Args...>::FunctionWrapper(FunctionWrapper<Args...>&& rhs)
    {
        m_func = rhs.m_func;
        rhs.m_func = nullptr;

        m_obj = rhs.m_obj;
        m_callFunc = rhs.m_callFunc;
        m_destroyFunc = rhs.m_destroyFunc;
        returnType = rhs.returnType;
    }

    template<typename... Args>
    coil::detail::FunctionWrapper<Args...>::~FunctionWrapper()
    {
        (this->*m_destroyFunc)();
    }

    template<typename... Args>
    std::optional<std::string> FunctionWrapper<Args...>::invoke(Args... args)
    {
        return (this->*m_callFunc)(std::move(args)...);
    }
}
