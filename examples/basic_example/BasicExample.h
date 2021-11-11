#pragma once

#include <string_view>
#include <functional>

namespace coil
{
    class Bindings;
}

class BasicExample final
{
public:
    void registerExample(coil::Bindings& bindings);

private:
    void run();
};
