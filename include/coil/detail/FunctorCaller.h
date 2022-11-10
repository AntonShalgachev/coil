#pragma once

// TODO don't use ".." (everywhere)
#include "../TypeSerializer.h"
#include "../Types.h"
#include "CallContext.h"
#include "Utility.h"
#include "Sequence.h"
#include "../String.h"
#include "../Assert.h"

namespace coil::detail
{
    template<size_t i>
    Context createContext(CallContext& context);
    template<>
    Context createContext<0>(CallContext& context);

    template<typename T>
    void reportError(CallContext& context, Expected<T, coil::String> const& result)
    {
        if (!result)
            context.reportError(result.error());
    }

    template<typename FuncWrapper, size_t... NonUserIndices, typename... Es>
    void invoke(FuncWrapper& func, CallContext& context, Es... expectedArgs)
    {
        if ((!expectedArgs || ...))
        {
            (reportError(context, expectedArgs), ...);
            return;
        }

        Optional<String> returnValue = func.invoke(createContext<NonUserIndices>(context)..., *coil::move(expectedArgs)...);
        if (!context.hasErrors())
            context.result.returnValue = coil::move(returnValue);
    }

    template<typename FuncWrapper, size_t... NonUserIndices, typename... UserArgs, size_t... UserIndices>
    void unpackAndInvoke(FuncWrapper& func, CallContext& context, IndexSequence<NonUserIndices...>, Types<UserArgs...>, IndexSequence<UserIndices...>)
    {
        invoke<FuncWrapper, NonUserIndices...>(func, context, TypeSerializer<UserArgs>::fromString(context.input.arguments[UserIndices])...);
    }
}
