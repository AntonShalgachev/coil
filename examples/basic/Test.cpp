#include "Test.h"
#include "coil/Bindings.h"
#include "coil/AnyArgView.h"

#include "common/ExamplesCommon.h"

#include "magic_enum.hpp"

namespace
{
    enum class ScopedEnum
    {
        One,
        Two,
        Three,
    };

    enum UnscopedEnum
    {
        UnscopedEnum_One,
        UnscopedEnum_Two,
        UnscopedEnum_Three,
    };

    struct Object
    {
        float memberFunc(float val)
        {
            return val * 2.0f;
        }

        float memberFuncWithTarget(Object*, float val)
        {
            return val * 2.0f;
        }

        float memberFuncWithTargetContext(Object*, coil::Context&, float val)
        {
            return val * 2.0f;
        }

        float memberFuncWithContext(coil::Context&, float val)
        {
            return val * 2.0f;
        }

        static float staticFunc(float val)
        {
            return val * 2.0f;
        }

        static float staticFuncWithTarget(Object*, float val)
        {
            return val * 2.0f;
        }

        static float staticFuncWithTargetContext(Object*, coil::Context&, float val)
        {
            return val * 2.0f;
        }

        static float staticFuncWithContext(coil::Context&, float val)
        {
            return val * 2.0f;
        }

        float memberVariable = 2.0f;
    };

    struct SecondObject
    {

    };

    struct Functor
    {
        float operator()(float val)
        {
            return val * 2.0f;
        }
    };

    struct FunctorWithTarget
    {
        float operator()(Object*, float val)
        {
            return val * 2.0f;
        }
    };

    struct FunctorWithTargetContext
    {
        float operator()(Object*, coil::Context&, float val)
        {
            return val * 2.0f;
        }
    };

    struct FunctorWithContext
    {
        float operator()(coil::Context&, float val)
        {
            return val * 2.0f;
        }
    };

    float freeFunc(float val)
    {
        return val * 2.0f;
    }

    float freeFuncWithContext(coil::Context&, float val)
    {
        return val * 2.0f;
    }

    float freeFuncWithTarget(Object*, float val)
    {
        return val * 2.0f;
    }

    [[maybe_unused]] float freeFuncWithWrongTarget(SecondObject*, float val)
    {
        return val * 2.0f;
    }

    float freeFuncWithTargetContext(Object*, coil::Context&, float val)
    {
        return val * 2.0f;
    }

    void freeFuncWithoutArgs()
    {

    }

    void freeFuncWithoutArgsWithTarget(Object*)
    {

    }

    void freeFuncWithoutArgsWithTargetContext(Object*, coil::Context&)
    {

    }

    void freeFuncWithoutArgsWithContext(coil::Context&)
    {

    }

    std::size_t funcVariadicVector(float, std::string const&, std::vector<coil::AnyArgView> const& args)
    {
        return args.size();
    }

    std::size_t funcFloatVector(float, std::string const&, std::vector<float> const& args)
    {
        return args.size();
    }

    float funcOptional(float, std::string const&, std::optional<float> arg)
    {
        return arg.value_or(0.0f);
    }

    ScopedEnum funcScopedEnum(ScopedEnum val)
    {
        return val;
    }

    UnscopedEnum funcUnscopedEnum(UnscopedEnum val)
    {
        return val;
    }

    void funcNamedArgs(coil::NamedArgs)
    {

    }

    void funcTargetNamedArgs(Object*, coil::NamedArgs)
    {

    }
}

void compilation_test::run()
{
    [[maybe_unused]] coil::Bindings cmd;

    [[maybe_unused]] Object object;

    [[maybe_unused]] auto lambda = [](float val)
    {
        return val * 2.0f;
    };
    [[maybe_unused]] auto lambdaWithTarget = [](Object*, float val)
    {
        return val * 2.0f;
    };
    [[maybe_unused]] auto lambdaWithTargetContext = [](Object*, coil::Context&, float val)
    {
        return val * 2.0f;
    };
    [[maybe_unused]] auto lambdaWithContext = [](coil::Context&, float val)
    {
        return val * 2.0f;
    };

    [[maybe_unused]] Functor functor;
    [[maybe_unused]] FunctorWithTarget functorWithTarget;
    [[maybe_unused]] FunctorWithTargetContext functorWithTargetContext;
    [[maybe_unused]] FunctorWithContext functorWithContext;

    float variable = 2.0f;

    cmd.addObject("obj", &object);

    cmd[""] = &freeFunc;
    cmd[""] = &freeFuncWithContext;
    cmd[""] = &variable;
    cmd[""] = &freeFuncWithoutArgs;
    cmd[""] = &freeFuncWithoutArgsWithContext;
    cmd[""] = functor;
    cmd[""] = functorWithContext;
    cmd[""] = lambda;
    cmd[""] = lambdaWithContext;
    cmd[""] = &Object::staticFunc;
    cmd[""] = &Object::staticFuncWithContext;
    cmd.bind("", &Object::memberFunc, &object);
    cmd.bind("", &Object::memberFuncWithContext, &object);

    cmd[""] = [](coil::NamedArgs) {};
    cmd[""] = [](coil::NamedArgs&) {};
    cmd[""] = [](coil::NamedArgs const&) {};
    cmd[""] = [](coil::Context) {};
    cmd[""] = [](coil::Context&) {};
    cmd[""] = [](coil::Context const&) {};

    cmd.bind<Object>("", &Object::memberFunc);
    cmd.bind<Object>("", &Object::memberFuncWithContext);
    cmd.bind<Object>("", &Object::memberVariable);
    cmd.bind<Object>("", functorWithTarget);
    cmd.bind<Object>("", functorWithTargetContext);
    cmd.bind<Object>("", lambdaWithTarget);
    cmd.bind<Object>("", lambdaWithTargetContext);
    cmd.bind<Object>("", &freeFuncWithTarget);
    cmd.bind<Object>("", &freeFuncWithTargetContext);
    cmd.bind<Object>("", &freeFuncWithoutArgsWithTarget);
    cmd.bind<Object>("", &freeFuncWithoutArgsWithTargetContext);
    cmd.bind<Object>("", [](Object*) {});
    cmd.bind<Object>("", [](Object const*) {});
    cmd.bind<Object>("", &freeFuncWithoutArgs);
    cmd.bind<Object>("", &freeFunc);
    cmd.bind<Object>("", []() {});
    cmd.bind<Object>("", [](int) {});
    cmd.bind<Object>("", &Object::staticFuncWithTarget);
    cmd.bind<Object>("", &Object::staticFuncWithTargetContext);

    cmd.bind<Object>("", &funcTargetNamedArgs);

    cmd.bind<Object>("", &Object::memberFuncWithTarget, &object);
    cmd.bind<Object>("", &Object::memberFuncWithTargetContext, &object);

    cmd[""] = &funcVariadicVector;
    cmd[""] = &funcFloatVector;
    cmd[""] = &funcOptional;
    cmd[""] = &funcNamedArgs;

    cmd[""] = &funcScopedEnum;
    cmd[""] = &funcUnscopedEnum;

    // Compilation error
    //cmd.bind<Object>("", &variable);
    //cmd.bind<Object>("", [](int*) {});
    //cmd.bind<Object>("", &Object::memberFuncWithTarget);
    //cmd.bind<Object>("", &Object::memberFuncWithTargetContext);
    //cmd.bind<Object>("", &freeFuncWithWrongTarget);

    //cmd[""] = &Object::memberFunc;
    //cmd[""] = &freeFuncWithTarget;
    //cmd[""] = &Object::memberVariable;
}
