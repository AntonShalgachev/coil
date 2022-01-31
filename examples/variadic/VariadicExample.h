#pragma once

#include "coil/Bindings.h"

class VariadicExample final
{
public:
    static void registerExample(coil::Bindings& globalBindings)
    {
        auto exampleBindings = globalBindings.createObjectBindings<VariadicExample>();
        exampleBindings["run"] = &VariadicExample::run;
    }

private:
    void run();
};