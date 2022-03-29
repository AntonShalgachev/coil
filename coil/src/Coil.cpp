#include "coil/Coil.h"

namespace coil
{
    namespace detail
    {
        /// AnyFunctor.h ///
        AnyStorageBase::AnyStorageBase() = default;
        AnyStorageBase::~AnyStorageBase() = default;

        AnyFunctor::AnyFunctor(AnyFunctor&& rhs)
        {
            using namespace std;
            swap(rhs.m_storage, m_storage);
            swap(rhs.m_arity, m_arity);
        }

        AnyFunctor::~AnyFunctor()
        {
            destroy();
        }

        void AnyFunctor::destroy()
        {
            if (m_storage)
                delete m_storage;

            m_storage = nullptr;
        }

        void AnyFunctor::invokeTrampoline(detail::CallContext& context)
        {
            return m_storage->invoke(context);
        }

        std::size_t AnyFunctor::arity() const { return m_arity; }

        /// FunctorCaller.h ///
        template<>
        Context createContext<0>(CallContext& context)
        {
            return Context{ context };
        }

        void reportExceptionError(CallContext& context)
        {
            context.reportError("Exception caught during execution");
        }

        void reportExceptionError(CallContext& context, std::exception const& ex)
        {
            context.reportError(formatString("Exception caught during execution: %s", ex.what()));
        }

        /// CallContext.h ///
        CallContext::CallContext(ExecutionInput const& input) : input(input) {}

        std::ostream& CallContext::out() { return result.output; }

        void CallContext::reportError(std::string error)
        {
            result.errors.push_back(std::move(error));
        }

        bool CallContext::hasErrors() const
        {
            return !result.errors.empty();
        }
    }

    /// Bindings.h ///
    BindingProxy<Bindings> Bindings::operator[](std::string_view name)
    {
        return BindingProxy<Bindings>{ *this, { name } };
    }

    void Bindings::add(std::string_view name, detail::AnyFunctor anyFunctor)
    {
        // No move list-initialization in vector? Really, C++?
        std::vector<detail::AnyFunctor> functors;
        functors.push_back(std::move(anyFunctor));
        m_commands.insert_or_assign(name, std::move(functors));
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

    /// Context.h ///
    Context::Context(detail::CallContext& callContext) : m_callContext(callContext) {}

    std::ostream& Context::out() { return m_callContext.out(); }

    void Context::reportError(std::string error)
    {
        m_callContext.reportError(std::move(error));
    }

    bool Context::hasErrors() const
    {
        return m_callContext.hasErrors();
    }

    NamedArgs Context::namedArgs() { return NamedArgs{ m_callContext }; }

    /// NamedArgs.h ///
    NamedAnyArgView::NamedAnyArgView(std::string_view key, ArgValue value) : m_key(key), m_value(value) {}

    std::string_view NamedAnyArgView::key() const { return m_key; }
    AnyArgView NamedAnyArgView::value() const { return m_value; }

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

    /// ArgValue.h ///
    ArgValue::ArgValue() = default; // @NOCOVERAGE
    ArgValue::ArgValue(std::string_view value, std::vector<std::string_view> subvalues) : value(value), subvalues(std::move(subvalues)) {}

    bool ArgValue::operator==(ArgValue const& rhs) const
    {
        return value == rhs.value && subvalues == rhs.subvalues;
    }

    /// TypeSerializer.h ///
    coil::Expected<bool, std::string> coil::TypeSerializer<bool>::fromString(ArgValue const& input)
    {
        auto equalCaseInsensitive = [](std::string_view a, std::string_view b)
        {
            std::size_t const length = a.length();
            if (b.length() != length)
                return false;

            for (std::size_t i = 0; i < a.length(); i++)
                if (std::tolower(a[i]) != std::tolower(b[i]))
                    return false;

            return true;
        };

        if (input.value == "1")
            return true;
        if (input.value == "0")
            return false;

        if (equalCaseInsensitive(input.value, "true"))
            return true;
        if (equalCaseInsensitive(input.value, "false"))
            return false;

        return makeSerializationError<bool>(input);
    }

    std::string coil::TypeSerializer<bool>::toString(bool const& value)
    {
        return value ? "true" : "false";
    }

    /// ExecutionResult.h ///
    void ExecutionResult::setReturnValue(std::string value)
    {
        returnValue = std::move(value);
    }

    COIL_CREATE_TYPE_NAME_DEFINITION(bool);
    COIL_CREATE_TYPE_NAME_DEFINITION(char);
    COIL_CREATE_TYPE_NAME_DEFINITION(signed char);
    COIL_CREATE_TYPE_NAME_DEFINITION(unsigned char);
    COIL_CREATE_TYPE_NAME_DEFINITION(short);
    COIL_CREATE_TYPE_NAME_DEFINITION(unsigned short);
    COIL_CREATE_TYPE_NAME_DEFINITION(int);
    COIL_CREATE_TYPE_NAME_DEFINITION(unsigned int);
    COIL_CREATE_TYPE_NAME_DEFINITION(long);
    COIL_CREATE_TYPE_NAME_DEFINITION(unsigned long);
    COIL_CREATE_TYPE_NAME_DEFINITION(long long);
    COIL_CREATE_TYPE_NAME_DEFINITION(unsigned long long);
    COIL_CREATE_TYPE_NAME_DEFINITION(float);
    COIL_CREATE_TYPE_NAME_DEFINITION(double);
    COIL_CREATE_TYPE_NAME_DEFINITION(long double);
}

// Explicitly instantiate used templates here in order to avoid intantiating them in each source file
template class std::vector<std::string>;
template class std::optional<std::string>;

template class std::vector<coil::ArgValue>;
template class std::vector<std::pair<std::string_view, coil::ArgValue>>;

template class std::vector<std::string_view>;

template class std::optional<coil::AnyArgView>;
template class coil::Expected<coil::AnyArgView, coil::NamedArgs::Error>;

template class coil::BasicStringWrapper<std::string>;
template struct std::hash<coil::BasicStringWrapper<std::string>>;

template class coil::BindingProxy<coil::Bindings>;

template class std::basic_string_view<char>;
template class std::basic_string<char>;

template class coil::Unexpected<std::string>;
template coil::Unexpected<std::string> coil::makeUnexpected(std::string value);
template coil::Unexpected<std::string>&& std::move<coil::Unexpected<std::string>&>(coil::Unexpected<std::string>&) noexcept;

template coil::detail::AnyStorageBase*&& std::move<coil::detail::AnyStorageBase*&>(coil::detail::AnyStorageBase*&) noexcept;
template void std::swap<coil::detail::AnyStorageBase*>(coil::detail::AnyStorageBase*&, coil::detail::AnyStorageBase*&) noexcept;

template std::string&& std::forward<std::string>(std::string&) noexcept;

template std::vector<coil::detail::AnyFunctor>::~vector();

COIL_TYPE_SERIALIZER_TEMPLATE(signed short);
COIL_TYPE_SERIALIZER_TEMPLATE(unsigned short);
COIL_TYPE_SERIALIZER_TEMPLATE(signed int);
COIL_TYPE_SERIALIZER_TEMPLATE(unsigned int);
COIL_TYPE_SERIALIZER_TEMPLATE(signed long);
COIL_TYPE_SERIALIZER_TEMPLATE(unsigned long);
COIL_TYPE_SERIALIZER_TEMPLATE(signed long long);
COIL_TYPE_SERIALIZER_TEMPLATE(unsigned long long);
COIL_TYPE_SERIALIZER_TEMPLATE(float);
COIL_TYPE_SERIALIZER_TEMPLATE(double);
COIL_TYPE_SERIALIZER_TEMPLATE(long double);
