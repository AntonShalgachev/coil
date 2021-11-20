#include "VariadicExample.h"

#include "common/ExamplesCommon.h"
#include "coil/VariadicArg.h"

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

    std::vector<Entity> entities = { {0, "entity0"}, {1, "entity1" }, {2, "entity2"} };

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

    void renameEntity(coil::Context& context, coil::VariadicArg entity, std::string_view newName)
    {
        Entity* target = nullptr;
        if (auto optionalValue = entity.tryGet<std::uint64_t>())
            target = getEntityById(*optionalValue);
        else if (auto optionalValue = entity.tryGet<std::string_view>())
            target = getEntityByName(*optionalValue);

        using namespace std::literals::string_literals;
        if (target)
            target->name = newName;
        else
            context.reportError("Failed to find entity '"s + std::string{ entity.getRaw() } + "'"s);
    }

    void printEntities()
    {
        std::cout << "Entities:" << std::endl;
        for (Entity const& entity : entities)
            std::cout << entity.id << ": " << entity.name << std::endl;
    }
}

void VariadicExample::run()
{
    coil::Bindings bindings;

    bindings["sum_all"] = &sumAll;
    bindings["scale"] = &scale;

    bindings["rename_entity"] = &renameEntity;
    bindings["print_entities"] = &printEntities;

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

    common::printSectionHeader("VariadicArg can be used with any type:");
    common::executeCommand(bindings, "print_entities");
    common::executeCommand(bindings, "rename_entity 0 player0");
    common::executeCommand(bindings, "rename_entity entity1 player1");
    common::executeCommand(bindings, "rename_entity 3 player3");
    common::executeCommand(bindings, "print_entities");
}
