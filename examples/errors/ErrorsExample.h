#pragma once

#include "coil/Bindings.h"

class ErrorsExample final
{
public:
    static void registerExample(coil::Bindings& globalBindings)
    {
        auto exampleBindings = globalBindings.createObjectBindings<ErrorsExample>();
        exampleBindings["run"] = &ErrorsExample::run;
    }

private:
    void run();
};
