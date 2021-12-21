#include "Common.h"

int main()
{
    [[maybe_unused]] coil::Bindings cmd;

    int var = 42;

    cmd[""] = &var;
}
