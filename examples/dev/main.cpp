#include <iostream>

#include "coil/CommandListener.h"
#include "coil/VariadicArg.h"
#include "tests/Test.h"
#include "SimpleLexer.h"
#include "coil/NamedArgs.h"

namespace test
{
    class ServiceB
    {
    public:
        float update(coil::Context& context, float dt)
        {
            if (dt < 1.0f)
            {
                context.reportError("Very low dt");
                return 0;
            }

            std::cout << "ServiceB::update " << dt << std::endl;
            return dt;
        }
    };

    coil::VariadicArg freeFunction(coil::Context&, coil::VariadicArg arg)
    {
        std::cout << "I'm a free function!" << std::endl;
        return !arg.as<bool>();
    }

    std::optional<bool> optionalArgFunc(std::optional<bool> arg)
    {
        std::cout << "Optional arg!" << std::endl;

        if (arg.has_value())
            return !arg.value();

        return {};
    }

    void variadicNamedFunc(coil::NamedArgs args)
    {
        std::cout << args.size() << " arguments were received:" << std::endl;
        for (coil::NamedArg const& arg : args)
        {
            auto variadic = arg.asVariadic();
            bool isFloat = variadic.is<float>();
            std::cout << arg.key() << ": " << arg.value() << (isFloat ? " (float)" : "") << std::endl;
        }
    }

    void test()
    {
        coil::CommandListener cmd;

        ServiceB serviceB;

        cmd.addObject("service", &serviceB);

        cmd.bind<ServiceB>("update", &ServiceB::update);

        cmd.bind("func", &optionalArgFunc);
        cmd.bind("namedFunc", &variadicNamedFunc);

        SimpleLexer lexer;

		auto execute = [&cmd, &lexer](std::string command)
		{
			std::cout << "Executing [" << command << "]" << std::endl;
			auto result = cmd.execute(std::move(command), lexer);

			for (const auto& error : result.errors)
				std::cout << "\t" << "Error: " << error << std::endl;
			if (!result.output.empty())
				std::cout << "\t" << "Output: '" << result.output << "'" << std::endl;
            std::cout << std::endl;
		};

        //execute("service.update 0.16");
        //execute("service.update 1.16");
        //execute("service.update 1.16s");
        execute("func true");
        execute("func trues");
        execute("func");
        execute("func key=val");
        execute("namedFunc time=0.15 key=value dt=0.12");
    }
}

int main()
{
    try
    {
        coil::tests::test();

        test::test();
        std::getchar();
    }
    catch (std::exception& e)
    {
        std::cout << "Finished with exception:" << std::endl;
        std::cout << e.what();
        std::getchar();
    }

	return 0;
}
