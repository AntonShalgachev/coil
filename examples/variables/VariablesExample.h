#pragma once

#include "coil/Bindings.h"

class VariablesExample final
{
public:
    static void registerExample(coil::Bindings& globalBindings)
    {
        globalBindings.bind<VariablesExample>("run", &VariablesExample::run);
    }

private:
    void run();
};