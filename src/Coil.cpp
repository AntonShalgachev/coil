#include "coil/Coil.h"
#include "coil/DefaultLexer.h"

#include "coil/detail/Utility.h"

#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>

// Explicitly instantiate used templates here in order to avoid intantiating them in each source file
template class coil::Vector<coil::String>;
template class coil::Optional<coil::String>;

template class coil::Vector<coil::Value>;
template class coil::Vector<coil::NamedValue>;

template class coil::Vector<coil::StringView>;

template class coil::Expected<coil::Value, coil::NamedArgs::Error>;

template class coil::BasicStringWrapper<coil::String>;
template struct std::hash<coil::BasicStringWrapper<coil::String>>;

template class coil::BindingProxy<coil::Bindings>;
template class std::unique_ptr<coil::Lexer>;

template class coil::Unexpected<coil::String>;
template coil::Unexpected<coil::String> coil::makeUnexpected(coil::String value);
template coil::Unexpected<coil::String>&& coil::Move<coil::Unexpected<coil::String>&>(coil::Unexpected<coil::String>&) noexcept;

template coil::detail::AnyStorageBase*&& coil::Move<coil::detail::AnyStorageBase*&>(coil::detail::AnyStorageBase*&) noexcept;
template void std::swap<coil::detail::AnyStorageBase*>(coil::detail::AnyStorageBase*&, coil::detail::AnyStorageBase*&) noexcept;

template coil::String&& coil::Forward<coil::String>(coil::String&) noexcept;

// TODO
// template std::vector<coil::AnyFunctor>::~vector();

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

        void CallContext::reportError(String error)
        {
            result.errors.pushBack(coil::Move(error));
        }

        bool CallContext::hasErrors() const
        {
            return !result.errors.empty();
        }
    }

    /// AnyFcuntor.h ///

    AnyFunctor::AnyFunctor(AnyFunctor&& rhs)
    {
        coil::exchange(rhs.m_storage, m_storage);
        coil::exchange(rhs.m_parameterTypes, m_parameterTypes);
        coil::exchange(rhs.m_returnType, m_returnType);
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

    size_t AnyFunctor::arity() const
    {
        return m_parameterTypes.size();
    }

    Vector<StringView> const& AnyFunctor::parameterTypes() const
    {
        return m_parameterTypes;
    }

    StringView AnyFunctor::returnType() const
    {
        return m_returnType;
    }

    /// Bindings.h ///
    Bindings::Bindings() : m_lexer(std::make_unique<DefaultLexer>()) {}

    void Bindings::setLexer(std::unique_ptr<Lexer> lexer)
    {
        m_lexer = coil::Move(lexer);
    }

    BindingProxy<Bindings> Bindings::operator[](StringView name)
    {
        return BindingProxy<Bindings>{*this, {name}};
    }

    Bindings::Command const& Bindings::add(StringView name, AnyFunctor anyFunctor)
    {
        Vector<AnyFunctor> functors;
        functors.pushBack(coil::Move(anyFunctor));
        return add(name, coil::Move(functors));
    }

    Bindings::Command const& Bindings::add(StringView name, Vector<AnyFunctor> anyFunctors)
    {
        auto it = m_commands.insert_or_assign(name, Command{ StringView{}, coil::Move(anyFunctors) }).first;
        it->second.name = it->first;

        return it->second;
    }

    void Bindings::remove(StringView name)
    {
        m_commands.erase(name);
    }

    Bindings::Command const* Bindings::get(StringView name) const
    {
        auto it = m_commands.find(name);
        if (it == m_commands.end())
            return nullptr;

        return &it->second;
    }

    void Bindings::clear()
    {
        m_commands.clear();
    }

    ExecutionResult Bindings::execute(ExecutionInput input)
    {
        detail::CallContext context{coil::Move(input)};
        execute(context);
        context.result.input = coil::Move(context.input);
        return coil::Move(context).result;
    }

    ExecutionResult Bindings::execute(StringView command)
    {
        Expected<ExecutionInput, String> input = m_lexer->parse(command);
        if (!input)
        {
            ExecutionResult result;
            result.errors.pushBack("Syntax error: " + input.error());
            return result;
        }

        return execute(*input);
    }

    void Bindings::execute(detail::CallContext& context)
    {
        if (context.input.name.empty())
        {
            context.result.errors.pushBack("No function name is specified");
            return;
        }

        auto it = m_commands.find(context.input.name);
        if (it == m_commands.end())
        {
            context.result.errors.pushBack(sprintf("No function '%.*s' is registered", context.input.name.length(), context.input.name.data()));
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
            context.reportError(sprintf("Exception caught during execution: %s", ex.what()));
            return;
        }
        catch (...)
        {
            context.reportError("Exception caught during execution");
            return;
        }
#endif // COIL_CONFIG_CATCH_EXCEPTIONS

        String expectedStr;
        expectedStr.reserve(functors.size() * 3); // N + (N-2)*2 + 4

        for (size_t i = 0; i < functors.size(); i++)
        {
            if (i > 0 && i != functors.size() - 1)
                expectedStr += ", ";
            if (i > 0 && i == functors.size() - 1)
                expectedStr += " or ";

            expectedStr += toString(functors[i].arity());
        }

        size_t const actualArgsCount = context.input.arguments.size();
        auto error = sprintf("Wrong number of arguments to '%.*s': expected %s, got %d", context.input.name.length(), context.input.name.data(), expectedStr.cStr(), actualArgsCount);
        context.reportError(coil::Move(error));
    }

    /// Context.h ///
    Context::Context(detail::CallContext& callContext) : m_callContext(callContext) {}

    void Context::log(String const& str)
    {
        m_callContext.result.output += str;
    }

    void Context::logline(String const& str)
    {
        m_callContext.result.output.reserve(m_callContext.result.output.size() + str.size() + 1);
        m_callContext.result.output += str;
        m_callContext.result.output += '\n';
    }

    void Context::logf(char const* format, ...)
    {
        va_list args;
        va_start(args, format);
        log(vsprintf(format, args));
        va_end(args);
    }

    void Context::loglinef(char const* format, ...)
    {
        va_list args;
        va_start(args, format);
        logline(vsprintf(format, args));
        va_end(args);
    }

    void Context::reportError(String error)
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
    NamedArgs::NamedArgs(detail::CallContext& context) : m_context(context) {}

    Expected<ReferenceWrapper<Value const>, NamedArgs::Error> NamedArgs::get(StringView key) const
    {
        auto it = find(key);
        if (it == end())
            return makeUnexpected(Error(Error::Type::MissingKey, sprintf("Missing named argument '%.*s'", key.length(), key.data())));

        return {it->value()};
    }

    Value const* NamedArgs::getOrReport(StringView key, ArgType argType) const
    {
        if (auto anyArg = get(key))
            return &static_cast<Value const&>(*anyArg);
        else if (argType == ArgType::Required)
            m_context.reportError(coil::Move(anyArg).error().message);

        return nullptr;
    }

    size_t NamedArgs::size() const
    {
        return m_context.input.namedArguments.size();
    }

    NamedArgs::NamedArgsIteratorT NamedArgs::begin() const
    {
        return m_context.input.namedArguments.begin();
    }

    NamedArgs::NamedArgsIteratorT NamedArgs::end() const
    {
        return m_context.input.namedArguments.end();
    }

    NamedArgs::NamedArgsIteratorT NamedArgs::find(StringView key) const
    {
        for (auto it = begin(); it != end(); ++it)
            if (it->key() == key)
                return it;
        return end();
    }

    /// Value.h ///
    Value::Value() = default; // @NOCOVERAGE
    Value::Value(StringView value) { subvalues.pushBack(Move(value)); }
    Value::Value(char const* value) : Value(StringView{ value }) {}
    Value::Value(Vector<StringView> subvalues) : subvalues(coil::Move(subvalues)) {}

    bool Value::operator==(Value const& rhs) const
    {
        return subvalues == rhs.subvalues;
    }

    bool Value::operator!=(Value const& rhs) const
    {
        return !(*this == rhs);
    }

    String Value::str() const
    {
        String result;
        StringView prefix = "";
        for (StringView subvalue : subvalues)
        {
            result += prefix;
            result += subvalue;
            prefix = " ";
        }

        return result;
    }

    coil::Expected<ReferenceWrapper<Value const>, String> coil::TypeSerializer<Value>::fromString(Value const& value)
    {
        return {value};
    }

    String coil::TypeSerializer<Value>::toString(Value const& value)
    {
        return value.str();
    }

    /// TypeSerializer.h ///
    coil::Expected<bool, String> coil::TypeSerializer<bool>::fromString(Value const& input)
    {
        auto equalCaseInsensitive = [](StringView a, StringView b) {
            size_t const length = a.length();
            if (b.length() != length)
                return false;

            for (size_t i = 0; i < a.length(); i++)
                if (tolower(a[i]) != tolower(b[i]))
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

    String coil::TypeSerializer<bool>::toString(bool const& value)
    {
        return value ? "true" : "false";
    }

    coil::Expected<String, String> coil::TypeSerializer<String>::fromString(Value const& input)
    {
        if (input.subvalues.size() != 1)
            return errors::createMismatchedSubvaluesError<String>(input, 1);

        return String{ input.subvalues[0] };
    }

    String coil::TypeSerializer<String>::toString(String const& value)
    {
        return value;
    }

    coil::Expected<StringView, String> coil::TypeSerializer<StringView>::fromString(Value const& input)
    {
        if (input.subvalues.size() != 1)
            return errors::createMismatchedSubvaluesError<StringView>(input, 1);

        return input.subvalues[0];
    }

    String coil::TypeSerializer<StringView>::toString(StringView const& value)
    {
        return value;
    }

    String coil::TypeSerializer<char const*>::toString(char const* const& value)
    {
        return String{value};
    }

    /// Utils.h ///
    String sprintf(char const* format, ...)
    {
        va_list args;
        va_start(args, format);
        auto res = vsprintf(format, args);
        va_end(args);

        return res;
    }

    String vsprintf(char const* format, va_list args)
    {
        va_list args2;
        va_copy(args2, args);
        size_t stringSize = static_cast<size_t>(vsnprintf(nullptr, 0, format, args2));
        va_end(args2);

        String str;
        str.resize(stringSize);

        [[maybe_unused]] int result = vsnprintf(str.data(), str.size() + 1, format, args);

        assert(result >= 0 && static_cast<size_t>(result) <= str.size());

        return str;
    }
}

/// TypeName.h ///
COIL_CREATE_TYPE_NAME_DEFINITION(bool, "bool");
COIL_CREATE_TYPE_NAME_DEFINITION(coil::String, "string");
COIL_CREATE_TYPE_NAME_DEFINITION(coil::StringView, "string");

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
#endif // COIL_CONFIG_BASIC_TYPENAME
