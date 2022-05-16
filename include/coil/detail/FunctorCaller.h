#pragma once

#include <string>

#include "CallContext.h"
#include "coil/Types.h"
#include "coil/TypeSerializer.h"
#include "FuncTraits.h"

namespace coil::detail
{
    template<std::size_t i>
    Context createContext(CallContext& context);
    template<>
    Context createContext<0>(CallContext& context);

    void reportExceptionError(CallContext& context);
    void reportExceptionError(CallContext& context, std::exception const& ex);

    template<typename T>
    void reportError(CallContext& context, Expected<T, std::string> const& result)
    {
        if (!result)
            context.reportError(result.error());
    }

    template<typename FuncWrapper, std::size_t... NonUserIndices, typename... Es>
    void invoke(FuncWrapper& func, CallContext& context, Es... expectedArgs)
    {
        if ((!expectedArgs || ...))
        {
            (reportError(context, expectedArgs), ...);
            return;
        }

        try
        {
            std::optional<std::string> returnValue = func.invoke(createContext<NonUserIndices>(context)..., *std::move(expectedArgs)...);
            if (!context.hasErrors())
                context.result.returnValue = returnValue;
        }
        catch (std::exception const& ex)
        {
            reportExceptionError(context, ex);
        }
        catch (...)
        {
            reportExceptionError(context);
        }
    }

    template<typename FuncWrapper, std::size_t... NonUserIndices, typename... UserArgs, std::size_t... UserIndices>
    void unpackAndInvoke(FuncWrapper& func, CallContext& context, std::index_sequence<NonUserIndices...>, Types<UserArgs...>, std::index_sequence<UserIndices...>)
    {
        invoke<FuncWrapper, NonUserIndices...>(func, context, TypeSerializer<UserArgs>::fromString(context.input.arguments[UserIndices])...);
    }
}
