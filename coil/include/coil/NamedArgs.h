#pragma once

#include "detail/CallContext.h"
#include "AnyArgView.h"

namespace coil
{
    class NamedAnyArgView
    {
    public:
        NamedAnyArgView(std::string_view key, ArgValue value) : m_key(key), m_value(value) {}

        std::string_view key() const { return m_key; }
        AnyArgView value() const { return m_value; }

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

        NamedArgsIterator(UnderlyingIteratorT iterator) : m_iterator(iterator) {}

        NamedAnyArgView operator*()
        {
            return NamedAnyArgView(m_iterator->first, m_iterator->second);
        }

        struct NamedArgContainer
        {
            NamedAnyArgView arg;
            NamedAnyArgView* operator->() { return std::addressof(arg); }
        };

        NamedArgContainer operator->() { return NamedArgContainer{ **this }; }

        bool operator==(NamedArgsIterator const& rhs)
        {
            return m_iterator == rhs.m_iterator;
        }

        bool operator!=(NamedArgsIterator const& rhs)
        {
            return !(*this == rhs);
        }

        NamedArgsIterator& operator++()
        {
            m_iterator++;
            return *this;
        }

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

            operator std::string() const& { return message; }
            operator std::string()& { return message; }
            operator std::string()&& { return std::move(message); }

            Type type = Type::MissingKey;
            std::string message;
        };

        NamedArgs(detail::CallContext& context) : m_context(context) {}

        Expected<AnyArgView, Error> get(std::string_view key) const
        {
            auto it = find(key);
            if (it == end())
                return makeUnexpected(Error(Error::Type::MissingKey, utils::formatString("Missing named argument '%.*s'", key.size(), key.data())));

            return it->value();
        }

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

        std::optional<AnyArgView> getOrReport(std::string_view key, ArgType argType = ArgType::Optional) const
        {
            if (auto anyArg = get(key))
                return *anyArg;
            else if (argType == ArgType::Required)
                m_context.reportError(std::move(anyArg).error());

            return {};
        }

        template<typename T>
        std::optional<T> getOrReport(std::string_view key, ArgType argType = ArgType::Optional, std::optional<T> defaultValue = {}) const
        {
            if (auto value = get<T>(key))
                return *value;
            else if (argType == ArgType::Optional && value.error().type == coil::NamedArgs::Error::Type::MissingKey)
                return defaultValue;
            else
                m_context.reportError(std::move(value).error());

            return {};
        }

        std::size_t size() const
        {
            return m_context.input.namedArguments.size();
        }

        NamedArgsIterator begin() const
        {
            return m_context.input.namedArguments.cbegin();
        }

        NamedArgsIterator end() const
        {
            return m_context.input.namedArguments.cend();
        }

        NamedArgsIterator find(std::string_view key) const
        {
            return std::find_if(begin(), end(), [key](NamedAnyArgView const& arg)
            {
                return arg.key() == key;
            });
        }

    private:
        detail::CallContext& m_context;
    };
}
