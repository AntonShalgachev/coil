#pragma once

#include "StringView.h"
#include "Value.h"
#include "Vector.h"

namespace coil
{
    struct ExecutionInput
    {
        StringView name;
        Vector<Value> arguments;
        Vector<NamedValue> namedArguments;
    };
}
