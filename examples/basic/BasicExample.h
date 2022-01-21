#pragma once

#include "coil/Bindings.h"

class BasicExample final
{
public:
    static void registerExample(coil::Bindings& globalBindings)
    {
        auto exampleBindings = globalBindings.createObjectBindings<BasicExample>();
        exampleBindings["run"] = &run;
    }

private:
    void run();
};
