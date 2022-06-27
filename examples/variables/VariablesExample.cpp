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
}

void VariablesExample::run()
{
    coil::Bindings bindings;

    float timeScale = 1.0f;
    std::string city = "Moscow";
    Type type = Type::Type2;

    bindings["time_scale"] = coil::variable(&timeScale);
    bindings["city"] = coil::variable(&city);
    bindings["type"] = coil::variable(&type);

    bindings["print_variables"] = [&timeScale, &city, &type](coil::Context context) {
        context.out() << "Time scale: " << timeScale << "; city: " << city << "; type: " << magic_enum::enum_name(type) << std::endl;
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
}
