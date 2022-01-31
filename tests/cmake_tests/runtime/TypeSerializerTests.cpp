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
        static Expected<WithoutDefaultConstructor, std::string> fromString(std::string_view str)
        {
            Expected<int, std::string> innerValue = TypeSerializer<int>::fromString(str);

            if (!innerValue)
                return reportConversionError<WithoutDefaultConstructor>(str, innerValue.error());

            return WithoutDefaultConstructor{ *innerValue };
        }

        static std::string toString(WithoutDefaultConstructor const& value)
        {
            return "WithoutDefaultConstructor{" + std::to_string(value.m_value) + "}";
        }
    };

    template<>
    struct TypeName<WithoutDefaultConstructor>
    {
        static std::string_view name() { return "WithoutDefaultConstructor"; }
    };
}

TEST(TypeSerializerTests, TestIntValidInputFromString)
{
    EXPECT_EQ(coil::TypeSerializer<int>::fromString("42"), 42);
}

TEST(TypeSerializerTests, TestIntInvalidInputFromString)
{
    EXPECT_EQ(coil::TypeSerializer<int>::fromString("42foo"), coil::makeUnexpected("Unable to convert '42foo' to type 'int'"));
}

TEST(TypeSerializerTests, TestIntToString)
{
    EXPECT_EQ(coil::TypeSerializer<int>::toString(42), "42");
}

TEST(TypeSerializerTests, TestBoolValidInputFromString)
{
    EXPECT_EQ(coil::TypeSerializer<bool>::fromString("false"), false);
    EXPECT_EQ(coil::TypeSerializer<bool>::fromString("False"), false);
    EXPECT_EQ(coil::TypeSerializer<bool>::fromString("FALse"), false);
    EXPECT_EQ(coil::TypeSerializer<bool>::fromString("FALSE"), false);
    EXPECT_EQ(coil::TypeSerializer<bool>::fromString("0"), false);

    EXPECT_EQ(coil::TypeSerializer<bool>::fromString("true"), true);
    EXPECT_EQ(coil::TypeSerializer<bool>::fromString("True"), true);
    EXPECT_EQ(coil::TypeSerializer<bool>::fromString("TRue"), true);
    EXPECT_EQ(coil::TypeSerializer<bool>::fromString("TRUE"), true);
    EXPECT_EQ(coil::TypeSerializer<bool>::fromString("1"), true);
}

TEST(TypeSerializerTests, TestBoolInvalidInputFromString)
{
    EXPECT_EQ(coil::TypeSerializer<bool>::fromString("2"), coil::makeUnexpected("Unable to convert '2' to type 'bool'"));
    EXPECT_EQ(coil::TypeSerializer<bool>::fromString("none"), coil::makeUnexpected("Unable to convert 'none' to type 'bool'"));
    EXPECT_EQ(coil::TypeSerializer<bool>::fromString("-1"), coil::makeUnexpected("Unable to convert '-1' to type 'bool'"));
}

TEST(TypeSerializerTests, TestBoolToString)
{
    EXPECT_EQ(coil::TypeSerializer<bool>::toString(true), "true");
    EXPECT_EQ(coil::TypeSerializer<bool>::toString(false), "false");
}

TEST(TypeSerializerTests, TestUserTypeFromStringValid)
{
    EXPECT_EQ(coil::TypeSerializer<WithoutDefaultConstructor>::fromString("42"), WithoutDefaultConstructor{ 42 });
}

TEST(TypeSerializerTests, TestUserTypeFromStringInvalid)
{
    EXPECT_EQ(coil::TypeSerializer<WithoutDefaultConstructor>::fromString("foo"), coil::makeUnexpected("Unable to convert 'foo' to type 'WithoutDefaultConstructor': Unable to convert 'foo' to type 'int'"));
}

TEST(TypeSerializerTests, TestUserTypeToString)
{
    EXPECT_EQ(coil::TypeSerializer<WithoutDefaultConstructor>::toString(WithoutDefaultConstructor{ 42 }), "WithoutDefaultConstructor{42}");
}
