#include <hw02.h>
#include <gtest/gtest.h>

TEST(Hw02Tests, Test1)
{
    const auto expected = "Helo";
    const auto actual = hw02("Hello");
    EXPECT_EQ(expected, actual);
}

TEST(Hw02Tests, Test2)
{
    const auto expected = "ABC";
    const auto actual = hw02("AABBCC");
    EXPECT_EQ(expected, actual);
}

TEST(Hw02Tests, Test3)
{
    const auto expected = "!HW02COMPLET";
    const auto actual = hw02("!HHWW02COMPLLETEE!");
    EXPECT_EQ(expected, actual);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}