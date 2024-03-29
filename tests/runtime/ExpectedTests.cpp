#include "Common.h"

#include "gtest/gtest.h"

namespace
{
    template<typename T>
    class Dummy
    {
    public:
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
            copies = 0;
            moves = 0;
            copyConstructions = 0;
            moveConstructions = 0;
            copyAssignments = 0;
            moveAssignments = 0;
            destructions = 0;
        }
    };

    using V = Dummy<int>;
    using E = Dummy<float>;

    void resetStats()
    {
        V::resetStats();
        E::resetStats();
    }
}

TEST(ExpectedTests, TestValueInitialization)
{
    resetStats();

    coil::Expected<V, E> e = V{42};

    EXPECT_EQ(V::constructions, 1u);
    EXPECT_EQ(V::copies, 0u);
    EXPECT_GE(V::moveConstructions, 1u);

    EXPECT_EQ(E::constructions, 0u);
    EXPECT_EQ(E::copyConstructions, 0u);
    EXPECT_EQ(E::moveConstructions, 0u);
    EXPECT_EQ(E::destructions, 0u);

    ASSERT_TRUE(e);
    EXPECT_EQ(*e, V{42});
}

TEST(ExpectedTests, TestErrorInitialization)
{
    resetStats();

    coil::Expected<V, E> e = coil::makeUnexpected(E{3.14f});

    EXPECT_EQ(E::constructions, 1u);
    EXPECT_EQ(E::copies, 0u);
    EXPECT_GE(E::moveConstructions, 1u);

    EXPECT_EQ(V::constructions, 0u);
    EXPECT_EQ(V::copyConstructions, 0u);
    EXPECT_EQ(V::moveConstructions, 0u);
    EXPECT_EQ(V::destructions, 0u);

    ASSERT_FALSE(e);
    EXPECT_EQ(e.error(), E{3.14f});
}

TEST(ExpectedTests, TestValueCopyInitialization)
{
    coil::Expected<V, E> e1 = V{42};

    resetStats();

    coil::Expected<V, E> e2 = e1;

    EXPECT_EQ(V::copyConstructions, 1u);
    EXPECT_EQ(V::copyAssignments, 0u);
    EXPECT_EQ(V::copies, 1u);

    ASSERT_TRUE(e1);
    EXPECT_EQ(*e1, V{42});
    ASSERT_TRUE(e2);
    EXPECT_EQ(*e2, V{42});
}

TEST(ExpectedTests, TestErrorCopyInitialization)
{
    coil::Expected<V, E> e1 = coil::makeUnexpected(E{3.14f});

    resetStats();

    coil::Expected<V, E> e2 = e1;

    EXPECT_EQ(E::copyConstructions, 1u);
    EXPECT_EQ(E::copyAssignments, 0u);
    EXPECT_EQ(E::copies, 1u);

    ASSERT_FALSE(e1);
    EXPECT_EQ(e1.error(), E{3.14f});
    ASSERT_FALSE(e2);
    EXPECT_EQ(e2.error(), E{3.14f});
}

TEST(ExpectedTests, TestValueMoveInitialization)
{
    coil::Expected<V, E> e1 = V{42};

    resetStats();

    coil::Expected<V, E> e2 = std::move(e1);

    EXPECT_EQ(V::copies, 0u);
    EXPECT_GE(V::moveConstructions, 1u);

    ASSERT_TRUE(e1);
    EXPECT_EQ(*e1, V{0});
    ASSERT_TRUE(e2);
    EXPECT_EQ(*e2, V{42});
}

TEST(ExpectedTests, TestErrorMoveInitialization)
{
    coil::Expected<V, E> e1 = coil::makeUnexpected(E{3.14f});

    resetStats();

    coil::Expected<V, E> e2 = std::move(e1);

    EXPECT_EQ(E::copies, 0u);
    EXPECT_GE(E::moveConstructions, 1u);

    ASSERT_FALSE(e1);
    EXPECT_EQ(e1.error(), E{0.0f});
    ASSERT_FALSE(e2);
    EXPECT_EQ(e2.error(), E{3.14f});
}

TEST(ExpectedTests, TestValueCopyAssignment)
{
    coil::Expected<V, E> e1 = V{42};
    coil::Expected<V, E> e2 = V{0};

    resetStats();

    e2 = e1;

    EXPECT_EQ(V::copyConstructions, 0u);
    EXPECT_EQ(V::copyAssignments, 1u);
    EXPECT_EQ(V::copies, 1u);

    ASSERT_TRUE(e1);
    EXPECT_EQ(*e1, V{42});
    ASSERT_TRUE(e2);
    EXPECT_EQ(*e2, V{42});
}

TEST(ExpectedTests, TestErrorCopyAssignment)
{
    coil::Expected<V, E> e1 = coil::makeUnexpected(E{3.14f});
    coil::Expected<V, E> e2 = coil::makeUnexpected(E{0.0f});

    resetStats();

    e2 = e1;

    EXPECT_EQ(E::copyConstructions, 0u);
    EXPECT_EQ(E::copyAssignments, 1u);
    EXPECT_EQ(E::copies, 1u);

    ASSERT_FALSE(e1);
    EXPECT_EQ(e1.error(), E{3.14f});
    ASSERT_FALSE(e2);
    EXPECT_EQ(e2.error(), E{3.14f});
}

TEST(ExpectedTests, TestValueErrorCopyAssignment)
{
    coil::Expected<V, E> e1 = V{42};
    coil::Expected<V, E> e2 = coil::makeUnexpected(E{0.0f});

    resetStats();

    e2 = e1;

    EXPECT_EQ(E::moves, 0u);
    EXPECT_EQ(V::moves, 0u);
    EXPECT_GE(E::copyAssignments, 0u);
    EXPECT_GE(V::copyAssignments, 0u);
    EXPECT_GE(E::copyConstructions, 0u);
    EXPECT_GE(V::copyConstructions, 1u);

    ASSERT_TRUE(e1);
    EXPECT_EQ(*e1, V{42});
    ASSERT_TRUE(e2);
    EXPECT_EQ(*e2, V{42});
}

TEST(ExpectedTests, TestValueMoveAssignment)
{
    coil::Expected<V, E> e1 = V{42};
    coil::Expected<V, E> e2 = V{0};

    resetStats();

    e2 = std::move(e1);

    EXPECT_EQ(V::copies, 0u);
    EXPECT_GE(V::moveAssignments, 1u);

    ASSERT_TRUE(e2);
    EXPECT_EQ(*e2, V{42});
}

TEST(ExpectedTests, TestErrorMoveAssignment)
{
    coil::Expected<V, E> e1 = coil::makeUnexpected(E{3.14f});
    coil::Expected<V, E> e2 = coil::makeUnexpected(E{0.0f});

    resetStats();

    e2 = std::move(e1);

    EXPECT_EQ(E::copies, 0u);
    EXPECT_GE(E::moveAssignments, 1u);

    ASSERT_FALSE(e2);
    EXPECT_EQ(e2.error(), E{3.14f});
}

TEST(ExpectedTests, TestValueErrorMoveAssignment)
{
    coil::Expected<V, E> e1 = V{42};
    coil::Expected<V, E> e2 = coil::makeUnexpected(E{0.0f});

    resetStats();

    e2 = std::move(e1);

    EXPECT_EQ(E::copies, 0u);
    EXPECT_EQ(V::copies, 0u);
    EXPECT_GE(E::moveAssignments, 0u);
    EXPECT_GE(V::moveAssignments, 0u);
    EXPECT_GE(E::moveConstructions, 0u);
    EXPECT_GE(V::moveConstructions, 1u);

    ASSERT_TRUE(e2);
    EXPECT_EQ(*e2, V{42});
}

TEST(ExpectedTests, TestExpectedArrow)
{
    coil::Expected<V, E> e1 = V{42};
    coil::Expected<V, E> const e2 = V{42};

    EXPECT_EQ(e1->payload(), 42);
    EXPECT_EQ(e2->payload(), 42);
}
