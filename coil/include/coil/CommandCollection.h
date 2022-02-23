#include "Bindings.h"

#include <vector>
#include <string_view>

// TODO update this file and use it in the examples

namespace coil
{
    class CommandCollection final
    {
    public:
        CommandCollection(coil::Bindings& bindings) : m_bindings(&bindings) {}
        ~CommandCollection() { clear(); }

        CommandCollection(CommandCollection&& rhs)
        {
            clear();

            m_bindings = std::move(rhs.m_bindings);
            m_paths = std::move(rhs.m_paths);
        }

        CommandCollection& operator=(CommandCollection&& rhs)
        {
            clear();

            m_bindings = std::move(rhs.m_bindings);
            m_paths = std::move(rhs.m_paths);
            return *this;
        }

        template<typename Callable>
        void add(std::vector<std::string_view> path, Callable&& callable)
        {
            m_bindings->add(path, std::forward<Callable>(callable));
            m_paths.push_back(std::move(path));
        }

        BindingProxy<CommandCollection> operator[](std::string_view name)
        {
            return BindingProxy<CommandCollection>{ *this, { name } };
        }

    private:
        void clear()
        {
            for (auto const& path : m_paths)
                m_bindings->remove(path);
        }

        coil::Bindings* m_bindings;
        std::vector<std::vector<std::string_view>> m_paths;
    };
}
