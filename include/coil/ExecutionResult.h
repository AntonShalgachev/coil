#pragma once

#include <optional>
#include <sstream>
#include <string>
#include <vector>

namespace coil
{
    struct ExecutionResult
    {
        std::vector<std::string> errors;
        std::optional<std::string> returnValue;
        std::stringstream output;
    };
}
