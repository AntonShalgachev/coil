#include "VariablesExample.h"

#include "common/ExamplesCommon.h"
#include "common/FlagVariableWrapper.h"

#include <iostream>

namespace
{
    enum class Flags
    {
        Flag1 = 0b0001,
        Flag2 = 0b0010,
        Flag3 = 0b0100,
        Flag4 = 0b1000,
    };

    Flags operator|(Flags lhs, Flags rhs)
    {
        using UT = std::underlying_type_t<Flags>;
        return static_cast<Flags>(static_cast<UT>(lhs) | static_cast<UT>(rhs));
    }
}

void VariablesExample::run()
{
    coil::Bindings bindings;

    float timeScale = 1.0f;
    std::string city = "Moscow";
    Flags flags = Flags::Flag1 | Flags::Flag3;

    bindings["time_scale"] = coil::variable(&timeScale);
    bindings["city"] = coil::variable(&city);
    bindings["flags"] = ::flags(&flags);

    bindings["print_variables"] = [&timeScale, &city, &flags](coil::Context context) {
        context.out() << "Time scale: " << timeScale << "; city: " << city << "; flags: " << magic_enum::flags::enum_name(flags) << std::endl;
    };

    common::printSectionHeader("Calling variable without arguments will return its value:");
    common::executeCommand(bindings, "time_scale");
    common::executeCommand(bindings, "city");
    common::executeCommand(bindings, "flags");
    common::executeCommand(bindings, "print_variables");

    common::printSectionHeader("Calling variable with an argument will update and return the value:");
    common::executeCommand(bindings, "time_scale 2.0");
    common::executeCommand(bindings, "city Berlin");
    common::executeCommand(bindings, "flags Flag1|Flag2|Flag4");
    common::executeCommand(bindings, "print_variables");

    common::printSectionHeader("Errors are handled just as for functions (variables won't change):");
    common::executeCommand(bindings, "time_scale 2.0 3.0");
    common::executeCommand(bindings, "city Porto Athens");
    common::executeCommand(bindings, "flags Flag1 Flag2"); // considered to be 2 arguments, therefore error
    common::executeCommand(bindings, "flags Foo|Flag4|Bar");
    common::executeCommand(bindings, "print_variables");
}
