#include "gtest/gtest.h"
#include "Automata.h"

TEST(lab4,task1)
{
    Automata atm;
    atm.on();
    EXPECT_EQ(0, atm.getMoney());
}

TEST(lab4,task2)
{
    Automata atm;
    atm.on();
    atm.coin(100);
    atm.choice(2);
    EXPECT_EQ(30, atm.getMoney());
}

TEST(lab4,task3)
{
    Automata atm;
    atm.on();
    atm.coin(100);
    atm.choice(3);
    EXPECT_EQ(10, atm.getMoney());
}
