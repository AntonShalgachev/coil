#pragma once

#include "Overloaded.h"
#include "detail/TypeTraits.h"
#include "detail/Utility.h"

#include <string_view>

namespace coil
{
    template<typename Func, typename Arg, typename... RestArgs>
    decltype(auto) simpleInvoke(Func&& func, Arg&& arg0, RestArgs&&... args)
    {
        if constexpr (IsMemberPointerV<DecayT<Func>>)
            return (Forward<Arg>(arg0)->*Forward<Func>(func))(Forward<RestArgs>(args)...);
        else
            return Forward<Func>(func)(Forward<Arg>(arg0), Forward<RestArgs>(args)...);
    }

    template<typename G, typename S>
    auto property(G getter, S setter)
    {
        auto get = [getter]() -> decltype(auto) { return getter(); };

        using T = DecayT<decltype(getter())>;
        auto set = [getter, setter = Move(setter)](T const& value) -> decltype(auto) {
            setter(value);
            return getter();
        };

        return coil::overloaded(Move(get), Move(set));
    }

    template<typename G>
    auto property(G getter)
    {
        auto get = [getter]() -> decltype(auto) { return getter(); };

        auto set = [getter](Context context, std::string_view) -> decltype(auto) {
            context.reportError("This property is read-only");
            return getter();
        };

        return coil::overloaded(Move(get), Move(set));
    }

    template<typename C, typename G, typename S>
    auto bindProperty(G getter, S setter, C* object)
    {
        auto get = [getter, object]() -> decltype(auto) { return simpleInvoke(getter, object); };

        using T = DecayT<decltype(simpleInvoke(getter, object))>;
        auto set = [getter, setter = Move(setter), object](T const& value) -> decltype(auto) {
            simpleInvoke(setter, object, value);
            return simpleInvoke(getter, object);
        };

        return coil::overloaded(Move(get), Move(set));
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

        return coil::overloaded(Move(get), Move(set));
    }
}
