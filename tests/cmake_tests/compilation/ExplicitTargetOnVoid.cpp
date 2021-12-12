#include "Common.h"

int main()
{    
    [[maybe_unused]] coil::Bindings cmd;

    cmd[""] = &freeFuncWithTarget;
}
