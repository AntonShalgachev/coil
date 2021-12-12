#include "Common.h"

int main()
{
    [[maybe_unused]] coil::Bindings cmd;

    cmd.bind<Object>("", [](int*) {});
}
