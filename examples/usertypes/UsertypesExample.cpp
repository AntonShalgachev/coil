#include "UsertypesExample.h"

#include "common/ExamplesCommon.h"

#include "coil/StdLibCompat.h" // implementation of TypeSerializer and TypeName for some C++ Standard Library types

#include <algorithm>
#include <numeric>
#include <vector>

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

    class Entities
    {
    public:
        EntityId add(std::string name)
        {
            std::size_t newId = m_entityNames.size();
            m_entityNames.push_back(std::move(name));
            return EntityId{newId};
        }

        std::optional<EntityId> find(std::string const& name)
        {
            auto it = std::find(m_entityNames.begin(), m_entityNames.end(), name);
            if (it != m_entityNames.end())
                return EntityId{static_cast<std::size_t>(std::distance(m_entityNames.begin(), it))};

            return {};
        }

        void removeSome(DynamicArray<std::string> const& names)
        {
            for (std::string const& name : names)
                m_entityNames.erase(std::remove(m_entityNames.begin(), m_entityNames.end(), name), m_entityNames.end());
        }

        EntityId focusedEntity = EntityId{0};

    private:
        std::vector<std::string> m_entityNames;
    };
}

namespace coil
{
    // To be able to (de)serialize your types you'll have to provide a specialization of coil::TypeSerializer

    template<>
    struct TypeSerializer<EntityId>
    {
        static Expected<EntityId, coil::String> fromString(Value const& input)
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

        static coil::String toString(EntityId value)
        {
            return coil::sprintf("EntityId{%zu}", value.index);
        }
    };

    template<>
    struct TypeSerializer<Vec2>
    {
        static Expected<Vec2, coil::String> fromString(Value const& input)
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
            return coil::sprintf("(%f, %f)", value.x, value.y);
        }
    };

    template<typename T>
    struct TypeSerializer<DynamicArray<T>>
    {
        static Expected<DynamicArray<T>, coil::String> fromString(Value const& input)
        {
            DynamicArray<T> result;

            for (coil::StringView subvalue : input.subvalues)
            {
                Expected<T, coil::String> expectedArg = TypeSerializer<T>::fromString(subvalue);
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
        static StringView name()
        {
            static String result = "DynamicArray<" + String{TypeName<T>::name()} + ">";
            return result;
        }
    };

    template<>
    struct TypeName<Vec2>
    {
        static StringView name()
        {
            return "Vec2";
        }
    };

    template<>
    struct TypeName<EntityId>
    {
        static StringView name()
        {
            return "EntityId";
        }
    };
}

void UsertypesExample::run()
{
    coil::Bindings bindings;

    Entities entities;
    bindings["entities.add"] = coil::bind(&Entities::add, &entities);
    bindings["entities.find"] = coil::bind(&Entities::find, &entities);
    bindings["entities.focused_entity"] = coil::variable(&entities.focusedEntity);
    bindings["entities.remove_some"] = coil::bind(&Entities::removeSome, &entities);

    struct Particle
    {
        Vec2 pos{};
        Vec2 vel{};
    };
    Particle spawnedParticle;
    bindings["particles.spawn"] = [&spawnedParticle](Vec2 pos, Vec2 vel) { spawnedParticle = Particle{pos, vel}; };
    bindings["particles.get_pos_at"] = [&spawnedParticle](float t) { return spawnedParticle.pos + spawnedParticle.vel * t; };
    bindings["particles.last_particle_pos"] = coil::variable(&spawnedParticle.pos);

    bindings["sum"] = [](DynamicArray<int> const& values) { return std::accumulate(values.begin(), values.end(), 0); };

    common::printSectionHeader("You can use user defined types:");
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
    common::executeCommand(bindings, "particles.last_particle_pos (one 2)");
    common::executeCommand(bindings, "particles.last_particle_pos (1 two)");
    common::executeCommand(bindings, "sum (one two)");
}
