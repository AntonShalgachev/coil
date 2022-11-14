#include "EnumsExample.h"

#include "common/EnumSupport.h" // user-provided TypeSerializer for enums
#include "common/ExamplesCommon.h"

#include <iostream>

// The main challenge with enums is that C++ doesn't offer any means to get a string name of the enum item
// In order for enums to work, we need to provide specializations for TypeSerialization and TypeName
// Check `EnumSupport.h` to check how these specializations are implemented

namespace
{
    class PlayerAbilitySystem
    {
    public:
        // scoped enum
        enum class Ability
        {
            None,
            SpeedBoost,
            IncreasedHealth,
        };

        // unscoped enum
        enum ResetMode
        {
            Never,
            AfterDelay,
            AfterDeath,
        };

        void setAbility(Ability ability, ResetMode resetMode)
        {
            m_ability = ability;
            m_resetMode = resetMode;
        }
        Ability getAbility() const
        {
            return m_ability;
        }
        ResetMode getResetMode() const
        {
            return m_resetMode;
        }

    private:
        Ability m_ability = Ability::None;
        ResetMode m_resetMode = ResetMode::Never;
    };
}

void EnumsExample::run()
{
    coil::Bindings bindings;
    PlayerAbilitySystem abilities;

    enum class VariableType
    {
        Integer,
        Float,
        String,
    };

    VariableType variableType = VariableType::String;

    bindings["abilities.set_ability"] = coil::bind(&PlayerAbilitySystem::setAbility, &abilities);
    bindings["abilities.get_ability"] = coil::bind(&PlayerAbilitySystem::getAbility, &abilities);
    bindings["abilities.get_reset_mode"] = coil::bind(&PlayerAbilitySystem::getResetMode, &abilities);
    bindings["variable_type"] = coil::variable(&variableType);

    common::printSectionHeader("Enums can be used as long as a corresponding TypeSerializer is specialized:");
    common::executeCommand(bindings, "abilities.set_ability SpeedBoost AfterDelay");

    common::printSectionHeader("Both scoped and unscoped enums can be used:");
    common::executeCommand(bindings, "abilities.get_ability");
    common::executeCommand(bindings, "abilities.get_reset_mode");

    common::printSectionHeader("Enum variables can also be used:");
    common::executeCommand(bindings, "variable_type");
    common::executeCommand(bindings, "variable_type Float");

    common::printSectionHeader("It is possible to make the enum conversion errors detailed:");
    common::executeCommand(bindings, "variable_type Custom");
    common::executeCommand(bindings, "abilities.set_ability NoRecoil AfterDelay");
    common::executeCommand(bindings, "abilities.set_ability SpeedBoost AfterFrame");
}
