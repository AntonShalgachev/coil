#pragma once

#include "coil/Bindings.h"

class ErrorsExample final
{
public:
    static void registerExample(coil::Bindings& globalBindings)
    {
        globalBindings.bind<ErrorsExample>("run", &ErrorsExample::run);
    }

private:
    void run();
};
