#include "coil/Bindings.h"
#include "coil/AnyArgView.h"

namespace coil
{
    template<typename EnumT>
    struct TypeSerializer<EnumT, std::enable_if_t<std::is_enum_v<EnumT>>>
    {
        template<typename OnError>
        static EnumT fromString(std::string_view str, [[maybe_unused]] OnError&& onError)
        {
            return EnumT{};
        }

        static std::string_view toString(EnumT const& value)
        {
            return "";
        }
    };
}

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

    [[maybe_unused]] float freeFunc(float val)
    {
        return val * 2.0f;
    }

    [[maybe_unused]] float freeFuncWithContext(coil::Context&, float val)
    {
        return val * 2.0f;
    }

    [[maybe_unused]] float freeFuncWithTarget(Object*, float val)
    {
        return val * 2.0f;
    }

    [[maybe_unused]] float freeFuncWithConstTarget(Object const*, float val)
    {
        return val * 2.0f;
    }

    [[maybe_unused]] float freeFuncWithWrongTarget(SecondObject*, float val)
    {
        return val * 2.0f;
    }

    [[maybe_unused]] float freeFuncWithTargetContext(Object*, coil::Context&, float val)
    {
        return val * 2.0f;
    }

    [[maybe_unused]] void freeFuncWithoutArgs()
    {

    }

    [[maybe_unused]] void freeFuncWithoutArgsWithTarget(Object*)
    {

    }

    [[maybe_unused]] void freeFuncWithoutArgsWithTargetContext(Object*, coil::Context&)
    {

    }

    [[maybe_unused]] void freeFuncWithoutArgsWithContext(coil::Context&)
    {

    }

    [[maybe_unused]] std::size_t funcVariadicVector(float, std::string const&, std::vector<coil::AnyArgView> const& args)
    {
        return args.size();
    }

    [[maybe_unused]] std::size_t funcFloatVector(float, std::string const&, std::vector<float> const& args)
    {
        return args.size();
    }

    [[maybe_unused]] float funcOptional(float, std::string const&, std::optional<float> arg)
    {
        return arg.value_or(0.0f);
    }

    [[maybe_unused]] ScopedEnum funcScopedEnum(ScopedEnum val)
    {
        return val;
    }

    [[maybe_unused]] UnscopedEnum funcUnscopedEnum(UnscopedEnum val)
    {
        return val;
    }

    [[maybe_unused]] void funcNamedArgs(coil::NamedArgs)
    {

    }

    [[maybe_unused]] void funcTargetNamedArgs(Object*, coil::NamedArgs)
    {

    }

    template<typename T>
    [[maybe_unused]] T funcWithType(T v) { return v; }
}

int main()
{
    [[maybe_unused]] Object object;
    [[maybe_unused]] float variable = 2.0f;

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
    
    [[maybe_unused]] coil::Bindings cmd;

    cmd[""] = &Object::memberFunc;
}
