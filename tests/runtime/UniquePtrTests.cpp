#include "gtest/gtest.h"

#include "coil/UniquePtr.h"

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

TEST(UniquePtrTests, TestMakeUnique)
{
    coil::UniquePtr<Integer> ptr = coil::makeUnique<Integer>(42);
    coil::UniquePtr<Integer> const& constPtr = ptr;

    ASSERT_TRUE(ptr);
    ASSERT_TRUE(constPtr);

    EXPECT_EQ(ptr->payload(), 42);
    EXPECT_EQ(constPtr->payload(), 42);

    ASSERT_TRUE(ptr.get() != nullptr);
    ASSERT_TRUE(constPtr.get() != nullptr);
    EXPECT_EQ(ptr.get()->payload(), 42);
    EXPECT_EQ(constPtr.get()->payload(), 42);

    EXPECT_EQ((*ptr).payload(), 42);
    EXPECT_EQ((*constPtr).payload(), 42);
}

TEST(UniquePtrTests, TestMoveConstructor)
{
    coil::UniquePtr<Integer> sourcePtr = coil::makeUnique<Integer>(42);
    coil::UniquePtr<Integer> ptr = coil::move(sourcePtr);

    ASSERT_TRUE(ptr);
    EXPECT_EQ(ptr->payload(), 42);
}

TEST(UniquePtrTests, TestMoveAssignment)
{
    coil::UniquePtr<Integer> sourcePtr = coil::makeUnique<Integer>(42);
    coil::UniquePtr<Integer> ptr = coil::makeUnique<Integer>(314);
    ptr = coil::move(sourcePtr);

    ASSERT_TRUE(ptr);
    EXPECT_EQ(ptr->payload(), 42);
}

TEST(UniquePtrTests, TestMakeUniqueStats)
{
    Integer::resetStats();

    coil::UniquePtr<Integer> ptr = coil::makeUnique<Integer>(42);

    EXPECT_EQ(Integer::constructions, 1u);
    EXPECT_EQ(Integer::copies, 0u);
    EXPECT_EQ(Integer::moves, 0u);
    EXPECT_EQ(Integer::destructions, 0u);
}

TEST(UniquePtrTests, TestMoveConstructorStats)
{
    coil::UniquePtr<Integer> sourcePtr = coil::makeUnique<Integer>(42);

    Integer::resetStats();

    coil::UniquePtr<Integer> ptr = coil::move(sourcePtr);

    EXPECT_EQ(Integer::constructions, 0u);
    EXPECT_EQ(Integer::copies, 0u);
    EXPECT_EQ(Integer::moves, 0u);
    EXPECT_EQ(Integer::destructions, 0u);
}

TEST(UniquePtrTests, TestMoveAssignmentStats)
{
    coil::UniquePtr<Integer> sourcePtr = coil::makeUnique<Integer>(42);
    coil::UniquePtr<Integer> ptr = coil::makeUnique<Integer>(314);

    Integer::resetStats();

    ptr = coil::move(sourcePtr);

    EXPECT_EQ(Integer::constructions, 0u);
    EXPECT_EQ(Integer::copies, 0u);
    EXPECT_EQ(Integer::moves, 0u);
    EXPECT_EQ(Integer::destructions, 0u);
}

TEST(UniquePtrTests, TestDestructorStats)
{
    {
        coil::UniquePtr<Integer> ptr = coil::makeUnique<Integer>(42);

        Integer::resetStats();
    }

    EXPECT_EQ(Integer::constructions, 0u);
    EXPECT_EQ(Integer::copies, 0u);
    EXPECT_EQ(Integer::moves, 0u);
    EXPECT_EQ(Integer::destructions, 1u);
}

TEST(UniquePtrTests, TestCastToRelatedType)
{
    struct Base
    {
        virtual ~Base() = default;
        virtual int func() { return 42; }
    };

    struct Child : public Base
    {
        int func() override { return 314; }
    };

    coil::UniquePtr<Base> ptr = coil::makeUnique<Child>();

    ASSERT_TRUE(ptr);
    EXPECT_EQ(ptr->func(), 314);
}
