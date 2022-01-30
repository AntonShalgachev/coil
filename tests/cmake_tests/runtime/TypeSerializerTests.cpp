#include "gtest/gtest.h"
#include "Common.h"
#include "coil/TypeSerializer.h"

namespace
{
    class WithoutDefaultConstructor
    {
    public:
        WithoutDefaultConstructor(int value) : m_value(value) {}

        int m_value = 0;
    };

    bool operator==(WithoutDefaultConstructor const& lhs, WithoutDefaultConstructor const& rhs)
    {
        return lhs.m_value == rhs.m_value;
    }
}

namespace coil
{
    template<>
    struct TypeSerializer<WithoutDefaultConstructor>
    {
        template<typename OnError>
        static WithoutDefaultConstructor fromString(std::string_view str, OnError&& onError)
        {
            int innerValue = TypeSerializer<int>::fromString(str, onError);

            return WithoutDefaultConstructor{ innerValue };
        }

        static std::string toString(WithoutDefaultConstructor const& value)
        {
            return "WithoutDefaultConstructor{" + std::to_string(value.m_value) + "}";
        }
    };
}

TEST(TypeSerializerTests, TestIntValidInputFromString)
{
    std::optional<std::string> error;
    auto onError = [&error](auto value)
    {
        error = std::move(value);
    };

    EXPECT_EQ(coil::TypeSerializer<int>::fromString("42", std::move(onError)), 42);
    EXPECT_FALSE(error.has_value());
}

TEST(TypeSerializerTests, TestIntInvalidInputFromString)
{
    std::optional<std::string> error;
    auto onError = [&error](auto value)
    {
        error = std::move(value);
    };

    EXPECT_EQ(coil::TypeSerializer<int>::fromString("42foo", std::move(onError)), 0);
    EXPECT_TRUE(error.has_value());
    EXPECT_EQ(*error, "Unable to convert '42foo' to type 'int'");
}

TEST(TypeSerializerTests, TestIntToString)
{
    EXPECT_EQ(coil::TypeSerializer<int>::toString(42), "42");
}

TEST(TypeSerializerTests, TestBoolValidInputFromString)
{
    std::optional<std::string> error;
    auto onError = [&error](auto value)
    {
        error = std::move(value);
    };

    EXPECT_EQ(coil::TypeSerializer<bool>::fromString("false", std::move(onError)), false);
    EXPECT_FALSE(error.has_value());
    EXPECT_EQ(coil::TypeSerializer<bool>::fromString("False", std::move(onError)), false);
    EXPECT_FALSE(error.has_value());
    EXPECT_EQ(coil::TypeSerializer<bool>::fromString("FALse", std::move(onError)), false);
    EXPECT_FALSE(error.has_value());
    EXPECT_EQ(coil::TypeSerializer<bool>::fromString("FALSE", std::move(onError)), false);
    EXPECT_FALSE(error.has_value());
    EXPECT_EQ(coil::TypeSerializer<bool>::fromString("0", std::move(onError)), false);
    EXPECT_FALSE(error.has_value());

    EXPECT_EQ(coil::TypeSerializer<bool>::fromString("true", std::move(onError)), true);
    EXPECT_FALSE(error.has_value());
    EXPECT_EQ(coil::TypeSerializer<bool>::fromString("True", std::move(onError)), true);
    EXPECT_FALSE(error.has_value());
    EXPECT_EQ(coil::TypeSerializer<bool>::fromString("TRue", std::move(onError)), true);
    EXPECT_FALSE(error.has_value());
    EXPECT_EQ(coil::TypeSerializer<bool>::fromString("TRUE", std::move(onError)), true);
    EXPECT_FALSE(error.has_value());
    EXPECT_EQ(coil::TypeSerializer<bool>::fromString("1", std::move(onError)), true);
    EXPECT_FALSE(error.has_value());
}

TEST(TypeSerializerTests, TestBoolInvalidInputFromString)
{
    std::optional<std::string> error;
    auto onError = [&error](auto value)
    {
        error = std::move(value);
    };

    EXPECT_EQ(coil::TypeSerializer<bool>::fromString("2", std::move(onError)), false);
    ASSERT_TRUE(error.has_value());
    EXPECT_EQ(*error, "Unable to convert '2' to type 'bool'");
    error = {};

    EXPECT_EQ(coil::TypeSerializer<bool>::fromString("none", std::move(onError)), false);
    ASSERT_TRUE(error.has_value());
    EXPECT_EQ(*error, "Unable to convert 'none' to type 'bool'");
    error = {};

    EXPECT_EQ(coil::TypeSerializer<bool>::fromString("-1", std::move(onError)), false);
    ASSERT_TRUE(error.has_value());
    EXPECT_EQ(*error, "Unable to convert '-1' to type 'bool'");
    error = {};
}

TEST(TypeSerializerTests, TestBoolToString)
{
    EXPECT_EQ(coil::TypeSerializer<bool>::toString(true), "true");
    EXPECT_EQ(coil::TypeSerializer<bool>::toString(false), "false");
}

TEST(TypeSerializerTests, TestUserTypeFromStringValid)
{
    std::optional<std::string> error;
    auto onError = [&error](auto value)
    {
        error = std::move(value);
    };

    EXPECT_EQ(coil::TypeSerializer<WithoutDefaultConstructor>::fromString("42", onError), WithoutDefaultConstructor{ 42 });
}

TEST(TypeSerializerTests, TestUserTypeFromStringInvalid)
{
    std::optional<std::string> error;
    auto onError = [&error](auto value)
    {
        error = std::move(value);
    };

    EXPECT_EQ(coil::TypeSerializer<WithoutDefaultConstructor>::fromString("foo", onError), WithoutDefaultConstructor{ 0 });
    EXPECT_TRUE(error.has_value());
    EXPECT_EQ(*error, "Unable to convert 'foo' to type 'WithoutDefaultConstructor'");
}

TEST(TypeSerializerTests, TestUserTypeToString)
{
    EXPECT_EQ(coil::TypeSerializer<WithoutDefaultConstructor>::toString(WithoutDefaultConstructor{ 42 }), "WithoutDefaultConstructor{42}");
}
