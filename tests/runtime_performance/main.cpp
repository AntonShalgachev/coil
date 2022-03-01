#include "coil/Bindings.h"

#pragma warning(push)
#pragma warning(disable: 4701) // potentially uninitialized local variable 'newColor' used
#include "hayai/hayai.hpp"
#pragma warning(pop)

namespace user
{
    template<std::size_t I>
    double function(float, float)
    {
        return 3.14;
    }
}

namespace util
{
    using FuncT = decltype(&user::function<0>);

    template<std::size_t... Is>
    std::vector<FuncT> generateUniqueFunctionsImpl(std::index_sequence<Is...>)
    {
        return std::vector<FuncT>{&user::function<Is>...};
    }

    template<std::size_t N>
    std::vector<FuncT> generateUniqueFunctions()
    {
        return generateUniqueFunctionsImpl(std::make_index_sequence<N>{});
    }
}

namespace
{
    coil::Bindings cmd;
    coil::ExecutionInput cmdInput{ "long_function_name_please0", {{"3.14"}, {"0.16"}}, {} };

    std::size_t constexpr freeFuncsCount = 500;

    void prepare()
    {
        auto functions = util::generateUniqueFunctions<freeFuncsCount>();

        for (std::size_t i = 0; i < freeFuncsCount; i++)
        {
            auto name = "long_function_name_please" + std::to_string(i);
            cmd[name] = functions[i];
        }
    }

    int runs = 1000;
    int iterations = 1000;

    BENCHMARK(Scripting, Coil, runs, iterations)
    {
        cmd.execute("long_function_name_please0 3.14 0.16");
    }

    BENCHMARK(Scripting, CoilNoParse, runs, iterations)
    {
        cmd.execute(cmdInput);
    }

    BENCHMARK(Scripting, DirectFromString, runs, iterations)
    {
        using namespace std::literals;

        using TS = coil::TypeSerializer<float>;
        auto arg1 = TS::fromString("3.14"sv);
        auto arg2 = TS::fromString("0.16"sv);
        if (arg1 && arg2)
            user::function<0>(*arg1, *arg2);
    }
}

int main()
{
    prepare();

    hayai::ConsoleOutputter consoleOutputter;

    hayai::Benchmarker::AddOutputter(consoleOutputter);
    hayai::Benchmarker::RunAllTests();

    std::getchar();

    return 0;
}