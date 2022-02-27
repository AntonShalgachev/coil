#include "UsertypesExample.h"

#include "common/ExamplesCommon.h"
#include "coil/Variable.h"

namespace
{
    struct Vec2
    {
        float x{};
        float y{};

        Vec2 operator*(float t)
        {
            return { x * t, y * t };
        }

        Vec2 operator+(Vec2 const& rhs)
        {
            return { x + rhs.x, y + rhs.y };
        }
    };

    struct EntityId
    {
        std::size_t index{};
    };
}

namespace entities
{
    std::vector<std::string> entityNames;

    EntityId add(std::string name)
    {
        std::size_t newId = entityNames.size();
        entityNames.push_back(std::move(name));
        return EntityId{ newId };
    }

    std::optional<EntityId> find(std::string const& name)
    {
        auto it = std::find(entityNames.begin(), entityNames.end(), name);
        if (it != entityNames.end())
            return EntityId{ static_cast<std::size_t>(std::distance(entityNames.begin(), it)) };

        return {};
    }

    EntityId focusedEntity = EntityId{ 0 };
}

namespace particles
{
    struct Particle
    {
        Vec2 pos{};
        Vec2 vel{};
    };

    Particle spawnedParticle;

    void spawn(Vec2 pos, Vec2 vel)
    {
        spawnedParticle = Particle{ pos, vel };
    }

    Vec2 getPosAt(float t)
    {
        return spawnedParticle.pos + spawnedParticle.vel * t;
    }
}

namespace coil
{
    template<>
    struct TypeSerializer<EntityId>
    {
        static Expected<EntityId, std::string> fromString(ArgValue const& input)
        {
            auto index = TypeSerializer<std::size_t>::fromString(input);
            if (!index)
            {
                // You can pass additional information to this function, which could clarify
                // what went wrong. Here we pass `index.error()`, which is an error message
                // from the index deserialization with the details
                return makeSerializationError<EntityId>(input, index.error());
            }

            return EntityId{ *index };
        }

        static auto toString(EntityId value)
        {
            std::stringstream ss;
            ss << "EntityId{" << value.index << "}";
            return ss.str();
        }
    };

    template<>
    struct TypeSerializer<Vec2>
    {
        static Expected<Vec2, std::string> fromString(ArgValue const& input)
        {
            if (input.subvalues.size() != 2)
                return makeSerializationError<Vec2>(input, 2);

            auto x = TypeSerializer<float>::fromString(input.subvalues[0]);
            auto y = TypeSerializer<float>::fromString(input.subvalues[1]);

            if (!x)
                return makeSerializationError<Vec2>(input, x.error());
            if (!y)
                return makeSerializationError<Vec2>(input, y.error());

            return Vec2{ *x, *y };
        }

        static auto toString(Vec2 const& value)
        {
            std::stringstream ss;
            ss << "(" << value.x << ", " << value.x << ")";
            return ss.str();
        }
    };
}

void UsertypesExample::run()
{
    coil::Bindings bindings;

    bindings["entities.add"] = &entities::add;
    bindings["entities.find"] = &entities::find;
    bindings["entities.focused_entity"] = coil::variable(&entities::focusedEntity);

    bindings["particles.spawn"] = &particles::spawn;
    bindings["particles.get_pos_at"] = &particles::getPosAt;
    bindings["particles.last_particle_pos"] = coil::variable(&particles::spawnedParticle.pos);

    common::printSectionHeader("You can use any user defined types: ");
    common::executeCommand(bindings, "entities.add player");
    common::executeCommand(bindings, "entities.add coop_player");
    common::executeCommand(bindings, "entities.add enemy");
    common::executeCommand(bindings, "entities.focused_entity");
    common::executeCommand(bindings, "entities.find coop_player");
    common::executeCommand(bindings, "entities.focused_entity 1");
    common::executeCommand(bindings, "particles.spawn (1, 1) (0.1, 0.1)");
    common::executeCommand(bindings, "particles.get_pos_at 0.5");
    common::executeCommand(bindings, "particles.last_particle_pos (1.5, 1.5)");
    common::executeCommand(bindings, "particles.last_particle_pos");

    common::printSectionHeader("You can pass compound arguments in several ways:");
    common::executeCommand(bindings, "particles.last_particle_pos (1.5, 1.5)");
    common::executeCommand(bindings, "particles.last_particle_pos (1.5 1.5)");
    common::executeCommand(bindings, "particles.last_particle_pos (1.5,1.5)");
    common::executeCommand(bindings, "particles.last_particle_pos 1.5,1.5");

    common::printSectionHeader("If the input can't be converted to the user type, an error would be returned:");
    common::executeCommand(bindings, "particles.get_name string_id");
    common::executeCommand(bindings, "particles.last_particle_pos 1 1");
    common::executeCommand(bindings, "particles.last_particle_pos (1, 1, 1)");
    common::executeCommand(bindings, "particles.last_particle_pos (1)");
    common::executeCommand(bindings, "particles.last_particle_pos (one 2)");
    common::executeCommand(bindings, "particles.last_particle_pos (1 two)");
}
