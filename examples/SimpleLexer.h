#pragma once

#include <string>

namespace coil
{
    struct ExecutionInput;
}

// TODO implement properly
struct SimpleLexer
{
public:
    coil::ExecutionInput operator()(std::string str) const;
};
