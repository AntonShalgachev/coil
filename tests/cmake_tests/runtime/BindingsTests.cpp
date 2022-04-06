#include "gtest/gtest.h"
#include "Common.h"

#include <stdexcept>
#include <numeric>

namespace stats
{
    std::size_t functionCalls = 0;

    std::size_t trackerConstructions = 0;
    std::size_t trackerValueConstructions = 0;
    std::size_t trackerCopyConstructions = 0;
    std::size_t trackerMoveConstructions = 0;

    std::size_t trackerAssignments = 0;
    std::size_t trackerCopyAssignments = 0;
    std::size_t trackerMoveAssignments = 0;

    void reset()
    {
        functionCalls = 0;

        trackerConstructions = 0;
        trackerValueConstructions = 0;
        trackerCopyConstructions = 0;
        trackerMoveConstructions = 0;

        trackerAssignments = 0;
        trackerCopyAssignments = 0;
        trackerMoveAssignments = 0;
    }
}

namespace
{
    template<typename T>
    class Tracker final
    {
    public:
        friend struct coil::TypeSerializer<Tracker<T>>;

        Tracker(T payload = T{}) : m_payload(std::move(payload))
        {
            stats::trackerConstructions++;
            stats::trackerValueConstructions++;
        }

        Tracker(Tracker<T> const& rhs) : m_payload(rhs.m_payload)
        {
            stats::trackerConstructions++;
            stats::trackerCopyConstructions++;
        }
        Tracker(Tracker<T>&& rhs) : m_payload(std::move(rhs.m_payload))
        {
            rhs.m_payload = T{};

            stats::trackerConstructions++;
            stats::trackerMoveConstructions++;
        }

        Tracker<T>& operator=(Tracker<T> const& rhs)
        {
            m_payload = rhs.m_payload;

            stats::trackerAssignments++;
            stats::trackerCopyAssignments++;

            return *this;
        }
        Tracker<T>& operator=(Tracker<T>&& rhs)
        {
            m_payload = std::move(rhs.m_payload);
            rhs.m_payload = T{};

            stats::trackerAssignments++;
            stats::trackerMoveAssignments++;

            return *this;
        }

        ~Tracker() = default;

        bool operator==(Tracker<T> const& rhs) const
        {
            return m_payload == rhs.m_payload;
        }

    private:
        T m_payload;
    };

    struct CompoundType
    {
        int field1{};
        int field2{};

        bool operator==(CompoundType const& rhs) const
        {
            return field1 == rhs.field1 && field2 == rhs.field2;
        }
    };

    bool containsError(std::vector<std::string> const& errors, std::string const& value)
    {
        return std::find(errors.begin(), errors.end(), value) != errors.end();
    }
}

namespace coil
{
    template<typename T>
    struct TypeSerializer<Tracker<T>>
    {
        static Expected<Tracker<T>, std::string> fromString(ArgValue const& input)
        {
            Expected<T, std::string> innerValue = TypeSerializer<T>::fromString(input);
            if (innerValue)
                return Tracker<T>{*innerValue};

            return errors::serializationError<Tracker<T>>(input, innerValue.error());
        }

        static std::string toString(Tracker<T> const& value)
        {
            return TypeSerializer<T>::toString(value.m_payload);
        }
    };

    template<>
    struct TypeSerializer<CompoundType>
    {
        static Expected<CompoundType, std::string> fromString(ArgValue const& input)
        {
            if (input.subvalues.size() != 2)
                return errors::wrongSubvaluesSize<CompoundType>(input, 2);

            auto field1 = TypeSerializer<int>::fromString(input.subvalues[0]);
            auto field2 = TypeSerializer<int>::fromString(input.subvalues[1]);

            if (!field1)
                return errors::serializationError<CompoundType>(input, field1.error());
            if (!field2)
                return errors::serializationError<CompoundType>(input, field2.error());

            return CompoundType{ *field1, *field2 };
        }

        static std::string toString(CompoundType const& value)
        {
            std::stringstream ss;
            ss << "CompoundType{" << value.field1 << ',' << value.field2 << '}';
            return ss.str();
        }
    };

    template<typename T>
    struct TypeName<Tracker<T>>
    {
        static std::string_view name()
        {
            using namespace std::literals::string_literals;
            static std::string const typeName = "Tracker<"s + std::string(TypeName<T>::name()) + ">"s;
            return typeName;
        }
    };

    template<>
    struct TypeName<CompoundType>
    {
        static std::string_view name() { return "CompoundType"; }
    };
}

TEST(BindingsTests, TestVoidFunctionCallStats)
{
    stats::reset();

    coil::Bindings bindings;
    bindings["func"] = []() { stats::functionCalls++; };
    auto result = bindings.execute("func");

    EXPECT_EQ(result.errors.size(), 0);

    EXPECT_EQ(stats::functionCalls, 1);
    EXPECT_EQ(stats::trackerAssignments, 0);
    EXPECT_EQ(stats::trackerConstructions, 0);
}

TEST(BindingsTests, TestVoidFunctionWithDotsCallStats)
{
    stats::reset();

    coil::Bindings bindings;
    bindings["namespace.func"] = []() { stats::functionCalls++; };
    auto result = bindings.execute("namespace.func");

    EXPECT_EQ(result.errors.size(), 0);

    EXPECT_EQ(stats::functionCalls, 1);
    EXPECT_EQ(stats::trackerAssignments, 0);
    EXPECT_EQ(stats::trackerConstructions, 0);
}

TEST(BindingsTests, TestVariableAssignmentStats)
{
    Tracker<int> trackedVariable;

    stats::reset();

    coil::Bindings bindings;
    bindings["var"] = coil::variable(&trackedVariable);
    auto result = bindings.execute("var 42");

    EXPECT_EQ(result.errors.size(), 0);

    EXPECT_EQ(stats::functionCalls, 0);
    EXPECT_EQ(stats::trackerValueConstructions, 1);
    EXPECT_EQ(stats::trackerCopyConstructions, 0);
    EXPECT_EQ(stats::trackerCopyAssignments, 0);
}

TEST(BindingsTests, TestPassingArgumentByValueStats)
{
    stats::reset();

    coil::Bindings bindings;
    bindings["func"] = [](Tracker<int>) {};
    auto result = bindings.execute("func 42");

    EXPECT_EQ(result.errors.size(), 0);

    EXPECT_EQ(stats::trackerValueConstructions, 1);
    EXPECT_EQ(stats::trackerCopyConstructions, 0);
    EXPECT_EQ(stats::trackerCopyAssignments, 0);
}

TEST(BindingsTests, TestPassingArgumentByRefStats)
{
    stats::reset();

    coil::Bindings bindings;
    bindings["func"] = [](Tracker<int> const) {};
    auto result = bindings.execute("func 42");

    EXPECT_EQ(result.errors.size(), 0);

    EXPECT_EQ(stats::trackerValueConstructions, 1);
    EXPECT_EQ(stats::trackerCopyConstructions, 0);
    EXPECT_EQ(stats::trackerCopyAssignments, 0);
}

TEST(BindingsTests, TestReturnByValueStats)
{
    stats::reset();

    coil::Bindings bindings;
    bindings["func"] = []() { return Tracker<int>{42}; };
    auto result = bindings.execute("func");

    EXPECT_EQ(result.errors.size(), 0);

    EXPECT_EQ(stats::trackerValueConstructions, 1);
    EXPECT_EQ(stats::trackerCopyConstructions, 0);
    EXPECT_EQ(stats::trackerCopyAssignments, 0);
}

TEST(BindingsTests, TestErrorStats)
{
    Tracker<int> variable = 0;

    stats::reset();

    coil::Bindings bindings;
    bindings["func_without_args"] = []() { stats::functionCalls++; };
    bindings["func_with_arg"] = [](int) { stats::functionCalls++; };
    bindings["var"] = coil::variable(&variable);

    bindings.execute("func_without_args arg");
    bindings.execute("func_with_arg string_arg");
    bindings.execute("var string_arg");
    bindings.execute("var 42 43");

    EXPECT_EQ(stats::functionCalls, 0);
    EXPECT_EQ(stats::trackerConstructions, 0);
    EXPECT_EQ(stats::trackerAssignments, 0);

    bindings.execute("var 42");
    bindings.execute("func_without_args");
    bindings.execute("func_with_arg 42");

    EXPECT_GT(stats::functionCalls, 0);
    EXPECT_GT(stats::trackerConstructions, 0);
    EXPECT_GT(stats::trackerAssignments, 0);
}

TEST(BindingsTests, TestVoidFunctionCall)
{
    coil::Bindings bindings;
    bindings["func"] = []() {};
    auto result = bindings.execute("func");

    EXPECT_EQ(result.errors.size(), 0);
    EXPECT_FALSE(result.returnValue.has_value());
}

TEST(BindingsTests, TestVariableRead)
{
    int variable = 42;

    coil::Bindings bindings;
    bindings["var"] = coil::variable(&variable);
    auto result = bindings.execute("var");

    EXPECT_EQ(result.errors.size(), 0);
    ASSERT_TRUE(result.returnValue.has_value());
    EXPECT_EQ(*result.returnValue, "42");
    EXPECT_EQ(variable, 42);
}

TEST(BindingsTests, TestVariableWrite)
{
    int variable = 42;

    coil::Bindings bindings;
    bindings["var"] = coil::variable(&variable);
    auto result = bindings.execute("var 365");

    EXPECT_EQ(result.errors.size(), 0);
    ASSERT_TRUE(result.returnValue.has_value());
    EXPECT_EQ(*result.returnValue, "365");
    EXPECT_EQ(variable, 365);
}

TEST(BindingsTests, TestReadonlyVariableRead)
{
    int const variable = 42;

    coil::Bindings bindings;
    bindings["var"] = coil::variable(&variable);
    auto result = bindings.execute("var");

    EXPECT_EQ(result.errors.size(), 0);
    ASSERT_TRUE(result.returnValue.has_value());
    EXPECT_EQ(*result.returnValue, "42");
    EXPECT_EQ(variable, 42);
}

TEST(BindingsTests, TestReadonlyVariableWrite)
{
    int const variable = 42;

    coil::Bindings bindings;
    bindings["var"] = coil::variable(&variable);
    auto result = bindings.execute("var 365");

    EXPECT_EQ(result.errors.size(), 1);
    EXPECT_PRED2(containsError, result.errors, "Cannot write to a read-only variable");
    EXPECT_EQ(variable, 42);
}

TEST(BindingsTests, TestOverloaded)
{
    coil::Bindings bindings;

    auto func1 = [](int) { return "func1"; };
    auto func2 = [](int, int) { return "func2"; };
    auto func3 = [](int, int, int) { return "func3"; };
    bindings["func"] = coil::overloaded(std::move(func1), std::move(func2), std::move(func3));

    auto result1 = bindings.execute("func 42");
    auto result2 = bindings.execute("func 42 42");
    auto result3 = bindings.execute("func 42 42 42");

    EXPECT_EQ(result1.errors.size(), 0);
    ASSERT_TRUE(result1.returnValue.has_value());
    EXPECT_EQ(*result1.returnValue, "func1");

    EXPECT_EQ(result2.errors.size(), 0);
    ASSERT_TRUE(result2.returnValue.has_value());
    EXPECT_EQ(*result2.returnValue, "func2");

    EXPECT_EQ(result3.errors.size(), 0);
    ASSERT_TRUE(result3.returnValue.has_value());
    EXPECT_EQ(*result3.returnValue, "func3");
}

TEST(BindingTests, TestOptionalEmpty)
{
    coil::Bindings bindings;
    bindings["func"] = [](std::optional<int> arg) { return arg; };

    auto result = bindings.execute("func ()");

    EXPECT_EQ(result.errors.size(), 0);
    ASSERT_TRUE(result.returnValue.has_value());
    EXPECT_EQ(*result.returnValue, "");
}

TEST(BindingTests, TestOptionalWithValue)
{
    coil::Bindings bindings;
    bindings["func"] = [](std::optional<int> arg) { return arg; };

    auto result = bindings.execute("func 42");

    EXPECT_EQ(result.errors.size(), 0);
    ASSERT_TRUE(result.returnValue.has_value());
    EXPECT_EQ(*result.returnValue, "42");
}

TEST(BindingTests, TestOptionalWithError)
{
    coil::Bindings bindings;
    bindings["func"] = [](std::optional<int> arg) { return arg; };

    auto result = bindings.execute("func foo");

    EXPECT_EQ(result.errors.size(), 1);
    EXPECT_PRED2(containsError, result.errors, "Unable to convert 'foo' to type 'std::optional<int>': Unable to convert 'foo' to type 'int'");
}

TEST(BindingsTests, TestCompoundSyntax)
{
    coil::Bindings bindings;
    bindings["get_compound"] = [](CompoundType const& val) { return val; };

    auto testCompound = [&bindings](std::string_view command, std::string_view expectedResult) {
        auto result = bindings.execute(command);

        EXPECT_EQ(result.errors.size(), 0);
        ASSERT_TRUE(result.returnValue.has_value());
        EXPECT_EQ(*result.returnValue, expectedResult);
    };

    testCompound("get_compound ( 6 , 28 )", "CompoundType{6,28}");
    testCompound("get_compound (6 , 28)", "CompoundType{6,28}");
    testCompound("get_compound (6, 28)", "CompoundType{6,28}");
    testCompound("get_compound (6 28)", "CompoundType{6,28}");
    testCompound("get_compound (6,28)", "CompoundType{6,28}");
    testCompound("get_compound 6,28", "CompoundType{6,28}");
}

TEST(BindingsTests, TestErrorNoFunction)
{
    coil::Bindings bindings;
    auto result = bindings.execute("");

    EXPECT_EQ(result.errors.size(), 1);
    EXPECT_PRED2(containsError, result.errors, "No function name is specified");
}

TEST(BindingsTests, TestErrorUndefinedFunction)
{
    coil::Bindings bindings;
    auto result = bindings.execute("foo");

    EXPECT_EQ(result.errors.size(), 1);
    EXPECT_PRED2(containsError, result.errors, "No function 'foo' is registered");
}

TEST(BindingsTests, TestErrorWrongArgumentsCountWithNonUserArgs)
{
    coil::Bindings bindings;
    bindings["func"] = [](coil::Context, int) {};
    auto result = bindings.execute("func foo bar");

    EXPECT_EQ(result.errors.size(), 1);
    EXPECT_PRED2(containsError, result.errors, "Wrong number of arguments to 'func': expected 1, got 2");
}

TEST(BindingsTests, TestErrorWrongArgumentsCount)
{
    coil::Bindings bindings;
    bindings["func"] = [](int, int) {};
    auto result = bindings.execute("func 1 2 3");

    EXPECT_EQ(result.errors.size(), 1);
    EXPECT_PRED2(containsError, result.errors, "Wrong number of arguments to 'func': expected 2, got 3");
}

TEST(BindingsTests, TestErrorWrongArgumentsCountOverload2)
{
    coil::Bindings bindings;

    auto func1 = [](int) {};
    auto func2 = [](int, int) {};
    bindings["func"] = coil::overloaded(std::move(func1), std::move(func2));

    auto result = bindings.execute("func");

    EXPECT_EQ(result.errors.size(), 1);
    EXPECT_PRED2(containsError, result.errors, "Wrong number of arguments to 'func': expected 1 or 2, got 0");
}

TEST(BindingsTests, TestErrorWrongArgumentsCountOverload3)
{
    coil::Bindings bindings;

    auto func1 = [](int) {};
    auto func2 = [](int, int) {};
    auto func3 = [](int, int, int) {};
    bindings["func"] = coil::overloaded(std::move(func1), std::move(func2), std::move(func3));

    auto result = bindings.execute("func");

    EXPECT_EQ(result.errors.size(), 1);
    EXPECT_PRED2(containsError, result.errors, "Wrong number of arguments to 'func': expected 1, 2 or 3, got 0");
}

TEST(BindingsTests, TestErrorWrongArgumentTypes)
{
    coil::Bindings bindings;
    bindings["func"] = [](int, int) {};
    auto result = bindings.execute("func foo bar");

    EXPECT_EQ(result.errors.size(), 2);
    EXPECT_PRED2(containsError, result.errors, "Unable to convert 'foo' to type 'int'");
    EXPECT_PRED2(containsError, result.errors, "Unable to convert 'bar' to type 'int'");
}

TEST(BindingsTests, TestErrorWrongArgumentTypesVector)
{
    coil::Bindings bindings;
    bindings["sum"] = [](std::vector<int> const&) {};
    auto result = bindings.execute("sum (foo bar baz)");

    EXPECT_EQ(result.errors.size(), 1);
    EXPECT_PRED2(containsError, result.errors, "Unable to convert 'foo bar baz' to type 'std::vector<int>': Unable to convert 'foo' to type 'int'");
}

TEST(BindingsTests, TestErrorWrongArgumentTypesVariable)
{
    int variable = 42;

    coil::Bindings bindings;
    bindings["var"] = coil::variable(&variable);

    auto result = bindings.execute("var foo");

    EXPECT_EQ(result.errors.size(), 1);
    EXPECT_PRED2(containsError, result.errors, "Unable to convert 'foo' to type 'int'");
}

TEST(BindingsTests, TestFunctionReturnValue)
{
    coil::Bindings bindings;
    bindings["sum"] = [](int a, int b) { return a + b; };
    auto result = bindings.execute("sum 8 800");

    EXPECT_EQ(result.errors.size(), 0);
    ASSERT_TRUE(result.returnValue.has_value());
    EXPECT_EQ(*result.returnValue, "808");
}

TEST(BindingsTests, TestOutput)
{
    coil::Bindings bindings;
    bindings["func"] = [](coil::Context context, std::string value) { context.out() << value; };
    auto result = bindings.execute("func Test");

    EXPECT_EQ(result.errors.size(), 0);
    EXPECT_EQ(result.output.str(), "Test");
}

TEST(BindingsTests, TestContextError)
{
    coil::Bindings bindings;
    bindings["func"] = [](coil::Context context, std::string value) { context.reportError("Custom error: " + std::move(value)); };
    auto result = bindings.execute("func Test");

    EXPECT_EQ(result.errors.size(), 1);
    EXPECT_PRED2(containsError, result.errors, "Custom error: Test");
}

TEST(BindingsTests, TestVectorFunctionReturnValue)
{
    coil::Bindings bindings;
    bindings["sum"] = [](std::vector<int> const& values) { return std::accumulate(values.begin(), values.end(), 0); };
    auto result = bindings.execute("sum (1 1 2 3 5 8)");

    EXPECT_EQ(result.errors.size(), 0);
    ASSERT_TRUE(result.returnValue.has_value());
    EXPECT_EQ(*result.returnValue, "20");
}

TEST(BindingsTests, TestUnbind)
{
    coil::Bindings bindings;
    bindings["func1"] = []() {};
    bindings["func2"] = []() {};

    bindings["func1"] = {};

    auto result1 = bindings.execute("func1");
    auto result2 = bindings.execute("func2");

    EXPECT_EQ(result1.errors.size(), 1);
    EXPECT_PRED2(containsError, result1.errors, "No function 'func1' is registered");

    EXPECT_EQ(result2.errors.size(), 0);
}

TEST(BindingsTests, TestClear)
{
    coil::Bindings bindings;
    bindings["func1"] = []() {};
    bindings["func2"] = []() {};

    bindings.clear();

    auto result1 = bindings.execute("func1");
    auto result2 = bindings.execute("func2");

    EXPECT_EQ(result1.errors.size(), 1);
    EXPECT_PRED2(containsError, result1.errors, "No function 'func1' is registered");

    EXPECT_EQ(result2.errors.size(), 1);
    EXPECT_PRED2(containsError, result2.errors, "No function 'func2' is registered");
}

TEST(BindingsTests, TestSyntaxError)
{
    coil::Bindings bindings;

    auto result = bindings.execute("func = arg");

    EXPECT_EQ(result.errors.size(), 1);
    EXPECT_PRED2(containsError, result.errors, "Syntax error: Unexpected token '=': no named for the named argument is provided");
}

TEST(BindingsTests, TestStdException)
{
    coil::Bindings bindings;
    bindings["func"] = []() { throw std::runtime_error("Test runtime exception"); };

    coil::ExecutionResult result;

    EXPECT_NO_THROW({
        result = bindings.execute("func");
    });

    EXPECT_EQ(result.errors.size(), 1);
    EXPECT_PRED2(containsError, result.errors, "Exception caught during execution: Test runtime exception");
}

TEST(BindingsTests, TestNonStdException)
{
    coil::Bindings bindings;
    bindings["func"] = []() { throw 42; };

    coil::ExecutionResult result;

    EXPECT_NO_THROW({
        result = bindings.execute("func");
    });

    EXPECT_EQ(result.errors.size(), 1);
    EXPECT_PRED2(containsError, result.errors, "Exception caught during execution");
}

TEST(BindingsTests, TestAnyArgView)
{
    coil::Bindings bindings;
    bindings["func"] = [](coil::AnyArgView const& value) {
        return *value.get<int>();
    };

    auto result = bindings.execute("func 42");
    EXPECT_EQ(result.returnValue, "42");
}

TEST(BindingsTests, TestNamedArgsGet)
{
    coil::Bindings bindings;
    bindings["func"] = [](coil::Context context) {
        coil::NamedArgs namedArgs = context.namedArgs();

        auto e1 = namedArgs.get<int>("non_existent_arg");
        ASSERT_FALSE(e1);
        EXPECT_EQ(e1.error().type, coil::NamedArgs::Error::Type::MissingKey);
        EXPECT_EQ(e1.error().message, "Missing named argument 'non_existent_arg'");

        auto e2 = namedArgs.get<int>("arg1");
        ASSERT_FALSE(e2);
        EXPECT_EQ(e2.error().type, coil::NamedArgs::Error::Type::TypeMismatch);
        EXPECT_EQ(e2.error().message, "Unable to convert 'str' to type 'int'");

        auto e3 = namedArgs.get<int>("arg2");
        ASSERT_TRUE(e3);
        EXPECT_EQ(*e3, 42);
    };

    auto result = bindings.execute("func arg1 = str arg2 = 42");
}

TEST(BindingsTests, TestNamedArgsGetOrReport)
{
    using namespace std::literals;

    coil::Bindings bindings;
    bindings["func"] = [](coil::Context context) {
        coil::NamedArgs namedArgs = context.namedArgs();

        {
            auto o = namedArgs.getOrReport<int>("arg2", coil::NamedArgs::ArgType::Optional);
            ASSERT_TRUE(o);
            EXPECT_EQ(*o, 42);
            EXPECT_FALSE(context.hasErrors());
        }

        {
            auto o = namedArgs.getOrReport<int>("arg2", coil::NamedArgs::ArgType::Required);
            ASSERT_TRUE(o);
            EXPECT_EQ(*o, 42);
            EXPECT_FALSE(context.hasErrors());
        }

        {
            auto o = namedArgs.getOrReport<int>("non_existent_arg", coil::NamedArgs::ArgType::Optional, 18);
            ASSERT_TRUE(o.has_value());
            EXPECT_EQ(*o, 18);
            EXPECT_FALSE(context.hasErrors());
        }

        {
            auto o = namedArgs.getOrReport("arg1", coil::NamedArgs::ArgType::Required);
            ASSERT_TRUE(o.has_value());
            EXPECT_EQ(o->getRaw().str(), "str"sv);
            EXPECT_FALSE(context.hasErrors());
        }

        {
            auto o = namedArgs.getOrReport("non_existent_arg", coil::NamedArgs::ArgType::Optional);
            ASSERT_FALSE(o.has_value());
            EXPECT_FALSE(context.hasErrors());
        }
    };

    auto result = bindings.execute("func arg1 = str arg2 = 42");
}

TEST(BindingsTests, TestNamedArgsTypedGetOrReportContextErrors)
{
    coil::Bindings bindings;
    bindings["func"] = [](coil::Context context) {
        context.namedArgs().getOrReport<int>("arg", coil::NamedArgs::ArgType::Required, 18);
    };

    {
        auto result = bindings.execute("func");
        EXPECT_EQ(result.errors.size(), 1);
        EXPECT_PRED2(containsError, result.errors, "Missing named argument 'arg'");
    }

    {
        auto result = bindings.execute("func arg = str");
        EXPECT_EQ(result.errors.size(), 1);
        EXPECT_PRED2(containsError, result.errors, "Unable to convert 'str' to type 'int'");
    }
}

TEST(BindingsTests, TestNamedArgsAnyGetOrReportContextErrors)
{
    coil::Bindings bindings;
    bindings["func"] = [](coil::Context context) {
        context.namedArgs().getOrReport("arg", coil::NamedArgs::ArgType::Required);
    };

    {
        auto result = bindings.execute("func");
        EXPECT_EQ(result.errors.size(), 1);
        EXPECT_PRED2(containsError, result.errors, "Missing named argument 'arg'");
    }
}

TEST(BindingsTests, TestNamedArgsSize)
{
    coil::Bindings bindings;
    bindings["func"] = [](coil::Context context) {
        return context.namedArgs().size();
    };

    {
        auto result = bindings.execute("func");
        EXPECT_EQ(result.errors.size(), 0);
        EXPECT_EQ(result.returnValue, "0");
    }

    {
        auto result = bindings.execute("func arg1=foo arg2=bar");
        EXPECT_EQ(result.errors.size(), 0);
        EXPECT_EQ(result.returnValue, "2");
    }
}

TEST(BindingsTests, TestBind)
{
    struct Object
    {
        int get() const { return 42; }
    };

    Object obj;

    coil::Bindings bindings;
    bindings["func"] = coil::bind(&Object::get, &obj);

    auto result = bindings.execute("func");
    EXPECT_EQ(result.errors.size(), 0);
    EXPECT_EQ(result.returnValue, "42");
}

TEST(BindingsTests, TestTypeNames)
{
    using namespace std::literals;

    EXPECT_EQ(coil::TypeName<bool>::name(), "bool"sv);
    EXPECT_EQ(coil::TypeName<char>::name(), "char"sv);
    EXPECT_EQ(coil::TypeName<signed char>::name(), "signed char"sv);
    EXPECT_EQ(coil::TypeName<unsigned char>::name(), "unsigned char"sv);
    EXPECT_EQ(coil::TypeName<short>::name(), "short"sv);
    EXPECT_EQ(coil::TypeName<unsigned short>::name(), "unsigned short"sv);
    EXPECT_EQ(coil::TypeName<int>::name(), "int"sv);
    EXPECT_EQ(coil::TypeName<unsigned int>::name(), "unsigned int"sv);
    EXPECT_EQ(coil::TypeName<long>::name(), "long"sv);
    EXPECT_EQ(coil::TypeName<unsigned long>::name(), "unsigned long"sv);
    EXPECT_EQ(coil::TypeName<long long>::name(), "long long"sv);
    EXPECT_EQ(coil::TypeName<unsigned long long>::name(), "unsigned long long"sv);
    EXPECT_EQ(coil::TypeName<float>::name(), "float"sv);
    EXPECT_EQ(coil::TypeName<double>::name(), "double"sv);
    EXPECT_EQ(coil::TypeName<long double>::name(), "long double"sv);
}

TEST(BindingsTests, TestArgValueToStream)
{
    coil::ArgValue value({ "foo", "bar" });
    std::stringstream ss;
    ss << value;
    EXPECT_EQ(ss.str(), "foo bar");
}
