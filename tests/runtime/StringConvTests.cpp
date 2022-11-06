#include "Common.h"
#include "gtest/gtest.h"

#include "coil/detail/StringConv.h"
#include "coil/String.h"
#include "coil/StringView.h"

TEST(StringConvTests, TestIntegerToString)
{
    EXPECT_EQ(coil::toString(314), "314");
    EXPECT_EQ(coil::toString(314l), "314");
    EXPECT_EQ(coil::toString(314ll), "314");

    EXPECT_EQ(coil::toString(-314), "-314");
    EXPECT_EQ(coil::toString(-314l), "-314");
    EXPECT_EQ(coil::toString(-314ll), "-314");

    EXPECT_EQ(coil::toString(314u), "314");
    EXPECT_EQ(coil::toString(314ul), "314");
    EXPECT_EQ(coil::toString(314ull), "314");
}

TEST(StringConvTests, TestFloatToString)
{
    EXPECT_EQ(coil::toString(3.14f), "3.14");
    EXPECT_EQ(coil::toString(3.14), "3.14");
    EXPECT_EQ(coil::toString(3.14l), "3.14");
}

TEST(StringConvTests, TestFloatToStringEdgeCases)
{
    // %g: %f for exponent in range [-4, 5] and %e otherwise

    EXPECT_EQ(coil::toString(100000.0f), "100000");
    EXPECT_EQ(coil::toString(1000000.0f), "1e+06");
    EXPECT_EQ(coil::toString(0.0001f), "0.0001");
    EXPECT_EQ(coil::toString(0.00001f), "1e-05");

    EXPECT_EQ(coil::toString(2.99999f), "2.99999");
    EXPECT_EQ(coil::toString(2.999999f), "3");
    EXPECT_EQ(coil::toString(3.000001f), "3");
    EXPECT_EQ(coil::toString(3.00001f), "3.00001");
}

TEST(StringConvTests, TestFloatToStringZero)
{
    EXPECT_EQ(coil::toString(0.0f), "0");
    EXPECT_EQ(coil::toString(+0.0f), "0");
    EXPECT_EQ(coil::toString(-0.0f), "0");
    EXPECT_EQ(coil::toString(0.0000001f), "0");
    EXPECT_EQ(coil::toString(-0.0000001f), "0");

    EXPECT_EQ(coil::toString(0.0), "0");
    EXPECT_EQ(coil::toString(+0.0), "0");
    EXPECT_EQ(coil::toString(-0.0), "0");
    EXPECT_EQ(coil::toString(0.0000001), "0");
    EXPECT_EQ(coil::toString(-0.0000001), "0");

    EXPECT_EQ(coil::toString(0.0l), "0");
    EXPECT_EQ(coil::toString(+0.0l), "0");
    EXPECT_EQ(coil::toString(-0.0l), "0");
    EXPECT_EQ(coil::toString(0.0000001l), "0");
    EXPECT_EQ(coil::toString(-0.0000001l), "0");
}

TEST(StringConvTests, TestFloatToStringSpecial)
{
    auto startsWith = [](coil::StringView lhs, coil::StringView rhs)
    {
        return lhs.substr(0, rhs.length()) == rhs;
    };

    EXPECT_PRED2(startsWith, coil::toString(nanf("")), "nan");
    EXPECT_PRED2(startsWith, coil::toString(HUGE_VALF), "inf");
    EXPECT_PRED2(startsWith, coil::toString(-HUGE_VALF), "-inf");
}

TEST(StringConvTests, TestIntegerFromStringValidPositive)
{
    {
        char value = 0;
        ASSERT_TRUE(coil::fromString("16", value));
        EXPECT_EQ(value, 16);
    }
    {
        signed char value = 0;
        ASSERT_TRUE(coil::fromString("16", value));
        EXPECT_EQ(value, 16);
    }
    {
        unsigned char value = 0;
        ASSERT_TRUE(coil::fromString("16", value));
        EXPECT_EQ(value, 16);
    }
    {
        short value = 0;
        ASSERT_TRUE(coil::fromString("16", value));
        EXPECT_EQ(value, 16);
    }
    {
        unsigned short value = 0;
        ASSERT_TRUE(coil::fromString("16", value));
        EXPECT_EQ(value, 16);
    }
    {
        int value = 0;
        ASSERT_TRUE(coil::fromString("16", value));
        EXPECT_EQ(value, 16);
    }
    {
        unsigned int value = 0;
        ASSERT_TRUE(coil::fromString("16", value));
        EXPECT_EQ(value, 16);
    }
    {
        long value = 0;
        ASSERT_TRUE(coil::fromString("16", value));
        EXPECT_EQ(value, 16);
    }
    {
        unsigned long value = 0;
        ASSERT_TRUE(coil::fromString("16", value));
        EXPECT_EQ(value, 16);
    }
    {
        long long value = 0;
        ASSERT_TRUE(coil::fromString("16", value));
        EXPECT_EQ(value, 16);
    }
    {
        unsigned long long value = 0;
        ASSERT_TRUE(coil::fromString("16", value));
        EXPECT_EQ(value, 16);
    }
}

TEST(StringConvTests, TestIntegerFromStringValidNegative)
{
    {
        signed char value = 0;
        ASSERT_TRUE(coil::fromString("-16", value));
        EXPECT_EQ(value, -16);
    }
    {
        short value = 0;
        ASSERT_TRUE(coil::fromString("-16", value));
        EXPECT_EQ(value, -16);
    }
    {
        int value = 0;
        ASSERT_TRUE(coil::fromString("-16", value));
        EXPECT_EQ(value, -16);
    }
    {
        long value = 0;
        ASSERT_TRUE(coil::fromString("-16", value));
        EXPECT_EQ(value, -16);
    }
    {
        long long value = 0;
        ASSERT_TRUE(coil::fromString("-16", value));
        EXPECT_EQ(value, -16);
    }
}

TEST(StringConvTests, TestIntegerFromStringOutOfRangePositive)
{
    {
        char value = 0;
        EXPECT_FALSE(coil::fromString(coil::toString(CHAR_MAX) + "0", value));
    }
    {
        signed char value = 0;
        EXPECT_FALSE(coil::fromString(coil::toString(SCHAR_MAX) + "0", value));
    }
    {
        unsigned char value = 0;
        EXPECT_FALSE(coil::fromString(coil::toString(UCHAR_MAX) + "0", value));
    }
    {
        short value = 0;
        EXPECT_FALSE(coil::fromString(coil::toString(SHRT_MAX) + "0", value));
    }
    {
        unsigned short value = 0;
        EXPECT_FALSE(coil::fromString(coil::toString(USHRT_MAX) + "0", value));
    }
    {
        int value = 0;
        EXPECT_FALSE(coil::fromString(coil::toString(INT_MAX) + "0", value));
    }
    {
        unsigned int value = 0;
        EXPECT_FALSE(coil::fromString(coil::toString(UINT_MAX) + "0", value));
    }
    {
        long value = 0;
        EXPECT_FALSE(coil::fromString(coil::toString(LONG_MAX) + "0", value));
    }
    {
        unsigned long value = 0;
        EXPECT_FALSE(coil::fromString(coil::toString(ULONG_MAX) + "0", value));
    }
    {
        long long value = 0;
        EXPECT_FALSE(coil::fromString(coil::toString(LLONG_MAX) + "0", value));
    }
    {
        unsigned long long value = 0;
        EXPECT_FALSE(coil::fromString(coil::toString(ULLONG_MAX) + "0", value));
    }
}

TEST(StringConvTests, TestIntegerFromStringOutOfRangeNegative)
{
    if constexpr (CHAR_MIN == 0)
    {
        char value = 0;
        EXPECT_FALSE(coil::fromString("-1", value));
    }
    else
    {
        char value = 0;
        EXPECT_FALSE(coil::fromString(coil::toString(CHAR_MIN) + "0", value));
    }

    {
        signed char value = 0;
        EXPECT_FALSE(coil::fromString(coil::toString(SCHAR_MIN) + "0", value));
    }
    {
        unsigned char value = 0;
        EXPECT_FALSE(coil::fromString("-1", value));
    }
    {
        short value = 0;
        EXPECT_FALSE(coil::fromString(coil::toString(SHRT_MIN) + "0", value));
    }
    {
        unsigned short value = 0;
        EXPECT_FALSE(coil::fromString("-1", value));
    }
    {
        int value = 0;
        EXPECT_FALSE(coil::fromString(coil::toString(INT_MIN) + "0", value));
    }
    {
        unsigned int value = 0;
        EXPECT_FALSE(coil::fromString("-1", value));
    }
    {
        long value = 0;
        EXPECT_FALSE(coil::fromString(coil::toString(LONG_MIN) + "0", value));
    }
    {
        unsigned long value = 0;
        EXPECT_FALSE(coil::fromString("-1", value));
    }
    {
        long long value = 0;
        EXPECT_FALSE(coil::fromString(coil::toString(LLONG_MIN) + "0", value));
    }
    {
        unsigned long long value = 0;
        EXPECT_FALSE(coil::fromString("-1", value));
    }
}

TEST(StringConvTests, TestIntegerFromStringNoDigits)
{
    {
        char value = 0;
        EXPECT_FALSE(coil::fromString("string", value));
        EXPECT_FALSE(coil::fromString("", value));
    }
    {
        signed char value = 0;
        EXPECT_FALSE(coil::fromString("string", value));
        EXPECT_FALSE(coil::fromString("", value));
    }
    {
        unsigned char value = 0;
        EXPECT_FALSE(coil::fromString("string", value));
        EXPECT_FALSE(coil::fromString("", value));
    }
    {
        short value = 0;
        EXPECT_FALSE(coil::fromString("string", value));
        EXPECT_FALSE(coil::fromString("", value));
    }
    {
        unsigned short value = 0;
        EXPECT_FALSE(coil::fromString("string", value));
        EXPECT_FALSE(coil::fromString("", value));
    }
    {
        int value = 0;
        EXPECT_FALSE(coil::fromString("string", value));
        EXPECT_FALSE(coil::fromString("", value));
    }
    {
        unsigned int value = 0;
        EXPECT_FALSE(coil::fromString("string", value));
        EXPECT_FALSE(coil::fromString("", value));
    }
    {
        long value = 0;
        EXPECT_FALSE(coil::fromString("string", value));
        EXPECT_FALSE(coil::fromString("", value));
    }
    {
        unsigned long value = 0;
        EXPECT_FALSE(coil::fromString("string", value));
        EXPECT_FALSE(coil::fromString("", value));
    }
    {
        long long value = 0;
        EXPECT_FALSE(coil::fromString("string", value));
        EXPECT_FALSE(coil::fromString("", value));
    }
    {
        unsigned long long value = 0;
        EXPECT_FALSE(coil::fromString("string", value));
        EXPECT_FALSE(coil::fromString("", value));
    }
}

TEST(StringConvTests, TestIntegerFromStringPartialNumber)
{
    {
        char value = 0;
        EXPECT_FALSE(coil::fromString("16string", value));
    }
    {
        signed char value = 0;
        EXPECT_FALSE(coil::fromString("16string", value));
    }
    {
        unsigned char value = 0;
        EXPECT_FALSE(coil::fromString("16string", value));
    }
    {
        short value = 0;
        EXPECT_FALSE(coil::fromString("16string", value));
    }
    {
        unsigned short value = 0;
        EXPECT_FALSE(coil::fromString("16string", value));
    }
    {
        int value = 0;
        EXPECT_FALSE(coil::fromString("16string", value));
    }
    {
        unsigned int value = 0;
        EXPECT_FALSE(coil::fromString("16string", value));
    }
    {
        long value = 0;
        EXPECT_FALSE(coil::fromString("16string", value));
    }
    {
        unsigned long value = 0;
        EXPECT_FALSE(coil::fromString("16string", value));
    }
    {
        long long value = 0;
        EXPECT_FALSE(coil::fromString("16string", value));
    }
    {
        unsigned long long value = 0;
        EXPECT_FALSE(coil::fromString("16string", value));
    }
}

TEST(StringConvTests, TestFloatFromStringValid)
{
    {
        float value = 0.0f;
        ASSERT_TRUE(coil::fromString("3.14", value));
        EXPECT_PRED_FORMAT2(::testing::internal::CmpHelperFloatingPointEQ<float>, value, 3.14f);
        ASSERT_TRUE(coil::fromString("0.0000001", value));
        EXPECT_PRED_FORMAT2(::testing::internal::CmpHelperFloatingPointEQ<float>, value, 0.0000001f);
        ASSERT_TRUE(coil::fromString("123456789", value));
        EXPECT_PRED_FORMAT2(::testing::internal::CmpHelperFloatingPointEQ<float>, value, 123456789.0f);
        ASSERT_TRUE(coil::fromString("1e16", value));
        EXPECT_PRED_FORMAT2(::testing::internal::CmpHelperFloatingPointEQ<float>, value, 1e16f);
        ASSERT_TRUE(coil::fromString("1e+16", value));
        EXPECT_PRED_FORMAT2(::testing::internal::CmpHelperFloatingPointEQ<float>, value, 1e16f);
        ASSERT_TRUE(coil::fromString("1e-16", value));
        EXPECT_PRED_FORMAT2(::testing::internal::CmpHelperFloatingPointEQ<float>, value, 1e-16f);
    }
    {
        double value = 0.0;
        ASSERT_TRUE(coil::fromString("3.14", value));
        EXPECT_PRED_FORMAT2(::testing::internal::CmpHelperFloatingPointEQ<double>, value, 3.14);
        ASSERT_TRUE(coil::fromString("0.0000001", value));
        EXPECT_PRED_FORMAT2(::testing::internal::CmpHelperFloatingPointEQ<double>, value, 0.0000001);
        ASSERT_TRUE(coil::fromString("123456789", value));
        EXPECT_PRED_FORMAT2(::testing::internal::CmpHelperFloatingPointEQ<double>, value, 123456789.0);
        ASSERT_TRUE(coil::fromString("1e16", value));
        EXPECT_PRED_FORMAT2(::testing::internal::CmpHelperFloatingPointEQ<double>, value, 1e16);
        ASSERT_TRUE(coil::fromString("1e+16", value));
        EXPECT_PRED_FORMAT2(::testing::internal::CmpHelperFloatingPointEQ<double>, value, 1e16);
        ASSERT_TRUE(coil::fromString("1e-16", value));
        EXPECT_PRED_FORMAT2(::testing::internal::CmpHelperFloatingPointEQ<double>, value, 1e-16);
    }
    {
        long double value = 0.0;
        ASSERT_TRUE(coil::fromString("3.14", value));
        EXPECT_PRED_FORMAT2(::testing::internal::CmpHelperFloatingPointEQ<long double>, value, 3.14l);
        ASSERT_TRUE(coil::fromString("0.0000001", value));
        EXPECT_PRED_FORMAT2(::testing::internal::CmpHelperFloatingPointEQ<long double>, value, 0.0000001l);
        ASSERT_TRUE(coil::fromString("123456789", value));
        EXPECT_PRED_FORMAT2(::testing::internal::CmpHelperFloatingPointEQ<long double>, value, 123456789.0l);
        ASSERT_TRUE(coil::fromString("1e16", value));
        EXPECT_PRED_FORMAT2(::testing::internal::CmpHelperFloatingPointEQ<long double>, value, 1e16l);
        ASSERT_TRUE(coil::fromString("1e+16", value));
        EXPECT_PRED_FORMAT2(::testing::internal::CmpHelperFloatingPointEQ<long double>, value, 1e16l);
        ASSERT_TRUE(coil::fromString("1e-16", value));
        EXPECT_PRED_FORMAT2(::testing::internal::CmpHelperFloatingPointEQ<long double>, value, 1e-16l);
    }
}

TEST(StringConvTests, TestFloatFromStringOutOfRange)
{
    {
        float value = 0.0f;
        EXPECT_FALSE(coil::fromString(coil::toString(FLT_MAX) + "0", value));
    }
    {
        double value = 0.0;
        EXPECT_FALSE(coil::fromString(coil::toString(DBL_MAX) + "0", value));
    }
    {
        long double value = 0.0;
        EXPECT_FALSE(coil::fromString(coil::toString(LDBL_MAX) + "0", value));
    }
}

TEST(StringConvTests, TestFloatFromStringNoDigits)
{
    {
        float value = 0.0f;
        EXPECT_FALSE(coil::fromString("string", value));
    }
    {
        double value = 0.0;
        EXPECT_FALSE(coil::fromString("string", value));
    }
    {
        long double value = 0.0;
        EXPECT_FALSE(coil::fromString("string", value));
    }
}

TEST(StringConvTests, TestFloatFromStringPartialNumber)
{
    {
        float value = 0.0f;
        EXPECT_FALSE(coil::fromString("3.14string", value));
    }
    {
        double value = 0.0;
        EXPECT_FALSE(coil::fromString("3.14string", value));
    }
    {
        long double value = 0.0;
        EXPECT_FALSE(coil::fromString("3.14string", value));
    }
}
