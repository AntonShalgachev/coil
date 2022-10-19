#pragma once

namespace coil
{
    struct NewTag {};
}

void* operator new(size_t, coil::NewTag, void* p);
void operator delete(void*, coil::NewTag, void*);
