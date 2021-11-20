#pragma once

#include "coil/Bindings.h"

class NamedExample final
{
public:
    static void registerExample(coil::Bindings& globalBindings)
    {
        globalBindings.bind<NamedExample>("run", &NamedExample::run);
    }

private:
    void run();
};