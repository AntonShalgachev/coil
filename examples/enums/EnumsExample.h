#pragma once

#include "coil/Bindings.h"

class EnumsExample final
{
public:
    static void registerExample(coil::Bindings& globalBindings)
    {
        auto exampleBindings = globalBindings.createObjectBindings<EnumsExample>();
        exampleBindings["run"] = &run;
    }

private:
    void run();
};
