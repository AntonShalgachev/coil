#pragma once

#include "Value.h"
#include "String.h"
#include "detail/CallContext.h"
#include "detail/Functional.h"
#include "detail/Utility.h"

namespace coil
{
    class NamedValue
    {
    public:
        NamedValue(StringView key, Value const& value);

        StringView key() const;
        Value const& value() const;

    private:
        StringView m_key;
        Value const& m_value;
    };

    class NamedArgsIterator
    {
    public:
        using UnderlyingIteratorT = decltype(std::declval<ExecutionInput>().namedArguments)::const_iterator;

        using iterator_category = std::forward_iterator_tag;
        using value_type = NamedValue;
        using difference_type = UnderlyingIteratorT::difference_type;
        using pointer = NamedValue*;
        using reference = NamedValue&;

        NamedArgsIterator(UnderlyingIteratorT iterator);

        NamedValue operator*();

        struct NamedArgContainer
        {
            NamedValue arg;
            NamedValue* operator->()
            {
                return std::addressof(arg);
            }
        };

        NamedArgContainer operator->();

        bool operator==(NamedArgsIterator const& rhs);

        bool operator!=(NamedArgsIterator const& rhs);

        NamedArgsIterator& operator++();

    private:
        UnderlyingIteratorT m_iterator;
    };

    class NamedArgs
    {
    public:
        struct Error
        {
            enum class Type
            {
                MissingKey,
                TypeMismatch,
            };

            Error(Type type, String message) : type(type), message(Move(message)) {}

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
        std::optional<T> getOrReport(StringView key, ArgType argType = ArgType::Optional, std::optional<T> defaultValue = {}) const;

        std::size_t size() const;

        NamedArgsIterator begin() const;

        NamedArgsIterator end() const;

        NamedArgsIterator find(StringView key) const;

    private:
        detail::CallContext& m_context;
    };

    template<typename T>
    Expected<T, NamedArgs::Error> NamedArgs::get(StringView key) const
    {
        auto typelessValue = get(key);
        if (!typelessValue)
            return makeUnexpected(Move(typelessValue).error());

        Expected<T, String> value = static_cast<Value const&>(*typelessValue).get<T>();
        if (!value)
            return makeUnexpected(Error(Error::Type::TypeMismatch, Move(value).error()));

        return *Move(value);
    }

    template<typename T>
    std::optional<T> NamedArgs::getOrReport(StringView key, ArgType argType, std::optional<T> defaultValue) const
    {
        if (Expected<T, Error> value = get<T>(key))
            return *value;
        else if (argType == ArgType::Optional && value.error().type == Error::Type::MissingKey)
            return defaultValue;
        else
            m_context.reportError(Move(value).error().message);

        return {};
    }
}
