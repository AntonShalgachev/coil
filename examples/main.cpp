#include <iostream>

#include "common/ExamplesCommon.h"

#include "advanced/AdvancedExample.h"
#include "basic/BasicExample.h"
#include "compound/CompoundExample.h"
#include "encapsulation/EncapsulationExample.h"
#include "enums/EnumsExample.h"
#include "errors/ErrorsExample.h"
#include "flags/FlagsExample.h"
#include "named/NamedExample.h"
#include "overloading/OverloadingExample.h"
#include "properties/PropertiesExample.h"
#include "usertypes/UsertypesExample.h"
#include "variables/VariablesExample.h"
#include "variadic/VariadicExample.h"

template<typename Example>
void bindExample(coil::Bindings& bindings, Example& example)
{
    bindings[Example::name] = coil::bind(&Example::run, &example);
}

template<typename... Examples, std::size_t... Is>
void bindExamples(coil::Bindings& bindings, std::tuple<Examples...>& examples, std::index_sequence<Is...>)
{
    (bindExample(bindings, std::get<Is>(examples)), ...);
}

template<typename... Examples>
void bindExamples(coil::Bindings& bindings, std::tuple<Examples...>& examples)
{
    bindExamples(bindings, examples, std::make_index_sequence<sizeof...(Examples)>{});
}

template<typename ExamplesTuple, std::size_t... Is>
auto extractNames(std::index_sequence<Is...>)
{
    return std::array<std::string_view, sizeof...(Is)>{std::tuple_element_t<Is, ExamplesTuple>::name...};
}

template<typename ExamplesTuple>
auto extractNames()
{
    return extractNames<ExamplesTuple>(std::make_index_sequence<std::tuple_size_v<ExamplesTuple>>());
}

int main()
{
    // clang-format off
    using Examples = std::tuple<
          BasicExample
        , VariablesExample
        , EnumsExample
        , FlagsExample
        , VariadicExample
        , NamedExample
        , UsertypesExample
        , ErrorsExample
        , CompoundExample
        , OverloadingExample
        , PropertiesExample
        , EncapsulationExample
        , AdvancedExample
	>;
    // clang-format on

    auto names = extractNames<Examples>();

    bool shouldExit = false;

    coil::Bindings bindings;

    bindings["help"] = [&names](coil::Context context) {
        context.logline("Available examples:");
        for (std::string_view name : names)
            context.logf("    %.*s\n", name.size(), name.data());
        context.logline("");
        context.logline("Type the example name to run it");
        context.logline("Type 'help' for this help");
        context.logline("Type 'exit' to exit");
        context.logline("");
    };
    bindings["exit"] = [&shouldExit]() { shouldExit = true; };
    bindings["run_all"] = [&names, &bindings]() {
        for (std::string_view name : names)
            bindings.execute(name);
    };

    Examples examples;
    bindExamples(bindings, examples);

    auto execute = [&bindings](std::string_view str) {
        auto result = bindings.execute(str);

        for (const auto& error : result.errors)
            std::cout << "Error: " << error << std::endl;

        std::cout << result.output;
        if (!result.output.empty() && result.output.back() != '\n')
            std::cout << std::endl;

        if (result.returnValue)
            std::cout << "Return value: '" << *result.returnValue << "'" << std::endl;
    };

    execute("help");

    while (!shouldExit)
    {
        std::cout << ">>> ";
        std::string line;
        std::getline(std::cin, line);

        execute(line);
    }

    return 0;
}