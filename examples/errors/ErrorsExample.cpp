#include "ErrorsExample.h"

#include "common/ExamplesCommon.h"
#include <iostream>

namespace
{
    float checkedSqrt(coil::Context& context, float value)
    {
        if (value < 0.0f)
        {
            context.reportError("Value should be non-negative!");
            return 0.0f;
        }

        return std::sqrt(value);
    }

    float getFloat(coil::Context& context, coil::AnyArgView arg)
    {
        auto asFloat = arg.get<float>();
        if (asFloat)
            return *asFloat;
        
        context.reportError(std::move(asFloat));
        return 0.0f;
    }

    std::string_view getTypeName(coil::Context& context, coil::AnyArgView arg)
    {
        if (auto asBool = arg.get<bool>())
            return "bool";
        else if (auto asInt = arg.get<int>())
            return "int";
        else if (auto asFloat = arg.get<float>())
            return "float";
        else
            context.reportErrors("Unknown type", std::move(asBool), std::move(asInt), std::move(asFloat));

        return {};
    }

    void testNamedArgs(coil::Context& context, coil::NamedArgs& namedArgs)
    {
        // This version will automatically report error if 'any_arg' isn't passed
        auto requiredAnyArg = namedArgs.get("any_arg", context, coil::NamedArgs::ArgType::Required);
        if (!requiredAnyArg)
            return;

        // This version will automatically report error if 'float_arg' isn't passed,
        // or if the value of 'float_arg' couldn't be converted to float
        auto requiredFloatArg = namedArgs.get<float>("float_arg", context, coil::NamedArgs::ArgType::Required);
        if (!requiredFloatArg)
            return;

        // This version will automatically report error only if the value of 'int_arg' couldn't be converted to int
        auto optionalFloatArg = namedArgs.get<int>("int_arg", context, coil::NamedArgs::ArgType::Optional);

        // If the type of 'int_arg' is wrong, the error would be reported and the default value would be
        // returned (by default it's an empty std::optional)
        if (context.hasErrors())
            return;

        std::cout << requiredAnyArg->getRaw() << ", " << *requiredFloatArg;
        if (optionalFloatArg)
            std::cout << ", " << *optionalFloatArg;
        std::cout << std::endl;
    }
}

void ErrorsExample::run()
{
    coil::Bindings bindings;

    bindings["sqrt"] = checkedSqrt;
    bindings["get_float"] = getFloat;
    bindings["get_type_name"] = getTypeName;
    bindings["test_named_args"] = testNamedArgs;

    common::printSectionHeader("You can use coil::Context before user arguments to report any errors during the command");
    common::executeCommand(bindings, "sqrt 9.8596");
    common::executeCommand(bindings, "sqrt -1");

    common::printSectionHeader("You can also pass a coil::Expected value if it has an error type convertible to std::string");
    common::executeCommand(bindings, "get_float 0.1");
    common::executeCommand(bindings, "get_float true");

    common::printSectionHeader("You can report several errors at once");
    common::executeCommand(bindings, "get_type_name true");
    common::executeCommand(bindings, "get_type_name 3.14");
    common::executeCommand(bindings, "get_type_name string");

    common::printSectionHeader("Some methods of coil::NamedArgs can also automatically report errors (see NamedExample for more details)");
    common::executeCommand(bindings, "test_named_args");
    common::executeCommand(bindings, "test_named_args any_arg=something");
    common::executeCommand(bindings, "test_named_args any_arg=something float_arg=non-float");
    common::executeCommand(bindings, "test_named_args any_arg=something float_arg=3.14");
    common::executeCommand(bindings, "test_named_args any_arg=something float_arg=3.14 int_arg=non-int");
    common::executeCommand(bindings, "test_named_args any_arg=something float_arg=3.14 int_arg=42");
}
