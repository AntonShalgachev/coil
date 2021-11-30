#include "coil/Bindings.h"
#include "sol/sol.hpp"
#include "hayai/hayai.hpp"

namespace user
{
    template<std::size_t I>
    class Object
    {
    public:
        template<std::size_t J>
        void method(float, float)
        {

        }
    };

    template<std::size_t I>
    void function(float, float)
    {

    }
}

namespace util
{
    using FuncT = void(*)(float, float);

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

    template<std::size_t... Is>
    std::tuple<user::Object<Is>...> createUniqueObjectsImpl(std::index_sequence<Is...>)
    {
        return std::tuple<user::Object<Is>...>{};
    }

    template<std::size_t N>
    auto createUniqueObjects()
    {
        return createUniqueObjectsImpl(std::make_index_sequence<N>{});
    }

    template<std::size_t I>
    using MethodT = void(user::Object<I>::*)(float ,float);

    template<std::size_t I, std::size_t... Js>
    std::vector<MethodT<I>> generateUniqueMethodsForTypeImpl(std::index_sequence<Js...>)
    {
        return {&user::Object<I>::template method<Js>...};
    }

    template<std::size_t I, std::size_t M>
    std::vector<MethodT<I>> generateUniqueMethodsForType()
    {
        return generateUniqueMethodsForTypeImpl<I>(std::make_index_sequence<M>{});
    }

    template<std::size_t M, std::size_t... Is>
    auto generateUniqueMethodsImpl(std::index_sequence<Is...>)
    {
        return std::tuple<std::vector<MethodT<Is>>...>{generateUniqueMethodsForType<Is, M>()...};
    }

    template<std::size_t N, std::size_t M>
    auto generateUniqueMethods()
    {
        return generateUniqueMethodsImpl<M>(std::make_index_sequence<N>{});
    }
}

namespace
{
    coil::Bindings cmd;
    coil::ExecutionInput cmdInput{ "", "long_function_name_please0", {"3.14", "0.16"}, {} };
    coil::ExecutionInput cmdInputObject{ "long_object_name_please0", "long_method_name_please0", {"3.14", "0.16"}, {} };

    sol::state lua;

    std::size_t constexpr freeFuncsCount = 500;
    std::size_t constexpr objectsCount = 10;
    std::size_t constexpr methodsCount = 300;

    auto objects = util::createUniqueObjects<objectsCount>();

    void prepare()
    {
        static std::list<std::string> names;

        auto getView = [](std::string value) -> std::string_view
        {
            names.push_back(std::move(value));
            return names.back();
        };

        auto functions = util::generateUniqueFunctions<freeFuncsCount>();

        for (std::size_t i = 0; i < freeFuncsCount; i++)
        {
            std::string_view name = getView("long_function_name_please" + std::to_string(i));
            cmd[name] = functions[i];
            lua[name] = functions[i];
        }

        auto addObject = [getView](auto&& object, std::size_t index)
        {
            std::string_view name = getView("long_object_name_please" + std::to_string(index));
            cmd.addObject(name, &object);
            lua[name] = &object;
        };

        std::apply([addObject = std::move(addObject)](auto&&... object)
        {
            std::size_t index = 0;
            (addObject(object, index++), ...);
        }, objects);

        auto methods = util::generateUniqueMethods<objectsCount, methodsCount>();

        auto addMethods = [getView](auto&& methods)
        {
            using Traits = coil::utils::FuncTraits<std::decay_t<decltype(methods[0])>>;

            auto usertype = lua.new_usertype<Traits::ObjectType>("Object", sol::no_constructor);

            for (std::size_t i = 0; i < methods.size(); i++)
            {
                auto const& method = methods[i];

                std::string_view name = getView("long_method_name_please" + std::to_string(i));
                cmd.bind<Traits::ObjectType>(name, method);

                usertype[name] = method;
            }
        };

        std::apply([addMethods = std::move(addMethods)](auto&&... methods)
        {
            (addMethods(methods), ...);
        }, methods);
    }

    int runs = 1000;
    int iterations = 1000;

    BENCHMARK(Scripting, Coil, runs, iterations)
    {
        cmd.execute("long_function_name_please0 3.14 0.16");
    }

    BENCHMARK(Scripting, Coil_Object, runs, iterations)
    {
        cmd.execute("long_object_name_please0.long_method_name_please0 3.14 0.16");
    }

    BENCHMARK(Scripting, CoilNoParse, runs, iterations)
    {
        cmd.execute(cmdInput);
    }

    BENCHMARK(Scripting, CoilNoParse_Object, runs, iterations)
    {
        cmd.execute(cmdInputObject);
    }

    BENCHMARK(Scripting, Sol, runs, iterations)
    {
        lua.script("long_function_name_please0(3.14, 0.16)");
    }

    BENCHMARK(Scripting, Sol_Object, runs, iterations)
    {
        lua.script("long_object_name_please0:long_method_name_please0(3.14, 0.16)");
    }

    BENCHMARK(Scripting, DirectFromString, runs, iterations)
    {
        using TS = coil::TypeSerializer<float>;
        auto onError = [](auto) {};
        user::function<0>(TS::fromString("3.14", onError), TS::fromString("0.16", onError));
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