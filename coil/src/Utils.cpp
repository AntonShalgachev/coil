#include "utils/Utils.h"

std::string utils::flatten(std::vector<std::string> const& strings, std::string decorator, std::string separator)
{
	std::string currentSeparator = "";
	std::stringstream ss;

	for (std::string const& value : strings)
	{
		std::string decoratedValue = decorator + value + decorator;
		ss << currentSeparator << decoratedValue;
		currentSeparator = separator;
	}

	return ss.str();
}
