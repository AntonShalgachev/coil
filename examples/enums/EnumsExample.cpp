#include "EnumsExample.h"

#include "common/EnumToString.h" // user-provided TypeSerializer for enums
#include "common/ExamplesCommon.h"

#include <iostream>

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
            NoRecoil,
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

    // See EnumToString.h to see how the serialization is implemented

    bindings["abilities.set_ability"] = coil::bind(&PlayerAbilitySystem::setAbility, &abilities);
    bindings["abilities.get_ability"] = coil::bind(&PlayerAbilitySystem::getAbility, &abilities);
    bindings["abilities.get_reset_mode"] = coil::bind(&PlayerAbilitySystem::getResetMode, &abilities);

    common::printSectionHeader("Enums can be used as long as a corresponding TypeSerializer is specialized:");
    common::executeCommand(bindings, "abilities.set_ability SpeedBoost AfterDelay");

    common::printSectionHeader("Both scoped and unscoped enums can be used:");
    common::executeCommand(bindings, "abilities.get_ability");
    common::executeCommand(bindings, "abilities.get_reset_mode");
}
