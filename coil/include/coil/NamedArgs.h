#pragma once

#include "detail/CallContext.h"
#include "VariadicArg.h"

namespace coil
{
    class NamedArg
    {
    public:
        NamedArg(std::string_view key, std::string_view value) : m_key(key), m_value(value) {}

        std::string_view key() const { return m_key; }
        std::string_view value() const { return m_value; }

        VariadicArg asVariadic() const { return VariadicArg{m_value}; }

    private:
        std::string_view m_key;
        std::string_view m_value;
    };

    class NamedArgsIterator
    {
    public:
        using UnderlyingIteratorT = decltype(std::declval<ExecutionInput>().namedArguments)::const_iterator;

        NamedArgsIterator(UnderlyingIteratorT iterator) : m_iterator(iterator) {}

        NamedArg operator*()
        {
            return NamedArg(m_iterator->first, m_iterator->second);
        }

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
        using IteratorT = decltype(std::declval<ExecutionInput>().namedArguments)::const_iterator;

        NamedArgs(ExecutionInput const& input) : m_input(input) {}

        template<typename T>
        std::optional<T> tryGet(std::string_view key)
        {
            auto it = find(key);
            if (it == end())
                return {};

            VariadicArg arg{ it->second };
            return arg.tryGet<T>();
        }

        template<typename T>
        T get(std::string_view key)
        {
            auto it = find(key);
            if (it == end())
                throw std::invalid_argument(utils::formatString("Named argument '%.*s' not found", key.length(), key.data()));

            VariadicArg arg{ it->second };
            return arg.as<T>();
        }

        bool has(std::string_view key)
        {
            return find(key) != end();
        }

        std::size_t size()
        {
            return m_input.namedArguments.size();
        }

        NamedArgsIterator begin() const
        {
            return m_input.namedArguments.cbegin();
        }

        NamedArgsIterator end() const
        {
            return m_input.namedArguments.cend();
        }

    private:
        NamedArgsIterator find(std::string_view key)
        {
            return std::find_if(begin(), end(), [key](NamedArg const& arg)
            {
                return arg.key() == key;
            });
        }

        ExecutionInput const& m_input;
    };
}
