#pragma once

#include <optional>
#include <string>
#include <memory>

namespace coil::detail
{
    template<typename... Args>
    class FunctionWrapper final
    {
    public:
        using ArgsTraits = ArgsTraitsImpl<std::decay_t<Args>...>; // TODO simplier decay

        template<typename Func, typename C = void>
        FunctionWrapper(Func func, C* obj = nullptr)
        {
            using UnqualifiedFunc = std::decay_t<Func>;

            static_assert(!std::is_member_function_pointer_v<UnqualifiedFunc> || !std::is_void_v<C>, "Func can only be a member function if C isn't void");

            m_func = new UnqualifiedFunc(std::move(func));
            m_obj = const_cast<std::remove_const_t<C>*>(obj); // this pointer would be casted back to C* in typedCall

            m_callFunc = &FunctionWrapper<Args...>::typedCall<UnqualifiedFunc, C>;
            m_destroyFunc = &FunctionWrapper<Args...>::typedDestroy<UnqualifiedFunc>;
        }
        ~FunctionWrapper();

        FunctionWrapper(FunctionWrapper const& rhs) = delete;
        FunctionWrapper(FunctionWrapper<Args...>&& rhs);

        FunctionWrapper& operator=(FunctionWrapper const& rhs) = delete;
        FunctionWrapper& operator=(FunctionWrapper&& rhs) = delete;

        std::optional<std::string> invoke(Args... args);


    private:
        using CallFuncPtr = std::optional<std::string>(FunctionWrapper::*)(Args... args);
        using DestroyFuncPtr = void(FunctionWrapper::*)();

        template<typename Func, typename C>
        std::optional<std::string> typedCall(Args... args)
        {
            Func& func = *static_cast<Func*>(m_func);
            C* obj = static_cast<C*>(m_obj);
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
