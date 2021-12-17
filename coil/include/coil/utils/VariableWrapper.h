#pragma once

#include <optional>

namespace coil::utils
{
    // TODO support const variables

    template<typename T>
    struct VariableWrapper
    {
    public:
        VariableWrapper(T* variable) : m_variable(variable)
        {
            static_assert(!std::is_const_v<T>, "Variable shouldn't be const");
        }

        T const& operator()(std::optional<T> const& arg)
        {
            if (arg.has_value())
                get() = arg.value();

            return get();
        }

    private:
        T& get() const
        {
            return *m_variable;
        }

        T* m_variable = nullptr;
    };

    template<typename T, typename C>
    struct MemberVariableWrapper
    {
    public:
        MemberVariableWrapper(T C::* variable) : m_variable(variable)
        {
            static_assert(!std::is_const_v<T>, "Variable shouldn't be const");
        }

        T const& operator()(C* target, std::optional<T> const& arg)
        {
            if (arg.has_value())
                get(target) = arg.value();

            return get(target);
        }

    private:
        T& get(C* target)
        {
            return std::invoke(m_variable, target); // TODO don't use std::invoke
        }

        T C::* m_variable = nullptr;
    };
}
