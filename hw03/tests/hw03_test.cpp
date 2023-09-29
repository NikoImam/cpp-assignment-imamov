#include <hw03.h>
#include <gtest/gtest.h>

TEST(Hw03Tests, Test1)
{
    const auto expected = "Hello_";
    char input[] = {"Hello_World"};
    hw03(input, "World");
    EXPECT_EQ(std::string(expected), std::string(input));
}

TEST(Hw03Tests, Test2)
{
    const auto expected = "@!$%COMPLETE%$!@";
    char input[] = {"@!$%HW03COMPLETE%$!@"};
    hw03(input, "HW03");
    EXPECT_EQ(std::string(expected), std::string(input));
}

TEST(Hw03Tests, Test3)
{
    const auto expected = "START__END";
    char input[] = {"START_TEXT_END"};
    hw03(input, "TEXT");
    EXPECT_EQ(std::string(expected), std::string(input));
}

TEST(Hw03Tests, Test4)
{
    const auto expected = "T_TEXT_END";
    char input[] = {"START_TEXT_END"};
    hw03(input, "STAR");
    EXPECT_EQ(std::string(expected), std::string(input));
}

TEST(Hw03Tests, Test5)
{
    const auto expected = "START_TEXT_END";
    char input[] = {"START_TEXT_END"};
    hw03(input, "BEGIN");
    EXPECT_EQ(std::string(expected), std::string(input));
}

TEST(Hw03Tests, Test6)
{
    const auto expected = "";
    char input[] = {"START_TEXT_END"};
    hw03(input, "START_TEXT_END");
    EXPECT_EQ(std::string(expected), std::string(input));
}

TEST(Hw03Tests, Test7)
{
    const auto expected = "";
    char input[] = {""};
    hw03(input, "aabbcc");
    EXPECT_EQ(std::string(expected), std::string(input));
}

TEST(Hw03Tests, Test8)
{
    const auto expected = "";
    char input[] = {"A"};
    hw03(input, "A");
    EXPECT_EQ(std::string(expected), std::string(input));
}

TEST(Hw03Tests, Test9)
{
    const auto expected = "ABC";
    char input[] = {"ABC"};
    hw03(input, "BCD");
    EXPECT_EQ(std::string(expected), std::string(input));
}

TEST(Hw03Tests, Test10)
{
    const auto expected = "AB";
    char input[] = {"ABC"};
    hw03(input, "C");
    EXPECT_EQ(std::string(expected), std::string(input));
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}