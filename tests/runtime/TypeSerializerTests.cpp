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
        static Expected<WithoutDefaultConstructor, coil::String> fromString(Value const& input)
        {
            auto innerValue = TypeSerializer<int>::fromString(input);

            if (!innerValue)
                return errors::createGenericError<WithoutDefaultConstructor>(input, innerValue.error());

            return WithoutDefaultConstructor{*innerValue};
        }

        static coil::String toString(WithoutDefaultConstructor const& value)
        {
            return coil::sprintf("WithoutDefaultConstructor{%d}", value.value);
        }
    };

    template<>
    struct TypeSerializer<CompoundType>
    {
        static Expected<CompoundType, coil::String> fromString(Value const& input)
        {
            if (input.subvalues.size() != 2)
                return errors::createMismatchedSubvaluesError<CompoundType>(input, 2);

            auto field1 = TypeSerializer<int>::fromString(input.subvalues[0]);
            auto field2 = TypeSerializer<int>::fromString(input.subvalues[1]);

            if (!field1)
                return errors::createGenericError<CompoundType>(input, field1.error());
            if (!field2)
                return errors::createGenericError<CompoundType>(input, field2.error());

            return CompoundType{*field1, *field2};
        }

        static coil::String toString(CompoundType const& value)
        {
            return coil::sprintf("CompoundType{%d,%d}", value.field1, value.field2);
        }
    };

    template<>
    struct TypeName<WithoutDefaultConstructor>
    {
        static coil::StringView name()
        {
            return "WithoutDefaultConstructor";
        }
    };

    template<>
    struct TypeName<CompoundType>
    {
        static coil::StringView name()
        {
            return "CompoundType";
        }
    };
}

TEST(TypeSerializerTests, TestIntValidInputFromString)
{
    EXPECT_EQ(coil::TypeSerializer<int>::fromString("42"), 42);
}

TEST(TypeSerializerTests, TestIntInvalidInputFromString)
{
    EXPECT_EQ(coil::TypeSerializer<int>::fromString({{"foo", "bar"}}), coil::makeUnexpected("Unable to convert 'foo bar' to type 'int': Expected 1 subvalues, got 2"));
    EXPECT_EQ(coil::TypeSerializer<int>::fromString("42foo"), coil::makeUnexpected("Unable to convert '42foo' to type 'int'"));
}

TEST(TypeSerializerTests, TestIntToString)
{
    int value = 42;
    EXPECT_EQ(coil::TypeSerializer<int>::toString(value), "42");
    EXPECT_EQ(coil::TypeSerializer<int*>::toString(&value), "42");
    EXPECT_EQ(coil::TypeSerializer<int*>::toString(nullptr), "null");
    EXPECT_EQ(coil::TypeSerializer<int const*>::toString(&value), "42");
    EXPECT_EQ(coil::TypeSerializer<int const*>::toString(nullptr), "null");
}

TEST(TypeSerializerTests, TestOutOfRangeInputFromString)
{
    EXPECT_EQ(coil::TypeSerializer<short>::fromString("99999999999"), coil::makeUnexpected("Unable to convert '99999999999' to type 'short': the value can't be represented in this type"));
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
    EXPECT_EQ(coil::TypeSerializer<bool>::fromString({{"foo", "bar"}}), coil::makeUnexpected("Unable to convert 'foo bar' to type 'bool': Expected 1 subvalues, got 2"));

    EXPECT_EQ(coil::TypeSerializer<bool>::fromString("2"), coil::makeUnexpected("Unable to convert '2' to type 'bool'"));
    EXPECT_EQ(coil::TypeSerializer<bool>::fromString("none"), coil::makeUnexpected("Unable to convert 'none' to type 'bool'"));
    EXPECT_EQ(coil::TypeSerializer<bool>::fromString("-1"), coil::makeUnexpected("Unable to convert '-1' to type 'bool'"));
}

TEST(TypeSerializerTests, TestBoolToString)
{
    EXPECT_EQ(coil::TypeSerializer<bool>::toString(true), "true");
    EXPECT_EQ(coil::TypeSerializer<bool>::toString(false), "false");
}

TEST(TypeSerializerTests, TestStringTypesValidInputFromString)
{
    EXPECT_EQ(coil::TypeSerializer<coil::StringView>::fromString("foo"), "foo");
    EXPECT_EQ(coil::TypeSerializer<coil::String>::fromString("foo"), "foo");
}

TEST(TypeSerializerTests, TestStringTypesInvalidInputFromString)
{
    EXPECT_EQ(coil::TypeSerializer<coil::String>::fromString({{"foo", "bar"}}), coil::makeUnexpected("Unable to convert 'foo bar' to type 'string': Expected 1 subvalues, got 2"));
    EXPECT_EQ(coil::TypeSerializer<coil::StringView>::fromString({{"foo", "bar"}}), coil::makeUnexpected("Unable to convert 'foo bar' to type 'string': Expected 1 subvalues, got 2"));
}

TEST(TypeSerializerTests, TestStringTypesToString)
{
    EXPECT_EQ(coil::TypeSerializer<coil::String>::toString("foo"), "foo");
    EXPECT_EQ(coil::TypeSerializer<coil::StringView>::toString("foo"), "foo");
}

TEST(TypeSerializerTests, TestUserTypeFromStringValid)
{
    EXPECT_EQ(coil::TypeSerializer<WithoutDefaultConstructor>::fromString("42"), WithoutDefaultConstructor{42});
}

TEST(TypeSerializerTests, TestUserTypeFromStringInvalid)
{
    EXPECT_EQ(coil::TypeSerializer<WithoutDefaultConstructor>::fromString("foo"),
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
