#include "ExamplesCommon.h"

#include <iostream>
#include "termcolor.hpp"

namespace
{
    auto headerColor = &termcolor::cyan<char>;
    auto errorColor = &termcolor::red<char>;
    auto commandColor = &termcolor::bright_yellow<char>;
    auto returnColor = &termcolor::green<char>;
    auto outputColor = &termcolor::bright_grey<char>;
}

void common::printSectionHeader(std::string_view header)
{
    std::cout << headerColor;
    std::cout << std::string(header.length(), '=') << std::endl;
    std::cout << header << std::endl;
    std::cout << std::string(header.length(), '=') << std::endl;
    std::cout << termcolor::reset;
}

void common::executeCommand(coil::Bindings& bindings, std::string_view command)
{
    std::cout << "Executing [" << commandColor << command << termcolor::reset << "]" << std::endl;
    auto result = bindings.execute(command);

    for (const auto& error : result.errors)
        std::cout << errorColor << "\t" << "Error: " << error << termcolor::reset << std::endl;

    std::cout << outputColor << result.output.str() << termcolor::reset;

    if (result.returnValue)
        std::cout << "\t" << "Returned '" << returnColor << *result.returnValue << termcolor::reset << "'" << std::endl;

    std::cout << std::endl;
}
