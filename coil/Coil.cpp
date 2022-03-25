#include "coil/Bindings.h"
#include "coil/Bind.h"
#include "coil/Variable.h"
#include "coil/NamedArgs.h"

namespace coil
{
    BindingProxy<Bindings> Bindings::operator[](std::string_view name)
    {
        return BindingProxy<Bindings>{ *this, { name } };
    }

    void Bindings::add(std::string_view name, std::vector<detail::AnyFunctor> anyFunctors)
    {
        m_commands.insert_or_assign(name, std::move(anyFunctors));
    }

    void Bindings::remove(std::string_view name)
    {
        m_commands.erase(name);
    }

    void Bindings::clear()
    {
        m_commands.clear();
    }

    ExecutionResult Bindings::execute(ExecutionInput const& input)
    {
        detail::CallContext context{ input };
        execute(context);
        return std::move(context).result;
    }

    ExecutionResult Bindings::execute(std::string_view command)
    {
        return execute(command, m_defaultLexer);
    }

    void Bindings::execute(detail::CallContext& context)
    {
        if (context.input.name.empty())
        {
            context.result.errors.push_back("No function name is specified");
            return;
        }

        auto it = m_commands.find(context.input.name);
        if (it == m_commands.end())
        {
            context.result.errors.push_back(formatString("No function '%.*s' is registered", context.input.name.size(), context.input.name.data()));
            return;
        }

        auto& functors = it->second;

        for (auto& functor : functors)
            if (functor.arity() == context.input.arguments.size())
                return functor.invokeTrampoline(context);

        std::stringstream argsCount;

        for (std::size_t i = 0; i < functors.size(); i++)
        {
            if (i > 0 && i != functors.size() - 1)
                argsCount << ", ";
            if (i > 0 && i == functors.size() - 1)
                argsCount << " or ";

            argsCount << functors[i].arity();
        }

        std::string const expectedStr = argsCount.str();
        std::size_t const actualArgsCount = context.input.arguments.size();
        auto error = formatString("Wrong number of arguments to '%.*s': expected %s, got %d", context.input.name.size(), context.input.name.data(), expectedStr.c_str(), actualArgsCount);
        context.reportError(std::move(error));
    }

    //////////////////////////////////////

    Context::Context(detail::CallContext& callContext) : m_callContext(callContext), m_namedArgs(callContext) {}

    std::ostream& Context::out() { return m_callContext.out(); }

    void Context::reportError(std::string error)
    {
        m_callContext.reportError(std::move(error));
    }

    bool Context::hasErrors() const
    {
        return m_callContext.hasErrors();
    }

    NamedArgs const& Context::namedArgs() { return m_namedArgs; }

    //////////////////////////////////////

    detail::CallContext::CallContext(ExecutionInput const& input) : input(input) {}

    std::ostream& detail::CallContext::out() { return result.output; }

    void detail::CallContext::reportError(std::string error)
    {
        result.errors.push_back(std::move(error));
    }

    bool detail::CallContext::hasErrors() const
    {
        return !result.errors.empty();
    }

    //////////////////////////////////////

    NamedAnyArgView::NamedAnyArgView(std::string_view key, ArgValue value) : m_key(key), m_value(value) {}

    std::string_view NamedAnyArgView::key() const { return m_key; }
    AnyArgView NamedAnyArgView::value() const { return m_value; }

    //////////////////////////////////////

    NamedArgsIterator::NamedArgsIterator(UnderlyingIteratorT iterator) : m_iterator(iterator) {}

    NamedAnyArgView NamedArgsIterator::operator*()
    {
        return NamedAnyArgView(m_iterator->first, m_iterator->second);
    }

    NamedArgsIterator::NamedArgContainer NamedArgsIterator::operator->() { return NamedArgContainer{ **this }; }

    bool NamedArgsIterator::operator==(NamedArgsIterator const& rhs)
    {
        return m_iterator == rhs.m_iterator;
    }

    bool NamedArgsIterator::operator!=(NamedArgsIterator const& rhs)
    {
        return !(*this == rhs);
    }

    NamedArgsIterator& NamedArgsIterator::operator++()
    {
        m_iterator++;
        return *this;
    }

    //////////////////////////////////////

    NamedArgs::NamedArgs(detail::CallContext& context) : m_context(context) {}

    Expected<AnyArgView, NamedArgs::Error> NamedArgs::get(std::string_view key) const
    {
        auto it = find(key);
        if (it == end())
            return makeUnexpected(Error(Error::Type::MissingKey, formatString("Missing named argument '%.*s'", key.size(), key.data())));

        return it->value();
    }

    std::optional<AnyArgView> NamedArgs::getOrReport(std::string_view key, ArgType argType) const
    {
        if (Expected<AnyArgView, Error> anyArg = get(key))
            return *anyArg;
        else if (argType == ArgType::Required)
            m_context.reportError(std::move(anyArg).error().message);

        return {};
    }

    std::size_t NamedArgs::size() const
    {
        return m_context.input.namedArguments.size();
    }

    NamedArgsIterator NamedArgs::begin() const
    {
        return m_context.input.namedArguments.cbegin();
    }

    NamedArgsIterator NamedArgs::end() const
    {
        return m_context.input.namedArguments.cend();
    }

    NamedArgsIterator NamedArgs::find(std::string_view key) const
    {
        return std::find_if(begin(), end(), [key](NamedAnyArgView const& arg)
        {
            return arg.key() == key;
        });
    }

    //////////////////////////////////////

    ArgValue::ArgValue() = default;
    ArgValue::ArgValue(std::string_view value, std::vector<std::string_view> subvalues) : value(value), subvalues(std::move(subvalues)) {}

    bool ArgValue::operator==(ArgValue const& rhs) const
    {
        return value == rhs.value && subvalues == rhs.subvalues;
    }
    bool ArgValue::operator!=(ArgValue const& rhs) const
    {
        return !(*this == rhs);
    }
}

template std::string coil::formatString<unsigned int, char const*>(char const*, unsigned int, char const*);
template std::string coil::formatString<unsigned int, char const*, unsigned int, char const*>(char const*, unsigned int, char const*, unsigned int, char const*);
template std::string coil::formatString<unsigned int, char const*, unsigned int, char const*, unsigned int, char const*>(char const*, unsigned int, char const*, unsigned int, char const*, unsigned int, char const*);
template std::string coil::formatString<char const*>(char const*, char const*);

template class std::vector<std::string>;
template class std::optional<std::string>;

template class std::vector<coil::ArgValue>;
template class std::vector<std::pair<std::string_view, coil::ArgValue>>;

template class std::vector<std::string_view>;

template class std::optional<coil::AnyArgView>;
template class coil::Expected<coil::AnyArgView, coil::NamedArgs::Error>;

template class coil::BasicStringWrapper<std::string>;
template struct std::hash<coil::BasicStringWrapper<std::string>>;
// template class std::vector<coil::detail::AnyFunctor>;
// template class std::unordered_map<coil::StringWrapper, std::vector<coil::detail::AnyFunctor>>;
template class coil::BindingProxy<coil::Bindings>;

template class std::basic_string_view<char>;
template class std::basic_string<char>;

template class coil::Unexpected<std::string>;
template coil::Unexpected<std::string> coil::makeUnexpected(std::string value);
