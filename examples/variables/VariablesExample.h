#pragma once

#include "coil/Bindings.h"

class VariablesExample final
{
public:
    static void registerExample(coil::Bindings& globalBindings)
    {
        auto exampleBindings = globalBindings.createObjectBindings<VariablesExample>();
        exampleBindings["run"] = &run;
    }

private:
    void run();
};