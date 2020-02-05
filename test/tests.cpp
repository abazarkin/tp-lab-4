#include "gtest/gtest.h"
#include "Automata.h"



//task1
TEST(lab4,task1)
{
    auto t = Automata();
    t.on();
    t.coin(10);
    t.choice(3);
    t.coin(100);
    t.choice(3);
    int res = t.getChange();
    EXPECT_EQ(55,res);
}

//task_2
TEST(lab4,task2)
{
    auto t = Automata();
    t.on();
    t.coin(100);
    t.choice(3);
    t.choice(2);
    int res = t.getChange();
    EXPECT_EQ(5,res);
}

//task_3
TEST(lab4,task3)
{
    auto t = Automata();
    States tmp = t.getState();
    EXPECT_EQ(STATES::OFF, tmp);
}

//task_4
TEST(lab4,task4)
{
    auto t = Automata();
    t.on();
    States tmp = t.getState();
    EXPECT_EQ(STATES::WAIT, tmp);
}


