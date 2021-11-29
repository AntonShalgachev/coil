#include "coil/Bindings.h"
#include "sol/sol.hpp"
#include "hayai/hayai.hpp"

namespace
{
#pragma optimize("", off)
    void function(float, float)
    {

    }
#pragma optimize("", off)

    coil::Bindings cmd;
    coil::ExecutionInput input{ "", "func", {"3.14", "0.16"} };

    sol::state lua;

    BENCHMARK(Scripting, Coil, 100, 1000)
    {
        cmd.execute("func 3.14 0.16");
    }

    BENCHMARK(Scripting, CoilNoParse, 100, 1000)
    {
        cmd.execute(input);
    }

    BENCHMARK(Scripting, Sol, 100, 1000)
    {
        lua.script("func(3.14, 0.16)");
    }

    BENCHMARK(Scripting, DirectFromString, 100, 1000)
    {
        using TS = coil::TypeSerializer<float>;
        auto onError = [](auto) {};
        function(TS::fromString("3.14", onError), TS::fromString("0.16", onError));
    }

    BENCHMARK(Scripting, Direct, 10, 100)
    {
        function(3.14f, 0.16f);
    }
}

int main()
{
    cmd["func"] = &function;
    lua["func"] = &function;

    hayai::ConsoleOutputter consoleOutputter;

    hayai::Benchmarker::AddOutputter(consoleOutputter);
    hayai::Benchmarker::RunAllTests();

    std::getchar();

    return 0;
}