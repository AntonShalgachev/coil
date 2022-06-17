#pragma once

#include "Overloaded.h"

namespace coil
{
    template<typename G, typename S>
    auto property(G getter, S setter)
    {
        auto get = [getter]() -> decltype(auto) { return getter(); };

        using T = std::decay_t<decltype(getter())>;
        auto set = [getter, setter = std::move(setter)](T const& value) -> decltype(auto) {
            setter(value);
            return getter();
        };

        return coil::overloaded(std::move(get), std::move(set));
    }

    template<typename C, typename G, typename S>
    auto property(G&& getter, S&& setter, C* object)
    {
        auto get = [getter, object]() -> decltype(auto) { return std::invoke(getter, object); };

        using T = std::decay_t<decltype(std::invoke(getter, object))>;
        auto set = [getter, setter = std::move(setter), object](T const& value) -> decltype(auto) {
            std::invoke(setter, object, value);
            return std::invoke(getter, object);
        };

        return coil::overloaded(std::move(get), std::move(set));
    }

    // TODO add readonly properties
}
