#include "Common.h"

int main()
{
    [[maybe_unused]] coil::Bindings cmd;

    cmd[""] = coil::variable(&Object::memberVariable);
}
