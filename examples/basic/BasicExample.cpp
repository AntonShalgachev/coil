#include "BasicExample.h"

#include "common/ExamplesCommon.h"

#include <iostream>
#include <functional>

namespace
{
    void hello()
    {
        std::cout << "Hello, world!" << std::endl;
    }

    void helloWithContext(coil::Context context)
    {
        context.log("log: no automatic");
        context.log(" line break\n");

        context.logline("logline: line break is added automatically");

        context.logf("logf: %s automatic", "no");
        context.logf(" line break, but %s", "formatted\n");

        context.loglinef("loglinef: automatic line break and formatted");
    }

    void printRepeated(coil::Context context, coil::String const& val, std::size_t repetitions)
    {
        for (std::size_t i = 0; i < repetitions; i++)
            context.log(val);
    }

    void printQuoted(coil::Context context, coil::StringView val)
    {
        context.loglinef("'%.*s'", val.slength(), val.data());
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

    std::string plainFunction(int arg)
    {
        return "I am a function: " + std::to_string(arg);
    }

    class Object
    {
    public:
        Object(int multiplier) : m_multiplier(multiplier) {}

        int getData() const
        {
            return m_multiplier;
        }

        int scale(int input) const
        {
            return input * m_multiplier;
        }

    private:
        int m_multiplier = 0;
    };

    struct CustomFunctor
    {
        std::string operator()(int arg)
        {
            return "I am a custom functor: " + std::to_string(arg);
        }
    };
}

void BasicExample::run()
{
    coil::Bindings bindings;

    bindings["hello"] = &hello;
    bindings["hello_with_context"] = &helloWithContext;
    bindings["print_repeated"] = &printRepeated;
    bindings["print_quoted"] = &printQuoted;
    bindings["invert"] = &invert;
    bindings["add"] = &add;
    bindings["concat"] = &concat;

    bindings["plain_function"] = &plainFunction;
    bindings["lambda"] = [](int arg) { return "I am a lambda: " + std::to_string(arg); };
    bindings["custom_functor"] = CustomFunctor{};
    std::function<std::string(int)> stdFunction = [](int arg) { return "I am a std::function: " + std::to_string(arg); };
    bindings["std_function"] = std::move(stdFunction);

    Object scaler1{2};
    Object scaler2{10};
    bindings["scaler1.scale"] = coil::bind(&Object::scale, &scaler1);
    bindings["scaler2.scale"] = coil::bind(&Object::scale, &scaler2);

    common::printSectionHeader("Basic function without any arguments:");
    common::executeCommand(bindings, "hello");

    common::printSectionHeader("Use coil::Context to capture output in the execution result:");
    common::executeCommand(bindings, "hello_with_context");

    common::printSectionHeader("Functions with arbitrary arguments:");
    common::executeCommand(bindings, "print_quoted coil");
    common::executeCommand(bindings, "print_repeated hi 10");

    common::printSectionHeader("Strings with spaces can be wrapped in single or double quotes:");
    common::executeCommand(bindings, "print_quoted 'I have spaces'");
    common::executeCommand(bindings, "print_repeated \"I also have spaces \" 5");

    common::printSectionHeader("Boolean arguments can be passed in any format:");
    common::executeCommand(bindings, "invert true");
    common::executeCommand(bindings, "invert True");
    common::executeCommand(bindings, "invert 0");
    common::executeCommand(bindings, "invert FALSE");

    common::printSectionHeader("Return values of functions are returned as strings:");
    common::executeCommand(bindings, "add 3.14 2.72");
    common::executeCommand(bindings, "concat abc 123");

    common::printSectionHeader("Any callable object can be bound:");
    common::executeCommand(bindings, "plain_function 101");
    common::executeCommand(bindings, "lambda 102");
    common::executeCommand(bindings, "custom_functor 103");
    common::executeCommand(bindings, "std_function 104");

    common::printSectionHeader("Use coil::bind to bind member functions:");
    common::executeCommand(bindings, "scaler1.scale 10");
    common::executeCommand(bindings, "scaler2.scale 10");

    common::printSectionHeader("coil catches wrong number of arguments:");
    common::executeCommand(bindings, "hello 1 2");
    common::executeCommand(bindings, "add 3.14");

    common::printSectionHeader("coil catches incompatible types:");
    common::executeCommand(bindings, "add one two");
}
