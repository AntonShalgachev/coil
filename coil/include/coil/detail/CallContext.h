#pragma once

#include <string>
#include <vector>
#include "ExecutionResult.h"

namespace coil
{
    namespace detail
    {
        struct CallContext
        {
            std::string target;
            std::string name;
            std::vector<std::string> arguments;

            ExecutionResult result;
        };
    }
}