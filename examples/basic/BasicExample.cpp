#include "BasicExample.h"

#include "common/ExamplesCommon.h"

#include <iostream>

namespace
{
    void hello()
    {
        std::cout << "Hello, world!" << std::endl;
    }

    void helloWithContext(coil::Context context)
    {
        context.out() << "Hello, world!" << std::endl;
    }

    void printRepeated(coil::Context context, std::string const& val, std::size_t repetitions)
    {
        for (std::size_t i = 0; i < repetitions; i++)
            context.out() << val;
        context.out() << std::endl;
    }

    void printQuoted(coil::Context context, std::string_view val)
    {
        context.out() << "'" << val << "'" << std::endl;
    }

    bool invert(bool val)
    {
        return !val;
    }

    float add(float a, float b)
    {
        return a + b;
    }

    std::string concat(std::string const& a, std::string const& b)
    {
        return a + b;
    }

    class Object
    {
    public:
        Object(int multiplier) : m_multiplier(multiplier) {}

        int getData() const { return m_multiplier; }

        int getMultiplied(int input)
        {
            return input * m_multiplier;
        }

    private:
        int m_multiplier = 0;
    };
}

void BasicExample::run()
{
    coil::Bindings bindings;

    bindings.bind("hello", &hello);
    // can be simplified to:
    // bindings["hello"] = &hello;

    bindings["hello_with_context"] = &helloWithContext;
    bindings["print_repeated"] = &printRepeated;
    bindings["print_quoted"] = &printQuoted;
    bindings["invert"] = &invert;
    bindings["add"] = &add;
    bindings["concat"] = &concat;

    auto objectBindings = bindings.createObjectBindings<Object>();
    objectBindings["get_multiplied"] = &Object::getMultiplied;
    // alternatively you can use this form:
    // bindings.bind<Object>("get_multiplied", &Object::getMultiplied);

    Object doubleMultiplier{ 2 };
    Object tenfoldMultiplier{ 10 };
    bindings.addObject("double_multiplier", &doubleMultiplier);
    bindings.addObject("tenfold_multiplier", &tenfoldMultiplier);

    common::printSectionHeader("Basic function without any arguments:");
    common::executeCommand(bindings, "hello");

    common::printSectionHeader("Use coil::Context to capture output in the execution result:");
    common::executeCommand(bindings, "hello_with_context");

    common::printSectionHeader("Functions with arbitrary arguments:");
    common::executeCommand(bindings, "print_quoted coil");
    common::executeCommand(bindings, "print_repeated hi 10");

    common::printSectionHeader("Boolean arguments can be passed in any format:");
    common::executeCommand(bindings, "invert true");
    common::executeCommand(bindings, "invert True");
    common::executeCommand(bindings, "invert 0");
    common::executeCommand(bindings, "invert FALSE");

    common::printSectionHeader("Functions with return values:");
    common::executeCommand(bindings, "add 3.14 2.72");
    common::executeCommand(bindings, "concat abc 123");

    common::printSectionHeader("coil catches wrong number of arguments:");
    common::executeCommand(bindings, "function 1 2");
    common::executeCommand(bindings, "add 3.14");

    common::printSectionHeader("coil catches incompatible types:");
    common::executeCommand(bindings, "add one two");

    common::printSectionHeader("You can also use add any C++ objects and call their methods:");
    common::executeCommand(bindings, "double_multiplier.get_multiplied 10");
    common::executeCommand(bindings, "tenfold_multiplier.get_multiplied 10");
}
