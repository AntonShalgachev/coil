#include "EncapsulationExample.h"

#include "common/ExamplesCommon.h"

#include "coil/StdLibCompat.h" // implementation of TypeSerializer and TypeName for some C++ Standard Library types

#include <iostream>
#include <memory>
#include <vector>

#include "assert.h"

// Try undefining this macro to remove command bindings from Subsystem
// This might be useful to remove the commands from the Release build
#define DEBUG_CONSOLE_ENABLED

namespace utils
{
    std::unique_ptr<coil::Bindings> g_globalBindings;

    class CommandsProxy;

    // This helper class can be used to automatically remove registered commands upon destructor
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
        void add(coil::StringView name, Functor&& functor)
        {
            utils::g_globalBindings->add(name, std::forward<Functor>(functor));
            m_names.push_back(coil::String{name});
        }

        CommandsProxy operator[](coil::StringView name);

    private:
        void clear()
        {
            for (auto const& name : m_names)
                utils::g_globalBindings->remove(name);
            m_names.clear();
        }

        std::vector<coil::String> m_names;
    };

    class CommandsProxy
    {
    public:
        CommandsProxy(ScopedDebugCommands& commands, coil::StringView name) : m_commands(commands), m_name(name) {}

        template<typename Func>
        CommandsProxy& operator=(Func&& func)
        {
            m_commands.add(m_name, std::forward<Func>(func));
            return *this;
        }
        CommandsProxy& operator=(coil::AnyFunctor anyFunctor)
        {
            m_commands.add(m_name, std::move(anyFunctor));
            return *this;
        }
        CommandsProxy& operator=(coil::Vector<coil::AnyFunctor> anyFunctors)
        {
            m_commands.add(m_name, std::move(anyFunctors));
            return *this;
        }

    private:
        ScopedDebugCommands& m_commands;
        coil::StringView m_name;
    };

    utils::CommandsProxy ScopedDebugCommands::operator[](coil::StringView name)
    {
        return CommandsProxy{*this, name};
    }
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
            return m_data + ": " + std::move(s) + std::to_string(i);
        }

        float m_time = 3.14f;
        int m_counter = 7;
        std::string m_data = "Something";

#ifdef DEBUG_CONSOLE_ENABLED
        utils::ScopedDebugCommands m_commands;
#endif
    };
}

void EncapsulationExample::run()
{
    utils::g_globalBindings = std::make_unique<coil::Bindings>();

    coil::Bindings& bindings = *utils::g_globalBindings;

    std::unique_ptr<Subsystem> subsystem;
    bindings["create_subsystem"] = [&subsystem]() { subsystem = std::make_unique<Subsystem>(); };
    bindings["destroy_subsystem"] = [&subsystem]() { subsystem = nullptr; };

    // if you undefine DEBUG_CONSOLE_ENABLED then the subsystem commands won't be registered, but the object would still be alive
    common::printSectionHeader("This is an example of encapsulating commands within an object (try undefining DEBUG_CONSOLE_ENABLED):");
    common::executeCommand(bindings, "create_subsystem");
    common::executeCommand(bindings, "subsystem.time");
    common::executeCommand(bindings, "subsystem.do_some_work foo 42");

    common::printSectionHeader("The object is alive and can still do work even without DEBUG_CONSOLE_ENABLED:");
    subsystem->doWorkPublicly();
    std::cout << std::endl;

    common::printSectionHeader("After destroying the subsystem all relevant commands would also be removed");
    common::executeCommand(bindings, "destroy_subsystem");
    common::executeCommand(bindings, "subsystem.data");
    common::executeCommand(bindings, "subsystem.do_some_work foo 42");

    utils::g_globalBindings = nullptr;
}
