#include "gtest/gtest.h"

#include "coil/Optional.h"

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
            valueConstructions++;
        }
        Dummy(Dummy<T> const& rhs) : m_payload(rhs.m_payload)
        {
            constructions++;
            copies++;
            copyConstructions++;
        }
        Dummy(Dummy<T>&& rhs) : m_payload(coil::move(rhs.m_payload))
        {
            rhs.m_payload = T{};

            constructions++;
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
        inline static size_t valueConstructions = 0;
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
            valueConstructions = 0;
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

TEST(OptionalTests, TestDefaultConstructor)
{
    coil::Optional<Integer> opt;

    EXPECT_FALSE(opt.hasValue());
    EXPECT_FALSE(opt);

    EXPECT_TRUE(opt == coil::Optional<Integer>{});
    EXPECT_TRUE(opt != coil::Optional<Integer>{0});

    EXPECT_TRUE(opt != 0);
}

TEST(OptionalTests, TestValueConstructor)
{
    coil::Optional<Integer> opt = Integer{42};
    coil::Optional<Integer> const& constOpt = opt;

    ASSERT_TRUE(opt.hasValue());
    ASSERT_TRUE(constOpt.hasValue());
    ASSERT_TRUE(opt);
    ASSERT_TRUE(constOpt);
    EXPECT_EQ(*opt, Integer{42});
    EXPECT_EQ(*constOpt, Integer{42});
    EXPECT_EQ(opt->payload(), 42);
    EXPECT_EQ(constOpt->payload(), 42);

    EXPECT_TRUE(opt != coil::Optional<Integer>{});
    EXPECT_TRUE(opt != coil::Optional<Integer>{0});
    EXPECT_TRUE(opt == coil::Optional<Integer>{42});

    EXPECT_TRUE(opt != 0);
    EXPECT_TRUE(opt == 42);
}

TEST(OptionalTests, TestCopyConstructorFromValue)
{
    coil::Optional<Integer> sourceOpt = Integer{42};
    coil::Optional<Integer> opt = sourceOpt;

    ASSERT_TRUE(sourceOpt);
    EXPECT_EQ(*sourceOpt, Integer{42});
    ASSERT_TRUE(opt);
    EXPECT_EQ(*opt, Integer{42});
    EXPECT_TRUE(sourceOpt == opt);
}

TEST(OptionalTests, TestCopyConstructorFromEmpty)
{
    coil::Optional<Integer> sourceOpt;
    coil::Optional<Integer> opt = sourceOpt;

    EXPECT_FALSE(sourceOpt);
    EXPECT_FALSE(opt);
    EXPECT_TRUE(sourceOpt == opt);
}

TEST(OptionalTests, TestMoveConstructorFromValue)
{
    coil::Optional<Integer> sourceOpt = Integer{42};
    coil::Optional<Integer> opt = coil::move(sourceOpt);

    ASSERT_TRUE(opt);
    EXPECT_EQ(*opt, Integer{42});
}

TEST(OptionalTests, TestMoveConstructorFromEmpty)
{
    coil::Optional<Integer> sourceOpt;
    coil::Optional<Integer> opt = coil::move(sourceOpt);

    EXPECT_FALSE(opt);
}

TEST(OptionalTests, TestCopyAssignment)
{
    coil::Optional<Integer> sourceOpt = Integer{42};
    coil::Optional<Integer> opt = Integer{0};
    opt = sourceOpt;

    ASSERT_TRUE(sourceOpt);
    EXPECT_EQ(*sourceOpt, Integer{42});
    ASSERT_TRUE(opt);
    EXPECT_EQ(*opt, Integer{42});
    EXPECT_TRUE(sourceOpt == opt);
}

TEST(OptionalTests, TestMoveAssignment)
{
    coil::Optional<Integer> sourceOpt = Integer{42};
    coil::Optional<Integer> opt = Integer{0};
    opt = coil::move(sourceOpt);

    ASSERT_TRUE(opt);
    EXPECT_EQ(*opt, Integer{42});
}

TEST(OptionalTests, TestDefaultConstructorStats)
{
    Integer::resetStats();

    {
        coil::Optional<Integer> opt;
    }

    EXPECT_EQ(Integer::constructions, 0u);
    EXPECT_EQ(Integer::copies, 0u);
    EXPECT_EQ(Integer::moves, 0u);
    EXPECT_EQ(Integer::destructions, 0u);
}

TEST(OptionalTests, TestCopyValueConstructorStats)
{
    Integer source{42};

    {
        Integer::resetStats();

        coil::Optional<Integer> opt = source;

        EXPECT_EQ(Integer::constructions, 1u);
        EXPECT_EQ(Integer::copies, 1u);
        EXPECT_EQ(Integer::moves, 0u);
        EXPECT_EQ(Integer::destructions, 0u);
    }

    EXPECT_EQ(Integer::constructions, 1u);
    EXPECT_EQ(Integer::copyConstructions, 1u);
    EXPECT_EQ(Integer::moves, 0u);
    EXPECT_EQ(Integer::destructions, 1u);
}

TEST(OptionalTests, TestMoveValueConstructorStats)
{
    Integer source{42};

    {
        Integer::resetStats();

        coil::Optional<Integer> opt = coil::move(source);

        EXPECT_EQ(Integer::constructions, 1u);
        EXPECT_EQ(Integer::copies, 0u);
        EXPECT_EQ(Integer::moveConstructions, 1u);
        EXPECT_EQ(Integer::moveAssignments, 0u);
        EXPECT_EQ(Integer::destructions, 0u);
    }

    EXPECT_EQ(Integer::constructions, 1u);
    EXPECT_EQ(Integer::copies, 0u);
    EXPECT_EQ(Integer::moveConstructions, 1u);
    EXPECT_EQ(Integer::moveAssignments, 0u);
    EXPECT_EQ(Integer::destructions, 1u);
}

TEST(OptionalTests, TestCopyConstructorStats)
{
    coil::Optional<Integer> source = Integer{42};

    {
        Integer::resetStats();

        coil::Optional<Integer> opt = source;

        EXPECT_EQ(Integer::constructions, 1u);
        EXPECT_EQ(Integer::copies, 1u);
        EXPECT_EQ(Integer::moves, 0u);
        EXPECT_EQ(Integer::destructions, 0u);
    }

    EXPECT_EQ(Integer::constructions, 1u);
    EXPECT_EQ(Integer::copies, 1u);
    EXPECT_EQ(Integer::moves, 0u);
    EXPECT_EQ(Integer::destructions, 1u);
}

TEST(OptionalTests, TestMoveConstructorStats)
{
    coil::Optional<Integer> source = Integer{42};

    {
        Integer::resetStats();

        coil::Optional<Integer> opt = coil::move(source);

        EXPECT_EQ(Integer::constructions, 1u);
        EXPECT_EQ(Integer::copies, 0u);
        EXPECT_EQ(Integer::moves, 1u);
        EXPECT_EQ(Integer::destructions, 0u);
    }

    EXPECT_EQ(Integer::constructions, 1u);
    EXPECT_EQ(Integer::copies, 0u);
    EXPECT_EQ(Integer::moves, 1u);
    EXPECT_EQ(Integer::destructions, 1u);
}

TEST(OptionalTests, TestMoveAssignmentValueFromEmptyStats)
{
    coil::Optional<Integer> opt;
    coil::Optional<Integer> source = Integer{42};

    {
        Integer::resetStats();

        opt = coil::move(source);

        EXPECT_EQ(Integer::copies, 0u);
        EXPECT_EQ(Integer::moveConstructions, 1u);
    }
}

TEST(OptionalTests, TestMoveAssignmentValueFromValueCall)
{
    coil::Optional<Integer> opt = Integer{314};
    coil::Optional<Integer> source = Integer{42};

    {
        Integer::resetStats();

        opt = coil::move(source);

        EXPECT_EQ(Integer::copies, 0u);
        EXPECT_EQ(Integer::moveAssignments, 1u);
    }
}

TEST(OptionalTests, TestMoveAssignmentEmptyFromValueCall)
{
    coil::Optional<Integer> opt = Integer{314};
    coil::Optional<Integer> source;

    {
        Integer::resetStats();

        opt = coil::move(source);

        EXPECT_EQ(Integer::copies, 0u);
        EXPECT_EQ(Integer::moves, 0u);
        EXPECT_EQ(Integer::destructions, 1u);
    }
}

TEST(OptionalTests, TestCopyAssignmentValueFromEmptyStats)
{
    coil::Optional<Integer> opt;
    coil::Optional<Integer> source = Integer{42};

    {
        Integer::resetStats();

        opt = source;

        EXPECT_EQ(Integer::copyConstructions, 1u);
        EXPECT_EQ(Integer::moves, 0u);
    }
}

TEST(OptionalTests, TestCopyAssignmentValueFromValueCall)
{
    coil::Optional<Integer> opt = Integer{314};
    coil::Optional<Integer> source = Integer{42};

    {
        Integer::resetStats();

        opt = source;

        EXPECT_EQ(Integer::copyAssignments, 1u);
        EXPECT_EQ(Integer::moves, 0u);
    }
}

TEST(OptionalTests, TestCopyAssignmentEmptyFromValueCall)
{
    coil::Optional<Integer> opt = Integer{314};
    coil::Optional<Integer> source;

    {
        Integer::resetStats();

        opt = source;

        EXPECT_EQ(Integer::copies, 0u);
        EXPECT_EQ(Integer::moves, 0u);
        EXPECT_EQ(Integer::destructions, 1u);
    }
}
