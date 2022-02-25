#pragma once

// TODO rename file

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
        MemberVariableWrapper(T C::* variable, C* object) : m_variable(variable), m_object(object)
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
        T& get()
        {
            return m_object->*m_variable;
        }

        T C::* m_variable = nullptr;
        C* m_object = nullptr;
    };
}

namespace coil
{
    template<typename T>
    auto variable(T* var)
    {
        return utils::VariableWrapper<T>{ var };
    }

    // TODO remove? Just get a variable from object
    template<typename T, typename C>
    auto variable(T C::* var, C* object)
    {
        return utils::MemberVariableWrapper<T, C>{ var, object };
    }
}
