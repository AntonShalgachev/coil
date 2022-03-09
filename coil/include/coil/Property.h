#pragma once
#include <type_traits>

// TODO use coil::overloaded

namespace coil
{
    template<typename G, typename S>
    class Property
    {
    public:
        using T = std::decay_t<decltype(std::declval<G>()())>;

        Property(G getter, S setter) : m_getter(std::move(getter)), m_setter(std::move(setter)) {}

        T operator()(std::optional<T> const& arg)
        {
            // TODO add user-friendly static_asserts

            if (arg.has_value())
                m_setter(arg.value());

            return m_getter();
        }

    private:
        G m_getter;
        S m_setter;
    };

    template<typename C, typename G, typename S>
    class MemberProperty
    {
    public:
        using T = std::decay_t<decltype(std::invoke(std::declval<G>(), std::declval<C*>()))>;

        MemberProperty(G getter, S setter, C* object) : m_getter(std::move(getter)), m_setter(std::move(setter)), m_object(object) {}

        T operator()(std::optional<T> const& arg)
        {
            // TODO add user-friendly static_asserts

            if (arg.has_value())
                std::invoke(m_setter, m_object, arg.value());

            return std::invoke(m_getter, m_object);
        }

    private:
        G m_getter;
        S m_setter;
        C* m_object = nullptr;
    };

    // TODO rename to `property`
    template<typename G, typename S>
    auto createProperty(G&& getter, S&& setter)
    {
        return Property{ std::forward<G>(getter), std::forward<S>(setter) };
    }

    template<typename C, typename G, typename S>
    auto createProperty(G&& getter, S&& setter, C* object)
    {
        return MemberProperty{ std::forward<G>(getter), std::forward<S>(setter), object };
    }

    // TODO add readonly properties
}
