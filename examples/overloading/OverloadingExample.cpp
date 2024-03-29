#include "OverloadingExample.h"

#include "common/ExamplesCommon.h"

#include "coil/StdLibCompat.h" // implementation of TypeSerializer and TypeName for some C++ Standard Library types

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

    class Object
    {
    public:
        Object(std::string name) : m_name(std::move(name)) {}

        std::string func1(std::string const&, float)
        {
            return "Object::func1 from " + m_name;
        }
        std::string func2(std::string const&, float, bool)
        {
            return "Object::func2 from " + m_name;
        }

    private:
        std::string m_name;
    };

    void createExplosion(coil::Context context, std::string_view id)
    {
        context.loglinef("Creating an explosion '%.*s' with the default radius", static_cast<int>(id.size()), id.data());
    }

    void createExplosion(coil::Context context, std::string_view id, float radius)
    {
        context.loglinef("Creating an explosion '%.*s' with the radius %f", static_cast<int>(id.size()), id.data(), radius);
    }

    // A small helper function template which returns the pointer to the specific overloaded function
    // Signature should be of form R(Arg1, Arg2), where R -- return type, ArgN -- parameter types
    // Usage:
    // int func(int, float) {return 42;}
    // bool func(float, std::string) {return false;}
    // bindings["func1"] = coil::resolve<int(int, float)>(func);
    // bindings["func2"] = coil::resolve<bool(float, std::string)>(func);
    template<typename Signature>
    Signature* resolve(Signature* func)
    {
        return func;
    }
}

void OverloadingExample::run()
{
    coil::Bindings bindings;

    Object object1{"object_one"};
    Object object2{"object_two"};

    bindings["func"] = coil::overloaded(&func1, &func2, &func3);
    bindings["mixed_func"] = coil::overloaded([]() { return "lambda1"; }, &func2, coil::bind(&Object::func1, &object1), coil::bind(&Object::func2, &object2));
    bindings["explosions.create"] = coil::overloaded(
        // use ::resolve to get a pointer to the specific overloaded function
        ::resolve<void(coil::Context, std::string_view)>(createExplosion),
        ::resolve<void(coil::Context, std::string_view, float)>(createExplosion));

    common::printSectionHeader("Use coil::overloaded to bind several functions to the same command:");
    common::executeCommand(bindings, "func");
    common::executeCommand(bindings, "func 42");
    common::executeCommand(bindings, "func 42 3.14");
    common::executeCommand(bindings, "mixed_func");
    common::executeCommand(bindings, "mixed_func 42");
    common::executeCommand(bindings, "mixed_func foo 3.14");
    common::executeCommand(bindings, "mixed_func foo 3.14 true");

    common::printSectionHeader("An overloaded C++ function can also be bound by listing all overloads explicitly with ::resolve:");
    common::executeCommand(bindings, "explosions.create small");
    common::executeCommand(bindings, "explosions.create small 1.5");

    common::printSectionHeader("If there is no overload for given arguments, an error would be returned:");
    common::executeCommand(bindings, "func 1 2 3 4");
    common::executeCommand(bindings, "mixed_func 1 2 3 4");
}
