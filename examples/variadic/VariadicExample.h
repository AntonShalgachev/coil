#pragma once

#include "coil/Bindings.h"

class VariadicExample final
{
public:
    static void registerExample(coil::Bindings& globalBindings)
    {
        globalBindings.bind<VariadicExample>("run", &VariadicExample::run);
    }

private:
    void run();
};