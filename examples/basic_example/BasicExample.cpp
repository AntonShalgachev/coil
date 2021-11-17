#include "BasicExample.h"

#include "coil/Bindings.h"
#include "EnumToString.h"
#include "Test.h"

#include "magic_enum.hpp"
#include <iostream>

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
        coil::Bindings cmd;

        ServiceB serviceB;

        cmd.addObject("service", &serviceB);

        cmd.bind<ServiceB>("update", &ServiceB::update);

        cmd["func"] = &optionalArgFunc;
        cmd["namedFunc"] = &variadicNamedFunc;
        cmd["enumFunc"] = &enumFunc;

        auto execute = [&cmd](std::string_view command)
        {
            std::cout << "Executing [" << command << "]" << std::endl;
            auto result = cmd.execute(command);

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

void BasicExample::registerExample(coil::Bindings& bindings)
{
    bindings.addObject("basic_example", this);

    bindings.bind<BasicExample>("run", & BasicExample::run);

    // TODO remove object upon destruction
}

void BasicExample::run()
{
    compilation_test::run();
    test::test();
}
