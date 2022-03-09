#include "VariadicExample.h"

#include "common/ExamplesCommon.h"
#include "coil/AnyArgView.h"

#include <vector>
#include <numeric>
#include <iostream>

// TODO probably irrelevant now, move to other examples

namespace
{
    float sumAll(std::vector<float> const& numbers)
    {
        return std::accumulate(numbers.begin(), numbers.end(), 0.0f);
    }

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

    void renameEntity(coil::Context context, coil::AnyArgView entity, std::string_view newName)
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
            context.reportError("Failed to find entity '"s + std::string{ entity.getRaw().value } + "'"s);
    }

    void printEntities(coil::Context context)
    {
        context.out() << "Entities:" << std::endl;
        for (Entity const& entity : entities)
            context.out() << entity.id << ": " << entity.name << std::endl;
    }

    void addEntities(std::size_t id, std::string name)
    {
        entities.push_back(Entity{ id, std::move(name) });
    }
}

void VariadicExample::run()
{
    coil::Bindings bindings;

    bindings["sum_all"] = &sumAll;

    bindings["entities.rename"] = &renameEntity;
    bindings["entities.list"] = &printEntities;
    bindings["entities.add"] = &addEntities;

    // TODO move to another example ("CompositeExample")
    common::printSectionHeader("std::vector accepts any amount of arguments:");
    common::executeCommand(bindings, "sum_all ()");
    common::executeCommand(bindings, "sum_all (1)");
    common::executeCommand(bindings, "sum_all (1 2 3 5 8)");

    common::printSectionHeader("AnyArgView can be used with any type:");
    common::executeCommand(bindings, "entities.add 0 entity0");
    common::executeCommand(bindings, "entities.add 1 entity1");
    common::executeCommand(bindings, "entities.add 2 entity2");
    common::executeCommand(bindings, "entities.list");
    common::executeCommand(bindings, "entities.rename 0 player0");
    common::executeCommand(bindings, "entities.rename entity1 player1");
    common::executeCommand(bindings, "entities.rename 3 player3");
    common::executeCommand(bindings, "entities.list");
}
