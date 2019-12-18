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
    aut.coin();
    EXPECT_EQ(2,aut.getState());
}

TEST(test1,task2)
{
    //is this thing work
    Automata aut;
    aut.on();
    aut.coin();
    aut.choice();
    aut.finish();
    aut.off()
    EXPECT_EQ(0,aut.getState());
}
