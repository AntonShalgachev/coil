#pragma once

#include "Value.h"
#include "StringView.h"
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
