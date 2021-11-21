#pragma once

#include "coil/Bindings.h"

class EnumsExample final
{
public:
    static void registerExample(coil::Bindings& globalBindings)
    {
        globalBindings.bind<EnumsExample>("run", &EnumsExample::run);
    }

private:
    void run();
};
