#include "Common.h"

#include "gtest/gtest.h"

namespace
{
    auto createProperty(int& variable)
    {
        auto get = [&variable]() { return variable; };
        auto set = [&variable](int value) { variable = value; };

        return coil::property(get, set);
    }

    struct Object
    {
        Object(int value) : m_field(value) {}

        int get() const
        {
            return m_field;
        }
        void set(int value)
        {
            m_field = value;
        }

    private:
        int m_field;
    };
}

TEST(PropertyTests, TestValidGet)
{
    int variable = 17;

    coil::Bindings bindings;
    bindings["func"] = createProperty(variable);

    auto result = bindings.execute("func");
    EXPECT_EQ(result.errors.size(), 0);

    ASSERT_TRUE(result.returnValue);
    EXPECT_EQ(*result.returnValue, "17");
    EXPECT_EQ(variable, 17);
}

TEST(PropertyTests, TestValidSet)
{
    int variable = 17;

    coil::Bindings bindings;
    bindings["func"] = createProperty(variable);

    auto result = bindings.execute("func 42");
    EXPECT_EQ(result.errors.size(), 0);

    ASSERT_TRUE(result.returnValue);
    EXPECT_EQ(*result.returnValue, "42");
    EXPECT_EQ(variable, 42);
}

TEST(PropertyTests, TestWrongArguments)
{
    int variable = 17;

    coil::Bindings bindings;
    bindings["func"] = createProperty(variable);

    auto result = bindings.execute("func 1 2");
    EXPECT_EQ(result.errors.size(), 1);
    EXPECT_PRED2(containsError, result.errors, "Wrong number of arguments to 'func': expected 0 or 1, got 2");
    EXPECT_EQ(variable, 17);
}

TEST(PropertyTests, TestValidGetOnObject)
{
    Object object = 17;

    coil::Bindings bindings;
    bindings["func"] = coil::property(&Object::get, &Object::set, &object);

    auto result = bindings.execute("func");
    EXPECT_EQ(result.errors.size(), 0);

    ASSERT_TRUE(result.returnValue);
    EXPECT_EQ(*result.returnValue, "17");
    EXPECT_EQ(object.get(), 17);
}

TEST(PropertyTests, TestValidSetOnObject)
{
    Object object = 17;

    coil::Bindings bindings;
    bindings["func"] = coil::property(&Object::get, &Object::set, &object);

    auto result = bindings.execute("func 42");
    EXPECT_EQ(result.errors.size(), 0);

    ASSERT_TRUE(result.returnValue);
    EXPECT_EQ(*result.returnValue, "42");
    EXPECT_EQ(object.get(), 42);
}

TEST(PropertyTests, TestWrongArgumentsOnObject)
{
    Object object = 17;

    coil::Bindings bindings;
    bindings["func"] = coil::property(&Object::get, &Object::set, &object);

    auto result = bindings.execute("func 1 2");
    EXPECT_EQ(result.errors.size(), 1);
    EXPECT_PRED2(containsError, result.errors, "Wrong number of arguments to 'func': expected 0 or 1, got 2");
    EXPECT_EQ(object.get(), 17);
}
