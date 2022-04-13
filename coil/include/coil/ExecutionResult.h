#pragma once

#include <vector>
#include <string>
#include <sstream>
#include <optional>

namespace coil
{
    struct ExecutionResult
    {
        void setReturnValue(std::string value);

        std::vector<std::string> errors;
        std::optional<std::string> returnValue;
        std::stringstream output;
    };
}
