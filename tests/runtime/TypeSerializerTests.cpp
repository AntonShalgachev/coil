#include "Common.h"

#include "gtest/gtest.h"

namespace
{
    struct WithoutDefaultConstructor
    {
        WithoutDefaultConstructor(int value) : value(value) {}

        bool operator==(WithoutDefaultConstructor const& rhs) const
        {
            return value == rhs.value;
        }

        int value = 0;
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

    std::ostream& operator<<(std::ostream& os, WithoutDefaultConstructor const& value)
    {
        return os << "WithoutDefaultConstructor{" << value.value << "}";
    }

    std::ostream& operator<<(std::ostream& os, CompoundType const& value)
    {
        return os << "CompoundType{" << value.field1 << ',' << value.field2 << '}';
    }
}

namespace coil
{
    template<>
    struct TypeSerializer<WithoutDefaultConstructor>
    {
        static Expected<WithoutDefaultConstructor, std::string> fromString(ArgValue const& input)
        {
            auto innerValue = TypeSerializer<int>::fromString(input);

            if (!innerValue)
                return errors::serializationError<WithoutDefaultConstructor>(input, innerValue.error());

            return WithoutDefaultConstructor{*innerValue};
        }

        static std::string toString(WithoutDefaultConstructor const& value)
        {
            return "WithoutDefaultConstructor{" + std::to_string(value.value) + "}";
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

            return CompoundType{*field1, *field2};
        }

        static std::string toString(CompoundType const& value)
        {
            std::stringstream ss;
            ss << "CompoundType{" << value.field1 << ',' << value.field2 << '}';
            return ss.str();
        }
    };

    template<>
    struct TypeName<WithoutDefaultConstructor>
    {
        static std::string_view name()
        {
            return "WithoutDefaultConstructor";
        }
    };

    template<>
    struct TypeName<CompoundType>
    {
        static std::string_view name()
        {
            return "CompoundType";
        }
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

    EXPECT_EQ(coil::TypeSerializer<int>::fromString({{"foo", "bar"}}), coil::makeUnexpected("Unable to convert 'foo bar' to type 'int': Expected 1 subvalues, got 2"));
    EXPECT_EQ(coil::TypeSerializer<int>::fromString("42foo"sv), coil::makeUnexpected("Unable to convert '42foo' to type 'int'"));
}

TEST(TypeSerializerTests, TestIntToString)
{
    using namespace std::literals;

    int value = 42;
    EXPECT_EQ(coil::TypeSerializer<int>::toString(value), "42");
    EXPECT_EQ(coil::TypeSerializer<int*>::toString(&value), "42");
    EXPECT_EQ(coil::TypeSerializer<int*>::toString(nullptr), "null");
    EXPECT_EQ(coil::TypeSerializer<int const*>::toString(&value), "42");
    EXPECT_EQ(coil::TypeSerializer<int const*>::toString(nullptr), "null");
}

TEST(TypeSerializerTests, TestOutOfRangeInputFromString)
{
    using namespace std::literals;

    EXPECT_EQ(coil::TypeSerializer<short>::fromString("99999999999"sv), coil::makeUnexpected("Unable to convert '99999999999' to type 'short': the value can't be represented in this type"));
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

    EXPECT_EQ(coil::TypeSerializer<bool>::fromString({{"foo", "bar"}}), coil::makeUnexpected("Unable to convert 'foo bar' to type 'bool': Expected 1 subvalues, got 2"));

    EXPECT_EQ(coil::TypeSerializer<bool>::fromString("2"sv), coil::makeUnexpected("Unable to convert '2' to type 'bool'"));
    EXPECT_EQ(coil::TypeSerializer<bool>::fromString("none"sv), coil::makeUnexpected("Unable to convert 'none' to type 'bool'"));
    EXPECT_EQ(coil::TypeSerializer<bool>::fromString("-1"sv), coil::makeUnexpected("Unable to convert '-1' to type 'bool'"));
}

TEST(TypeSerializerTests, TestBoolToString)
{
    EXPECT_EQ(coil::TypeSerializer<bool>::toString(true), "true");
    EXPECT_EQ(coil::TypeSerializer<bool>::toString(false), "false");
}

TEST(TypeSerializerTests, TestStringTypesValidInputFromString)
{
    using namespace std::literals;

    EXPECT_EQ(coil::TypeSerializer<std::string_view>::fromString("foo"sv), "foo");
    EXPECT_EQ(coil::TypeSerializer<std::string>::fromString("foo"sv), "foo");
}

TEST(TypeSerializerTests, TestStringTypesInvalidInputFromString)
{
    using namespace std::literals;

    EXPECT_EQ(coil::TypeSerializer<std::string>::fromString({{"foo", "bar"}}), coil::makeUnexpected("Unable to convert 'foo bar' to type 'std::string': Expected 1 subvalues, got 2"));
    EXPECT_EQ(coil::TypeSerializer<std::string_view>::fromString({{"foo", "bar"}}), coil::makeUnexpected("Unable to convert 'foo bar' to type 'std::string_view': Expected 1 subvalues, got 2"));
}

TEST(TypeSerializerTests, TestStringTypesToString)
{
    EXPECT_EQ(coil::TypeSerializer<std::string>::toString(std::string("foo")), "foo");
    EXPECT_EQ(coil::TypeSerializer<std::string_view>::toString(std::string_view("foo")), "foo");
}

TEST(TypeSerializerTests, TestUserTypeFromStringValid)
{
    using namespace std::literals;

    EXPECT_EQ(coil::TypeSerializer<WithoutDefaultConstructor>::fromString("42"sv), WithoutDefaultConstructor{42});
}

TEST(TypeSerializerTests, TestUserTypeFromStringInvalid)
{
    using namespace std::literals;

    EXPECT_EQ(coil::TypeSerializer<WithoutDefaultConstructor>::fromString("foo"sv),
              coil::makeUnexpected("Unable to convert 'foo' to type 'WithoutDefaultConstructor': Unable to convert 'foo' to type 'int'"));
}

TEST(TypeSerializerTests, TestUserTypeToString)
{
    EXPECT_EQ(coil::TypeSerializer<WithoutDefaultConstructor>::toString(WithoutDefaultConstructor{42}), "WithoutDefaultConstructor{42}");
}

TEST(TypeSerializerTests, TestCompoundUserTypeFromStringValid)
{
    EXPECT_EQ(coil::TypeSerializer<CompoundType>::fromString({{"6", "28"}}), (CompoundType{6, 28}));
}

TEST(TypeSerializerTests, TestCompoundUserTypeFromStringInvalid)
{
    EXPECT_EQ(coil::TypeSerializer<CompoundType>::fromString({{"6", "28", "496"}}), coil::makeUnexpected("Unable to convert '6 28 496' to type 'CompoundType': Expected 2 subvalues, got 3"));
    EXPECT_EQ(coil::TypeSerializer<CompoundType>::fromString({"6"}), coil::makeUnexpected("Unable to convert '6' to type 'CompoundType': Expected 2 subvalues, got 1"));
    EXPECT_EQ(coil::TypeSerializer<CompoundType>::fromString({{"six", "28"}}), coil::makeUnexpected("Unable to convert 'six 28' to type 'CompoundType': Unable to convert 'six' to type 'int'"));
}

TEST(TypeSerializerTests, TestCompoundUserTypeToString)
{
    CompoundType value{6, 28};
    EXPECT_EQ(coil::TypeSerializer<CompoundType>::toString(value), "CompoundType{6,28}");
    EXPECT_EQ(coil::TypeSerializer<CompoundType*>::toString(&value), "CompoundType{6,28}");
    EXPECT_EQ(coil::TypeSerializer<CompoundType*>::toString(nullptr), "null");
    EXPECT_EQ(coil::TypeSerializer<CompoundType const*>::toString(&value), "CompoundType{6,28}");
    EXPECT_EQ(coil::TypeSerializer<CompoundType const*>::toString(nullptr), "null");
}
