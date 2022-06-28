#include "EncapsulationExample.h"

#include "common/ExamplesCommon.h"

#include <iostream>

// Try undefining this macro to remove command bindings from Subsystem
// This might be useful to remove the commands from the Release build
#define DEBUG_CONSOLE_ENABLED

namespace utils
{
    coil::Bindings& getGlobalBindings()
    {
        static coil::Bindings bindings;
        return bindings;
    }

    // This helper class can be used to automatically remove registered commands upon destructor
    // It relies on coil::BindingProxy, but can be implemented in other ways without BindingProxy
    class ScopedDebugCommands
    {
    public:
        ScopedDebugCommands() = default;
        ScopedDebugCommands(ScopedDebugCommands&& rhs)
        {
            clear();
            m_names = std::move(rhs.m_names);
        }

        ~ScopedDebugCommands()
        {
            clear();
        }

        ScopedDebugCommands& operator=(ScopedDebugCommands&& rhs)
        {
            clear();
            m_names = std::move(rhs.m_names);
            return *this;
        }

        template<typename Functor>
        void add(std::string_view name, Functor&& functor)
        {
            getGlobalBindings().add(name, std::forward<Functor>(functor));
            m_names.push_back(std::string{name});
        }

        coil::BindingProxy<ScopedDebugCommands> operator[](std::string_view name)
        {
            return coil::BindingProxy<ScopedDebugCommands>{*this, name};
        }

    private:
        void clear()
        {
            for (auto const& name : m_names)
                getGlobalBindings().remove(name);
        }

        std::vector<std::string> m_names;
    };
}

namespace
{
    class Subsystem
    {
    public:
        Subsystem()
        {
#ifdef DEBUG_CONSOLE_ENABLED
            m_commands["subsystem.time"] = coil::variable(&m_time);
            m_commands["subsystem.counter"] = coil::variable(&m_counter);
            m_commands["subsystem.data"] = coil::variable(&m_data);
            m_commands["subsystem.do_some_work"] = coil::bind(&Subsystem::doSomeWork, this);
#endif // DEBUG_CONSOLE_ENABLED
        }

        void doWorkPublicly()
        {
            std::cout << "Subsystem is alive: " << m_time << " | " << doSomeWork(m_data, m_counter) << std::endl;
        }

    private:
        std::string doSomeWork(std::string s, int i)
        {
            return std::move(s) + std::to_string(i);
        }

        float m_time = 3.14f;
        int m_counter = 7;
        std::string m_data = "I have something";

#ifdef DEBUG_CONSOLE_ENABLED
        utils::ScopedDebugCommands m_commands;
#endif
    };
}

void EncapsulationExample::run()
{
    coil::Bindings& bindings = utils::getGlobalBindings();

    std::unique_ptr<Subsystem> subsystem;
    bindings["create_subsystem"] = [&subsystem]() { subsystem = std::make_unique<Subsystem>(); };
    bindings["destroy_subsystem"] = [&subsystem]() { subsystem = nullptr; };

    // if you undefine DEBUG_CONSOLE_ENABLED then the subsystem commands won't be registered, but the object would still be alive
    common::printSectionHeader("This is an example of encapsulating commands within an object:");
    common::executeCommand(bindings, "create_subsystem");
    common::executeCommand(bindings, "subsystem.time");
    common::executeCommand(bindings, "subsystem.do_some_work foo 42");
    subsystem->doWorkPublicly();
    common::executeCommand(bindings, "destroy_subsystem");
    common::executeCommand(bindings, "subsystem.data");
    common::executeCommand(bindings, "subsystem.do_some_work foo 42");
}
