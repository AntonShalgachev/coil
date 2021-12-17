#include "ExamplesCommon.h"

#include <iostream>
#include "coil/Bindings.h"

void common::printSectionHeader(std::string_view header)
{
    std::cout << header << std::endl;
    std::cout << std::string(header.length(), '=') << std::endl;
}

void common::executeCommand(coil::Bindings& bindings, std::string_view command)
{
    std::cout << "Executing [" << command << "]" << std::endl;
    auto result = bindings.execute(command);

    for (const auto& error : result.errors)
        std::cout << "\t" << "Error: " << error << std::endl;
    if (result.returnValue)
        std::cout << "\t" << "Return value: '" << *result.returnValue << "'" << std::endl;
    std::cout << std::endl;
}
