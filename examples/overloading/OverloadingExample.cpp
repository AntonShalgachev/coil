#include "OverloadingExample.h"

#include "common/ExamplesCommon.h"

// Several functions can be bound to the same command as long as those functions have different amount of arguments.

namespace
{
    std::string func1()
    {
        return "func1";
    }

    std::string func2(int)
    {
        return "func2";
    }

    std::string func3(int, float)
    {
        return "func3";
    }

    //     struct Object
    //     {
    //         std::string func1(std::string const&, float, bool)
    //         {
    //             return "Object::func1";
    // 		}
    // 		std::string func2(std::string const&, float)
    // 		{
    // 			return "Object::func2";
    // 		}
    //     };

    void createExplosion(coil::Context context, std::string_view id)
    {
        context.out() << "Creating an explosion '" << id << "' with the default radius" << std::endl;
    }

    void createExplosion(coil::Context context, std::string_view id, float radius)
    {
        context.out() << "Creating an explosion '" << id << "' with the radius " << radius << std::endl;
    }
}

void OverloadingExample::run()
{
    coil::Bindings bindings;

    //     Object object;

    auto lambda1 = []() { return "lambda1"; };

    bindings["func"] = coil::overloaded(&func1, &func2, &func3);
    bindings["mixed_func"] = coil::overloaded(std::move(lambda1), &func2 /*, coil::bind(&Object::func, &object)*/); // TODO fix
    bindings["explosions.create"] = coil::overloaded(
        // use coil::resolve to get a pointer to the specific overloaded function
        coil::resolve<void(coil::Context, std::string_view)>(createExplosion),
        coil::resolve<void(coil::Context, std::string_view, float)>(createExplosion));

    common::printSectionHeader("Several functions can be bound to the same command:");
    common::executeCommand(bindings, "func");
    common::executeCommand(bindings, "func 42");
    common::executeCommand(bindings, "func 42 3.14");
    common::executeCommand(bindings, "mixed_func");
    common::executeCommand(bindings, "mixed_func 42");
    common::executeCommand(bindings, "explosions.create small");
    common::executeCommand(bindings, "explosions.create small 1.5");

    common::printSectionHeader("If there is no overload for given arguments, an error would be returned:");
    common::executeCommand(bindings, "func 1 2 3 4");
    common::executeCommand(bindings, "mixed_func 42 3.14");
}
