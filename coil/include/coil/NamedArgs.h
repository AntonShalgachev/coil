#pragma once

#include "detail/CallContext.h"
#include "AnyArgView.h"

namespace coil
{
    class NamedAnyArgView
    {
    public:
        NamedAnyArgView(std::string_view key, ArgValue value);

        std::string_view key() const;
        AnyArgView value() const;

    private:
        std::string_view m_key;
        AnyArgView m_value;
    };

    class NamedArgsIterator
    {
    public:
        using UnderlyingIteratorT = decltype(std::declval<ExecutionInput>().namedArguments)::const_iterator;

        using iterator_category = std::forward_iterator_tag;
        using value_type = NamedAnyArgView;
        using difference_type = UnderlyingIteratorT::difference_type;
        using pointer = NamedAnyArgView*;
        using reference = NamedAnyArgView&;

        NamedArgsIterator(UnderlyingIteratorT iterator);

        NamedAnyArgView operator*();

        struct NamedArgContainer
        {
            NamedAnyArgView arg;
            NamedAnyArgView* operator->() { return std::addressof(arg); }
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

            Error(Type type, std::string message) : type(type), message(std::move(message)) {}

            Type type = Type::MissingKey;
            std::string message;
        };

        NamedArgs(detail::CallContext& context);

        Expected<AnyArgView, Error> get(std::string_view key) const;

        template<typename T>
        Expected<T, Error> get(std::string_view key) const
        {
            Expected<AnyArgView, Error> anyArg = get(key);
            if (!anyArg)
                return makeUnexpected(std::move(anyArg).error());

            Expected<T, std::string> value = anyArg->get<T>();
            if (!value)
                return makeUnexpected(Error(Error::Type::TypeMismatch, std::move(value).error()));

            return *std::move(value);
        }

        enum class ArgType
        {
            Optional,
            Required,
        };

        std::optional<AnyArgView> getOrReport(std::string_view key, ArgType argType = ArgType::Optional) const;

        template<typename T>
        std::optional<T> getOrReport(std::string_view key, ArgType argType = ArgType::Optional, std::optional<T> defaultValue = {}) const
        {
            if (Expected<T, Error> value = get<T>(key))
                return *value;
            else if (argType == ArgType::Optional && value.error().type == coil::NamedArgs::Error::Type::MissingKey)
                return defaultValue;
            else
                m_context.reportError(std::move(value).error().message);

            return {};
        }

        std::size_t size() const;

        NamedArgsIterator begin() const;

        NamedArgsIterator end() const;

        NamedArgsIterator find(std::string_view key) const;

    private:
        detail::CallContext& m_context;
    };
}

#define EXTERN_EXPLICIT_NAMED_ARGS_TEMPLATE(T) \
    extern template class std::optional<T>; \
    extern template class coil::ExpectedBase<T, coil::NamedArgs::Error>; \
    extern template class coil::Expected<T, coil::NamedArgs::Error>; \
    extern template coil::Expected<T, coil::NamedArgs::Error> coil::NamedArgs::get<T>(std::string_view key) const; \
    extern template std::optional<T> coil::NamedArgs::getOrReport(std::string_view key, coil::NamedArgs::ArgType argType, std::optional<T> defaultValue) const

#define EXPLICIT_NAMED_ARGS_TEMPLATE(T) \
    template class std::optional<T>; \
    template class coil::ExpectedBase<T, coil::NamedArgs::Error>; \
    template class coil::Expected<T, coil::NamedArgs::Error>; \
    template coil::Expected<T, coil::NamedArgs::Error> coil::NamedArgs::get<T>(std::string_view key) const; \
    template std::optional<T> coil::NamedArgs::getOrReport(std::string_view key, coil::NamedArgs::ArgType argType, std::optional<T> defaultValue) const

extern template class std::optional<coil::AnyArgView>;
extern template class coil::Expected<coil::AnyArgView, coil::NamedArgs::Error>;
EXTERN_EXPLICIT_NAMED_ARGS_TEMPLATE(int);
EXTERN_EXPLICIT_NAMED_ARGS_TEMPLATE(short);
EXTERN_EXPLICIT_NAMED_ARGS_TEMPLATE(bool);
EXTERN_EXPLICIT_NAMED_ARGS_TEMPLATE(unsigned);
EXTERN_EXPLICIT_NAMED_ARGS_TEMPLATE(float);
EXTERN_EXPLICIT_NAMED_ARGS_TEMPLATE(double);
