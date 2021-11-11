#include <iostream>

#include "basic_example/BasicExample.h"

#include "coil/Bindings.h"
#include "SimpleLexer.h"

void help()
{
    std::cout << "Some help" << std::endl;
}

int main()
{
    coil::Bindings bindings;

    bindings["help"] = &help;

    BasicExample example;
    example.registerExample(bindings);

    while (true)
    {
        std::cout << ">>> ";
        std::string line;
        std::getline(std::cin, line);

        auto result = bindings.execute(line, SimpleLexer{});

        for (const auto& error : result.errors)
            std::cout << "\t" << "Error: " << error << std::endl;
        if (!result.output.empty())
            std::cout << "\t" << "Output: '" << result.output << "'" << std::endl;
    }

    return 0;
}