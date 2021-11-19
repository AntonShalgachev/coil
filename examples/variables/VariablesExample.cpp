#include "VariablesExample.h"

#include "common/ExamplesCommon.h"

#include <iostream>

void VariablesExample::run()
{
    coil::Bindings bindings;

    float timeScale = 1.0f;
    std::string city = "Moscow";

    bindings["time_scale"] = &timeScale;
    bindings["city"] = &city;

    bindings["do_some_work"] = [&timeScale]()
    {
        std::cout << "Time scale is " << timeScale << std::endl;
    };

    common::printSectionHeader("Calling variable without arguments will return its value:");
    common::executeCommand(bindings, "time_scale");
    common::executeCommand(bindings, "city");

    common::printSectionHeader("Calling variable with an argument will update and return the value:");
    common::executeCommand(bindings, "time_scale 2.0");
    common::executeCommand(bindings, "city Berlin");

    common::printSectionHeader("Errors are handled just as for functions:");
    common::executeCommand(bindings, "time_scale 2.0 3.0");
    common::executeCommand(bindings, "city Porto Athens");
}

