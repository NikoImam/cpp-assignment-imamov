#include <hw06.h>
#include <gtest/gtest.h>

TEST(Hw06Tests, Test1)
{
    auto vect = MyIntVector();
    EXPECT_EQ(vect.size(), 0);
}

TEST(Hw06Tests, Test2)
{
    auto vect = MyIntVector(10);
    EXPECT_EQ(vect.size(), 0);
}

TEST(Hw06Tests, Test3)
{
    auto vect = MyIntVector(25, 5);
    EXPECT_EQ(vect.size(), 25);
}

TEST(Hw06Tests, Test4)
{
    auto vect = MyIntVector(10);
    EXPECT_EQ(vect.capacity(), 10);
}

TEST(Hw06Tests, Test5)
{
    auto vect = MyIntVector(10);
    vect.push_back(5);
    vect.push_back(-3);
    vect.push_back(2700000);
    EXPECT_EQ(vect[1], -3);
}

TEST(Hw06Tests, Test6)
{
    auto vect = MyIntVector(10);
    vect.push_back(5);
    vect.push_back(-3);
    vect.push_back(2700000);
    vect.push_back(7);
    vect.push_back(-323);
    vect.push_back(-342004500);
    vect.resize(5);
    EXPECT_EQ(*vect.end(), 0);
}

TEST(Hw06Tests, Test7)
{
    auto vect = MyIntVector(10);
    vect.push_back(5);
    vect.push_back(-3);
    vect.push_back(2700000);
    vect.push_back(7);
    vect.push_back(-323);
    vect.push_back(-342004500);
    vect.resize(15, 18);
    EXPECT_EQ(vect[13], 18);
}

TEST(Hw06Tests, Test8)
{
    auto vect = MyIntVector(10);
    vect.push_back(5);
    vect.push_back(-3);
    vect.push_back(2700000);
    vect.push_back(7);
    vect.push_back(-323);
    vect.push_back(-342004500);
    vect.reserve(50);
    EXPECT_EQ(vect.capacity(), 50);
}

TEST(Hw06Tests, Test9)
{
    auto vect = MyIntVector(10);
    vect.push_back(5);
    vect.push_back(-3);
    vect.push_back(2700000);
    vect.push_back(7);
    vect.push_back(-323);
    vect.push_back(-342004500);
    EXPECT_EQ(*vect.begin(), 5);
}

TEST(Hw06Tests, Test10)
{
    auto vect = MyIntVector(10);
    vect.push_back(5);
    vect.push_back(-3);
    vect.push_back(2700000);
    vect.push_back(7);
    vect.push_back(-323);
    vect.push_back(-342004500);
    vect.resize(6);
    vect.reserve(50);
    vect.shrink_to_fit();
    EXPECT_EQ(vect.capacity(), 6);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}