#pragma once

#include <vector>
#include <string>

namespace coil
{
    struct ExecutionInput
    {
        std::string target;
        std::string name;
        std::vector<std::string> arguments;
    };
}
