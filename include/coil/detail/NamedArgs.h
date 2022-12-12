#pragma once

#include "Optional.h"
#include "String.h"
#include "Value.h"
#include "CallContext.h"
#include "Functional.h"
#include "Utility.h"

namespace coil
{
    class NamedArgs
    {
    public:
        using NamedArgsIteratorT = NamedValue*;

        struct Error
        {
            enum class Type
            {
                MissingKey,
                TypeMismatch,
            };

            Error(Type type, String message) : type(type), message(coil::move(message)) {}

            Type type = Type::MissingKey;
            String message;
        };

        NamedArgs(detail::CallContext& context);

        Expected<ReferenceWrapper<Value const>, Error> get(StringView key) const;

        template<typename T>
        Expected<T, Error> get(StringView key) const;

        enum class ArgType
        {
            Optional,
            Required,
        };

        Value const* getOrReport(StringView key, ArgType argType = ArgType::Optional) const;

        template<typename T>
        Optional<T> getOrReport(StringView key, ArgType argType = ArgType::Optional, Optional<T> defaultValue = {}) const;

        size_t size() const;

        NamedArgsIteratorT begin() const;

        NamedArgsIteratorT end() const;

        NamedArgsIteratorT find(StringView key) const;

    private:
        detail::CallContext& m_context;
    };

    template<typename T>
    Expected<T, NamedArgs::Error> NamedArgs::get(StringView key) const
    {
        auto typelessValue = get(key);
        if (!typelessValue)
            return makeUnexpected(coil::move(typelessValue).error());

        Expected<T, String> value = static_cast<Value const&>(typelessValue.value()).get<T>();
        if (!value)
            return makeUnexpected(Error(Error::Type::TypeMismatch, coil::move(value).error()));

        return coil::move(value).value();
    }

    template<typename T>
    Optional<T> NamedArgs::getOrReport(StringView key, ArgType argType, Optional<T> defaultValue) const
    {
        if (Expected<T, Error> value = get<T>(key))
            return value.value();
        else if (argType == ArgType::Optional && value.error().type == Error::Type::MissingKey)
            return defaultValue;
        else
            m_context.reportError(coil::move(value).error().message);

        return {};
    }
}
