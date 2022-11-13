#include "coil/detail/New.h"

void* operator new(size_t, coil::NewTag, void* p)
{
    return p;
}

void operator delete(void*, coil::NewTag, void*) {} // @NOCOVERAGE
