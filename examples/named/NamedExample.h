#pragma once

#include "coil/Bindings.h"

class NamedExample final
{
public:
    static void registerExample(coil::Bindings& globalBindings)
    {
        auto exampleBindings = globalBindings.createObjectBindings<NamedExample>();
        exampleBindings["run"] = &run;
    }

private:
    void run();
};