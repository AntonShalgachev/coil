#pragma once

#include <string>
#include <vector>
#include <optional>

#include "CallContext.h"
#include "../utils/Types.h"
#include "coil/TypeSerializer.h"
#include "FuncTraitsEx.h"

namespace coil::detail
{
    // TODO move to another file
    // TODO allow specialization
    template<typename T>
    struct VariadicConsumer
    {
        template<typename OnError>
        static T consume(std::vector<std::string_view> const& arguments, std::size_t index, OnError&& onError)
        {
            return TypeSerializer<T>::fromString(arguments[index], std::forward<OnError>(onError));
        }
    };

    template<typename T>
    struct VariadicConsumer<std::vector<T>>
    {
        template<typename OnError>
        static std::vector<T> consume(std::vector<std::string_view> const& arguments, std::size_t index, OnError&& onError)
        {
            std::vector<T> args;
            args.reserve(arguments.size() - index);

            for (auto i = index; i < arguments.size(); i++)
                args.push_back(TypeSerializer<T>::fromString(arguments[i], onError));

            return args;
        }
    };

    template<typename T>
    struct VariadicConsumer<std::optional<T>>
    {
        template<typename OnError>
        static std::optional<T> consume(std::vector<std::string_view> const& arguments, std::size_t index, OnError&& onError)
        {
            if (index >= arguments.size())
                return {};

            return TypeSerializer<T>::fromString(arguments[index], std::forward<OnError>(onError));
        }
    };

    inline void reportInvalidArguments(std::size_t minArgs, std::size_t isUnlimited, std::size_t maxArgs, CallContext& context)
    {
        auto const& arguments = context.input.arguments;
        std::size_t const actualArgsCount = arguments.size();

        bool isVariadic = isUnlimited || (minArgs != maxArgs);

        std::string expectedMessage;
        if (isVariadic && isUnlimited)
            expectedMessage = utils::formatString("at least %d", minArgs);
        else if (isVariadic && !isUnlimited)
            expectedMessage = utils::formatString("from %d to %d", minArgs, maxArgs);
        else
            expectedMessage = utils::formatString("%d", minArgs);

        std::string_view functionName = context.input.functionName;
        auto errorMessage = utils::formatString("Wrong number of arguments to '%.*s': expected %s, got %d", functionName.size(), functionName.data(), expectedMessage.c_str(), actualArgsCount);

        context.result.errors.push_back(std::move(errorMessage));
    }

    inline bool validateArguments(std::size_t minArgs, std::size_t isUnlimited, std::size_t maxArgs, CallContext& context)
    {
        std::size_t const actualArgsCount = context.input.arguments.size();
        bool const argsCountOkay = actualArgsCount >= minArgs && (isUnlimited || actualArgsCount <= maxArgs);
        if (!argsCountOkay)
        {
            reportInvalidArguments(minArgs, isUnlimited, maxArgs, context);
            return false;
        }

        return true;
    }

    template<typename Func, typename Arg1, typename... Args>
    decltype(auto) invokeFunc(Func& func, Arg1&& arg1, Args&&... args)
    {
        if constexpr (utils::FuncTraits<Func>::isMethod)
            return (std::forward<Arg1>(arg1)->*func)(std::forward<Args>(args)...);
        else
            return func(std::forward<Arg1>(arg1), std::forward<Args>(args)...);
    }

    template<typename Func>
    decltype(auto) invokeFunc(Func& func)
    {
        return func();
    }

    template<typename Func, typename... Args>
    void invoke(ExecutionResult& result, Func& func, Args&&... args)
    {
        if (!result)
            return;

        using R = typename detail::FuncTraitsEx<Func>::ReturnType;

        try
        {
            if constexpr (std::is_void_v<R>)
            {
                invokeFunc(func, std::forward<Args>(args)...);
            }
            else
            {
                auto&& returnValue = invokeFunc(func, std::forward<Args>(args)...);
                if (result)
                    result.returnValue = TypeSerializer<std::decay_t<R>>::toString(returnValue);
            }
        }
        catch (std::exception const& ex)
        {
            result.errors.push_back(utils::formatString("Exception caught during execution: %s", ex.what()));
        }
    }

    struct ContextErrorAppender
    {
        ContextErrorAppender(CallContext& context) : m_context(context) {}

        void operator()(std::string error) const
        {
            m_context.result.errors.push_back(std::move(error));
        }

    private:
        CallContext& m_context;
    };

    template<typename T>
    struct NonUserArgs
    {
        T* target = nullptr;
        Context context;
        NamedArgs namedArgs;

        T* get(std::integral_constant<std::size_t, 0>) { return target; }
        Context& get(std::integral_constant<std::size_t, 1>) { return context; }
        NamedArgs& get(std::integral_constant<std::size_t, 2>) { return namedArgs; }
    };

    template<typename Func, typename T, std::size_t... NonUserIndices, typename... UserArgs, std::size_t... UserIndices>
    void unpackAndInvoke(Func& func, CallContext& context, NonUserArgs<T>& nonUserArgs, std::index_sequence<NonUserIndices...>, utils::Types<UserArgs...>, std::index_sequence<UserIndices...>)
    {
        ContextErrorAppender onError{ context };

        invoke(context.result, func, nonUserArgs.get(std::integral_constant<std::size_t, NonUserIndices>{})..., VariadicConsumer<std::decay_t<UserArgs>>::consume(context.input.arguments, UserIndices, onError)...);
    }
}
