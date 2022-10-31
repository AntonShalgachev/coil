#include "gtest/gtest.h"

#include "coil/Vector.h"

namespace
{
    template<typename T>
    class Dummy
    {
    public:
        Dummy()
        {
            constructions++;
            defaultConstructions++;
        }
        Dummy(T payload) : m_payload(coil::move(payload))
        {
            constructions++;
        }
        Dummy(Dummy<T> const& rhs) : m_payload(rhs.m_payload)
        {
            copies++;
            copyConstructions++;
        }
        Dummy(Dummy<T>&& rhs) : m_payload(coil::move(rhs.m_payload))
        {
            rhs.m_payload = T{};

            moves++;
            moveConstructions++;
        }
        Dummy<T>& operator=(Dummy<T> const& rhs)
        {
            m_payload = rhs.m_payload;

            copies++;
            copyAssignments++;

            return *this;
        }
        Dummy<T>& operator=(Dummy<T>&& rhs)
        {
            m_payload = coil::move(rhs.m_payload);
            rhs.m_payload = T{};

            moves++;
            moveAssignments++;

            return *this;
        }
        ~Dummy()
        {
            destructions++;
        }

        bool operator==(Dummy<T> const& rhs) const
        {
            return m_payload == rhs.m_payload;
        }

        T const& payload() const
        {
            return m_payload;
        }

    private:
        T m_payload;

    public:
        inline static size_t constructions = 0;
        inline static size_t defaultConstructions = 0;
        inline static size_t copies = 0;
        inline static size_t moves = 0;
        inline static size_t copyConstructions = 0;
        inline static size_t moveConstructions = 0;
        inline static size_t copyAssignments = 0;
        inline static size_t moveAssignments = 0;
        inline static size_t destructions = 0;

        static void resetStats()
        {
            constructions = 0;
            defaultConstructions = 0;
            copies = 0;
            moves = 0;
            copyConstructions = 0;
            moveConstructions = 0;
            copyAssignments = 0;
            moveAssignments = 0;
            destructions = 0;
        }
    };

    using Integer = Dummy<int>;
}

TEST(VectorTests, TestPushBack)
{
    coil::Vector<int> v;

    ASSERT_EQ(v.size(), 0u);
    ASSERT_TRUE(v.empty());

    v.pushBack(0);
    ASSERT_EQ(v.size(), 1u);
    ASSERT_FALSE(v.empty());
    EXPECT_EQ(v[0], 0);

    v.pushBack(1);
    ASSERT_EQ(v.size(), 2u);
    ASSERT_FALSE(v.empty());
    EXPECT_EQ(v[0], 0);
    EXPECT_EQ(v[1], 1);

    v.pushBack(2);
    ASSERT_EQ(v.size(), 3u);
    ASSERT_FALSE(v.empty());
    EXPECT_EQ(v[0], 0);
    EXPECT_EQ(v[1], 1);
    EXPECT_EQ(v[2], 2);
}

TEST(VectorTests, TestPopBack)
{
    coil::Vector<int> v;
    v.pushBack(0);
    v.pushBack(1);
    v.pushBack(2);

    ASSERT_EQ(v.size(), 3u);
    ASSERT_FALSE(v.empty());
    EXPECT_EQ(v[0], 0);
    EXPECT_EQ(v[1], 1);
    EXPECT_EQ(v[2], 2);

    v.popBack();
    ASSERT_EQ(v.size(), 2u);
    ASSERT_FALSE(v.empty());
    EXPECT_EQ(v[0], 0);
    EXPECT_EQ(v[1], 1);

    v.popBack();
    ASSERT_EQ(v.size(), 1u);
    ASSERT_FALSE(v.empty());
    EXPECT_EQ(v[0], 0);

    v.popBack();
    ASSERT_EQ(v.size(), 0u);
    ASSERT_TRUE(v.empty());
}

TEST(VectorTests, TestReserve)
{
    coil::Vector<int> v;

    EXPECT_EQ(v.size(), 0u);
    EXPECT_TRUE(v.empty());
    EXPECT_EQ(v.capacity(), 0u);

    v.reserve(10);

    EXPECT_EQ(v.size(), 0u);
    EXPECT_TRUE(v.empty());
    EXPECT_EQ(v.capacity(), 10u);
}

TEST(VectorTests, TestResizeFromEmpty)
{
    coil::Vector<int> v;

    EXPECT_EQ(v.size(), 0u);
    EXPECT_TRUE(v.empty());
    EXPECT_EQ(v.capacity(), 0u);

    v.resize(10);

    EXPECT_EQ(v.size(), 10u);
    EXPECT_FALSE(v.empty());
    EXPECT_GE(v.capacity(), 10u);
}

TEST(VectorTests, TestResizeGrow)
{
    coil::Vector<int> v;

    v.reserve(10);
    for (auto i = 0; i < 10; i++)
        v.pushBack(i);

    EXPECT_EQ(v.size(), 10u);
    EXPECT_FALSE(v.empty());
    EXPECT_EQ(v.capacity(), 10u);

    v.resize(20);

    EXPECT_EQ(v.size(), 20u);
    EXPECT_FALSE(v.empty());
    EXPECT_GE(v.capacity(), 10u);
}

TEST(VectorTests, TestResizeNoGrow)
{
    coil::Vector<int> v;

    v.reserve(20);
    for (auto i = 0; i < 10; i++)
        v.pushBack(i);

    EXPECT_EQ(v.size(), 10u);
    EXPECT_FALSE(v.empty());
    EXPECT_EQ(v.capacity(), 20u);

    v.resize(20);

    EXPECT_EQ(v.size(), 20u);
    EXPECT_FALSE(v.empty());
    EXPECT_GE(v.capacity(), 20u);
}

TEST(VectorTests, TestResizeShrink)
{
    coil::Vector<int> v;

    v.reserve(10);
    for (auto i = 0; i < 10; i++)
        v.pushBack(i);

    EXPECT_EQ(v.size(), 10u);
    EXPECT_FALSE(v.empty());
    EXPECT_EQ(v.capacity(), 10u);

    v.resize(5);

    EXPECT_EQ(v.size(), 5u);
    EXPECT_FALSE(v.empty());
    EXPECT_GE(v.capacity(), 10u);
}

TEST(VectorTests, TestDefaultConstructor)
{
    coil::Vector<int> v;

    EXPECT_EQ(v.size(), 0u);
    EXPECT_EQ(v.capacity(), 0u);
}

TEST(VectorTests, TestSpanConstructor)
{
    int data[5] = { 0,1,2,3,4 };
    coil::Vector<int> v{ data, 5 };

    ASSERT_EQ(v.size(), 5u);
    EXPECT_EQ(v[0], 0);
    EXPECT_EQ(v[1], 1);
    EXPECT_EQ(v[2], 2);
    EXPECT_EQ(v[3], 3);
    EXPECT_EQ(v[4], 4);
}

TEST(VectorTests, TestCopyConstructor)
{
    coil::Vector<int> v;
    for (auto i = 0; i < 5; i++)
        v.pushBack(i);

    ASSERT_EQ(v.size(), 5u);
    EXPECT_EQ(v[0], 0);
    EXPECT_EQ(v[1], 1);
    EXPECT_EQ(v[2], 2);
    EXPECT_EQ(v[3], 3);
    EXPECT_EQ(v[4], 4);

    coil::Vector<int> const v2 = v;

    ASSERT_EQ(v.size(), 5u);
    EXPECT_EQ(v[0], 0);
    EXPECT_EQ(v[1], 1);
    EXPECT_EQ(v[2], 2);
    EXPECT_EQ(v[3], 3);
    EXPECT_EQ(v[4], 4);

    ASSERT_EQ(v2.size(), 5u);
    EXPECT_EQ(v2[0], 0);
    EXPECT_EQ(v2[1], 1);
    EXPECT_EQ(v2[2], 2);
    EXPECT_EQ(v2[3], 3);
    EXPECT_EQ(v2[4], 4);
}

TEST(VectorTests, TestMoveConstructor)
{
    coil::Vector<int> v;
    for (auto i = 0; i < 5; i++)
        v.pushBack(i);

    ASSERT_EQ(v.size(), 5u);
    EXPECT_EQ(v[0], 0);
    EXPECT_EQ(v[1], 1);
    EXPECT_EQ(v[2], 2);
    EXPECT_EQ(v[3], 3);
    EXPECT_EQ(v[4], 4);

    coil::Vector<int> const v2 = coil::move(v);

    ASSERT_EQ(v2.size(), 5u);
    EXPECT_EQ(v2[0], 0);
    EXPECT_EQ(v2[1], 1);
    EXPECT_EQ(v2[2], 2);
    EXPECT_EQ(v2[3], 3);
    EXPECT_EQ(v2[4], 4);

    ASSERT_EQ(v.size(), 0u);
}

TEST(VectorTests, TestCopyAssignment)
{
    coil::Vector<int> v;
    for (auto i = 0; i < 5; i++)
        v.pushBack(i);

    ASSERT_EQ(v.size(), 5u);
    EXPECT_EQ(v[0], 0);
    EXPECT_EQ(v[1], 1);
    EXPECT_EQ(v[2], 2);
    EXPECT_EQ(v[3], 3);
    EXPECT_EQ(v[4], 4);

    coil::Vector<int> v2;
    v2 = v;

    ASSERT_EQ(v.size(), 5u);
    EXPECT_EQ(v[0], 0);
    EXPECT_EQ(v[1], 1);
    EXPECT_EQ(v[2], 2);
    EXPECT_EQ(v[3], 3);
    EXPECT_EQ(v[4], 4);

    ASSERT_EQ(v2.size(), 5u);
    EXPECT_EQ(v2[0], 0);
    EXPECT_EQ(v2[1], 1);
    EXPECT_EQ(v2[2], 2);
    EXPECT_EQ(v2[3], 3);
    EXPECT_EQ(v2[4], 4);
}

TEST(VectorTests, TestMoveAssignment)
{
    coil::Vector<int> v;
    for (auto i = 0; i < 5; i++)
        v.pushBack(i);

    ASSERT_EQ(v.size(), 5u);
    EXPECT_EQ(v[0], 0);
    EXPECT_EQ(v[1], 1);
    EXPECT_EQ(v[2], 2);
    EXPECT_EQ(v[3], 3);
    EXPECT_EQ(v[4], 4);

    coil::Vector<int> v2;
    v2 = coil::move(v);

    ASSERT_EQ(v2.size(), 5u);
    EXPECT_EQ(v2[0], 0);
    EXPECT_EQ(v2[1], 1);
    EXPECT_EQ(v2[2], 2);
    EXPECT_EQ(v2[3], 3);
    EXPECT_EQ(v2[4], 4);

    ASSERT_EQ(v.size(), 0u);
}

TEST(VectorTests, TestData)
{
    coil::Vector<int> v;
    for (auto i = 0; i < 5; i++)
        v.pushBack(i);

    ASSERT_EQ(v.size(), 5u);

    coil::Vector<int> const& constV = v;

    int* data = v.data();
    int const* constData = constV.data();

    EXPECT_EQ(data, constData);

    EXPECT_EQ(constData[0], 0);
    EXPECT_EQ(constData[1], 1);
    EXPECT_EQ(constData[2], 2);
    EXPECT_EQ(constData[3], 3);
    EXPECT_EQ(constData[4], 4);

    data[2] = 42;

    EXPECT_EQ(constData[0], 0);
    EXPECT_EQ(constData[1], 1);
    EXPECT_EQ(constData[2], 42);
    EXPECT_EQ(constData[3], 3);
    EXPECT_EQ(constData[4], 4);
}

TEST(VectorTests, TestRange)
{
    coil::Vector<int> v;
    for (auto i = 0; i < 5; i++)
        v.pushBack(i);

    coil::Vector<int> const& constV = v;

    {
        size_t index = 0;
        for (int const& value : constV)
        {
            EXPECT_EQ(value, index);
            index++;
        }
    }

    for (int& value : v)
        value *= 2;

    {
        size_t index = 0;
        for (int const& value : constV)
        {
            EXPECT_EQ(value, index * 2);
            index++;
        }
    }
}

TEST(VectorTests, TestFrontBack)
{
    coil::Vector<int> v;
    for (auto i = 0; i < 5; i++)
        v.pushBack(i);

    coil::Vector<int> const& constV = v;

    ASSERT_EQ(v.size(), 5);

    EXPECT_EQ(constV.front(), 0);
    EXPECT_EQ(constV.back(), 4);

    v.front() = 100;
    v.back() = 104;

    EXPECT_EQ(constV.front(), 100);
    EXPECT_EQ(constV.back(), 104);
}

TEST(VectorTests, TestEqualityComparison)
{
    coil::Vector<int> v1;
    for (auto i = 0; i < 5; i++)
        v1.pushBack(i);

    {
        coil::Vector<int> v2;
        for (auto i = 0; i < 5; i++)
            v2.pushBack(i);

        EXPECT_TRUE(v1 == v2);
    }

    {
        coil::Vector<int> v2;
        for (auto i = 0; i < 5; i++)
            v2.pushBack(100 + i);

        EXPECT_FALSE(v1 == v2);
    }

    {
        coil::Vector<int> v2;
        for (auto i = 0; i < 10; i++)
            v2.pushBack(i);

        EXPECT_FALSE(v1 == v2);
    }
}

TEST(VectorTests, TestPushBackStats)
{
    coil::Vector<Integer> v;

    Integer::resetStats();

    v.pushBack(Integer{ 42 });

    EXPECT_EQ(Integer::constructions, 1u);
    EXPECT_EQ(Integer::copies, 0u);
}

TEST(VectorTests, TestPopBackStats)
{
    coil::Vector<Integer> v;
    v.pushBack(Integer{ 42 });

    Integer::resetStats();

    v.popBack();

    EXPECT_EQ(Integer::constructions, 0u);
    EXPECT_EQ(Integer::copies, 0u);
    EXPECT_EQ(Integer::moves, 0u);
    EXPECT_EQ(Integer::destructions, 1u);
}

TEST(VectorTests, TestReserveStats)
{
    coil::Vector<Integer> v;

    Integer::resetStats();

    v.reserve(10);

    EXPECT_EQ(Integer::constructions, 0u);
    EXPECT_EQ(Integer::copies, 0u);
    EXPECT_EQ(Integer::moves, 0u);
    EXPECT_EQ(Integer::destructions, 0u);
}

TEST(VectorTests, TestResizeFromEmptyStats)
{
    coil::Vector<Integer> v;

    Integer::resetStats();

    v.resize(10);

    EXPECT_EQ(Integer::constructions, 10u);
    EXPECT_EQ(Integer::copies, 0u);
    EXPECT_EQ(Integer::moves, 0u);
    EXPECT_EQ(Integer::destructions, 0u);
}

TEST(VectorTests, TestResizeGrowStats)
{
    coil::Vector<Integer> v;

    v.reserve(10);
    for (auto i = 0; i < 10; i++)
        v.pushBack(i);

    Integer::resetStats();

    v.resize(20);

    EXPECT_EQ(Integer::constructions, 10u);
    EXPECT_EQ(Integer::defaultConstructions, 10u);
    EXPECT_EQ(Integer::copies, 0u);
    EXPECT_EQ(Integer::moves, 10u);
    EXPECT_EQ(Integer::destructions, 10u); // 10 moved-from items
}

TEST(VectorTests, TestResizeNoGrowStats)
{
    coil::Vector<Integer> v;

    v.reserve(20);
    for (auto i = 0; i < 10; i++)
        v.pushBack(i);

    Integer::resetStats();

    v.resize(20);

    EXPECT_EQ(Integer::constructions, 10u);
    EXPECT_EQ(Integer::defaultConstructions, 10u);
    EXPECT_EQ(Integer::copies, 0u);
    EXPECT_EQ(Integer::moves, 0u);
    EXPECT_EQ(Integer::destructions, 0u);
}

TEST(VectorTests, TestResizeShrinkStats)
{
    coil::Vector<Integer> v;

    v.reserve(10);
    for (auto i = 0; i < 10; i++)
        v.pushBack(i);

    Integer::resetStats();

    v.resize(5);

    EXPECT_EQ(Integer::constructions, 0u);
    EXPECT_EQ(Integer::copies, 0u);
    EXPECT_EQ(Integer::moves, 0u);
    EXPECT_EQ(Integer::destructions, 5u);
}

TEST(VectorTests, TestClearStats)
{
    coil::Vector<Integer> v;

    v.reserve(10);
    for (auto i = 0; i < 10; i++)
        v.pushBack(i);

    Integer::resetStats();

    v.clear();

    EXPECT_EQ(Integer::constructions, 0u);
    EXPECT_EQ(Integer::copies, 0u);
    EXPECT_EQ(Integer::moves, 0u);
    EXPECT_EQ(Integer::destructions, 10u);
}

TEST(VectorTests, TestDestructorStats)
{
    {
        coil::Vector<Integer> v;

        for (auto i = 0; i < 10; i++)
            v.pushBack(i);

        Integer::resetStats();
    }

    EXPECT_EQ(Integer::constructions, 0u);
    EXPECT_EQ(Integer::copies, 0u);
    EXPECT_EQ(Integer::moves, 0u);
    EXPECT_EQ(Integer::destructions, 10u);
}
