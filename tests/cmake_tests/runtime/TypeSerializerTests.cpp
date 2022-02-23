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
        static Expected<WithoutDefaultConstructor, std::string> fromString(ArgValue const& str)
        {
            Expected<int, std::string> innerValue = TypeSerializer<int>::fromString(str);

            if (!innerValue)
                return reportConversionError<WithoutDefaultConstructor>(str.value, innerValue.error());

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
    using namespace std::literals;

    EXPECT_EQ(coil::TypeSerializer<int>::fromString("42"sv), 42);
}

TEST(TypeSerializerTests, TestIntInvalidInputFromString)
{
    using namespace std::literals;

    EXPECT_EQ(coil::TypeSerializer<int>::fromString("42foo"sv), coil::makeUnexpected("Unable to convert '42foo' to type 'int'"));
}

TEST(TypeSerializerTests, TestIntToString)
{
    using namespace std::literals;

    EXPECT_EQ(coil::TypeSerializer<int>::toString(42), "42");
}

TEST(TypeSerializerTests, TestBoolValidInputFromString)
{
    using namespace std::literals;

    EXPECT_EQ(coil::TypeSerializer<bool>::fromString("false"sv), false);
    EXPECT_EQ(coil::TypeSerializer<bool>::fromString("False"sv), false);
    EXPECT_EQ(coil::TypeSerializer<bool>::fromString("FALse"sv), false);
    EXPECT_EQ(coil::TypeSerializer<bool>::fromString("FALSE"sv), false);
    EXPECT_EQ(coil::TypeSerializer<bool>::fromString("0"sv), false);

    EXPECT_EQ(coil::TypeSerializer<bool>::fromString("true"sv), true);
    EXPECT_EQ(coil::TypeSerializer<bool>::fromString("True"sv), true);
    EXPECT_EQ(coil::TypeSerializer<bool>::fromString("TRue"sv), true);
    EXPECT_EQ(coil::TypeSerializer<bool>::fromString("TRUE"sv), true);
    EXPECT_EQ(coil::TypeSerializer<bool>::fromString("1"sv), true);
}

TEST(TypeSerializerTests, TestBoolInvalidInputFromString)
{
    using namespace std::literals;

    EXPECT_EQ(coil::TypeSerializer<bool>::fromString("2"sv), coil::makeUnexpected("Unable to convert '2' to type 'bool'"));
    EXPECT_EQ(coil::TypeSerializer<bool>::fromString("none"sv), coil::makeUnexpected("Unable to convert 'none' to type 'bool'"));
    EXPECT_EQ(coil::TypeSerializer<bool>::fromString("-1"sv), coil::makeUnexpected("Unable to convert '-1' to type 'bool'"));
}

TEST(TypeSerializerTests, TestBoolToString)
{
    EXPECT_EQ(coil::TypeSerializer<bool>::toString(true), "true");
    EXPECT_EQ(coil::TypeSerializer<bool>::toString(false), "false");
}

TEST(TypeSerializerTests, TestUserTypeFromStringValid)
{
    using namespace std::literals;

    EXPECT_EQ(coil::TypeSerializer<WithoutDefaultConstructor>::fromString("42"sv), WithoutDefaultConstructor{ 42 });
}

TEST(TypeSerializerTests, TestUserTypeFromStringInvalid)
{
    using namespace std::literals;

    EXPECT_EQ(coil::TypeSerializer<WithoutDefaultConstructor>::fromString("foo"sv), coil::makeUnexpected("Unable to convert 'foo' to type 'WithoutDefaultConstructor': Unable to convert 'foo' to type 'int'"));
}

TEST(TypeSerializerTests, TestUserTypeToString)
{
    using namespace std::literals;

    EXPECT_EQ(coil::TypeSerializer<WithoutDefaultConstructor>::toString(WithoutDefaultConstructor{ 42 }), "WithoutDefaultConstructor{42}");
}
