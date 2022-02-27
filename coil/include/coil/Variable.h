#pragma once

#include <optional>

namespace coil
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

    template<typename T>
    auto variable(T* var)
    {
        return VariableWrapper<T>{ var };
    }
}
