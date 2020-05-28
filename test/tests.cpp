#include "gtest/gtest.h"
#include "Automata.h"


// task1
TEST(test1,task1)
{
    //is this thing work
    Automata aut;
    aut.on();
    EXPECT_EQ(1,aut.getState());
}

TEST(test1,task2)
{
    //is this thing work
    Automata aut;
    aut.on();
    aut.coin(50);
    EXPECT_EQ(2,aut.getState());
}

TEST(test1,task3)
{
    //is this thing work
    Automata aut;
    aut.on();
    aut.coin(50);
    aut.choice(0);
    aut.finish();
    aut.off();
    EXPECT_EQ(0,aut.getState());
}

TEST(test1,task4)
{
    //is this thing work
    Automata aut;
    aut.on();
    aut.coin(50);
    aut.cancel();
    EXPECT_EQ(1,aut.getState());
}
