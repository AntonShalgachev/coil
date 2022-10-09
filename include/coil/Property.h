#pragma once

#include "Overloaded.h"
#include "detail/TypeTraits.h"
#include "detail/Utility.h"

#include <functional>

namespace coil
{
    template<typename G, typename S>
    auto property(G getter, S setter)
    {
        auto get = [getter]() -> decltype(auto) { return getter(); };

        using T = RemoveCvT<RemoveReferenceT<decltype(getter())>>;
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
        auto get = [getter, object]() -> decltype(auto) { return std::invoke(getter, object); };

        using T = RemoveCvT<RemoveReferenceT<decltype(std::invoke(getter, object))>>;
        auto set = [getter, setter = Move(setter), object](T const& value) -> decltype(auto) {
            std::invoke(setter, object, value);
            return std::invoke(getter, object);
        };

        return coil::overloaded(Move(get), Move(set));
    }

    template<typename C, typename G>
    auto bindProperty(G getter, C* object)
    {
        auto get = [getter, object]() -> decltype(auto) { return std::invoke(getter, object); };

        using T = RemoveCvT<RemoveReferenceT<decltype(std::invoke(getter, object))>>;
        auto set = [getter, object](Context context, T) -> decltype(auto) {
            context.reportError("This property is read-only");
            return std::invoke(getter, object);
        };

        return coil::overloaded(Move(get), Move(set));
    }
}
