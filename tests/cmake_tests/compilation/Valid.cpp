#include "Common.h"

int main()
{
    [[maybe_unused]] coil::Bindings cmd;

    cmd.addObject("obj", &object);

    cmd[""] = &freeFunc;
    cmd[""] = &freeFuncWithContext;
    cmd[""] = coil::variable(&variable);
    cmd[""] = &freeFuncWithoutArgs;
    cmd[""] = &freeFuncWithoutArgsWithContext;
    cmd[""] = functor;
    cmd[""] = functorWithContext;
    cmd[""] = lambda;
    cmd[""] = lambdaWithContext;
    cmd[""] = &Object::staticFunc;
    cmd[""] = &Object::staticFuncWithContext;
    cmd.bind("", coil::bind(&Object::memberFunc, &object));
    cmd.bind("", coil::bind(&Object::memberFuncWithContext, &object));

    cmd[""] = [](coil::Context) {};
    cmd[""] = [](coil::Context&) {};
    cmd[""] = [](coil::Context const&) {};

    cmd.bind<Object>("", &Object::memberFunc);
    cmd.bind<Object>("", &Object::memberFuncWithContext);
    cmd.bind<Object>("", coil::variable(&Object::memberVariable));
    cmd.bind<Object>("", functorWithTarget);
    cmd.bind<Object>("", functorWithTargetContext);
    cmd.bind<Object>("", lambdaWithTarget);
    cmd.bind<Object>("", lambdaWithTargetContext);
    cmd.bind<Object>("", &freeFuncWithTarget);
    cmd.bind<Object>("", &freeFuncWithConstTarget);
    cmd.bind<Object>("", &freeFuncWithTargetContext);
    cmd.bind<Object>("", &freeFuncWithoutArgsWithTarget);
    cmd.bind<Object>("", &freeFuncWithoutArgsWithTargetContext);
    cmd.bind<Object>("", [](Object*) {});
    cmd.bind<Object>("", [](Object const*) {});
    cmd.bind<Object>("", &freeFuncWithoutArgs);
    cmd.bind<Object>("", &freeFunc);
    cmd.bind<Object>("", coil::variable(&variable));
    cmd.bind<Object>("", []() {});
    cmd.bind<Object>("", [](int) {});
    cmd.bind<Object>("", &Object::staticFuncWithTarget);
    cmd.bind<Object>("", &Object::staticFuncWithTargetContext);

    cmd.bind<Object>("", coil::bind(&Object::memberFuncWithTarget, &object));
    cmd.bind<Object>("", coil::bind(&Object::memberFuncWithTargetContext, &object));

    cmd[""] = &funcVariadicVector;
    cmd[""] = &funcFloatVector;
    cmd[""] = &funcOptional;

    cmd[""] = &funcScopedEnum;
    cmd[""] = &funcUnscopedEnum;

    cmd[""] = &funcWithType<int>;
    cmd[""] = &funcWithType<unsigned>;
    cmd[""] = &funcWithType<short>;
    cmd[""] = &funcWithType<unsigned short>;
    cmd[""] = &funcWithType<long>;
    cmd[""] = &funcWithType<unsigned long>;
    cmd[""] = &funcWithType<long long>;
    cmd[""] = &funcWithType<unsigned long long>;
    cmd[""] = &funcWithType<char>;
    cmd[""] = &funcWithType<unsigned char>;
    cmd[""] = &funcWithType<bool>;
    cmd[""] = &funcWithType<std::uint8_t>;
    cmd[""] = &funcWithType<std::uint16_t>;
    cmd[""] = &funcWithType<std::uint32_t>;
    cmd[""] = &funcWithType<std::uint64_t>;
    cmd[""] = &funcWithType<std::int8_t>;
    cmd[""] = &funcWithType<std::int16_t>;
    cmd[""] = &funcWithType<std::int32_t>;
    cmd[""] = &funcWithType<std::int64_t>;
    cmd[""] = &funcWithType<ScopedEnum>;
    cmd[""] = &funcWithType<UnscopedEnum>;
    cmd[""] = &funcWithType<std::string>;
    cmd[""] = &funcWithType<std::string_view>;
    cmd[""] = &funcWithType<std::optional<float>>;

    cmd.bind<Object>("", coil::createProperty(&Object::get, &Object::set));
    cmd.bind<Object>("", coil::createProperty([](Object*) { return 1.0f; }, [](Object*, float) {}));
    cmd.bind<Object>("", coil::createProperty(&Object::get, [](Object*, float) {}));
    cmd.bind<Object>("", coil::createProperty([](Object*) { return 1.0f; }, & Object::set));

    cmd.bind<Object>("", coil::createProperty(&getVariable, &setVariable));
    cmd.bind<Object>("", coil::createProperty([]() { return 1.0f; }, [](float) {}));
    cmd.bind<Object>("", coil::createProperty(&getVariable, [](float) {}));
    cmd.bind<Object>("", coil::createProperty([]() { return 1.0f; }, & setVariable));

    cmd[""] = coil::createProperty(&getVariable, &setVariable);
    cmd[""] = coil::createProperty([]() { return 1.0f; }, [](float) {});
    cmd[""] = coil::createProperty(&getVariable, [](float) {});
    cmd[""] = coil::createProperty([]() { return 1.0f; }, & setVariable);
}
