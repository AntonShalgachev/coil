#pragma once

#include <string>

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
    void invoke(Func& func, CallContext& context, Es... expectedArgs)
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
                func(createContext<NonUserIndices>(context)..., *std::move(expectedArgs)...);
            }
            else
            {
                auto&& returnValue = func(createContext<NonUserIndices>(context)..., *std::move(expectedArgs)...);
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
}

#define EXTERN_EEXPLICIT_FUNCTOR_CALLER_TEMPLATE(T) \
    extern template void coil::detail::reportError<T>(coil::detail::CallContext& context, coil::Expected<T, std::string> const& result)

#define EEXPLICIT_FUNCTOR_CALLER_TEMPLATE(T) \
    template void coil::detail::reportError<T>(coil::detail::CallContext& context, coil::Expected<T, std::string> const& result)

EXTERN_EEXPLICIT_FUNCTOR_CALLER_TEMPLATE(int);
EXTERN_EEXPLICIT_FUNCTOR_CALLER_TEMPLATE(short);
EXTERN_EEXPLICIT_FUNCTOR_CALLER_TEMPLATE(bool);
EXTERN_EEXPLICIT_FUNCTOR_CALLER_TEMPLATE(unsigned);
EXTERN_EEXPLICIT_FUNCTOR_CALLER_TEMPLATE(float);
EXTERN_EEXPLICIT_FUNCTOR_CALLER_TEMPLATE(double);
