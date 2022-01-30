#pragma once

#include "coil\TypeName.h"

namespace coil
{
    template<>
    struct TypeName<bool>
    {
        static std::string_view name() { return "bool"; }
    };
    template<>
    struct TypeName<int>
    {
        static std::string_view name() { return "int"; }
    };
}
