#pragma once

namespace coil
{
    struct NewTag {};
}

void* operator new(size_t, coil::NewTag, void* p);
