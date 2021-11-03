#include "Test.h"
#include "coil/CommandListener.h"
#include "coil/VariadicArg.h"

namespace
{
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

    std::size_t funcVariadicVector(float, std::string const&, std::vector<coil::VariadicArg> const& args)
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
}

void coil::tests::test()
{
    [[maybe_unused]] coil::CommandListener cmd;

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

    cmd.bind("", &freeFunc);
    cmd.bind("", &freeFuncWithContext);
    cmd.bind("", &variable);
    cmd.bind("", &freeFuncWithoutArgs);
    cmd.bind("", &freeFuncWithoutArgsWithContext);
    cmd.bind("", functor);
    cmd.bind("", functorWithContext);
    cmd.bind("", lambda);
    cmd.bind("", lambdaWithContext);
    cmd.bind("", &Object::staticFunc);
    cmd.bind("", &Object::staticFuncWithContext);
    cmd.bind("", &Object::memberFunc, &object);
    cmd.bind("", &Object::memberFuncWithContext, &object);

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

    cmd.bind<Object>("", &Object::memberFuncWithTarget, &object);
    cmd.bind<Object>("", &Object::memberFuncWithTargetContext, &object);

    cmd.bind("", &funcVariadicVector);
    cmd.bind("", &funcFloatVector);
    cmd.bind("", &funcOptional);

    // Compilation error
    //cmd.bind<Object>("", &variable);
    //cmd.bind<Object>("", [](int*) {});
    //cmd.bind<Object>("", &Object::memberFuncWithTarget);
    //cmd.bind<Object>("", &Object::memberFuncWithTargetContext);

    //cmd.bind("", &Object::memberFunc);
    //cmd.bind("", &freeFuncWithTarget);
    //cmd.bind("", &Object::memberVariable);
}
