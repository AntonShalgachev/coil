#include "Common.h"

int main()
{
    coil::Bindings cmd;

    cmd["foo"]["bar"] = &Object::memberFunc;
}
