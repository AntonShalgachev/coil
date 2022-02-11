#include "coil/Bindings.h"
#include "coil/AnyArgView.h"
#include "coil/Property.h"
#include "coil/utils/VariableWrapper.h"
#include "coil/utils/MemberFunctionFunctor.h"

namespace coil
{
    template<typename E>
    struct TypeSerializer<E, std::enable_if_t<std::is_enum_v<E>>>
    {
        static Expected<E, std::string> fromString(std::string_view str)
        {
            return E{};
        }

        static std::string_view toString(E value)
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

        float memberFuncConst(float val) const
        {
            return val * 2.0f;
        }

        float memberFuncWithContext(coil::Context, float val)
        {
            return val * 2.0f;
        }

        static float staticFunc(float val)
        {
            return val * 2.0f;
        }

        static float staticFuncWithContext(coil::Context, float val)
        {
            return val * 2.0f;
        }

        void set(float value)
        {
            memberVariable = value;
        }

        float get() const
        {
            return memberVariable;
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

    struct FunctorWithContext
    {
        float operator()(coil::Context, float val)
        {
            return val * 2.0f;
        }
    };

    [[maybe_unused]] float freeFunc(float val)
    {
        return val * 2.0f;
    }

    [[maybe_unused]] float freeFuncWithContext(coil::Context, float val)
    {
        return val * 2.0f;
    }

    [[maybe_unused]] void freeFuncWithoutArgs()
    {

    }

    [[maybe_unused]] void freeFuncWithoutArgsWithContext(coil::Context)
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

    template<typename T>
    [[maybe_unused]] T funcWithType(T v) { return v; }

    [[maybe_unused]] void setVariable(float value)
    {
    }

    [[maybe_unused]] float getVariable()
    {
        return 1.0f;
    }

    [[maybe_unused]] Object object;
    [[maybe_unused]] Object const objectConst;
    [[maybe_unused]] float variable = 2.0f;

    [[maybe_unused]] auto lambda = [](float val)
    {
        return val * 2.0f;
    };
    [[maybe_unused]] auto lambdaWithContext = [](coil::Context, float val)
    {
        return val * 2.0f;
    };

    [[maybe_unused]] Functor functor;
    [[maybe_unused]] FunctorWithContext functorWithContext;
}
