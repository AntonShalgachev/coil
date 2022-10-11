#include "FlagsExample.h"

#include "common/ExamplesCommon.h"

namespace
{
    enum class EntityDebugDrawFlags
    {
        DrawBoundingBox = 0b0001,
        DrawOrigin = 0b0010,
        DrawWireframe = 0b0100,
        DrawName = 0b1000,
    };

    EntityDebugDrawFlags operator|(EntityDebugDrawFlags lhs, EntityDebugDrawFlags rhs)
    {
        using UT = std::underlying_type_t<EntityDebugDrawFlags>;
        return static_cast<EntityDebugDrawFlags>(static_cast<UT>(lhs) | static_cast<UT>(rhs));
    }

    EntityDebugDrawFlags operator&(EntityDebugDrawFlags lhs, EntityDebugDrawFlags rhs)
    {
        using UT = std::underlying_type_t<EntityDebugDrawFlags>;
        return static_cast<EntityDebugDrawFlags>(static_cast<UT>(lhs) & static_cast<UT>(rhs));
    }

    // This function is similar to coil::variable, but instead of accepting the enum value as a
    // parameter, it accepts the vector of them. This allows the user to pass several flags which
    // will be OR'ed automatically upon invocation. This enables the user to do the following:
    // "some_flags"
    // "some_flags Flag1"
    // "some_flags Flag1|Flag2|Flag3"
    //
    // Effectively this creates functions, one of which (setter) accepts a vector of enums. Since
    // '|' is considered to be a separator, this means that the individual flags can be passed
    // to the setter using any of the compound argument systax:
    // "some_flags Flag1|Flag2|Flag3"
    // "some_flags Flag1,Flag2,Flag3"
    // "some_flags Flag1;Flag2;Flag3"
    // "some_flags (Flag1 Flag2 Flag3)"
    // "some_flags (Flag1, Flag2, Flag3)"
    template<typename E>
    auto flagsVariable(E* var)
    {
        // Getters and setters return the string representation of the flags variable because the
        // TypeSerializer for enums (see examples\common\EnumTypeSerializer.h) doesn't handle flags by default

        auto get = [var]() { return magic_enum::flags::enum_name(*var); };
        auto set = [var](std::vector<E> const& args) {
            using UT = std::underlying_type_t<E>;

            auto newValue = UT{0};
            for (auto arg : args)
                newValue = static_cast<UT>(newValue) | static_cast<UT>(arg);
            *var = static_cast<E>(newValue);

            return magic_enum::flags::enum_name(*var);
        };

        return coil::overloaded(std::move(get), std::move(set));
    }
}

void FlagsExample::run()
{
    coil::Bindings bindings;

    EntityDebugDrawFlags flags = EntityDebugDrawFlags::DrawBoundingBox | EntityDebugDrawFlags::DrawName;

    bindings["entity.flags"] = ::flagsVariable(&flags);
    bindings["entity.draw"] = [&flags](coil::Context context) {
        if ((flags & EntityDebugDrawFlags::DrawBoundingBox) == EntityDebugDrawFlags::DrawBoundingBox)
            context.logline("Drawing bounding box");
        if ((flags & EntityDebugDrawFlags::DrawOrigin) == EntityDebugDrawFlags::DrawOrigin)
            context.logline("Drawing origin");
        if ((flags & EntityDebugDrawFlags::DrawWireframe) == EntityDebugDrawFlags::DrawWireframe)
            context.logline("Drawing wireframe");
        if ((flags & EntityDebugDrawFlags::DrawName) == EntityDebugDrawFlags::DrawName)
            context.logline("Drawing name");
    };

    common::printSectionHeader("Getting the value of a flag variable returns a string represenation of it:");
    common::executeCommand(bindings, "entity.flags");
    common::executeCommand(bindings, "entity.draw");

    common::printSectionHeader("Flags can be set by grouping them in a single compound argument:");
    common::executeCommand(bindings, "entity.flags DrawOrigin|DrawWireframe");
    common::executeCommand(bindings, "entity.draw");
    common::executeCommand(bindings, "entity.flags DrawOrigin");
    common::executeCommand(bindings, "entity.draw");

    common::printSectionHeader("As with the compound objects, you have several options of passing multiple flags:");
    common::executeCommand(bindings, "entity.flags DrawOrigin,DrawWireframe");
    common::executeCommand(bindings, "entity.flags (DrawOrigin DrawWireframe)");
    common::executeCommand(bindings, "entity.flags (DrawOrigin, DrawWireframe)");

    common::printSectionHeader("Errors are handled just like for any compound type:");
    common::executeCommand(bindings, "entity.flags DrawName|DrawSomethingElse");

    common::printSectionHeader("Passing several arguments instead of one compound argument is also an error:");
    common::executeCommand(bindings, "entity.flags DrawName DrawSomethingElse");
}
