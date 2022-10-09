#include "coil/Coil.h"
#include "coil/DefaultLexer.h"

// Explicitly instantiate used templates here in order to avoid intantiating them in each source file
template class std::vector<std::string>;
template class std::optional<std::string>;
template std::optional<std::string>::optional(std::string&&);

template class std::vector<coil::Value>;
template class std::vector<std::pair<std::string_view, coil::Value>>;

template class std::vector<std::string_view>;

template class std::optional<coil::Value>;
template class coil::Expected<coil::Value, coil::NamedArgs::Error>;

template class coil::BasicStringWrapper<std::string>;
template struct std::hash<coil::BasicStringWrapper<std::string>>;

template class coil::BindingProxy<coil::Bindings>;
template class std::unique_ptr<coil::Lexer>;

template class std::basic_string_view<char>;
template class std::basic_string<char>;

template class coil::Unexpected<std::string>;
template coil::Unexpected<std::string> coil::makeUnexpected(std::string value);
template coil::Unexpected<std::string>&& coil::Move<coil::Unexpected<std::string>&>(coil::Unexpected<std::string>&) noexcept;

template coil::detail::AnyStorageBase*&& coil::Move<coil::detail::AnyStorageBase*&>(coil::detail::AnyStorageBase*&) noexcept;
template void std::swap<coil::detail::AnyStorageBase*>(coil::detail::AnyStorageBase*&, coil::detail::AnyStorageBase*&) noexcept;

template std::string&& coil::Forward<std::string>(std::string&) noexcept;

template std::vector<coil::AnyFunctor>::~vector();

namespace coil
{
    namespace detail
    {
        /// AnyFunctor.h ///
        AnyStorageBase::AnyStorageBase() = default;
        AnyStorageBase::~AnyStorageBase() = default;

        /// FunctorCaller.h ///
        template<>
        Context createContext<0>(CallContext& context)
        {
            return Context{context};
        }

        /// CallContext.h ///
        CallContext::CallContext(ExecutionInput input) : input(coil::Move(input)) {}

        std::ostream& CallContext::log()
        {
            return result.output;
        }

        void CallContext::reportError(std::string error)
        {
            result.errors.push_back(coil::Move(error));
        }

        bool CallContext::hasErrors() const
        {
            return !result.errors.empty();
        }
    }

    /// AnyFcuntor.h ///

    AnyFunctor::AnyFunctor(AnyFunctor&& rhs)
    {
        using namespace std;
        swap(rhs.m_storage, m_storage);
        swap(rhs.m_parameterTypes, m_parameterTypes);
        swap(rhs.m_returnType, m_returnType);
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

    std::size_t AnyFunctor::arity() const
    {
        return m_parameterTypes.size();
    }

    std::vector<std::string_view> const& AnyFunctor::parameterTypes() const
    {
        return m_parameterTypes;
    }

    std::string_view AnyFunctor::returnType() const
    {
        return m_returnType;
    }

    /// Bindings.h ///
    Bindings::Bindings() : m_lexer(std::make_unique<DefaultLexer>()) {}

    void Bindings::setLexer(std::unique_ptr<Lexer> lexer)
    {
        m_lexer = coil::Move(lexer);
    }

    BindingProxy<Bindings> Bindings::operator[](std::string_view name)
    {
        return BindingProxy<Bindings>{*this, {name}};
    }

    Bindings::Command const& Bindings::add(std::string_view name, AnyFunctor anyFunctor)
    {
        // No move list-initialization in vector? Really, C++?
        std::vector<AnyFunctor> functors;
        functors.push_back(coil::Move(anyFunctor));
        return add(name, coil::Move(functors));
    }

    Bindings::Command const& Bindings::add(std::string_view name, std::vector<AnyFunctor> anyFunctors)
    {
        auto it = m_commands.insert_or_assign(name, Command{coil::Move(anyFunctors)}).first;

        m_commandNames.push_back(it->first);
        return it->second;
    }

    void Bindings::remove(std::string_view name)
    {
        m_commandNames.erase(std::remove(m_commandNames.begin(), m_commandNames.end(), name), m_commandNames.end());
        m_commands.erase(name);
    }

    Bindings::Command const* Bindings::get(std::string_view name) const
    {
        auto it = m_commands.find(name);
        if (it == m_commands.end())
            return nullptr;

        return &it->second;
    }

    void Bindings::clear()
    {
        m_commandNames.clear();
        m_commands.clear();
    }

    std::vector<std::string_view> const& Bindings::commands() const
    {
        return m_commandNames;
    }

    ExecutionResult Bindings::execute(ExecutionInput input)
    {
        detail::CallContext context{coil::Move(input)};
        execute(context);
        context.result.input = coil::Move(context.input);
        return coil::Move(context).result;
    }

    ExecutionResult Bindings::execute(std::string_view command)
    {
        Expected<ExecutionInput, std::string> input = m_lexer->parse(command);
        if (!input)
        {
            ExecutionResult result;
            result.errors.push_back(std::string("Syntax error: ") + input.error());
            return result;
        }

        return execute(*input);
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

        Command& container = it->second;
        auto& functors = container.functors;

#if COIL_CONFIG_CATCH_EXCEPTIONS
        try
#endif // COIL_CONFIG_CATCH_EXCEPTIONS
        {
            for (auto& functor : functors)
                if (functor.arity() == context.input.arguments.size())
                    return functor.invokeTrampoline(context);
        }
#if COIL_CONFIG_CATCH_EXCEPTIONS
        catch (std::exception const& ex)
        {
            context.reportError(formatString("Exception caught during execution: %s", ex.what()));
            return;
        }
        catch (...)
        {
            context.reportError("Exception caught during execution");
            return;
        }
#endif // COIL_CONFIG_CATCH_EXCEPTIONS

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
        context.reportError(coil::Move(error));
    }

    /// Context.h ///
    Context::Context(detail::CallContext& callContext) : m_callContext(callContext) {}

    std::ostream& Context::log()
    {
        return m_callContext.log();
    }

    void Context::log(std::string_view str)
    {
        log() << str;
    }

    void Context::reportError(std::string error)
    {
        m_callContext.reportError(coil::Move(error));
    }

    bool Context::hasErrors() const
    {
        return m_callContext.hasErrors();
    }

    NamedArgs Context::namedArgs()
    {
        return NamedArgs{m_callContext};
    }

    /// NamedArgs.h ///
    NamedValue::NamedValue(std::string_view key, Value const& value) : m_key(key), m_value(value) {}

    std::string_view NamedValue::key() const
    {
        return m_key;
    }
    Value const& NamedValue::value() const
    {
        return m_value;
    }

    NamedArgsIterator::NamedArgsIterator(UnderlyingIteratorT iterator) : m_iterator(iterator) {}

    NamedValue NamedArgsIterator::operator*()
    {
        return NamedValue(m_iterator->first, m_iterator->second);
    }

    NamedArgsIterator::NamedArgContainer NamedArgsIterator::operator->()
    {
        return NamedArgContainer{**this};
    }

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

    Expected<std::reference_wrapper<Value const>, NamedArgs::Error> NamedArgs::get(std::string_view key) const
    {
        auto it = find(key);
        if (it == end())
            return makeUnexpected(Error(Error::Type::MissingKey, formatString("Missing named argument '%.*s'", key.size(), key.data())));

        return {it->value()};
    }

    Value const* NamedArgs::getOrReport(std::string_view key, ArgType argType) const
    {
        if (auto anyArg = get(key))
            return &static_cast<Value const&>(*anyArg);
        else if (argType == ArgType::Required)
            m_context.reportError(coil::Move(anyArg).error().message);

        return nullptr;
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
        return std::find_if(begin(), end(), [key](NamedValue const& arg) { return arg.key() == key; });
    }

    /// Value.h ///
    Value::Value() = default; // @NOCOVERAGE
    Value::Value(std::string_view value) : subvalues({value}) {}
    Value::Value(std::vector<std::string_view> subvalues) : subvalues(coil::Move(subvalues)) {}

    bool Value::operator==(Value const& rhs) const
    {
        return subvalues == rhs.subvalues;
    }

    std::string Value::str() const
    {
        std::stringstream ss;
        std::string_view prefix = "";
        for (std::string_view subvalue : subvalues)
        {
            ss << prefix << subvalue;
            prefix = " ";
        }

        return ss.str();
    }

    std::ostream& operator<<(std::ostream& os, Value const& rhs)
    {
        return os << rhs.str();
    }

    coil::Expected<std::reference_wrapper<Value const>, std::string> coil::TypeSerializer<Value>::fromString(Value const& value)
    {
        return {value};
    }

    std::string coil::TypeSerializer<Value>::toString(Value const& value)
    {
        return value.str();
    }

    /// TypeSerializer.h ///
    coil::Expected<bool, std::string> coil::TypeSerializer<bool>::fromString(Value const& input)
    {
        auto equalCaseInsensitive = [](std::string_view a, std::string_view b) {
            std::size_t const length = a.length();
            if (b.length() != length)
                return false;

            for (std::size_t i = 0; i < a.length(); i++)
                if (std::tolower(a[i]) != std::tolower(b[i]))
                    return false;

            return true;
        };

        if (input.subvalues.size() != 1)
            return errors::createMismatchedSubvaluesError<bool>(input, 1);

        auto value = input.subvalues[0];

        if (value == "1")
            return true;
        if (value == "0")
            return false;

        if (equalCaseInsensitive(value, "true"))
            return true;
        if (equalCaseInsensitive(value, "false"))
            return false;

        return errors::createGenericError<bool>(input);
    }

    std::string coil::TypeSerializer<bool>::toString(bool const& value)
    {
        return value ? "true" : "false";
    }

    std::string coil::TypeSerializer<char const*>::toString(char const* const& value)
    {
        return std::string{value};
    }

    /// TypeName.h ///
    COIL_CREATE_TYPE_NAME_DEFINITION(bool, "bool");

#if COIL_CONFIG_BASIC_TYPENAME
    COIL_CREATE_TYPE_NAME_DEFINITION(void, "void");
    COIL_CREATE_TYPE_NAME_DEFINITION(char, "char");
    COIL_CREATE_TYPE_NAME_DEFINITION(signed char, "schar");
    COIL_CREATE_TYPE_NAME_DEFINITION(unsigned char, "uchar");
    COIL_CREATE_TYPE_NAME_DEFINITION(short, "short");
    COIL_CREATE_TYPE_NAME_DEFINITION(unsigned short, "ushort");
    COIL_CREATE_TYPE_NAME_DEFINITION(int, "int");
    COIL_CREATE_TYPE_NAME_DEFINITION(unsigned int, "uint");
    COIL_CREATE_TYPE_NAME_DEFINITION(long, "long");
    COIL_CREATE_TYPE_NAME_DEFINITION(unsigned long, "ulong");
    COIL_CREATE_TYPE_NAME_DEFINITION(long long, "llong");
    COIL_CREATE_TYPE_NAME_DEFINITION(unsigned long long, "ullong");
    COIL_CREATE_TYPE_NAME_DEFINITION(float, "float");
    COIL_CREATE_TYPE_NAME_DEFINITION(double, "double");
    COIL_CREATE_TYPE_NAME_DEFINITION(long double, "ldouble");
    COIL_CREATE_TYPE_NAME_DEFINITION(std::string, "std::string");
    COIL_CREATE_TYPE_NAME_DEFINITION(std::string_view, "std::string_view");
#endif // COIL_CONFIG_BASIC_TYPENAME
}
