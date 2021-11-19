#pragma once

#include <string_view>
#include "coil/Bindings.h"

class BasicExample final
{
public:
    void registerExample(coil::Bindings& globalBindings)
    {
        globalBindings.bind<BasicExample>("run", &BasicExample::run);
    }

private:
    void run();
};
