#pragma once

#include "Overloaded.h"
#include "TypeTraits.h"
#include "Utility.h"

namespace coil
{
    template<typename Func, typename Arg, typename... RestArgs>
    decltype(auto) simpleInvoke(Func&& func, Arg&& arg0, RestArgs&&... args)
    {
        if constexpr (IsMemberPointerV<DecayT<Func>>)
            return (coil::forward<Arg>(arg0)->*coil::forward<Func>(func))(coil::forward<RestArgs>(args)...);
        else
            return coil::forward<Func>(func)(coil::forward<Arg>(arg0), coil::forward<RestArgs>(args)...);
    }

    template<typename G, typename S>
    auto property(G getter, S setter)
    {
        auto get = [getter]() -> decltype(auto) { return getter(); };

        using T = DecayT<decltype(getter())>;
        auto set = [getter, setter = coil::move(setter)](T const& value) -> decltype(auto) {
            setter(value);
            return getter();
        };

        return coil::overloaded(coil::move(get), coil::move(set));
    }

    template<typename G>
    auto property(G getter)
    {
        auto get = [getter]() -> decltype(auto) { return getter(); };

        auto set = [getter](Context context, coil::Value) -> decltype(auto) {
            context.reportError("This property is read-only");
            return getter();
        };

        return coil::overloaded(coil::move(get), coil::move(set));
    }

    template<typename C, typename G, typename S>
    auto bindProperty(G getter, S setter, C* object)
    {
        auto get = [getter, object]() -> decltype(auto) { return simpleInvoke(getter, object); };

        using T = DecayT<decltype(simpleInvoke(getter, object))>;
        auto set = [getter, setter = coil::move(setter), object](T const& value) -> decltype(auto) {
            simpleInvoke(setter, object, value);
            return simpleInvoke(getter, object);
        };

        return coil::overloaded(coil::move(get), coil::move(set));
    }

    template<typename C, typename G>
    auto bindProperty(G getter, C* object)
    {
        auto get = [getter, object]() -> decltype(auto) { return simpleInvoke(getter, object); };

        using T = DecayT<decltype(simpleInvoke(getter, object))>;
        auto set = [getter, object](Context context, T) -> decltype(auto) {
            context.reportError("This property is read-only");
            return simpleInvoke(getter, object);
        };

        return coil::overloaded(coil::move(get), coil::move(set));
    }
}
