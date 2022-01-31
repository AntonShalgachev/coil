#pragma once

#include <string>
#include <vector>
#include <optional>

#include "CallContext.h"
#include "../utils/Types.h"
#include "coil/TypeSerializer.h"
#include "FuncTraitsEx.h"
#include "coil/VariadicConsumer.h"

namespace coil::detail
{
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

    template<typename T>
    struct NonUserArgs
    {
        T* target = nullptr;
        Context context;

        T* get(std::integral_constant<std::size_t, 0>) { return target; }
        Context& get(std::integral_constant<std::size_t, 1>) { return context; }
    };

    template<typename Func, typename T, std::size_t... NonUserIndices, typename... Es, bool isVoid = std::is_void_v<typename detail::FuncTraitsEx<Func>::ReturnType>>
    void invoke(Func& func, CallContext& context, NonUserArgs<T>& nonUserArgs, Es&&... expectedArgs)
    {
        if (!(expectedArgs && ...))
            return;

        using R = typename detail::FuncTraitsEx<Func>::ReturnType;

        try
        {
            if constexpr (isVoid)
            {
                invokeFunc(func, nonUserArgs.get(std::integral_constant<std::size_t, NonUserIndices>{})..., *std::forward<Es>(expectedArgs)...);
            }
            else
            {
                auto&& returnValue = invokeFunc(func, nonUserArgs.get(std::integral_constant<std::size_t, NonUserIndices>{})..., *std::forward<Es>(expectedArgs)...);
                if (!context.hasErrors())
                    context.result.returnValue = TypeSerializer<std::decay_t<R>>::toString(returnValue);
            }
        }
        catch (std::exception const& ex)
        {
            context.reportError(utils::formatString("Exception caught during execution: %s", ex.what()));
        }
    }

    template<typename Func, typename T, std::size_t... NonUserIndices, typename... UserArgs, std::size_t... UserIndices>
    void unpackAndInvoke(Func& func, CallContext& context, NonUserArgs<T>& nonUserArgs, std::index_sequence<NonUserIndices...>, utils::Types<UserArgs...>, std::index_sequence<UserIndices...>)
    {
        invoke<Func, T, NonUserIndices...>(func, context, nonUserArgs, VariadicConsumer<std::decay_t<UserArgs>>::consume(Context{ context }, context.input.arguments, UserIndices)...);
    }
}
