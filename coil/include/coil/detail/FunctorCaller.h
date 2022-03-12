#pragma once

#include <string>
#include <any>

#include "CallContext.h"
#include "coil/Types.h"
#include "coil/TypeSerializer.h"
#include "FuncTraits.h"

namespace coil::detail
{
    template<std::size_t i>
    inline Context createContext(CallContext& context);
    template<>
    inline Context createContext<0>(CallContext& context)
    {
        return Context{ context };
    }

    template<typename T>
    void reportError(CallContext& context, Expected<T, std::string> const& result)
    {
        if (!result)
            context.reportError(result.error());
    }

    template<typename Func, std::size_t... NonUserIndices, typename... Es>
    void invoke(Func& func, CallContext& context, Es&&... expectedArgs)
    {
        if ((!expectedArgs || ...))
        {
            (reportError(context, expectedArgs), ...);
            return;
        }

        using R = typename detail::FuncTraits<Func>::ReturnType;

        try
        {
            if constexpr (std::is_void_v<R>)
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
            context.reportError(formatString("Exception caught during execution: %s", ex.what()));
        }
        catch (...)
        {
            context.reportError("Exception caught during execution");
        }
    }

    template<typename Func, std::size_t... NonUserIndices, typename... UserArgs, std::size_t... UserIndices>
    void unpackAndInvoke(Func& func, CallContext& context, std::index_sequence<NonUserIndices...>, Types<UserArgs...>, std::index_sequence<UserIndices...>)
    {
        invoke<Func, NonUserIndices...>(func, context, TypeSerializer<std::decay_t<UserArgs>>::fromString(context.input.arguments[UserIndices])...);
    }

    template<typename FuncT>
    void functorTrampoline(std::any& anyFunctor, detail::CallContext& context)
    {
        FuncT* functor = std::any_cast<FuncT>(&anyFunctor);

        if (!functor)
        {
            context.result.errors.push_back("Internal error"); // @NOCOVERAGE
            return; // @NOCOVERAGE
        }

        using FuncTraits = detail::FuncTraits<FuncT>;
        using ArgsTraits = typename FuncTraits::ArgsTraits;

        using UserArgTypes = typename ArgsTraits::UserArgumentTypes;
        using UserArgIndicesType = typename UserArgTypes::IndicesType;
        using NonUserArgsIndicesType = typename ArgsTraits::NonUserArgsIndices;

        unpackAndInvoke(*functor, context, NonUserArgsIndicesType{}, UserArgTypes{}, UserArgIndicesType{});
    }
}
