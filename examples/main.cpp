#include <iostream>

#include "basic/BasicExample.h"
#include "variadic/VariadicExample.h"

#include "coil/Bindings.h"
#include "CustomTypeName.h"

#include "LexerTests.h"

void help()
{
    std::cout << "Some help" << std::endl;
}

int main()
{
    bool shouldExit = false;

    coil::Bindings bindings;

    bindings["help"] = &help;
    bindings["exit"] = [&shouldExit]()
    {
        shouldExit = true;
    };

    BasicExample basic;
    basic.registerExample(bindings);
    bindings.addObject("basic", &basic);

    VariadicExample variadic;
    variadic.registerExample(bindings);
    bindings.addObject("variadic", &variadic);

    while (!shouldExit)
    {
        std::cout << ">>> ";
        std::string line;
        std::getline(std::cin, line);

        auto result = bindings.execute(line);

        for (const auto& error : result.errors)
            std::cout << "Error: " << error << std::endl;
        if (!result.output.empty())
            std::cout << "Output: '" << result.output << "'" << std::endl;
    }

    return 0;
}