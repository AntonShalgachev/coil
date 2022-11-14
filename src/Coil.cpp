#include "coil/Coil.h"

#include "coil/Assert.h"
#include "coil/DefaultLexer.h"
#include "coil/ExecutionResult.h"
#include "coil/Expected.h"
#include "coil/Lexer.h"
#include "coil/Utils.h"

#include "coil/detail/FunctorCaller.h"
#include "coil/detail/Utility.h"

#include <ctype.h>
#include <stdarg.h>
#include <stdio.h>

#if COIL_CONFIG_CATCH_EXCEPTIONS
    #include <exception>
#endif

// Explicitly instantiate used templates here in order to avoid intantiating them in each source file
template class coil::Vector<coil::String>;
template class coil::Optional<coil::String>;

template class coil::Vector<coil::Value>;
template class coil::Vector<coil::NamedValue>;

template class coil::Vector<coil::StringView>;

template class coil::Expected<coil::ReferenceWrapper<coil::Value const>, coil::String>;
template class coil::Expected<coil::ReferenceWrapper<coil::Value const>, coil::NamedArgs::Error>;
template coil::Unexpected<coil::NamedArgs::Error> coil::makeUnexpected(coil::NamedArgs::Error value);

template coil::Vector<coil::AnyFunctor>::Vector(size_t);
template void coil::Vector<coil::AnyFunctor>::pushBack(coil::AnyFunctor);
template coil::Vector<coil::AnyFunctor>::~Vector();

template class coil::UniquePtr<coil::Lexer>;

template class coil::Unexpected<coil::String>;
template coil::Unexpected<coil::String> coil::makeUnexpected(coil::String value);
template coil::Unexpected<coil::String>&& coil::move<coil::Unexpected<coil::String>&>(coil::Unexpected<coil::String>&) noexcept;

template coil::detail::AnyStorageBase*&& coil::move<coil::detail::AnyStorageBase*&>(coil::detail::AnyStorageBase*&) noexcept;
template void coil::exchange<coil::detail::AnyStorageBase*>(coil::detail::AnyStorageBase*&, coil::detail::AnyStorageBase*&) noexcept;

template coil::String&& coil::forward<coil::String>(coil::String&) noexcept;

namespace
{
    template<typename T>
    coil::Expected<T, coil::String> arithmeticFromString(coil::Value const& input)
    {
        if (input.subvalues.size() != 1)
            return coil::errors::createMismatchedSubvaluesError<T>(input, 1);

        T value{};
        if (!coil::fromString(input.subvalues[0], value))
            return coil::errors::createGenericError<T>(input);
        return value;
    }

    template<typename T>
    constexpr char const* defaultName = nullptr;

    template<>
    [[maybe_unused]] constexpr char const* defaultName<char> = "char";
    template<>
    [[maybe_unused]] constexpr char const* defaultName<signed char> = "signed char";
    template<>
    [[maybe_unused]] constexpr char const* defaultName<unsigned char> = "unsigned char";
    template<>
    [[maybe_unused]] constexpr char const* defaultName<short> = "short";
    template<>
    [[maybe_unused]] constexpr char const* defaultName<unsigned short> = "unsigned short";
    template<>
    [[maybe_unused]] constexpr char const* defaultName<int> = "int";
    template<>
    [[maybe_unused]] constexpr char const* defaultName<unsigned int> = "unsigned int";
    template<>
    [[maybe_unused]] constexpr char const* defaultName<long> = "long";
    template<>
    [[maybe_unused]] constexpr char const* defaultName<unsigned long> = "unsigned long";
    template<>
    [[maybe_unused]] constexpr char const* defaultName<long long> = "long long";
    template<>
    [[maybe_unused]] constexpr char const* defaultName<unsigned long long> = "unsigned long long";

    template<typename T>
    constexpr char const* arithmeticName()
    {
#if COIL_CONFIG_TYPE_NAME_USE_INTEGER_ALIAS
        if constexpr (coil::IsSameV<T, int8_t>)
            return "int8";
        if constexpr (coil::IsSameV<T, uint8_t>)
            return "uint8";
        if constexpr (coil::IsSameV<T, int16_t>)
            return "int16";
        if constexpr (coil::IsSameV<T, uint16_t>)
            return "uint16";
        if constexpr (coil::IsSameV<T, int32_t>)
            return "int32";
        if constexpr (coil::IsSameV<T, uint32_t>)
            return "uint32";
        if constexpr (coil::IsSameV<T, int64_t>)
            return "int64";
        if constexpr (coil::IsSameV<T, uint64_t>)
            return "uint64";
#endif

        static_assert(defaultName<T> != nullptr, "Unexpected type T");
        return defaultName<T>;
    }
}

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
        CallContext::CallContext(ExecutionInput input) : input(coil::move(input)) {}

        void CallContext::reportError(String error)
        {
            result.errors.pushBack(coil::move(error));
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
    Bindings::Bindings() : m_lexer(makeUnique<DefaultLexer>()) {}
    Bindings::Bindings(Bindings&& rhs) = default;
    Bindings::~Bindings() = default;

    Bindings& Bindings::operator=(Bindings&& rhs) = default;

    void Bindings::setLexer(UniquePtr<Lexer> lexer)
    {
        m_lexer = coil::move(lexer);
    }

    BindingProxy Bindings::operator[](StringView name)
    {
        return BindingProxy{*this, {name}};
    }

    Bindings::Command const& Bindings::add(StringView name, AnyFunctor anyFunctor)
    {
        Vector<AnyFunctor> functors;
        functors.pushBack(coil::move(anyFunctor));
        return add(name, coil::move(functors));
    }

    Bindings::Command const& Bindings::add(StringView name, Vector<AnyFunctor> anyFunctors)
    {
        auto it = m_commands.insertOrAssign(name, Command{StringView{}, coil::move(anyFunctors)});
        it->value().name = it->key();

        return it->value();
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

        return &it->value();
    }

    void Bindings::clear()
    {
        m_commands.clear();
    }

    ExecutionResult Bindings::execute(ExecutionInput input)
    {
        detail::CallContext context{coil::move(input)};
        execute(context);
        context.result.input = coil::move(context.input);
        return coil::move(context).result;
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

        return execute(*coil::move(input));
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
            context.result.errors.pushBack(sprintf("No function '%.*s' is registered", context.input.name.slength(), context.input.name.data()));
            return;
        }

        Command& container = it->value();
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
        auto error = sprintf("Wrong number of arguments to '%.*s': expected %s, got %zu", context.input.name.slength(), context.input.name.data(), expectedStr.cStr(), actualArgsCount);
        context.reportError(coil::move(error));
    }

    BindingProxy::BindingProxy(Bindings& bindings, StringView name) : m_bindings(bindings), m_name(name) {}

    BindingProxy& BindingProxy::operator=(AnyFunctor anyFunctor)
    {
        m_bindings.add(m_name, coil::move(anyFunctor));
        return *this;
    }
    BindingProxy& BindingProxy::operator=(Vector<AnyFunctor> anyFunctors)
    {
        m_bindings.add(m_name, coil::move(anyFunctors));
        return *this;
    }
    BindingProxy& BindingProxy::operator=(nullptr_t)
    {
        m_bindings.remove(m_name);
        return *this;
    }

    /// Context.h ///
    Context::Context(detail::CallContext& callContext) : m_callContext(callContext) {}

    void Context::log(String const& str)
    {
        m_callContext.result.output += str;
    }

    void Context::logline(String const& str)
    {
        m_callContext.result.output.reserve(m_callContext.result.output.length() + str.length() + 1);
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
        m_callContext.reportError(coil::move(error));
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
            return makeUnexpected(Error(Error::Type::MissingKey, sprintf("Missing named argument '%.*s'", key.slength(), key.data())));

        return {it->value};
    }

    Value const* NamedArgs::getOrReport(StringView key, ArgType argType) const
    {
        if (auto anyArg = get(key))
            return &static_cast<Value const&>(*anyArg);
        else if (argType == ArgType::Required)
            m_context.reportError(coil::move(anyArg).error().message);

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
            if (it->key == key)
                return it;
        return end();
    }

    /// Value.h ///
    Value::Value() = default; // @NOCOVERAGE
    Value::Value(StringView value)
    {
        subvalues.pushBack(coil::move(value));
    }
    Value::Value(char const* value) : Value(StringView{value}) {}
    Value::Value(Vector<StringView> subvalues) : subvalues(coil::move(subvalues)) {}

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

    bool NamedValue::operator==(NamedValue const& rhs) const
    {
        return key == rhs.key && value == rhs.value;
    }

    bool NamedValue::operator!=(NamedValue const& rhs) const
    {
        return !(*this == rhs);
    }

    /// TypeSerializer.h ///
    namespace errors
    {
        Unexpected<String> createGenericError(StringView typeName, Value const& input, StringView details)
        {
            String representation = input.str();

            if (details.empty())
                return makeUnexpected(sprintf("Unable to convert '%s' to type '%.*s'", representation.cStr(), typeName.slength(), typeName.data()));

            return makeUnexpected(sprintf("Unable to convert '%s' to type '%.*s': %.*s", representation.cStr(), typeName.slength(), typeName.data(), details.slength(), details.data()));
        }

        Unexpected<String> createMismatchedSubvaluesError(StringView typeName, Value const& input, size_t expectedSubvalues)
        {
            return createGenericError(typeName, input, sprintf("Expected %zu subvalues, got %zu", expectedSubvalues, input.subvalues.size()));
        }
    }

#define DEFINE_ARITHMETIC_TYPE_SERIALIZER(Type)                                       \
    coil::Expected<Type, String> TypeSerializer<Type>::fromString(Value const& input) \
    {                                                                                 \
        return ::arithmeticFromString<Type>(input);                                   \
    }                                                                                 \
    coil::String TypeSerializer<Type>::toString(Type const& value)                    \
    {                                                                                 \
        return coil::toString(value);                                                 \
    }

    DEFINE_ARITHMETIC_TYPE_SERIALIZER(char);
    DEFINE_ARITHMETIC_TYPE_SERIALIZER(signed char);
    DEFINE_ARITHMETIC_TYPE_SERIALIZER(unsigned char);
    DEFINE_ARITHMETIC_TYPE_SERIALIZER(short);
    DEFINE_ARITHMETIC_TYPE_SERIALIZER(unsigned short);
    DEFINE_ARITHMETIC_TYPE_SERIALIZER(int);
    DEFINE_ARITHMETIC_TYPE_SERIALIZER(unsigned int);
    DEFINE_ARITHMETIC_TYPE_SERIALIZER(long);
    DEFINE_ARITHMETIC_TYPE_SERIALIZER(unsigned long);
    DEFINE_ARITHMETIC_TYPE_SERIALIZER(long long);
    DEFINE_ARITHMETIC_TYPE_SERIALIZER(unsigned long long);
    DEFINE_ARITHMETIC_TYPE_SERIALIZER(float);
    DEFINE_ARITHMETIC_TYPE_SERIALIZER(double);
    DEFINE_ARITHMETIC_TYPE_SERIALIZER(long double);
#undef DEFINE_ARITHMETIC_TYPE_SERIALIZER

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

        // TODO also handle yes/no

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

        return String{input.subvalues[0]};
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

        [[maybe_unused]] int result = vsnprintf(str.data(), str.length() + 1, format, args);

        COIL_ASSERT(result >= 0 && static_cast<size_t>(result) <= str.length());

        return str;
    }
}

/// TypeName.h ///
COIL_CREATE_TYPE_NAME_DEFINITION(void, "void");
COIL_CREATE_TYPE_NAME_DEFINITION(bool, "bool");

COIL_CREATE_TYPE_NAME_DEFINITION(char, arithmeticName<char>());
COIL_CREATE_TYPE_NAME_DEFINITION(signed char, arithmeticName<signed char>());
COIL_CREATE_TYPE_NAME_DEFINITION(unsigned char, arithmeticName<unsigned char>());
COIL_CREATE_TYPE_NAME_DEFINITION(short, arithmeticName<short>());
COIL_CREATE_TYPE_NAME_DEFINITION(unsigned short, arithmeticName<unsigned short>());
COIL_CREATE_TYPE_NAME_DEFINITION(int, arithmeticName<int>());
COIL_CREATE_TYPE_NAME_DEFINITION(unsigned int, arithmeticName<unsigned int>());
COIL_CREATE_TYPE_NAME_DEFINITION(long, arithmeticName<long>());
COIL_CREATE_TYPE_NAME_DEFINITION(unsigned long, arithmeticName<unsigned long>());
COIL_CREATE_TYPE_NAME_DEFINITION(long long, arithmeticName<long long>());
COIL_CREATE_TYPE_NAME_DEFINITION(unsigned long long, arithmeticName<unsigned long long>());

COIL_CREATE_TYPE_NAME_DEFINITION(float, "float");
COIL_CREATE_TYPE_NAME_DEFINITION(double, "double");
COIL_CREATE_TYPE_NAME_DEFINITION(long double, "long double");

COIL_CREATE_TYPE_NAME_DEFINITION(coil::String, "string");
COIL_CREATE_TYPE_NAME_DEFINITION(coil::StringView, "string");
