#include "Common.h"

int main()
{
    coil::Bindings cmd;

    // Different functor types with float argument
    cmd["foo.bar"] = &freeFunc;
    cmd["foo.bar"] = &freeFuncWithContext;
    cmd["foo.bar"] = functor;
    cmd["foo.bar"] = functorWithContext;
    cmd["foo.bar"] = functorConst;
    cmd["foo.bar"] = functorWithContextConst;
    cmd["foo.bar"] = lambda;
    cmd["foo.bar"] = lambdaWithContext;
    cmd["foo.bar"] = &Object::staticFunc;
    cmd["foo.bar"] = &Object::staticFuncWithContext;
    cmd["foo.bar"] = coil::bind(&Object::memberFunc, &object);
    cmd["foo.bar"] = coil::bind(&Object::memberFuncWithContext, &object);
    cmd["foo.bar"] = coil::bind(&Object::memberFuncConst, &object);
    cmd["foo.bar"] = coil::bind(&Object::memberFuncConst, &objectConst);

    // Functors without arguments
    cmd["foo.bar"] = &freeFuncWithoutArgs;
    cmd["foo.bar"] = &freeFuncWithoutArgsWithContext;
    cmd["foo.bar"] = []() {};
    cmd["foo.bar"] = [](coil::Context) {};

    // Functors with variadic arguments
    cmd["foo.bar"] = &funcVariadicVector;
    cmd["foo.bar"] = &funcFloatVector;
    cmd["foo.bar"] = &funcOptional;

    // Functors with enums
    cmd["foo.bar"] = &funcScopedEnum;
    cmd["foo.bar"] = &funcUnscopedEnum;

    // Functors with specific parameter and return types
    cmd["foo.bar"] = &funcWithType<int>;
    cmd["foo.bar"] = &funcWithType<unsigned>;
    cmd["foo.bar"] = &funcWithType<short>;
    cmd["foo.bar"] = &funcWithType<unsigned short>;
    cmd["foo.bar"] = &funcWithType<long>;
    cmd["foo.bar"] = &funcWithType<unsigned long>;
    cmd["foo.bar"] = &funcWithType<long long>;
    cmd["foo.bar"] = &funcWithType<unsigned long long>;
    cmd["foo.bar"] = &funcWithType<char>;
    cmd["foo.bar"] = &funcWithType<unsigned char>;
    cmd["foo.bar"] = &funcWithType<bool>;
    cmd["foo.bar"] = &funcWithType<std::uint8_t>;
    cmd["foo.bar"] = &funcWithType<std::uint16_t>;
    cmd["foo.bar"] = &funcWithType<std::uint32_t>;
    cmd["foo.bar"] = &funcWithType<std::uint64_t>;
    cmd["foo.bar"] = &funcWithType<std::int8_t>;
    cmd["foo.bar"] = &funcWithType<std::int16_t>;
    cmd["foo.bar"] = &funcWithType<std::int32_t>;
    cmd["foo.bar"] = &funcWithType<std::int64_t>;
    cmd["foo.bar"] = &funcWithType<ScopedEnum>;
    cmd["foo.bar"] = &funcWithType<UnscopedEnum>;
    cmd["foo.bar"] = &funcWithType<std::string>;
    cmd["foo.bar"] = &funcWithType<std::string_view>;
    cmd["foo.bar"] = &funcWithType<std::optional<float>>;
    cmd["foo.bar"] = &funcWithType<Object>;

    // Pointers
    cmd["foo.bar"] = []() -> int* { return nullptr; };
    cmd["foo.bar"] = []() -> int const* { return nullptr; };
    cmd["foo.bar"] = []() -> ScopedEnum* { return nullptr; };
    cmd["foo.bar"] = []() -> ScopedEnum const* { return nullptr; };
    cmd["foo.bar"] = []() -> Object* { return nullptr; };
    cmd["foo.bar"] = []() -> Object const* { return nullptr; };

    // Variables
    cmd["foo.bar"] = coil::variable(&variable);
    cmd["foo.bar"] = coil::variable(&object.memberVariable);

    // Overloads
    // TODO add

    // Properties
    cmd["foo.bar"] = coil::property(&getVariable, &setVariable);
    cmd["foo.bar"] = coil::property([]() { return 1.0f; }, [](float) {});
    cmd["foo.bar"] = coil::property(&getVariable, [](float) {});
    cmd["foo.bar"] = coil::property([]() { return 1.0f; }, &setVariable);
    cmd["foo.bar"] = coil::property(&Object::get, &Object::set, &object);
    cmd["foo.bar"] = coil::property([](Object*) { return 1.0f; }, [](Object*, float) {}, &object);
    cmd["foo.bar"] = coil::property(
        &Object::get, [](Object*, float) {}, &object);
    cmd["foo.bar"] = coil::property([](Object*) { return 1.0f; }, &Object::set, &object);

    cmd["foo.bar"] = coil::property(
        []() -> float& {
            static float v = 1.0f;
            return v;
        },
        [](float) {});
    cmd["foo.bar"] = coil::property(
        []() -> float& {
            static float v = 1.0f;
            return v;
        },
        [](float const&) {});
    cmd["foo.bar"] = coil::property(
        []() -> float {
            static float v = 1.0f;
            return v;
        },
        [](float const&) {});

    cmd["foo.bar"] = coil::property(
        &Object::getReference, [](Object*, float) {}, &object);
    cmd["foo.bar"] = coil::property(
        &Object::getReference, [](Object*, float const&) {}, &object);
    cmd["foo.bar"] = coil::property(
        &Object::get, [](Object*, float const&) {}, &object);
}
