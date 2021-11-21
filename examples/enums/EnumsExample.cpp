#include "EnumsExample.h"

#include "common/ExamplesCommon.h"

// user-provided TypeSerializer for enums
#include "EnumToString.h"

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

        void setAbility(Ability ability, ResetMode resetMode) { m_ability = ability; m_resetMode = resetMode; }
        Ability getAbility() const { return m_ability; }
        ResetMode getResetMode() const { return m_resetMode; }

    private:
        Ability m_ability = Ability::None;
        ResetMode m_resetMode = ResetMode::Never;
    };
}

void EnumsExample::run()
{
    coil::Bindings bindings;

    // See EnumToString.h to see how the serialization is implemented

    bindings.bind<PlayerAbilitySystem>("set_ability", &PlayerAbilitySystem::setAbility);
    bindings.bind<PlayerAbilitySystem>("get_ability", &PlayerAbilitySystem::getAbility);
    bindings.bind<PlayerAbilitySystem>("get_reset_mode", &PlayerAbilitySystem::getResetMode);

    PlayerAbilitySystem abilities;
    bindings.addObject("abilities", &abilities);

    common::printSectionHeader("Enums can also be as long as a corresponding TypeSerializer is specialized:");
    common::executeCommand(bindings, "abilities.set_ability SpeedBoost AfterDelay");

    common::printSectionHeader("Both scoped and unscoped enums can be used:");
    common::executeCommand(bindings, "abilities.get_ability");
    common::executeCommand(bindings, "abilities.get_reset_mode");
}
