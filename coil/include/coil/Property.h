#pragma once
#include <type_traits>

namespace coil
{
    template<typename G, typename S>
    class Property
    {
    public:
        using T = std::decay_t<decltype(std::declval<G>()())>;

        Property(G&& getter, S&& setter) : m_getter(std::forward<G>(getter)), m_setter(std::forward<S>(setter)) {}

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

        MemberProperty(G&& getter, S&& setter) : m_getter(std::forward<G>(getter)), m_setter(std::forward<S>(setter)) {}

        T operator()(C* target, std::optional<T> const& arg)
        {
            // TODO add user-friendly static_asserts

            if (arg.has_value())
                std::invoke(m_setter, target, arg.value());

            return std::invoke(m_getter, target);
        }

    private:
        G m_getter;
        S m_setter;
    };

    template<typename G, typename S>
    auto createProperty(G&& getter, S&& setter)
    {
        using GetterTraits = detail::FuncTraitsEx<G>;
        using SetterTraits = detail::FuncTraitsEx<S>;
        static constexpr bool getterHasTarget = GetterTraits::isMethod || GetterTraits::ArgsTraits::hasTarget;
        static constexpr bool setterHasTarget = SetterTraits::isMethod || SetterTraits::ArgsTraits::hasTarget;

        static_assert(getterHasTarget == setterHasTarget, "Either both or none functors should be callable with a target");
        static constexpr bool hasTarget = getterHasTarget;

        if constexpr (!hasTarget)
        {
            return Property{ std::forward<G>(getter), std::forward<S>(setter) };
        }
        else
        {
            using GetterTargetType = std::conditional_t<GetterTraits::ArgsTraits::hasTarget, typename GetterTraits::ArgsTraits::ExplicitTargetType, typename GetterTraits::ObjectType>;
            using SetterTargetType = std::conditional_t<SetterTraits::ArgsTraits::hasTarget, typename SetterTraits::ArgsTraits::ExplicitTargetType, typename SetterTraits::ObjectType>;

            static_assert(std::is_same_v<GetterTargetType, SetterTargetType>, "Both functors should be callable with the same target type");

            using C = GetterTargetType;

            return MemberProperty<C, G, S>(std::forward<G>(getter), std::forward<S>(setter));
        }
    }
}
