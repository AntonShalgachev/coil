#include "AdvancedExample.h"

#include "common/ExamplesCommon.h"

#include "coil/StdLibCompat.h" // implementation of TypeSerializer and TypeName for some C++ Standard Library types

#include <algorithm>
#include <vector>
#include <sstream>

// In these examples:
// * Wrapping functions which take pointers
// * Creating coil variables dynamically
// * A variable wrapper for angles (to allow degrees and radians input)

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

    // An alternative would be to create a new type and to define its TypeSerializer so that
    // you could also easily pass angles in various functions
    std::string angleToString(float degrees)
    {
        std::stringstream ss;
        ss << degrees << " degrees";
        return ss.str();
    }

    auto angleVariable(float* var)
    {
        auto get = [var]() { return angleToString(*var); };
        auto set = [var](coil::Context context, coil::StringView val) {
            if (val.empty())
            {
                context.reportError("Conversion error");
                return angleToString(*var);
            }

            coil::StringView numberString = val;
            bool numberIsRadians = false;

            char lastChar = val[val.length() - 1];
            if (lastChar == 'r')
            {
                numberIsRadians = true;
                numberString = val.substr(0, val.length() - 1);
            }
            else if (lastChar == 'd')
            {
                numberIsRadians = false;
                numberString = val.substr(0, val.length() - 1);
            }

            auto expectedValue = coil::TypeSerializer<float>::fromString(numberString);
            if (!expectedValue)
            {
                context.reportError(std::move(expectedValue).error());
                return angleToString(*var);
            }

            *var = *expectedValue;
            if (numberIsRadians)
                *var *= (180.0f / 3.14159265358979f);

            return angleToString(*var);
        };

        return coil::overloaded(std::move(get), std::move(set));
    }
}

namespace coil
{
    template<>
    struct TypeSerializer<Entity>
    {
        static coil::String toString(Entity const& value)
        {
            return coil::sprintf("EntityId{%s}", value.id.c_str());
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

    bindings["entities.rename"] = [&entities](coil::Context context, std::string_view id, std::string newName) {
        Entity* entity = entities.find(id);
        if (!entity)
        {
            context.reportError("Failed to find entity '" + coil::fromStdString(id) + "'");
            return;
        }

        renameEntity(entity, std::move(newName));
    };

    bindings["entities.create_entity_variable"] = [&entities, &bindings](coil::StringView variableName, std::string_view id) {
        auto get = [&entities, id]() { return entities.find(id); };
        bindings[variableName] = coil::property([get]() { return get(); });
        bindings[coil::String(variableName) + ".id"] = coil::property([get]() { return get()->id; });
        bindings[coil::String(variableName) + ".name"] = coil::property([get]() { return get()->name; }, [get](std::string const& value) { get()->name = value; });
        bindings[coil::String(variableName) + ".payload"] = coil::property([get]() { return get()->payload; }, [get](std::string const& value) { get()->payload = value; });
    };

    bindings["entities.list"] = [&entities](coil::Context context) {
        context.logline("ID\tName\tPayload");
        context.logline("--\t----\t-------");
        for (Entity const& entity : entities.getEntities())
            context.loglinef("%s\t%s\t%s", entity.id.c_str(), entity.name.c_str(), entity.payload.c_str());
    };

    float angle = 45.0f;
    bindings["direction"] = ::angleVariable(&angle);

    common::printSectionHeader("You can use lambdas to wrap functions taking pointers:");
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

    common::printSectionHeader("Angle variable wrapper:");
    common::executeCommand(bindings, "direction 30");
    common::executeCommand(bindings, "direction 60d");
    common::executeCommand(bindings, "direction 3.1415926535r");
}
