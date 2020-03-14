#include "gtest/gtest.h"
#include "task1.h"
#include "task2.h"
#include "task3.h"
#include "task4.h"
#include "task5.h"

// task1
TEST(lab4,task1_1)
{
	Automata automat_1;
	automat_1.coin(50);

    EXPECT_EQ(1, automat_1.check(25));
}
