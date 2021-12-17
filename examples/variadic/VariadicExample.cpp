#include "VariadicExample.h"

#include "common/ExamplesCommon.h"
#include "coil/AnyArgView.h"

#include <vector>
#include <numeric>
#include <iostream>

namespace
{
    float sumAll(std::vector<float> const& numbers)
    {
        return std::accumulate(numbers.begin(), numbers.end(), 0.0f);
    }

    float scale(float value, std::optional<float> multiplier)
    {
        return value * multiplier.value_or(1.0f);
    }

    struct Entity
    {
        std::uint64_t id;
        std::string_view name;
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

    void renameEntity(coil::Context& context, coil::AnyArgView entity, std::string_view newName)
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
            context.reportError("Failed to find entity '"s + std::string{ entity.getRaw() } + "'"s);
    }

    void printEntities(coil::Context& context)
    {
        context.out() << "Entities:" << std::endl;
        for (Entity const& entity : entities)
            context.out() << entity.id << ": " << entity.name << std::endl;
    }

    void addEntities(coil::Context& context, std::vector<coil::AnyArgView> const& args)
    {
        using namespace std::literals::string_literals;

        if (args.size() % 2 != 0)
        {
            context.reportError("Even amount of arguments was expected, got "s + std::to_string(args.size()));
            return;
        }

        for (std::size_t i = 0; i < args.size(); i += 2)
        {
            auto optionalId = args[i].get<std::uint64_t>();
            auto optionalName = args[i + 1].get<std::string_view>();

            if (!optionalId)
                context.reportError("Argument "s + std::to_string(i) + ": expected id, got '"s + std::string{ args[i].getRaw() } + "'"s);
            if (!optionalName)
                context.reportError("Argument "s + std::to_string(i) + ": expected name, got '"s + std::string{ args[i + 1].getRaw() } + "'"s);

            if (!optionalId || !optionalName)
                return;

            entities.push_back(Entity{ *optionalId, *optionalName });
        }
    }
}

void VariadicExample::run()
{
    coil::Bindings bindings;

    bindings["sum_all"] = &sumAll;
    bindings["scale"] = &scale;

    bindings["rename_entity"] = &renameEntity;
    bindings["print_entities"] = &printEntities;
    bindings["add_entities"] = &addEntities;

    common::printSectionHeader("std::vector consumes all remaining arguments:");
    common::executeCommand(bindings, "sum_all");
    common::executeCommand(bindings, "sum_all 1");
    common::executeCommand(bindings, "sum_all 1 2 3 5 8");

    common::printSectionHeader("std::optional consumes 0 or 1 argument:");
    common::executeCommand(bindings, "scale 3.14");
    common::executeCommand(bindings, "scale 3.14 2.0");

    common::printSectionHeader("coil also catches invalid number or type of variadic arguments:");
    common::executeCommand(bindings, "scale");
    common::executeCommand(bindings, "scale 3.14 2.0 3.0");
    common::executeCommand(bindings, "scale 3.14 two");

    common::printSectionHeader("AnyArgView can be used with any type:");
    common::executeCommand(bindings, "add_entities 0 entity0 1 entity1 2 entity2");
    common::executeCommand(bindings, "print_entities");
    common::executeCommand(bindings, "rename_entity 0 player0");
    common::executeCommand(bindings, "rename_entity entity1 player1");
    common::executeCommand(bindings, "rename_entity 3 player3");
    common::executeCommand(bindings, "print_entities");
}
