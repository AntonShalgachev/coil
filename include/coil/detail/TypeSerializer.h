#pragma once

#include "Expected.h"
#include "String.h"
#include "TypeName.h"
#include "Utility.h"
#include "Utils.h"
#include "Value.h"

namespace coil
{
    namespace errors
    {
        Unexpected<String> createGenericError(StringView typeName, Value const& input, StringView details = {});

        template<typename T>
        Unexpected<String> createGenericError(Value const& input, StringView details = {})
        {
            return createGenericError(TypeName<T>::name(), input, details);
        }

        Unexpected<String> createMismatchedSubvaluesError(StringView typeName, Value const& input, size_t expectedSubvalues);

        template<typename T>
        Unexpected<String> createMismatchedSubvaluesError(Value const& input, size_t expectedSubvalues)
        {
            return createMismatchedSubvaluesError(TypeName<T>::name(), input, expectedSubvalues);
        }
    }

    //////////////////////////////////////

    template<typename T, typename = void>
    struct TypeSerializer;

    //////////////////////////////////////

#define DECLARE_ARITHMETIC_TYPE_SERIALIZER(Type)                      \
    template<>                                                        \
    struct TypeSerializer<Type>                                       \
    {                                                                 \
        static Expected<Type, String> fromString(Value const& input); \
        static String toString(Type const& value);                    \
    }

    DECLARE_ARITHMETIC_TYPE_SERIALIZER(char);
    DECLARE_ARITHMETIC_TYPE_SERIALIZER(signed char);
    DECLARE_ARITHMETIC_TYPE_SERIALIZER(unsigned char);
    DECLARE_ARITHMETIC_TYPE_SERIALIZER(short);
    DECLARE_ARITHMETIC_TYPE_SERIALIZER(unsigned short);
    DECLARE_ARITHMETIC_TYPE_SERIALIZER(int);
    DECLARE_ARITHMETIC_TYPE_SERIALIZER(unsigned int);
    DECLARE_ARITHMETIC_TYPE_SERIALIZER(long);
    DECLARE_ARITHMETIC_TYPE_SERIALIZER(unsigned long);
    DECLARE_ARITHMETIC_TYPE_SERIALIZER(long long);
    DECLARE_ARITHMETIC_TYPE_SERIALIZER(unsigned long long);
    DECLARE_ARITHMETIC_TYPE_SERIALIZER(float);
    DECLARE_ARITHMETIC_TYPE_SERIALIZER(double);
    DECLARE_ARITHMETIC_TYPE_SERIALIZER(long double);
#undef DECLARE_ARITHMETIC_TYPE_SERIALIZER

    //////////////////////////////////////

    template<>
    struct TypeSerializer<bool>
    {
        static Expected<bool, String> fromString(Value const& input);
        static String toString(bool const& value);
    };

    //////////////////////////////////////

    template<>
    struct TypeSerializer<char const*>
    {
        static String toString(char const* const& value);
    };

    //////////////////////////////////////

    template<>
    struct TypeSerializer<String>
    {
        static Expected<String, String> fromString(Value const& input);
        static String toString(String const& value);
    };

    //////////////////////////////////////

    template<>
    struct TypeSerializer<StringView>
    {
        static Expected<StringView, String> fromString(Value const& input);
        static String toString(StringView const& value);
    };

    //////////////////////////////////////

    // TODO remove this specialization?
    template<typename T>
    struct TypeSerializer<T*>
    {
        static String toString(T* const& value);
    };

    template<typename T>
    coil::String coil::TypeSerializer<T*>::toString(T* const& value)
    {
        if (!value)
            return "null";

        return TypeSerializer<DecayT<T>>::toString(*value);
    }
}
