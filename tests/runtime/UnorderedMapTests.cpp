#include "gtest/gtest.h"

#include "coil/UnorderedMap.h"

namespace coil
{
    template<>
    struct Hash<int>
    {
        size_t operator()(int const& value)
        {
            size_t res = value;
            res = ((res >> 16) ^ res) * 0x45d9f3b;
            res = ((res >> 16) ^ res) * 0x45d9f3b;
            res = (res >> 16) ^ res;
            return res;
        }
    };
}

TEST(UnorderedMapTests, TestEmpty)
{
    coil::UnorderedMap<int, int> map;

    EXPECT_EQ(map.size(), 0);
}

TEST(UnorderedMapTests, TestInsert)
{
    coil::UnorderedMap<int, int> map;

    for (int i = 0; i < 100; i++)
    {
        map.insertOrAssign(i, 2 * i + 1);

        EXPECT_EQ(map.size(), i + 1);

        for (int j = 0; j < static_cast<int>(map.size()); j++)
        {
            auto it = map.find(j);
            ASSERT_TRUE(it != map.end());

            EXPECT_EQ(it->key(), j);
            EXPECT_EQ(it->value(), 2 * j + 1);
        }

        for (auto const& pair : map)
            EXPECT_EQ(pair.value(), 2 * pair.key() + 1);
    }
}

TEST(UnorderedMapTests, TestAssign)
{
    coil::UnorderedMap<int, int> map;

    map.insertOrAssign(314, 42);
    map.insertOrAssign(314, 0);

    EXPECT_EQ(map.size(), 1);

    auto it = map.find(314);
    ASSERT_TRUE(it != map.end());

    EXPECT_EQ(it->key(), 314);
    EXPECT_EQ(it->value(), 0);
}

TEST(UnorderedMapTests, TestAccessors)
{
    coil::UnorderedMap<int, int> map;
    map.insertOrAssign(1, 42);
    map.insertOrAssign(2, 314);

    coil::UnorderedMap<int, int> const& constMap = map;

    EXPECT_EQ(map.size(), 2);
    EXPECT_EQ(constMap.size(), 2);

    {
        {
            auto it = map.find(1);
            ASSERT_TRUE(it != map.end());
            EXPECT_EQ(it->key(), 1);
            EXPECT_EQ(it->value(), 42);
        }
        {
            auto it = constMap.find(1);
            ASSERT_TRUE(it != constMap.end());
            EXPECT_EQ(it->key(), 1);
            EXPECT_EQ(it->value(), 42);
        }
    }
    {
        {
            auto it = map.find(2);
            ASSERT_TRUE(it != map.end());
            EXPECT_EQ(it->key(), 2);
            EXPECT_EQ(it->value(), 314);
        }
        {
            auto it = constMap.find(2);
            ASSERT_TRUE(it != constMap.end());
            EXPECT_EQ(it->key(), 2);
            EXPECT_EQ(it->value(), 314);
        }
    }
    {
        {
            auto it = map.find(3);
            EXPECT_TRUE(it == map.end());
        }
        {
            auto it = constMap.find(3);
            EXPECT_TRUE(it == constMap.end());
        }
    }

    {
        size_t items = 0;
        for (auto const& pair : map)
        {
            if (pair.key() == 1)
                EXPECT_EQ(pair.value(), 42);
            else if (pair.key() == 2)
                EXPECT_EQ(pair.value(), 314);
            else
                FAIL();

            items++;
        }
        EXPECT_EQ(items, 2);
    }

    {
        size_t items = 0;
        for (auto const& pair : constMap)
        {
            if (pair.key() == 1)
                EXPECT_EQ(pair.value(), 42);
            else if (pair.key() == 2)
                EXPECT_EQ(pair.value(), 314);
            else
                FAIL();

            items++;
        }
        EXPECT_EQ(items, 2);
    }
}

TEST(UnorderedMapTests, TestErase)
{
    coil::UnorderedMap<int, int> map;

    for (int i = 0; i < 100; i++)
        map.insertOrAssign(i, 2 * i + 1);

    for (int i = 0; i < 100; i++)
    {
        EXPECT_EQ(map.size(), 100 - i);

        map.erase(i);

        EXPECT_EQ(map.size(), 100 - i - 1);

        EXPECT_TRUE(map.find(i) == map.end());

        for (int j = i + 1; j < 100; j++)
        {
            auto it = map.find(j);
            ASSERT_TRUE(it != map.end());

            EXPECT_EQ(it->key(), j);
            EXPECT_EQ(it->value(), 2 * j + 1);
        }

        for (auto const& pair : map)
            EXPECT_EQ(pair.value(), 2 * pair.key() + 1);
    }
}

TEST(UnorderedMapTests, TestEraseFromSameBucket)
{
    coil::UnorderedMap<int, int> map;

    for (int i = 0; i < 3; i++)
        map.insertOrAssign(i, 2 * i + 1);

    EXPECT_EQ(map.size(), 3);
    map.erase(2);
    EXPECT_EQ(map.size(), 2);
    map.erase(0);
    EXPECT_EQ(map.size(), 1);
}

TEST(UnorderedMapTests, TestEraseNonExistent)
{
    coil::UnorderedMap<int, int> map;

    for (int i = 0; i < 100; i++)
        map.insertOrAssign(i, 2 * i + 1);

    EXPECT_EQ(map.size(), 100);
    for (auto const& pair : map)
        EXPECT_EQ(pair.value(), 2 * pair.key() + 1);

    map.erase(100);

    EXPECT_EQ(map.size(), 100);
    for (auto const& pair : map)
        EXPECT_EQ(pair.value(), 2 * pair.key() + 1);
}

TEST(UnorderedMapTests, TestClear)
{
    coil::UnorderedMap<int, int> map;

    for (int i = 0; i < 100; i++)
        map.insertOrAssign(i, 2 * i + 1);

    EXPECT_EQ(map.size(), 100);

    map.clear();

    EXPECT_EQ(map.size(), 0);
}
