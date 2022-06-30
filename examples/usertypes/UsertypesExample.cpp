#include "UsertypesExample.h"

#include "common/ExamplesCommon.h"

#include <numeric>

// In most cases you'll have to provide 2 specializations per user type:
// * TypeSerializer to be able to convert your type to/from string
// * TypeName to be able to display the name of your type when an error occurs
//
// If you use RTTI, nameof library or any other means to get a name of the generic
// type, then you won't need to provide a TypeName specialization for your type. See
// `CustomTypeName.h` to check the general-case implementation of it using RTTI

namespace
{
    struct Vec2
    {
        float x{};
        float y{};

        Vec2 operator*(float t)
        {
            return {x * t, y * t};
        }

        Vec2 operator+(Vec2 const& rhs)
        {
            return {x + rhs.x, y + rhs.y};
        }
    };

    struct EntityId
    {
        std::size_t index{};
    };

    template<typename T>
    class DynamicArray
    {
    public:
        auto begin() const
        {
            return m_data.begin();
        }
        auto end() const
        {
            return m_data.end();
        }
        auto push_back(T value)
        {
            return m_data.push_back(std::move(value));
        }

    private:
        std::vector<T> m_data;
    };
}

namespace entities
{
    std::vector<std::string> entityNames;

    EntityId add(std::string name)
    {
        std::size_t newId = entityNames.size();
        entityNames.push_back(std::move(name));
        return EntityId{newId};
    }

    std::optional<EntityId> find(std::string const& name)
    {
        auto it = std::find(entityNames.begin(), entityNames.end(), name);
        if (it != entityNames.end())
            return EntityId{static_cast<std::size_t>(std::distance(entityNames.begin(), it))};

        return {};
    }

    void removeSome(DynamicArray<std::string> const& names)
    {
        for (std::string const& name : names)
            entityNames.erase(std::remove(entityNames.begin(), entityNames.end(), name), entityNames.end());
    }

    EntityId focusedEntity = EntityId{0};
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
        spawnedParticle = Particle{pos, vel};
    }

    Vec2 getPosAt(float t)
    {
        return spawnedParticle.pos + spawnedParticle.vel * t;
    }
}

namespace coil
{
    // To be able to (de)serialize your types you'll have to provide a specialization of coil::TypeSerializer

    template<>
    struct TypeSerializer<EntityId>
    {
        static Expected<EntityId, std::string> fromString(Value const& input)
        {
            auto index = TypeSerializer<std::size_t>::fromString(input);
            if (!index)
            {
                // You can pass additional information to this function, which could clarify
                // what went wrong. Here we pass `index.error()`, which is an error message
                // from the index deserialization with the details
                return errors::createGenericError<EntityId>(input, index.error());
            }

            return EntityId{*index};
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
        static Expected<Vec2, std::string> fromString(Value const& input)
        {
            if (input.subvalues.size() != 2)
                return errors::createMismatchedSubvaluesError<Vec2>(input, 2);

            auto x = TypeSerializer<float>::fromString(input.subvalues[0]);
            auto y = TypeSerializer<float>::fromString(input.subvalues[1]);

            if (!x)
                return errors::createGenericError<Vec2>(input, x.error());
            if (!y)
                return errors::createGenericError<Vec2>(input, y.error());

            return Vec2{*x, *y};
        }

        static auto toString(Vec2 const& value)
        {
            std::stringstream ss;
            ss << "(" << value.x << ", " << value.x << ")";
            return ss.str();
        }
    };

    template<typename T>
    struct TypeSerializer<DynamicArray<T>>
    {
        static Expected<DynamicArray<T>, std::string> fromString(Value const& input)
        {
            DynamicArray<T> result;

            for (std::string_view subvalue : input.subvalues)
            {
                Expected<T, std::string> expectedArg = TypeSerializer<T>::fromString(subvalue);
                if (!expectedArg)
                    return errors::createGenericError<DynamicArray<T>>(input, std::move(expectedArg).error());

                result.push_back(*std::move(expectedArg));
            }

            return result;
        }
    };

    // Sometimes coil needs to print the name of the type (e.g. when a string can't be converted to the type). For
    // that to work you'll have to provide a specialization of coil::TypeName

    template<typename T>
    struct TypeName<DynamicArray<T>>
    {
        static std::string_view name()
        {
            static std::string result = "DynamicArray<" + std::string{TypeName<T>::name()} + ">";
            return result;
        }
    };

    template<>
    struct TypeName<Vec2>
    {
        static std::string_view name()
        {
            return "Vec2";
        }
    };

    template<>
    struct TypeName<EntityId>
    {
        static std::string_view name()
        {
            return "EntityId";
        }
    };
}

void UsertypesExample::run()
{
    coil::Bindings bindings;

    bindings["entities.add"] = &entities::add;
    bindings["entities.find"] = &entities::find;
    bindings["entities.focused_entity"] = coil::variable(&entities::focusedEntity);
    bindings["entities.remove_some"] = &entities::removeSome;

    bindings["particles.spawn"] = &particles::spawn;
    bindings["particles.get_pos_at"] = &particles::getPosAt;
    bindings["particles.last_particle_pos"] = coil::variable(&particles::spawnedParticle.pos);

    bindings["sum"] = [](DynamicArray<int> const& values) { return std::accumulate(values.begin(), values.end(), 0); };

    common::printSectionHeader("You can use any user defined types:");
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

    common::printSectionHeader("Custom container types can also be used:");
    common::executeCommand(bindings, "sum 1");
    common::executeCommand(bindings, "sum 1,2,3");
    common::executeCommand(bindings, "sum (1 2 3 4 5)");

    common::printSectionHeader("If the input can't be converted to the user type, an error would be returned:");
    common::executeCommand(bindings, "particles.get_name string_id");
    common::executeCommand(bindings, "particles.last_particle_pos (one 2)");
    common::executeCommand(bindings, "particles.last_particle_pos (1 two)");
    common::executeCommand(bindings, "sum (one two)");
}
