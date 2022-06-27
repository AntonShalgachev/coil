#include "AdvancedExample.h"

#include "common/ExamplesCommon.h"

#include <iostream>

namespace
{
    struct Entity
    {
        std::string id;
        std::string name;
        std::string payload;
    };

    class EntitySystem
    {
    public:
        void add(std::string id, std::string name, std::string payload)
        {
            m_entities.push_back(Entity{std::move(id), std::move(name), std::move(payload)});
        }

        Entity* find(std::string_view id)
        {
            auto it = std::find_if(m_entities.begin(), m_entities.end(), [id](Entity const& entity) { return entity.id == id; });
            if (it != m_entities.end())
                return &(*it);

            return nullptr;
        }

        std::vector<Entity> const& getEntities() const
        {
            return m_entities;
        }

    private:
        std::vector<Entity> m_entities;
    };

    void renameEntity(Entity* entity, std::string newName)
    {
        entity->name = std::move(newName);
    }
}

namespace utils
{
    coil::Bindings& getGlobalBindings()
    {
        static coil::Bindings bindings;
        return bindings;
    }

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

// #define DEBUG_CONSOLE_ENABLED

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

namespace coil
{
    template<>
    struct TypeSerializer<Entity>
    {
        static auto toString(Entity const& value)
        {
            std::stringstream ss;
            ss << "EntityId{" << value.id << "}";
            return ss.str();
        }
    };
}

void AdvancedExample::run()
{
    coil::Bindings bindings;

    EntitySystem entities;
    entities.add("player", "Player", "I am a player");
    entities.add("npc1", "NPC 1", "A pretty weak NPC");
    entities.add("npc2", "NPC 2", "A strong NPC");

    bindings["entities.rename"] = [&entities](coil::Context context, std::string_view id, std::string name) {
        Entity* entity = entities.find(id);
        if (!entity)
        {
            context.reportError("Failed to find entity '" + std::string{id} + "'");
            return;
        }

        renameEntity(entity, std::move(name));
    };

    bindings["entities.create_entity_variable"] = [&entities, &bindings](std::string_view name, std::string_view id) {
        auto get = [&entities, id]() { return entities.find(id); };
        bindings[name] = coil::property([get]() { return get(); });
        bindings[std::string(name) + ".id"] = coil::property([get]() { return get()->id; });
        bindings[std::string(name) + ".name"] = coil::property([get]() { return get()->name; }, [get](std::string const& value) { get()->name = value; });
        bindings[std::string(name) + ".payload"] = coil::property([get]() { return get()->payload; }, [get](std::string const& value) { get()->payload = value; });
    };

    bindings["entities.list"] = [&entities](coil::Context context) {
        context.out() << "ID\tName\tPayload" << std::endl;
        context.out() << "--\t----\t-------" << std::endl;
        for (Entity const& entity : entities.getEntities())
            context.out() << entity.id << '\t' << entity.name << '\t' << entity.payload << std::endl;
    };

    common::printSectionHeader("You can wrap functions taking pointers:");
    common::executeCommand(bindings, "entities.list");
    common::executeCommand(bindings, "entities.rename npc1 'Enemy'");
    common::executeCommand(bindings, "entities.list");

    common::printSectionHeader("You can create variables dynamically:");
    common::executeCommand(bindings, "entities.list");
    common::executeCommand(bindings, "entities.create_entity_variable player_entity player");
    common::executeCommand(bindings, "player_entity");
    common::executeCommand(bindings, "player_entity.id");
    common::executeCommand(bindings, "player_entity.name");
    common::executeCommand(bindings, "player_entity.payload");
    common::executeCommand(bindings, "player_entity.payload 'I am a modified player'");
    common::executeCommand(bindings, "entities.list");

    std::unique_ptr<Subsystem> subsystem;
    utils::getGlobalBindings()["create_subsystem"] = [&subsystem]() { subsystem = std::make_unique<Subsystem>(); };
    utils::getGlobalBindings()["destroy_subsystem"] = [&subsystem]() { subsystem = nullptr; };

    // if you undefine DEBUG_CONSOLE_ENABLED then the subsystem commands won't be registered, but the object would still be alive
    common::printSectionHeader("This is an example of encapsulating commands within an object:");
    common::executeCommand(utils::getGlobalBindings(), "create_subsystem");
    common::executeCommand(utils::getGlobalBindings(), "subsystem.time");
    common::executeCommand(utils::getGlobalBindings(), "subsystem.do_some_work foo 42");
    subsystem->doWorkPublicly();
    common::executeCommand(utils::getGlobalBindings(), "destroy_subsystem");
    common::executeCommand(utils::getGlobalBindings(), "subsystem.data");
    common::executeCommand(utils::getGlobalBindings(), "subsystem.do_some_work foo 42");
}
