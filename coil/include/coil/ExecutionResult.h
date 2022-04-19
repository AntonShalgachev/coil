#pragma once

#include <vector>
#include <string>
#include <sstream>
#include <optional>

namespace coil
{
    struct ExecutionResult
    {
        std::vector<std::string> errors;
        std::optional<std::string> returnValue;
        std::stringstream output;
    };
}
