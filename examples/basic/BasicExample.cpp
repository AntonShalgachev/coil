#include "BasicExample.h"

#include "common/ExamplesCommon.h"

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

    common::printSectionHeader("Basic function without any arguments:");
    common::executeCommand(bindings, "function");

    common::printSectionHeader("Functions with arbitrary arguments:");
    common::executeCommand(bindings, "print_decorated coil");
    common::executeCommand(bindings, "print_repeated hi 10");

    common::printSectionHeader("Functions with return values:");
    common::executeCommand(bindings, "add 3.14 2.72");
    common::executeCommand(bindings, "concat abc 123");

    common::printSectionHeader("coil catches wrong number of arguments:");
    common::executeCommand(bindings, "function 1 2");
    common::executeCommand(bindings, "add 3.14");

    common::printSectionHeader("coil catches incompatible types:");
    common::executeCommand(bindings, "add one two");
}
