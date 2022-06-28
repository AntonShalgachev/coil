#include "VariadicExample.h"

#include "common/ExamplesCommon.h"

namespace
{
    struct Entity
    {
        std::uint64_t id;
        std::string name;
    };

    std::vector<Entity> entities;

    Entity* getEntityById(std::uint64_t id)
    {
        for (Entity& entity : entities)
            if (entity.id == id)
                return &entity;
        return nullptr;
    }

    Entity* getEntityByName(std::string_view name)
    {
        for (Entity& entity : entities)
            if (entity.name == name)
                return &entity;
        return nullptr;
    }

    void renameEntity(coil::Context context, coil::Value entity, std::string_view newName)
    {
        Entity* target = nullptr;
        if (auto id = entity.get<std::uint64_t>())
            target = getEntityById(*id);
        else if (auto name = entity.get<std::string_view>())
            target = getEntityByName(*name);

        using namespace std::literals::string_literals;
        if (target)
            target->name = newName;
        else
            context.reportError("Failed to find entity '"s + entity.str() + "'"s);
    }

    void printEntities(coil::Context context)
    {
        context.out() << "Entities:" << std::endl;
        for (Entity const& entity : entities)
            context.out() << entity.id << ": " << entity.name << std::endl;
    }

    void addEntities(std::size_t id, std::string name)
    {
        entities.push_back(Entity{id, std::move(name)});
    }
}

void VariadicExample::run()
{
    coil::Bindings bindings;

    bindings["entities.rename"] = &renameEntity;
    bindings["entities.list"] = &printEntities;
    bindings["entities.add"] = &addEntities;

    common::printSectionHeader("Value can be used with any type:");
    common::executeCommand(bindings, "entities.add 0 entity0");
    common::executeCommand(bindings, "entities.add 1 entity1");
    common::executeCommand(bindings, "entities.add 2 entity2");
    common::executeCommand(bindings, "entities.list");
    common::executeCommand(bindings, "entities.rename 0 player0");
    common::executeCommand(bindings, "entities.rename entity1 player1");
    common::executeCommand(bindings, "entities.rename 3 player3");
    common::executeCommand(bindings, "entities.list");
}
