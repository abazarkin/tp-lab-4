#include "gtest/gtest.h"
#include "Automata.h"


// task1
TEST(lab4,task1_1)
{
	Automata automat_1;
	automat_1.coin(50);

    EXPECT_EQ(1, automat_1.check(25));
}
