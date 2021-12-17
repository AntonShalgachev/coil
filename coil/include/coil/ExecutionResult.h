#pragma once

#include <vector>
#include <string>
#include <sstream>
#include <optional>

namespace coil
{
	struct ExecutionResult
    {
        operator bool() const
        {
            return errors.empty();
        }

		std::vector<std::string> errors;
		std::optional<std::string> returnValue;
        std::stringstream output;
	};
}
