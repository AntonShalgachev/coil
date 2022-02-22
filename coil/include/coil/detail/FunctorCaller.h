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

        auto errorMessage = utils::formatString("Wrong number of arguments to '%.*s': expected %s, got %d", context.input.name.size(), context.input.name.data(), expectedMessage.c_str(), actualArgsCount);

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

    template<std::size_t i>
    inline Context createContext(CallContext& context);
    template<>
    inline Context createContext<0>(CallContext& context)
    {
        return Context{ context };
    }

    template<typename Func, std::size_t... NonUserIndices, typename... Es, bool isVoid = std::is_void_v<typename detail::FuncTraitsEx<Func>::ReturnType>>
    void invoke(Func& func, CallContext& context, Es&&... expectedArgs)
    {
        if (!(expectedArgs && ...))
            return;

        using R = typename detail::FuncTraitsEx<Func>::ReturnType;

        try
        {
            if constexpr (isVoid)
            {
                func(createContext<NonUserIndices>(context)..., *std::forward<Es>(expectedArgs)...);
            }
            else
            {
                auto&& returnValue = func(createContext<NonUserIndices>(context)..., *std::forward<Es>(expectedArgs)...);
                if (!context.hasErrors())
                    context.result.returnValue = TypeSerializer<std::decay_t<R>>::toString(returnValue);
            }
        }
        catch (std::exception const& ex)
        {
            context.reportError(utils::formatString("Exception caught during execution: %s", ex.what()));
        }
    }

    template<typename Func, std::size_t... NonUserIndices, typename... UserArgs, std::size_t... UserIndices>
    void unpackAndInvoke(Func& func, CallContext& context, std::index_sequence<NonUserIndices...>, utils::Types<UserArgs...>, std::index_sequence<UserIndices...>)
    {
        invoke<Func, NonUserIndices...>(func, context, VariadicConsumer<std::decay_t<UserArgs>>::consume(Context{ context }, context.input.arguments, UserIndices)...);
    }

    template<typename FuncT>
    void functorTrampoline(std::any& anyFunctor, detail::CallContext& context)
    {
        FuncT* functor = std::any_cast<FuncT>(&anyFunctor);

        if (!functor)
        {
            context.result.errors.push_back("Internal error");
            return;
        }

        using FuncTraits = detail::FuncTraitsEx<FuncT>;
        using ArgsTraits = typename FuncTraits::ArgsTraits;

        if (!validateArguments(ArgsTraits::minArgs, ArgsTraits::isUnlimited, ArgsTraits::maxArgs, context))
            return;

        using UserArgTypes = typename ArgsTraits::UserArgumentTypes;
        using UserArgIndicesType = typename UserArgTypes::IndicesType;
        using NonUserArgsIndicesType = typename ArgsTraits::NonUserArgsIndices;

        unpackAndInvoke(*functor, context, NonUserArgsIndicesType{}, UserArgTypes{}, UserArgIndicesType{});
    }
}
