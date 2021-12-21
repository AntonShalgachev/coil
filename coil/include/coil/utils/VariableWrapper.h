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

        T const& operator()(std::optional<T> arg)
        {
            if (arg.has_value())
                get() = std::move(arg).value();

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

        T const& operator()(C* target, std::optional<T> arg)
        {
            if (arg.has_value())
                get(target) = std::move(arg).value();

            return get(target);
        }

    private:
        T& get(C* target)
        {
            return target->*m_variable;
        }

        T C::* m_variable = nullptr;
    };
}

namespace coil
{
    template<typename T>
    auto variable(T* var)
    {
        return utils::VariableWrapper<T>{ var };
    }

    template<typename T, typename C>
    auto variable(T C::* var)
    {
        return utils::MemberVariableWrapper<T, C>{ var };
    }
}
