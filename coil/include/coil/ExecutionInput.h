#pragma once

#include <vector>
#include <string>
#include <unordered_map>

namespace coil
{
    struct ExecutionInput
    {
        std::string target;
        std::string name;
        std::vector<std::string> arguments;
        std::unordered_map<std::string, std::string> namedArguments;
    };
}
