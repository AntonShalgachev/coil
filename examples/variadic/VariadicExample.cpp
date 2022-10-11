#include "VariadicExample.h"

#include "common/ExamplesCommon.h"

namespace
{
    struct Entity
    {
        std::uint64_t id;
        std::string name;
    };

    class Entities
    {
    public:
        Entity* getById(std::uint64_t id)
        {
            for (Entity& entity : m_entities)
                if (entity.id == id)
                    return &entity;
            return nullptr;
        }

        Entity* getByName(std::string_view name)
        {
            for (Entity& entity : m_entities)
                if (entity.name == name)
                    return &entity;
            return nullptr;
        }

        void rename(coil::Context context, coil::Value entity, std::string_view newName)
        {
            // Here the argument `entity` is variadic: internally it's a string, but it can be converted to any type
            // coil::Value::get<T> returns Expected<T, std::string>, so if the conversion failed, you have an option
            // either to silently ignore this error, or to report the error

            // Here we try to convert `entity` to different types. If converting to integer succeeded, then we are
            // going to find the entity by that id. We try then conversion to a string. If the conversion still
            // doesn't succeed, then we report all previous errors (`id` and `name` both contain errors, not values),
            // so the user would know which conversions were attempted

            // See ErrorsExample ('errors') to learn more about reporting errors
            Entity* target = nullptr;
            if (auto id = entity.get<std::uint64_t>())
                target = getById(*id);
            else if (auto name = entity.get<std::string_view>())
                target = getByName(*name);
            else
                return context.reportErrors("Unknown type of 'entity'", std::move(id).error(), std::move(name).error());

            using namespace std::literals::string_literals;
            if (target)
                target->name = newName;
            else
                context.reportError("Failed to find entity '"s + entity.str() + "'"s);
        }

        void list(coil::Context context)
        {
            context.logline("Entities:");
            for (Entity const& entity : m_entities)
                context.loglinef("%llu: %s", entity.id, entity.name.c_str());
        }

        void add(std::size_t id, std::string name)
        {
            m_entities.push_back(Entity{id, std::move(name)});
        }

    private:
        std::vector<Entity> m_entities;
    };
}

void VariadicExample::run()
{
    coil::Bindings bindings;

    Entities entities;
    bindings["entities.rename"] = coil::bind(&Entities::rename, &entities);
    bindings["entities.list"] = coil::bind(&Entities::list, &entities);
    bindings["entities.add"] = coil::bind(&Entities::add, &entities);

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
