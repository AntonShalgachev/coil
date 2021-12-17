#include <iostream>

#include "common/ExamplesCommon.h"

#include "basic/BasicExample.h"
#include "variadic/VariadicExample.h"
#include "variables/VariablesExample.h"
#include "named/NamedExample.h"
#include "enums/EnumsExample.h"
#include "errors/ErrorsExample.h"

#include "coil/Bindings.h"

void help()
{
    std::cout << "Some help" << std::endl;
}

template<typename Example>
void bindExample(coil::Bindings& bindings, Example& example, std::string_view name)
{
    Example::registerExample(bindings);
    bindings.addObject(name, &example);
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
    bool shouldExit = false;

    coil::Bindings bindings;

    bindings["help"] = &help;
    bindings["exit"] = [&shouldExit]()
    {
        shouldExit = true;
    };

    using Examples = std::tuple<BasicExample
        , VariadicExample
        , VariablesExample
        , NamedExample
        , EnumsExample
        , ErrorsExample
    >;

    std::array<std::string_view, std::tuple_size_v<Examples>> names = {
        "basic",
        "variadic",
        "variables",
        "named",
        "enums",
        "errors",
    };

    Examples examples;
    bindExamples(bindings, examples, names);

    while (!shouldExit)
    {
        std::cout << ">>> ";
        std::string line;
        std::getline(std::cin, line);

        auto result = bindings.execute(line);

        for (const auto& error : result.errors)
            std::cout << "Error: " << error << std::endl;
        if (result.returnValue)
            std::cout << "Return value: '" << *result.returnValue << "'" << std::endl;
    }

    return 0;
}