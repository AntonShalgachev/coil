#pragma once

#include <vector>
#include <string>

namespace coil
{
	struct ExecutionResult
    {
        operator bool() const
        {
            return errors.empty();
        }

		std::vector<std::string> errors;
		std::string output;
	};
}
