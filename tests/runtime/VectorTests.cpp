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
        Dummy(T payload) : m_payload(std::move(payload))
        {
            constructions++;
        }
        Dummy(Dummy<T> const& rhs) : m_payload(rhs.m_payload)
        {
            copies++;
            copyConstructions++;
        }
        Dummy(Dummy<T>&& rhs) : m_payload(std::move(rhs.m_payload))
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
            m_payload = std::move(rhs.m_payload);
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
        inline static std::size_t constructions = 0;
        inline static std::size_t defaultConstructions = 0;
        inline static std::size_t copies = 0;
        inline static std::size_t moves = 0;
        inline static std::size_t copyConstructions = 0;
        inline static std::size_t moveConstructions = 0;
        inline static std::size_t copyAssignments = 0;
        inline static std::size_t moveAssignments = 0;
        inline static std::size_t destructions = 0;

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
