#pragma once

#include <string>

namespace coil
{
    template<typename Bindings, typename KeyT>
    class BindingProxy
    {
    public:
        BindingProxy(Bindings& bindings, KeyT name) : m_bindings(bindings), m_name(std::move(name)) {}

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

        BindingProxy& operator=(std::nullptr_t) const = delete;

        BindingProxy& operator=(std::nullptr_t)
        {
            m_bindings.unbind(m_name);
            return *this;
        }

    private:
        Bindings& m_bindings;
        KeyT m_name;
    };
}
