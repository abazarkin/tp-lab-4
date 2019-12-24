#include "gtest/gtest.h"
#include "automata.h"

TEST(lab1,task1_1)
{
    auto t = Automata();
    t.on();
    t.coin(10);
    t.choice(0);
    t.choice(3);
    t.coin(100);
    t.choice(3);
    int res = t.getCash();
    EXPECT_EQ(70,res);
}
TEST(lab1,task1_2)
{
    auto t = Automata();
    t.on();
    t.coin(10);
    t.choice(0);
    t.choice(3);
    int res = t.getCash();
    EXPECT_EQ(10, res);
}

TEST(lab1,task1_3)
{
    auto t = Automata();
    States check = t.getState();
    EXPECT_EQ(States::OFF, check);
}
TEST(lab1,task1_4)
{
    auto t = Automata();
    t.on();
    States check = t.getState();
    EXPECT_EQ(States::WAIT, check);
}