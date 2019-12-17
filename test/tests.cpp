#include "gtest/gtest.h"
#include "Automata.h"


// task1
TEST(test1,task1)
{
    Automata aut;
    aut.on()
    EXPECT_EQ(1,aut.getState());
}

