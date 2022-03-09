#include "gtest/gtest.h"
#include "Common.h"
#include "coil/Bindings.h"
#include "coil/Variable.h"

#include <stdexcept>

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
    void function()
    {
        stats::functionCalls++;
    }

    int sum(int a, int b)
    {
        return a + b;
    }

    int sumAllInit(int init, std::vector<int> const& values)
    {
        int result = init;
        for (auto const& value : values)
            result += value;
        return result;
    }

    int sumAll(std::vector<int> const& values)
    {
        return sumAllInit(0, values);
    }

    void funcWithOptional(int, float, std::optional<float>)
    {

    }

    void output(coil::Context context, std::string value)
    {
        context.out() << value;
    }

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

    int variable = 42;
    Tracker<int> trackedVariable;

    Tracker<int> createTracker() { return 42; }
    void useTrackerByValue(Tracker<int>) {}
    void useTrackerByRef(Tracker<int> const&) {}

    struct CompoundType
    {
        int field1{};
        int field2{};

        bool operator==(CompoundType const& rhs) const
        {
            return field1 == rhs.field1 && field2 == rhs.field2;
        }
    };

    CompoundType getCompound(CompoundType const& val)
    {
        return val;
    }

    void throwStdException()
    {
        throw std::runtime_error("Test runtime exception");
    }

    void throwNonStdException()
    {
        throw 42;
    }

    coil::Bindings createBindings()
    {
        coil::Bindings bindings;

        // TODO review

        bindings["func"] = &function;
        bindings["ns.func"] = &function;

        bindings["sum"] = &sum;
        bindings["ns.sum"] = &sum;

        bindings["sum_all"] = &sumAll;

        bindings["sum_all_init"] = &sumAllInit;
        bindings["ns.sum_all_init"] = &sumAllInit;

        bindings["func_with_optional"] = &funcWithOptional;
        bindings["ns.func_with_optional"] = &funcWithOptional;

        bindings["output"] = &output;
        bindings["ns.output"] = &output;

        bindings["var"] = coil::variable(&variable);
        bindings["ns.var"] = coil::variable(&variable);

        bindings["tracker_var"] = coil::variable(&trackedVariable);
        bindings["create_tracker"] = &createTracker;
        bindings["use_tracker_by_value"] = &useTrackerByValue;
        bindings["use_tracker_by_ref"] = &useTrackerByRef;

        bindings["get_compound"] = &getCompound;

        bindings["throw_std_exception"] = &throwStdException;
        bindings["throw_non_std_exception"] = &throwNonStdException;

        return bindings;
    }

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

            return makeSerializationError<Tracker<T>>(input, innerValue.error());
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
                return makeSerializationError<CompoundType>(input, 2);

            auto field1 = TypeSerializer<int>::fromString(input.subvalues[0]);
            auto field2 = TypeSerializer<int>::fromString(input.subvalues[1]);

            if (!field1)
                return makeSerializationError<CompoundType>(input, field1.error());
            if (!field2)
                return makeSerializationError<CompoundType>(input, field2.error());

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

    coil::Bindings bindings = createBindings();
    auto result = bindings.execute("func");

    EXPECT_EQ(result.errors.size(), 0);

    EXPECT_EQ(stats::functionCalls, 1);
    EXPECT_EQ(stats::trackerAssignments, 0);
    EXPECT_EQ(stats::trackerConstructions, 0);
}

TEST(BindingsTests, TestVoidFunctionWithCategoryCallStats)
{
    stats::reset();

    coil::Bindings bindings = createBindings();
    auto result = bindings.execute("ns.func");

    EXPECT_EQ(result.errors.size(), 0);

    EXPECT_EQ(stats::functionCalls, 1);
    EXPECT_EQ(stats::trackerAssignments, 0);
    EXPECT_EQ(stats::trackerConstructions, 0);
}

TEST(BindingsTests, TestVariableAssignmentStats)
{
    stats::reset();

    coil::Bindings bindings = createBindings();
    auto result = bindings.execute("tracker_var 42");

    EXPECT_EQ(result.errors.size(), 0);

    EXPECT_EQ(stats::functionCalls, 0);
    EXPECT_EQ(stats::trackerValueConstructions, 1);
    EXPECT_EQ(stats::trackerCopyConstructions, 0);
    EXPECT_EQ(stats::trackerCopyAssignments, 0);
}

TEST(BindingsTests, TestPassingArgumentByValueStats)
{
    stats::reset();

    coil::Bindings bindings = createBindings();
    auto result = bindings.execute("use_tracker_by_value 42");

    EXPECT_EQ(result.errors.size(), 0);

    EXPECT_EQ(stats::trackerValueConstructions, 1);
    EXPECT_EQ(stats::trackerCopyConstructions, 0);
    EXPECT_EQ(stats::trackerCopyAssignments, 0);
}

TEST(BindingsTests, TestPassingArgumentByRefStats)
{
    stats::reset();

    coil::Bindings bindings = createBindings();
    auto result = bindings.execute("use_tracker_by_ref 42");

    EXPECT_EQ(result.errors.size(), 0);

    EXPECT_EQ(stats::trackerValueConstructions, 1);
    EXPECT_EQ(stats::trackerCopyConstructions, 0);
    EXPECT_EQ(stats::trackerCopyAssignments, 0);
}

TEST(BindingsTests, TestReturnByValueStats)
{
    stats::reset();

    coil::Bindings bindings = createBindings();
    auto result = bindings.execute("create_tracker");

    EXPECT_EQ(result.errors.size(), 0);

    EXPECT_EQ(stats::trackerValueConstructions, 1);
    EXPECT_EQ(stats::trackerCopyConstructions, 0);
    EXPECT_EQ(stats::trackerCopyAssignments, 0);
}

TEST(BindingsTests, TestErrorStats)
{
    stats::reset();

    coil::Bindings bindings = createBindings();
    bindings.execute("foo");
    bindings.execute("baz.foo.sum");
    bindings.execute("foo_var 42");

    EXPECT_EQ(stats::functionCalls, 0);
    EXPECT_EQ(stats::trackerConstructions, 0);
    EXPECT_EQ(stats::trackerAssignments, 0);
}

TEST(BindingsTests, TestVoidFunctionCall)
{
    coil::Bindings bindings = createBindings();
    auto result = bindings.execute("func");

    EXPECT_EQ(result.errors.size(), 0);
    EXPECT_FALSE(result.returnValue.has_value());
}

TEST(BindingsTests, TestVoidFunctionCallWithCategory)
{
    coil::Bindings bindings = createBindings();
    auto result = bindings.execute("ns.func");

    EXPECT_EQ(result.errors.size(), 0);
    EXPECT_FALSE(result.returnValue.has_value());
}

TEST(BindingsTests, TestVariableRead)
{
    variable = 42;

    coil::Bindings bindings = createBindings();
    auto result = bindings.execute("var");

    EXPECT_EQ(result.errors.size(), 0);
    ASSERT_TRUE(result.returnValue.has_value());
    EXPECT_EQ(*result.returnValue, "42");
    EXPECT_EQ(variable, 42);
}

TEST(BindingsTests, TestVariableWrite)
{
    variable = 42;

    coil::Bindings bindings = createBindings();
    auto result = bindings.execute("var 365");

    EXPECT_EQ(result.errors.size(), 0);
    ASSERT_TRUE(result.returnValue.has_value());
    EXPECT_EQ(*result.returnValue, "365");
    EXPECT_EQ(variable, 365);
}

TEST(BindingsTests, TestVariableReadWithCategory)
{
    variable = 42;

    coil::Bindings bindings = createBindings();
    auto result = bindings.execute("ns.var");

    EXPECT_EQ(result.errors.size(), 0);
    ASSERT_TRUE(result.returnValue.has_value());
    EXPECT_EQ(*result.returnValue, "42");
    EXPECT_EQ(variable, 42);
}

TEST(BindingsTests, TestVariableWriteWithCategory)
{
    variable = 42;

    coil::Bindings bindings = createBindings();
    auto result = bindings.execute("ns.var 365");

    EXPECT_EQ(result.errors.size(), 0);
    ASSERT_TRUE(result.returnValue.has_value());
    EXPECT_EQ(*result.returnValue, "365");
    EXPECT_EQ(variable, 365);
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

TEST(BindingsTests, TestCompoundSyntax)
{
    coil::Bindings bindings = createBindings();

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
    coil::Bindings bindings = createBindings();
    auto result = bindings.execute("");

    EXPECT_EQ(result.errors.size(), 1);
    EXPECT_PRED2(containsError, result.errors, "No function name is specified");
}

TEST(BindingsTests, TestErrorUndefinedFunction)
{
    coil::Bindings bindings = createBindings();
    auto result = bindings.execute("foo");

    EXPECT_EQ(result.errors.size(), 1);
    EXPECT_PRED2(containsError, result.errors, "No function 'foo' is registered");
}

TEST(BindingsTests, TestErrorUndefinedFunctionWithCategory)
{
    coil::Bindings bindings = createBindings();
    auto result = bindings.execute("ns.foo");

    EXPECT_EQ(result.errors.size(), 1);
    EXPECT_PRED2(containsError, result.errors, "No function 'ns.foo' is registered");
}

TEST(BindingsTests, TestErrorWrongArgumentsCountWithNonUserArgs)
{
    coil::Bindings bindings = createBindings();
    auto result = bindings.execute("output foo bar");

    EXPECT_EQ(result.errors.size(), 1);
    EXPECT_PRED2(containsError, result.errors, "Wrong number of arguments to 'output': expected 1, got 2");
}

TEST(BindingsTests, TestErrorWrongArgumentsCountWithNonUserArgsWithCategory)
{
    coil::Bindings bindings = createBindings();
    auto result = bindings.execute("ns.output foo bar");

    EXPECT_EQ(result.errors.size(), 1);
    EXPECT_PRED2(containsError, result.errors, "Wrong number of arguments to 'ns.output': expected 1, got 2");
}

TEST(BindingsTests, TestErrorWrongArgumentsCount)
{
    coil::Bindings bindings = createBindings();
    auto result = bindings.execute("sum 1 2 3");

    EXPECT_EQ(result.errors.size(), 1);
    EXPECT_PRED2(containsError, result.errors, "Wrong number of arguments to 'sum': expected 2, got 3");
}

TEST(BindingsTests, TestErrorWrongArgumentsCountWithCategory)
{
    coil::Bindings bindings = createBindings();
    auto result = bindings.execute("ns.sum 1 2 3");

    EXPECT_EQ(result.errors.size(), 1);
    EXPECT_PRED2(containsError, result.errors, "Wrong number of arguments to 'ns.sum': expected 2, got 3");
}

// TODO it's not variadic anymore
TEST(BindingsTests, TestErrorWrongArgumentsCountVariadicAtLeast)
{
    coil::Bindings bindings = createBindings();
    auto result = bindings.execute("sum_all_init");

    EXPECT_EQ(result.errors.size(), 1);
    EXPECT_PRED2(containsError, result.errors, "Wrong number of arguments to 'sum_all_init': expected 2, got 0");
}

// TODO it's not variadic anymore
TEST(BindingsTests, TestErrorWrongArgumentsCountVariadicAtLeastWithCategory)
{
    coil::Bindings bindings = createBindings();
    auto result = bindings.execute("ns.sum_all_init");

    EXPECT_EQ(result.errors.size(), 1);
    EXPECT_PRED2(containsError, result.errors, "Wrong number of arguments to 'ns.sum_all_init': expected 2, got 0");
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
    coil::Bindings bindings = createBindings();
    auto result = bindings.execute("sum foo bar");

    EXPECT_EQ(result.errors.size(), 2);
    EXPECT_PRED2(containsError, result.errors, "Unable to convert 'foo' to type 'int'");
    EXPECT_PRED2(containsError, result.errors, "Unable to convert 'bar' to type 'int'");
}

// TODO it's not variadic anymore
TEST(BindingsTests, TestErrorWrongArgumentTypesVariadic)
{
    coil::Bindings bindings = createBindings();
    auto result = bindings.execute("sum_all (foo bar baz)");

    EXPECT_EQ(result.errors.size(), 1);
    EXPECT_PRED2(containsError, result.errors, "Unable to convert 'foo' to type 'int'");
}

TEST(BindingsTests, TestErrorWrongArgumentTypesVariable)
{
    coil::Bindings bindings = createBindings();
    auto result = bindings.execute("tracker_var foo");

    EXPECT_EQ(result.errors.size(), 1);
    EXPECT_PRED2(containsError, result.errors, "Unable to convert 'foo' to type 'Tracker<int>': Unable to convert 'foo' to type 'int'");
}

TEST(BindingsTests, TestFunctionReturnValue)
{
    coil::Bindings bindings = createBindings();
    auto result = bindings.execute("sum 8 800");

    EXPECT_EQ(result.errors.size(), 0);
    ASSERT_TRUE(result.returnValue.has_value());
    EXPECT_EQ(*result.returnValue, "808");
}

TEST(BindingsTests, TestOutput)
{
    coil::Bindings bindings = createBindings();
    auto result = bindings.execute("output Test");

    EXPECT_EQ(result.errors.size(), 0);
    EXPECT_EQ(result.output.str(), "Test");
}

TEST(BindingsTests, TestVector)
{
    coil::Bindings bindings = createBindings();
    auto result = bindings.execute("sum_all (1 1 2 3 5 8)");

    EXPECT_EQ(result.errors.size(), 0);
    ASSERT_TRUE(result.returnValue.has_value());
    EXPECT_EQ(*result.returnValue, "20");
}

TEST(BindingsTests, TestUnbind)
{
    coil::Bindings bindings = createBindings();
    bindings["func"] = {};
    auto result1 = bindings.execute("func");
    auto result2 = bindings.execute("ns.func");

    EXPECT_EQ(result1.errors.size(), 1);
    EXPECT_PRED2(containsError, result1.errors, "No function 'func' is registered");

    EXPECT_EQ(result2.errors.size(), 0);
}

TEST(BindingsTests, TestUnbindWithCategory)
{
    coil::Bindings bindings = createBindings();
    bindings["ns.func"] = {};
    auto result1 = bindings.execute("func");
    auto result2 = bindings.execute("ns.func");

    EXPECT_EQ(result1.errors.size(), 0);

    EXPECT_EQ(result2.errors.size(), 1);
    EXPECT_PRED2(containsError, result2.errors, "No function 'ns.func' is registered");
}

TEST(BindingsTests, TestClear)
{
    coil::Bindings bindings = createBindings();
    bindings.clear();
    auto result1 = bindings.execute("func");
    auto result2 = bindings.execute("ns.func");

    EXPECT_EQ(result1.errors.size(), 1);
    EXPECT_PRED2(containsError, result1.errors, "No function 'func' is registered");

    EXPECT_EQ(result2.errors.size(), 1);
    EXPECT_PRED2(containsError, result2.errors, "No function 'ns.func' is registered");
}

TEST(BindingsTests, TestSyntaxError)
{
    coil::Bindings bindings = createBindings();

    auto result = bindings.execute("func = arg");

    EXPECT_EQ(result.errors.size(), 1);
    EXPECT_PRED2(containsError, result.errors, "Syntax error: Unexpected token '=': no named for the named argument is provided");
}

TEST(BindingsTests, TestStdException)
{
    coil::Bindings bindings = createBindings();

    coil::ExecutionResult result;

    EXPECT_NO_THROW({
        result = bindings.execute("throw_std_exception");
    });

    EXPECT_EQ(result.errors.size(), 1);
    EXPECT_PRED2(containsError, result.errors, "Exception caught during execution: Test runtime exception");
}

TEST(BindingsTests, TestNonStdException)
{
    coil::Bindings bindings = createBindings();

    coil::ExecutionResult result;

    EXPECT_NO_THROW({
        result = bindings.execute("throw_non_std_exception");
    });

    EXPECT_EQ(result.errors.size(), 1);
    EXPECT_PRED2(containsError, result.errors, "Exception caught during execution");
}
