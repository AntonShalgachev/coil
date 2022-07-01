#pragma once

#include "ExecutionInput.h"

#include <optional>
#include <sstream>
#include <string>
#include <vector>

namespace coil
{
    struct ExecutionResult
    {
        ExecutionInput input;
        std::vector<std::string> errors;
        std::optional<std::string> returnValue;
        std::stringstream output;
    };
}
