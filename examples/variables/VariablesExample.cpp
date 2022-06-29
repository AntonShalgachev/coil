#include "VariablesExample.h"

#include "common/ExamplesCommon.h"

#include <iostream>

namespace
{
    enum class Type
    {
        Type1,
        Type2,
        Type3
    };

    auto toggle(bool* var)
    {
        auto toggler = [var]() {
            *var = !*var;
            return *var;
        };
        auto setter = [var](bool val) {
            *var = std::move(val);
            return *var;
        };

        return coil::overloaded(std::move(toggler), std::move(setter));
    }
}

void VariablesExample::run()
{
    coil::Bindings bindings;

    float timeScale = 1.0f;
    std::string city = "Moscow";
    Type type = Type::Type2;
    bool godMode = false;

    bindings["time_scale"] = coil::variable(&timeScale);
    bindings["city"] = coil::variable(&city);
    bindings["type"] = coil::variable(&type);
    bindings["god_var"] = coil::variable(&godMode);
    bindings["god_toggle"] = ::toggle(&godMode);

    bindings["print_variables"] = [&timeScale, &city, &type](coil::Context context) {
        context.log() << "Time scale: " << timeScale << "; city: " << city << "; type: " << magic_enum::enum_name(type) << std::endl;
    };

    common::printSectionHeader("Calling variable without arguments will return its value:");
    common::executeCommand(bindings, "time_scale");
    common::executeCommand(bindings, "city");
    common::executeCommand(bindings, "type");
    common::executeCommand(bindings, "print_variables");

    common::printSectionHeader("Calling variable with an argument will update and return the value:");
    common::executeCommand(bindings, "time_scale 2.0");
    common::executeCommand(bindings, "city Berlin");
    common::executeCommand(bindings, "type Type3");
    common::executeCommand(bindings, "print_variables");

    common::printSectionHeader("Errors are handled just as for functions (variables won't change):");
    common::executeCommand(bindings, "time_scale 2.0 3.0");
    common::executeCommand(bindings, "city Porto Athens");
    common::executeCommand(bindings, "type UnknownType");
    common::executeCommand(bindings, "print_variables");

    common::printSectionHeader("You can create your own variable-like commands");
    common::executeCommand(bindings, "god_var");
    common::executeCommand(bindings, "god_toggle"); // toggles the bool instead of just returning the value
    common::executeCommand(bindings, "god_toggle false");
    common::executeCommand(bindings, "god_toggle 1");
}
