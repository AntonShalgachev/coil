#pragma once

#include <vector>
#include <string>

namespace cmdapi
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
