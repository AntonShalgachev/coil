#include "gtest/gtest.h"
#include "Common.h"
#include "coil/Bindings.h"
#include "coil/utils/VariableWrapper.h"

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

    coil::Bindings createBindings()
    {
        coil::Bindings bindings;

        bindings["func"] = &function;
        bindings["ns"]["func"] = &function;

        bindings["sum"] = &sum;
        bindings["ns"]["sum"] = &sum;

        bindings["sum_all"] = &sumAll;

        bindings["sum_all_init"] = &sumAllInit;
        bindings["ns"]["sum_all_init"] = &sumAllInit;

        bindings["func_with_optional"] = &funcWithOptional;
        bindings["ns"]["func_with_optional"] = &funcWithOptional;

        bindings["output"] = &output;
        bindings["ns"]["output"] = &output;

        bindings["var"] = coil::variable(&variable);
        bindings["ns"]["var"] = coil::variable(&variable);

        bindings["tracker_var"] = coil::variable(&trackedVariable);
        bindings["create_tracker"] = &createTracker;
        bindings["use_tracker_by_value"] = &useTrackerByValue;
        bindings["use_tracker_by_ref"] = &useTrackerByRef;

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
        static Expected<Tracker<T>, std::string> fromString(std::string_view str)
        {
            Expected<T, std::string> innerValue = TypeSerializer<T>::fromString(str);
            if (innerValue)
                return Tracker<T>{*innerValue};

            return reportConversionError<Tracker<T>>(str, innerValue.error());
        }

        static std::string toString(Tracker<T> const& value)
        {
            return TypeSerializer<T>::toString(value.m_payload);
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

TEST(BindingsTests, TestErrorWrongArgumentsCountVariadicAtLeast)
{
    coil::Bindings bindings = createBindings();
    auto result = bindings.execute("sum_all_init");

    EXPECT_EQ(result.errors.size(), 1);
    EXPECT_PRED2(containsError, result.errors, "Wrong number of arguments to 'sum_all_init': expected at least 1, got 0");
}

TEST(BindingsTests, TestErrorWrongArgumentsCountVariadicAtLeastWithCategory)
{
    coil::Bindings bindings = createBindings();
    auto result = bindings.execute("ns.sum_all_init");

    EXPECT_EQ(result.errors.size(), 1);
    EXPECT_PRED2(containsError, result.errors, "Wrong number of arguments to 'ns.sum_all_init': expected at least 1, got 0");
}

TEST(BindingsTests, TestErrorWrongArgumentsCountVariadicBetween)
{
    coil::Bindings bindings = createBindings();
    auto result = bindings.execute("func_with_optional");

    EXPECT_EQ(result.errors.size(), 1);
    EXPECT_PRED2(containsError, result.errors, "Wrong number of arguments to 'func_with_optional': expected from 2 to 3, got 0");
}

TEST(BindingsTests, TestErrorWrongArgumentsCountVariadicBetweenWithCategory)
{
    coil::Bindings bindings = createBindings();
    auto result = bindings.execute("ns.func_with_optional");

    EXPECT_EQ(result.errors.size(), 1);
    EXPECT_PRED2(containsError, result.errors, "Wrong number of arguments to 'ns.func_with_optional': expected from 2 to 3, got 0");
}

TEST(BindingsTests, TestErrorWrongArgumentTypes)
{
    coil::Bindings bindings = createBindings();
    auto result = bindings.execute("sum foo bar");

    EXPECT_EQ(result.errors.size(), 2);
    EXPECT_PRED2(containsError, result.errors, "Unable to convert 'foo' to type 'int'");
    EXPECT_PRED2(containsError, result.errors, "Unable to convert 'bar' to type 'int'");
}

TEST(BindingsTests, TestErrorWrongArgumentTypesVariadic)
{
    coil::Bindings bindings = createBindings();
    auto result = bindings.execute("sum_all foo bar baz");

    EXPECT_EQ(result.errors.size(), 3);
    EXPECT_PRED2(containsError, result.errors, "Unable to convert 'foo' to type 'int'");
    EXPECT_PRED2(containsError, result.errors, "Unable to convert 'bar' to type 'int'");
    EXPECT_PRED2(containsError, result.errors, "Unable to convert 'baz' to type 'int'");
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

TEST(BindingsTests, TestVariadicVector)
{
    coil::Bindings bindings = createBindings();
    auto result = bindings.execute("sum_all 1 1 2 3 5 8");

    EXPECT_EQ(result.errors.size(), 0);
    ASSERT_TRUE(result.returnValue.has_value());
    EXPECT_EQ(*result.returnValue, "20");
}

TEST(BindingsTests, TestUnbind)
{
    coil::Bindings bindings = createBindings();
    bindings["func"] = {};
    auto result = bindings.execute("func");

    EXPECT_EQ(result.errors.size(), 1);
    EXPECT_PRED2(containsError, result.errors, "No function 'func' is registered");
}

TEST(BindingsTests, TestUnbindWithCategory)
{
    coil::Bindings bindings = createBindings();
    bindings["ns"]["func"] = {};
    auto result = bindings.execute("ns.func");

    EXPECT_EQ(result.errors.size(), 1);
    EXPECT_PRED2(containsError, result.errors, "No function 'ns.func' is registered");
}
