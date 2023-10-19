#include <hw05.h>
#include <gtest/gtest.h>

TEST(Hw05Tests, Test1)
{
    VecOfStr input{"madam", "radar", "anagram", "rotor"};
    auto expected = VecOfStr{"madam", "radar", "rotor"};
    auto actual = hw05(input);
    EXPECT_EQ(actual, expected);
}

TEST(Hw05Tests, Test2)
{
    VecOfStr input{"Madam, in Eden, I'm Adam"};
    auto expected = VecOfStr{"Madam, in Eden, I'm Adam"};
    auto actual = hw05(input);
    EXPECT_EQ(actual, expected);
}

TEST(Hw05Tests, Test3)
{
    VecOfStr input{"Red roses run no risk, sir, on Nurse's order"};
    auto expected = VecOfStr{"Red roses run no risk, sir, on Nurse's order"};
    auto actual = hw05(input);
    EXPECT_EQ(actual, expected);
}

TEST(Hw05Tests, Test4)
{
    VecOfStr input{"Won't lovers revolt now?"};
    auto expected = VecOfStr{"Won't lovers revolt now?"};
    auto actual = hw05(input);
    EXPECT_EQ(actual, expected);
}

TEST(Hw05Tests, Test5)
{
    VecOfStr input{"A man, a plan, a canal, Panama!", "SIMPLETEXT"};
    auto expected = VecOfStr{"A man, a plan, a canal, Panama!"};
    auto actual = hw05(input);
    EXPECT_EQ(actual, expected);
}

//MyTests

TEST(Hw05Tests, Test6)
{
    VecOfStr input{"Cowwow", "aboba"};
    auto expected = VecOfStr{"aboba"};
    auto actual = hw05(input);
    EXPECT_EQ(actual, expected);
}

TEST(Hw05Tests, Test7)
{
    VecOfStr input{"iskat -taksi", "makaka","Cigar? Toss it in a can. It is so tragic"};
    auto expected = VecOfStr{"iskat -taksi", "Cigar? Toss it in a can. It is so tragic"};
    auto actual = hw05(input);
    EXPECT_EQ(actual, expected);
}

TEST(Hw05Tests, Test8)
{
    VecOfStr input{"Naomi, Gianna, Ed, Nall, Robert, Allen, Red, Hon, Evan, Eden, Mel, Lola, Alol, Lemned, Enave, Noh, Der, Nella, Trebor, Llan, De, Anna, Ig & I moan", "Rats drown in WordStar.", "May a moody baby doom a yam", "I want to sleep!!!", "Go, Johny, go, go", "Egad! An adage!"};
    auto expected = VecOfStr{"Naomi, Gianna, Ed, Nall, Robert, Allen, Red, Hon, Evan, Eden, Mel, Lola, Alol, Lemned, Enave, Noh, Der, Nella, Trebor, Llan, De, Anna, Ig & I moan", "Rats drown in WordStar.", "May a moody baby doom a yam", "Egad! An adage!"};
    auto actual = hw05(input);
    EXPECT_EQ(actual, expected);
}

TEST(Hw05Tests, Test9)
{
    VecOfStr input{"\"Regal as tide\", Kramer remarked. \"It's a lager!\""};
    auto expected = VecOfStr{"\"Regal as tide\", Kramer remarked. \"It's a lager!\""};
    auto actual = hw05(input);
    EXPECT_EQ(actual, expected);
}

TEST(Hw05Tests, Test10)
{
    VecOfStr input{"Just text", "Yo hago yoga hoy", "a-*$&#-a"};
    auto expected = VecOfStr{"Yo hago yoga hoy", "a-*$&#-a"};
    auto actual = hw05(input);
    EXPECT_EQ(actual, expected);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}