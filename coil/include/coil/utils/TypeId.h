#pragma once

namespace coil::utils
{
    using TypeIdT = void const*;
    template<typename T>
    TypeIdT typeId()
    {
        static char constexpr c = 0;
        return &c;
    }
}