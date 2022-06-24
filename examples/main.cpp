#include <iostream>

#include "common/ExamplesCommon.h"

#include "basic/BasicExample.h"
#include "compound/CompoundExample.h"
#include "enums/EnumsExample.h"
#include "errors/ErrorsExample.h"
#include "flags/FlagsExample.h"
#include "named/NamedExample.h"
#include "overloading/OverloadingExample.h"
#include "usertypes/UsertypesExample.h"
#include "variables/VariablesExample.h"
#include "variadic/VariadicExample.h"

template<typename Example>
void bindExample(coil::Bindings& bindings, Example& example, std::string_view name)
{
    bindings[name] = coil::bind(&Example::run, &example);
}

template<typename... Examples, std::size_t... Is>
void bindExamples(coil::Bindings& bindings, std::tuple<Examples...>& examples, std::array<std::string_view, sizeof...(Examples)> const& names, std::index_sequence<Is...>)
{
    (bindExample(bindings, std::get<Is>(examples), std::get<Is>(names)), ...);
}

template<typename... Examples>
void bindExamples(coil::Bindings& bindings, std::tuple<Examples...>& examples, std::array<std::string_view, sizeof...(Examples)> const& names)
{
    bindExamples(bindings, examples, names, std::make_index_sequence<sizeof...(Examples)>{});
}

int main()
{
    // clang-format off
    using Examples = std::tuple<
          BasicExample
        , VariadicExample
        , VariablesExample
        , NamedExample
        , EnumsExample
        , ErrorsExample
        , UsertypesExample
        , CompoundExample
        , FlagsExample
        , OverloadingExample
	>;
    // clang-format on

    // TODO sort examples in the order which makes sense
    std::array<std::string_view, std::tuple_size_v<Examples>> names = {
        "basic",
        "variadic",
        "variables",
        "named",
        "enums",
        "errors",
        "usertypes",
        "compound",
        "flags",
        "overloading",
    };

    std::array<std::string_view, 4> commands = {
        "help",
        "list",
        "run_all",
        "exit",
    };

    bool shouldExit = false;

    coil::Bindings bindings;

    bindings["help"] = [&commands, &names](coil::Context context) {
        context.out() << "Available commands:" << std::endl;
        for (std::string_view name : names)
            context.out() << '\t' << name << std::endl;
        context.out() << std::endl;
        for (std::string_view name : commands)
            context.out() << '\t' << name << std::endl;
    };
    bindings["exit"] = [&shouldExit]() { shouldExit = true; };
    bindings["list"] = [&names](coil::Context context) {
        context.out() << "Available examples:" << std::endl;
        for (std::string_view name : names)
            context.out() << '\t' << name << std::endl;
    };
    bindings["run_all"] = [&names, &bindings]() {
        for (std::string_view name : names)
            bindings.execute(name);
    };

    Examples examples;
    bindExamples(bindings, examples, names);

    auto execute = [&bindings](std::string_view str) {
        auto result = bindings.execute(str);

        for (const auto& error : result.errors)
            std::cout << "Error: " << error << std::endl;
        std::cout << result.output.str();
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