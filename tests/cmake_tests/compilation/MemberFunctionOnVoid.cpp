#include "Common.h"

int main()
{
    [[maybe_unused]] coil::Bindings cmd;

    cmd[""] = &Object::memberFunc;
}
