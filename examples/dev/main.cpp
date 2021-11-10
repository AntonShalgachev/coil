#include <iostream>

#include "coil/CommandListener.h"
#include "coil/VariadicArg.h"
#include "tests/Test.h"
#include "SimpleLexer.h"
#include "coil/NamedArgs.h"
#include "magic_enum.hpp"

#include "EnumToString.h"

namespace ext
{
    enum class Speed
    {
        Slow,
        Fast,
    };

#ifndef USE_MAGIC_ENUM
    static std::vector<std::string_view> speedEnumNames = { "Slow", "Fast" };
#endif
}

#ifndef USE_MAGIC_ENUM
namespace enum_util
{
    template<>
    std::vector<std::string_view> const& getEnumNames<ext::Speed>()
    {
        return ext::speedEnumNames;
    }
}
#endif

namespace test
{
    enum class Type
    {
        Soft,
        Hard,
    };

#ifndef USE_MAGIC_ENUM
    static std::vector<std::string_view> typeEnumNames = { "Soft", "Hard" };
#endif
}

#ifndef USE_MAGIC_ENUM
namespace enum_util
{
    template<>
    std::vector<std::string_view> const& getEnumNames<test::Type>()
    {
        return test::typeEnumNames;
    }
}
#endif

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

    bool freeFunction(coil::Context&, coil::VariadicArg arg)
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

    Type enumFunc(Type type, std::optional<ext::Speed> speed)
    {
        std::cout << "Type: " << magic_enum::enum_name(type) << std::endl;
        if (speed.has_value())
            std::cout << "Speed: " << magic_enum::enum_name(speed.value()) << std::endl;

        if (type == Type::Soft)
            return Type::Hard;
        return Type::Soft;
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
        cmd.bind("enumFunc", &enumFunc);

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

        execute("enumFunc Soft Fast");
        execute("enumFunc soft FAst");
        execute("enumFunc hard slOW");
        execute("enumFunc Hard Slow");
        execute("enumFunc foo bar");
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
