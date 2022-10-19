#pragma once

#include "Expected.h"
#include "TypeName.h"
#include "Utils.h"
#include "Value.h"
#include "String.h"
#include "detail/Utility.h"

#include "detail/StringConv.h"

namespace coil
{
    namespace errors
    {
        template<typename T>
        Unexpected<String> createGenericError(Value const& input, StringView details = {})
        {
            StringView typeName = TypeName<T>::name();

            String representation = input.str();

            if (details.empty())
                return makeUnexpected(sprintf("Unable to convert '%s' to type '%.*s'", representation.cStr(), typeName.length(), typeName.data()));

            return makeUnexpected(sprintf("Unable to convert '%s' to type '%.*s': %.*s", representation.cStr(), typeName.length(), typeName.data(), details.length(), details.data()));
        }

        template<typename T>
        Unexpected<String> createMismatchedSubvaluesError(Value const& input, size_t expectedSubvalues)
        {
            return createGenericError<T>(input, sprintf("Expected %d subvalues, got %d", expectedSubvalues, input.subvalues.size()));
        }
    }

    //////////////////////////////////////

    template<typename T, typename = void>
    struct TypeSerializer;

    //////////////////////////////////////

    template<typename T>
    struct TypeSerializer<T, EnableIfT<IsArithmetic<T>>>
    {
        static Expected<T, String> fromString(Value const& input);

        static String toString(T const& value);
    };

    template<typename T>
    coil::Expected<T, String> TypeSerializer<T, EnableIfT<IsArithmetic<T>>>::fromString(Value const& input)
    {
        if (input.subvalues.size() != 1)
            return errors::createMismatchedSubvaluesError<T>(input, 1);

        T value{};
        if (!coil::fromString(input.subvalues[0], value))
            return errors::createGenericError<T>(input);
        return value;
    }

    template<typename T>
    coil::String TypeSerializer<T, EnableIfT<IsArithmetic<T>>>::toString(T const& value)
    {
        return coil::toString(value);
    }

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
