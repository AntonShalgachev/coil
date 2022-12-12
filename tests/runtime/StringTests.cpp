#include "gtest/gtest.h"

#include "coil/detail/String.h"
#include "coil/detail/StringView.h"

namespace
{
    void testCommon(coil::String const& str)
    {
        char const* cString = str.cStr();
        ASSERT_TRUE(cString != nullptr);
        ASSERT_EQ(cString[str.length()], '\0');

        EXPECT_TRUE(str.data() == str.cStr());
        EXPECT_TRUE(str.begin() + str.length() == str.end());

        if (str.length() > 0)
            EXPECT_FALSE(str.empty());
        else
            EXPECT_TRUE(str.empty());
    }
}

TEST(StringTests, TestDefaultConstructed)
{
    coil::String str;

    EXPECT_EQ(str.length(), 0);
    EXPECT_EQ(str.slength(), 0);
    testCommon(str);
    EXPECT_STREQ(str.cStr(), "");
}

TEST(StringTests, TestConstructedFromCString)
{
    coil::String str{"Null-terminated C string"};

    EXPECT_EQ(str.length(), 24);
    EXPECT_EQ(str.slength(), 24);
    testCommon(str);
    EXPECT_STREQ(str.cStr(), "Null-terminated C string");
}

TEST(StringTests, TestConstructedFromCStringAndLength)
{
    coil::String str{"Some string", 4};

    EXPECT_EQ(str.length(), 4);
    EXPECT_EQ(str.slength(), 4);
    testCommon(str);
    EXPECT_STREQ(str.cStr(), "Some");
}

TEST(StringTests, TestConstructedFromStringView)
{
    coil::StringView view{"A string literal"};
    view = view.substr(2, 6);

    coil::String str{view};

    EXPECT_TRUE(str.slength() == view.slength());
    EXPECT_TRUE(str == view);
    EXPECT_EQ(str.length(), 6);
    EXPECT_EQ(str.slength(), 6);
    testCommon(str);
    EXPECT_STREQ(str.cStr(), "string");
}

TEST(StringTests, TestBack)
{
    coil::String str = "Test";
    coil::String const& constStr = str;

    testCommon(str);
    ASSERT_FALSE(str.empty());

    EXPECT_STREQ(str.cStr(), "Test");
    EXPECT_EQ(constStr.back(), 't');

    str.back() = 's';

    EXPECT_STREQ(str.cStr(), "Tess");

    EXPECT_EQ(constStr.back(), 's');
}

TEST(StringTests, TestData)
{
    coil::String str = "Test";
    coil::String const& constStr = str;

    testCommon(str);
    ASSERT_EQ(str.length(), 4);

    for (size_t i = 0; i < str.length(); i++)
        EXPECT_EQ(constStr.data()[i], "Test"[i]);

    str.data()[0] = 'c';
    str.data()[1] = 'o';
    str.data()[2] = 'i';
    str.data()[3] = 'l';

    for (size_t i = 0; i < str.length(); i++)
        EXPECT_EQ(constStr.data()[i], "coil"[i]);

    EXPECT_STREQ(str.cStr(), "coil");
}

TEST(StringTests, TestAppend)
{
    coil::String str = "One";
    str.append("Two", 3);

    testCommon(str);
    EXPECT_EQ(str.length(), 6);
    EXPECT_STREQ(str.cStr(), "OneTwo");
}

TEST(StringTests, TestAppendOperators)
{
    coil::String str = "";

    str += 'c';
    testCommon(str);
    EXPECT_EQ(str.length(), 1);
    EXPECT_STREQ(str.cStr(), "c");

    str += " c-string";
    testCommon(str);
    EXPECT_EQ(str.length(), 10);
    EXPECT_STREQ(str.cStr(), "c c-string");

    str += coil::String{" string"};
    testCommon(str);
    EXPECT_EQ(str.length(), 17);
    EXPECT_STREQ(str.cStr(), "c c-string string");

    str += coil::StringView{" string-view"};
    testCommon(str);
    EXPECT_EQ(str.length(), 29);
    EXPECT_STREQ(str.cStr(), "c c-string string string-view");
}

TEST(StringTests, TestEquality)
{
    coil::String str = "Test";

    EXPECT_TRUE(str == "Test");
    EXPECT_TRUE(str == coil::StringView{"Test"});
    EXPECT_TRUE(str == coil::String{"Test"});
}

TEST(StringTests, TestConcatenation)
{
    coil::String str = "String";

    {
        coil::String result = str + 'c';
        testCommon(result);
        EXPECT_EQ(result.length(), 7);
        EXPECT_STREQ(result.cStr(), "Stringc");
    }

    {
        coil::String result = str + " c-string";
        testCommon(result);
        EXPECT_EQ(result.length(), 15);
        EXPECT_STREQ(result.cStr(), "String c-string");
    }

    {
        coil::String result = str + coil::String{" string"};
        testCommon(result);
        EXPECT_EQ(result.length(), 13);
        EXPECT_STREQ(result.cStr(), "String string");
    }

    {
        coil::String result = str + coil::StringView{" string-view"};
        testCommon(result);
        EXPECT_EQ(result.length(), 18);
        EXPECT_STREQ(result.cStr(), "String string-view");
    }
}
