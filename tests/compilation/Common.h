#include "coil/Coil.h"

#include <stddef.h>
#include <stdint.h>

namespace
{
    template<class T>
    inline constexpr bool IsEnumV = __is_enum(T);

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

        float& getReference()
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

    [[maybe_unused]] void freeFuncWithoutArgs() {}

    [[maybe_unused]] void freeFuncWithoutArgsWithContext(coil::Context) {}

    [[maybe_unused]] ScopedEnum funcScopedEnum(ScopedEnum val)
    {
        return val;
    }

    [[maybe_unused]] UnscopedEnum funcUnscopedEnum(UnscopedEnum val)
    {
        return val;
    }

    template<typename T>
    [[maybe_unused]] T funcWithType(T v)
    {
        return v;
    }

    [[maybe_unused]] void setVariable(float value) {}

    [[maybe_unused]] float getVariable()
    {
        return 1.0f;
    }

    [[maybe_unused]] Object object;
    [[maybe_unused]] Object const objectConst;
    [[maybe_unused]] float variable = 2.0f;

    [[maybe_unused]] auto lambda = [](float val) { return val * 2.0f; };
    [[maybe_unused]] auto lambdaWithContext = [](coil::Context, float val) { return val * 2.0f; };

    [[maybe_unused]] Functor functor;
    [[maybe_unused]] FunctorWithContext functorWithContext;

    [[maybe_unused]] Functor const functorConst;
    [[maybe_unused]] FunctorWithContext const functorWithContextConst;
}

namespace coil
{
    template<typename E>
    struct TypeSerializer<E, coil::EnableIfT<IsEnumV<E>>>
    {
        static Expected<E, coil::String> fromString(Value const& input)
        {
            return E{};
        }

        static coil::String toString(E const& value)
        {
            return {};
        }
    };

    template<>
    struct TypeSerializer<Object>
    {
        static Expected<Object, coil::String> fromString(Value const& input)
        {
            return Object{};
        }

        static coil::String toString(Object const& value)
        {
            return {};
        }
    };

    template<typename T, typename>
    struct TypeName
    {
        static StringView name()
        {
            return "";
        }
    };
}
