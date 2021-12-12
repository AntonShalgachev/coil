#include "VariablesExample.h"

#include "common/ExamplesCommon.h"

#include <iostream>

void VariablesExample::run()
{
    coil::Bindings bindings;

    // TODO add enum variable
    // TODO add member variables
    // TODO add property example

    float timeScale = 1.0f;
    std::string city = "Moscow";

    bindings["time_scale"] = &timeScale;
    bindings["city"] = &city;

    bindings["print_variables"] = [&timeScale, &city]()
    {
        std::cout << "Time scale: " << timeScale << "; city: " << city << std::endl;
    };

    common::printSectionHeader("Calling variable without arguments will return its value:");
    common::executeCommand(bindings, "time_scale");
    common::executeCommand(bindings, "city");
    common::executeCommand(bindings, "print_variables");

    common::printSectionHeader("Calling variable with an argument will update and return the value:");
    common::executeCommand(bindings, "time_scale 2.0");
    common::executeCommand(bindings, "city Berlin");
    common::executeCommand(bindings, "print_variables");

    common::printSectionHeader("Errors are handled just as for functions (variables won't change):");
    common::executeCommand(bindings, "time_scale 2.0 3.0");
    common::executeCommand(bindings, "city Porto Athens");
    common::executeCommand(bindings, "print_variables");
}
