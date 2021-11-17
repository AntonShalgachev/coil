#include <iostream>

#include "basic_example/BasicExample.h"

#include "coil/Bindings.h"
#include "CustomTypeName.h"

#include "LexerTests.h"

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

    {
        //lexer_tests::run();
        bindings.execute("basic_example.run");
    }

    while (true)
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