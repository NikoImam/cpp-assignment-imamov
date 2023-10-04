#include <hw04.h>
#include <gtest/gtest.h>

TEST(Hw04Tests, Test1)
{
    int arr[] = {1, 2, 3, 4, -1, 5, 6, 0, 1, 2};
    std::size_t expected = 10;
    auto actual = hw04(arr, std::size(arr));
    EXPECT_EQ(actual, expected);
}

TEST(Hw04Tests, Test2)
{
    int arr[] = {0};
    std::size_t expected = 0;
    auto actual = hw04(arr, std::size(arr));
    EXPECT_EQ(actual, expected);
}

TEST(Hw04Tests, Test3)
{
    int arr[] = {-1};
    std::size_t expected = 0;
    auto actual = hw04(arr, std::size(arr));
    EXPECT_EQ(actual, expected);
}

TEST(Hw04Tests, Test4)
{
    int arr[] = {1, 2, 3, -1};
    std::size_t expected = 6;
    auto actual = hw04(arr, std::size(arr));
    EXPECT_EQ(actual, expected);
}

TEST(Hw04Tests, Test5)
{
    int arr[] = {11, 0, -22, 33, -1};
    std::size_t expected = 11;
    auto actual = hw04(arr, std::size(arr));
    EXPECT_EQ(actual, expected);
}

TEST(Hw04Tests, Test6)
{
    int arr[] = {'A', 'B', 'C', 'T', -1};
    std::size_t expected = 'A' + 'B' + 'C' + 'T';
    auto actual = hw04(arr, std::size(arr));
    EXPECT_EQ(actual, expected);
}

TEST(Hw04Tests, Test7)
{
    int arr[] = {'A', -1, 'B', 'C', 'T'};
    std::size_t expected = 'A';
    auto actual = hw04(arr, std::size(arr));
    EXPECT_EQ(actual, expected);
}

TEST(Hw04Tests, Test8)
{
    int arr[] = {'0', -1, 'B', 'C', -1, 'T'};
    std::size_t not_expected = '0' + 'B' + 'C';
    std::size_t expected = '0';
    auto actual = hw04(arr, std::size(arr));
    EXPECT_NE(actual, not_expected);
    EXPECT_EQ(actual, expected);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}