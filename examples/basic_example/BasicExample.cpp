#include "BasicExample.h"

#include "coil/Bindings.h"
#include "CustomTypeName.h"
#include "EnumToString.h"

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

    void funcVector(float, int, std::vector<double>)
    {

    }

    void funcOptional(float, int, std::optional<double>)
    {

    }

    void funcNormal(float, int, double)
    {

    }

    void test()
    {
        coil::Bindings cmd;

        ServiceB serviceB;

        cmd.addObject("service", &serviceB);

        cmd["normal"] = &funcNormal;
        cmd["optional"] = &funcOptional;
        cmd["vector"] = &funcVector;

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

        execute("normal 0 1");
        execute("normal 0 1 2");
        execute("normal 0 1 2 3");

        execute("optional 0");
        execute("optional 0 1");
        execute("optional 0 1 2");
        execute("optional 0 1 2 3");

        execute("vector 0");
        execute("vector 0 1");
        execute("vector 0 1 2");
        execute("vector 0 1 2 3");
    }
}

void BasicExample::registerExample(coil::Bindings& bindings)
{
    bindings.bind<BasicExample>("run", &BasicExample::run);
}

void BasicExample::run()
{
    test::test();
}
