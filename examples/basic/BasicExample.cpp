#include "BasicExample.h"

#include "coil/Bindings.h"

#include <iostream>

namespace
{
    void func()
    {
        std::cout << "Hello, world!" << std::endl;
    }

    void printRepeated(std::string const& val, std::size_t repetitions)
    {
        for (std::size_t i = 0; i < repetitions; i++)
            std::cout << val;
        std::cout << std::endl;
    }

    void printDecorated(std::string_view val)
    {
        std::cout << "'" << val << "'" << std::endl;
    }

    float add(float a, float b)
    {
        return a + b;
    }

    std::string concat(std::string const& a, std::string const& b)
    {
        return a + b;
    }
}

void BasicExample::run()
{
    coil::Bindings bindings;

    bindings["function"] = &func;
    bindings["print_repeated"] = &printRepeated;
    bindings["print_decorated"] = &printDecorated;
    bindings["add"] = &add;
    bindings["concat"] = &concat;

    auto header = [](std::string_view str)
    {
        std::cout << str << std::endl;
        std::cout << std::string(str.length(), '=') << std::endl;
    };

    auto execute = [&bindings](std::string_view command)
    {
        std::cout << "Executing [" << command << "]" << std::endl;
        auto result = bindings.execute(command);

        for (const auto& error : result.errors)
            std::cout << "\t" << "Error: " << error << std::endl;
        if (!result.output.empty())
            std::cout << "\t" << "Output: '" << result.output << "'" << std::endl;
        std::cout << std::endl;
    };

    header("Basic function without any arguments:");
    execute("function");

    header("Functions with arbitrary arguments:");
    execute("print_decorated coil");
    execute("print_repeated hi 10");

    header("Functions with return values:");
    execute("add 3.14 2.72");
    execute("concat abc 123");

    header("coil catches wrong number of arguments:");
    execute("function 1 2");
    execute("add 3.14");

    header("coil catches incompatible types");
    execute("add one two");
}
