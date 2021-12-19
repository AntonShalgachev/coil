#include "gtest/gtest.h"
#include "coil/Bindings.h"

namespace stats
{
    std::size_t functionCalls = 0;
    std::size_t methodCalls = 0;

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
        methodCalls = 0;

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

    struct Object
    {
        Object(int value = 0) : value(value) {}

        void method()
        {
            stats::methodCalls++;
        }

        int getDouble() const
        {
            return value * 2;
        }

        int value = 0;
    };

    Object object0;
    Object object42{ 42 };

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

    Tracker<int> trackedVariable;

    Tracker<int> createTracker() { return 42; }
    void useTrackerByValue(Tracker<int>) {}
    void useTrackerByRef(Tracker<int> const&) {}

    coil::Bindings createBindings()
    {
        coil::Bindings bindings;

        bindings.bind("func", &function);
        bindings.bind("sum", &sum);
        bindings.bind("sum_all", &sumAll);
        bindings.bind("sum_all_init", &sumAllInit);
        bindings.bind("func_with_optional", &funcWithOptional);
        bindings.bind("output", &output);
        bindings.bind("var", &trackedVariable);
        bindings.bind("create_tracker", &createTracker);
        bindings.bind("use_tracker_by_value", &useTrackerByValue);
        bindings.bind("use_tracker_by_ref", &useTrackerByRef);

        bindings.bind<Object>("method", &Object::method);
        bindings.bind<Object>("get_double", &Object::getDouble);
        bindings.bind<Object>("get_double_explicit", [](Object const* obj)
        {
            return obj->getDouble();
        });

        bindings.addObject("obj", &object0);
        bindings.addObject("obj42", &object42);

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
        template<typename OnError>
        static Tracker<T> fromString(std::string_view str, OnError&& onError)
        {
            return TypeSerializer<T>::fromString(str, std::forward<OnError>(onError));
        }

        static std::string toString(Tracker<T> const& value)
        {
            return TypeSerializer<T>::toString(value.m_payload);
        }
    };
}

TEST(BindingsTests, TestVoidFunctionCallStats)
{
    stats::reset();

    coil::Bindings bindings = createBindings();
    bindings.execute("func");

    EXPECT_EQ(stats::functionCalls, 1);
    EXPECT_EQ(stats::methodCalls, 0);
    EXPECT_EQ(stats::trackerAssignments, 0);
    EXPECT_EQ(stats::trackerConstructions, 0);
}

TEST(BindingsTests, TestVoidMethodCallStats)
{
    stats::reset();

    coil::Bindings bindings = createBindings();
    bindings.execute("obj.method");

    EXPECT_EQ(stats::functionCalls, 0);
    EXPECT_EQ(stats::methodCalls, 1);
    EXPECT_EQ(stats::trackerAssignments, 0);
    EXPECT_EQ(stats::trackerConstructions, 0);
}

TEST(BindingsTests, TestVariableAssignmentStats)
{
    stats::reset();

    coil::Bindings bindings = createBindings();
    bindings.execute("var 42");

    EXPECT_EQ(stats::functionCalls, 0);
    EXPECT_EQ(stats::methodCalls, 0);
    EXPECT_EQ(stats::trackerValueConstructions, 1);
    EXPECT_EQ(stats::trackerCopyConstructions, 0);
    EXPECT_EQ(stats::trackerCopyAssignments, 0);
}

TEST(BindingsTests, TestPassingArgumentByValueStats)
{
    stats::reset();

    coil::Bindings bindings = createBindings();
    bindings.execute("use_tracker_by_value 42");

    EXPECT_EQ(stats::trackerValueConstructions, 1);
    EXPECT_EQ(stats::trackerCopyConstructions, 0);
    EXPECT_EQ(stats::trackerCopyAssignments, 0);
}

TEST(BindingsTests, TestPassingArgumentByRefStats)
{
    stats::reset();

    coil::Bindings bindings = createBindings();
    bindings.execute("use_tracker_by_ref 42");

    EXPECT_EQ(stats::trackerValueConstructions, 1);
    EXPECT_EQ(stats::trackerCopyConstructions, 0);
    EXPECT_EQ(stats::trackerCopyAssignments, 0);
}

TEST(BindingsTests, TestReturnByValueStats)
{
    stats::reset();

    coil::Bindings bindings = createBindings();
    bindings.execute("create_tracker");

    EXPECT_EQ(stats::trackerValueConstructions, 1);
    EXPECT_EQ(stats::trackerCopyConstructions, 0);
    EXPECT_EQ(stats::trackerCopyAssignments, 0);
}

TEST(BindingsTests, TestErrorStats)
{
    stats::reset();

    coil::Bindings bindings = createBindings();
    bindings.execute("foo");
    bindings.execute("obj.foo");
    bindings.execute("foo.method");
    bindings.execute("foo_var 42");

    EXPECT_EQ(stats::functionCalls, 0);
    EXPECT_EQ(stats::methodCalls, 0);
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

TEST(BindingsTests, TestVoidMethodCall)
{
    coil::Bindings bindings = createBindings();
    auto result = bindings.execute("obj.method");

    EXPECT_EQ(result.errors.size(), 0);
    EXPECT_FALSE(result.returnValue.has_value());
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

TEST(BindingsTests, TestErrorUndefinedMethod)
{
    coil::Bindings bindings = createBindings();
    auto result = bindings.execute("obj.foo");

    EXPECT_EQ(result.errors.size(), 1);
    EXPECT_PRED2(containsError, result.errors, "No function 'foo' is registered for type 'unknown'");
}

TEST(BindingsTests, TestErrorUndefinedObject)
{
    coil::Bindings bindings = createBindings();
    auto result = bindings.execute("foo.method");

    EXPECT_EQ(result.errors.size(), 1);
    EXPECT_PRED2(containsError, result.errors, "Object 'foo' is not registered");
}

TEST(BindingsTests, TestErrorWrongArgumentsCount)
{
    coil::Bindings bindings = createBindings();
    auto result = bindings.execute("sum 1 2 3");

    EXPECT_EQ(result.errors.size(), 1);
    EXPECT_PRED2(containsError, result.errors, "Wrong number of arguments to 'sum': expected 2, got 3");
}

TEST(BindingsTests, TestErrorWrongArgumentsCountVariadicAtLeast)
{
    coil::Bindings bindings = createBindings();
    auto result = bindings.execute("sum_all_init");

    EXPECT_EQ(result.errors.size(), 1);
    EXPECT_PRED2(containsError, result.errors, "Wrong number of arguments to 'sum_all_init': expected at least 1, got 0");
}

TEST(BindingsTests, TestErrorWrongArgumentsCountVariadicBetween)
{
    coil::Bindings bindings = createBindings();
    auto result = bindings.execute("func_with_optional");

    EXPECT_EQ(result.errors.size(), 1);
    EXPECT_PRED2(containsError, result.errors, "Wrong number of arguments to 'func_with_optional': expected from 2 to 3, got 0");
}

TEST(BindingsTests, TestErrorWrongArgumentTypes)
{
    coil::Bindings bindings = createBindings();
    auto result = bindings.execute("sum foo bar");

    EXPECT_EQ(result.errors.size(), 2);
    EXPECT_PRED2(containsError, result.errors, "Unable to convert 'foo' to type 'unknown'");
    EXPECT_PRED2(containsError, result.errors, "Unable to convert 'bar' to type 'unknown'");
}

TEST(BindingsTests, TestErrorWrongArgumentTypesVariadic)
{
    coil::Bindings bindings = createBindings();
    auto result = bindings.execute("sum_all foo bar baz");

    EXPECT_EQ(result.errors.size(), 3);
    EXPECT_PRED2(containsError, result.errors, "Unable to convert 'foo' to type 'unknown'");
    EXPECT_PRED2(containsError, result.errors, "Unable to convert 'bar' to type 'unknown'");
    EXPECT_PRED2(containsError, result.errors, "Unable to convert 'baz' to type 'unknown'");
}

TEST(BindingsTests, TestFunctionReturnValue)
{
    coil::Bindings bindings = createBindings();
    auto result = bindings.execute("sum 8 800");

    EXPECT_EQ(result.errors.size(), 0);
    ASSERT_TRUE(result.returnValue.has_value());
    EXPECT_EQ(*result.returnValue, "808");
}

TEST(BindingsTests, TestMethodReturnValue)
{
    coil::Bindings bindings = createBindings();
    auto result = bindings.execute("obj.get_double");

    EXPECT_EQ(result.errors.size(), 0);
    ASSERT_TRUE(result.returnValue.has_value());
    EXPECT_EQ(*result.returnValue, "0");
}

TEST(BindingsTests, TestMethodWithExplicitTargetReturnValue)
{
    coil::Bindings bindings = createBindings();
    auto result = bindings.execute("obj42.get_double_explicit");

    EXPECT_EQ(result.errors.size(), 0);
    ASSERT_TRUE(result.returnValue.has_value());
    EXPECT_EQ(*result.returnValue, "84");
}

TEST(BindingsTests, TestTwoObjects)
{
    coil::Bindings bindings = createBindings();
    auto result1 = bindings.execute("obj.get_double");
    auto result2 = bindings.execute("obj42.get_double");

    EXPECT_EQ(result1.errors.size(), 0);
    EXPECT_EQ(result2.errors.size(), 0);

    ASSERT_TRUE(result1.returnValue.has_value());
    ASSERT_TRUE(result2.returnValue.has_value());

    EXPECT_EQ(*result1.returnValue, "0");
    EXPECT_EQ(*result2.returnValue, "84");
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
