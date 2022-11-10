#include "gtest/gtest.h"

#include "coil/Buffer.h"

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

TEST(BufferTests, TestConstructor)
{
    coil::Buffer buf{ 10, 1 };

    EXPECT_EQ(buf.capacity(), 10);
}

TEST(BufferTests, TestDefaultConstructor)
{
    coil::Buffer buf;

    EXPECT_EQ(buf.capacity(), 0);
}

TEST(BufferTests, TestCopyConstructor)
{
    coil::Buffer buf1{ 10, 1 };
    coil::Buffer buf2 = buf1;

    EXPECT_EQ(buf1.capacity(), 10);
    EXPECT_EQ(buf2.capacity(), 10);
}

TEST(BufferTests, TestMoveConstructor)
{
    coil::Buffer buf1{ 10, 1 };
    coil::Buffer buf2 = coil::move(buf1);

    EXPECT_EQ(buf2.capacity(), 10);
}

TEST(BufferTests, TestCopyAssignment)
{
    coil::Buffer buf1{ 10, 1 };
    coil::Buffer buf2{ 100, 8 };
    buf2 = buf1;

    EXPECT_EQ(buf1.capacity(), 10);
    EXPECT_EQ(buf2.capacity(), 10);
}

TEST(BufferTests, TestMoveAssignment)
{
    coil::Buffer buf1{ 10, 1 };
    coil::Buffer buf2{ 100, 8 };
    buf2 = coil::move(buf1);

    EXPECT_EQ(buf2.capacity(), 10);
}

TEST(BufferTests, TestCopy)
{
    coil::Buffer buf{ 10, 1 };

    char const* str = "hello";
    buf.copy(str, strlen(str) + 1);
    EXPECT_STRCASEEQ(buf.data(), "hello");

    buf.copy(nullptr, 0);
    EXPECT_STRCASEEQ(buf.data(), "hello");
}

TEST(BufferTests, TestAccessors)
{
    coil::Buffer buf{ 10, 1 };
    coil::Buffer const& constBuf = buf;

    char* at0 = buf.get(0);
    ASSERT_TRUE(at0);

    *at0 = '\0';
    EXPECT_EQ(*buf.get(0), '\0');
    EXPECT_EQ(*constBuf.get(0), '\0');

    EXPECT_STRCASEEQ(buf.data(), "");
    EXPECT_STRCASEEQ(constBuf.data(), "");

    char const* str = "hello";
    buf.copy(str, strlen(str) + 1);

    EXPECT_STRCASEEQ(buf.data(), "hello");
    EXPECT_STRCASEEQ(constBuf.data(), "hello");
}

TEST(BufferTests, TestResize)
{
    coil::Buffer buf{ 10, 1 };
    char const* str = "hello";
    buf.copy(str, strlen(str) + 1);
    buf.resize(strlen(str) + 1);

    EXPECT_EQ(buf.size(), 6);
}

TEST(BufferTests, TestTypedOperations)
{
    coil::Buffer buf{ 10, sizeof(Integer) };
    coil::Buffer const& constBuf = buf;

    Integer::resetStats();
    buf.constructNext<Integer>(42);

    EXPECT_EQ(Integer::constructions, 1u);
    EXPECT_EQ(Integer::copies, 0u);
    EXPECT_EQ(Integer::moves, 0u);
    EXPECT_EQ(Integer::destructions, 0u);

    EXPECT_EQ(buf.capacity(), 10);
    ASSERT_EQ(buf.size(), 1);

    Integer* integer = buf.get<Integer>(0);
    Integer const* constInteger = constBuf.get<Integer>(0);
    ASSERT_TRUE(integer);
    ASSERT_TRUE(constInteger);
    EXPECT_EQ(*integer, 42);
    EXPECT_EQ(*constInteger, 42);

    *integer = 0;
    EXPECT_EQ(*integer, 0);
    EXPECT_EQ(*constInteger, 0);

    Integer::resetStats();
    buf.destructLast<Integer>();

    EXPECT_EQ(Integer::constructions, 0u);
    EXPECT_EQ(Integer::copies, 0u);
    EXPECT_EQ(Integer::moves, 0u);
    EXPECT_EQ(Integer::destructions, 1u);
}
