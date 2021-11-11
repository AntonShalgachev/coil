#pragma once

#include <string>

namespace coil
{
    template<typename Bindings>
    class BindingProxy
    {
    public:
        BindingProxy(Bindings& bindings, std::string name) : m_bindings(bindings), m_name(std::move(name)) {}

        template<typename AnyT>
        BindingProxy& operator=(AnyT&& anything) const& = delete;

        template<typename AnyT>
        BindingProxy& operator=(AnyT&& anything)&
        {
            m_bindings.bind(m_name, std::forward<AnyT>(anything));
            return *this;
        }

        template<typename AnyT>
        BindingProxy& operator=(AnyT&& anything)&&
        {
            m_bindings.bind(std::move(m_name), std::forward<AnyT>(anything));
            return *this;
        }

        BindingProxy& operator=(nullptr_t) const = delete;

        BindingProxy& operator=(nullptr_t)
        {
            m_bindings.unbind(m_name);
            return *this;
        }

    private:
        Bindings& m_bindings;
        std::string m_name;
    };
}
