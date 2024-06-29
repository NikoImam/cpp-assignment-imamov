#include <hw01.h>
#include <gtest/gtest.h>

TEST(Hw01Tests, Test1)
{
    const auto expected = -1;
    const auto actual = hw01(2, 5);
    EXPECT_EQ(expected, actual);
}

TEST(Hw01Tests, Test2)
{
    const auto expected = 6;
    const auto actual = hw01(11, 15);
    EXPECT_EQ(expected, actual);
}

TEST(Hw01Tests, Test3)
{
    const auto expected = -1;
    const auto actual = hw01(2, 11);
    EXPECT_EQ(expected, actual);
}

TEST(Hw01Tests, Test4)
{
    const auto expected = 2 + 4 + 8 + 10 + 5 + 11 + 4 + 10;
    const auto actual = hw01(10, 40);
    EXPECT_EQ(expected, actual);
}


int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
