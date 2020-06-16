#include "gtest/gtest.h"
#include "../include/Automata.h"

TEST(Test1, task1)
{
	Automata test;
	test.on();
	EXPECT_EQ(300, test.coin(300));
	test.off();
}
TEST(Test1, task2)
{
	Automata test;
	test.on();
	test.coin(10);
	EXPECT_EQ(110, test.coin(100));
	test.off();
}
TEST(Test1, task3)
{
	Automata test;
	test.on();
	EXPECT_EQ("Black tea", test.choice("Black tea"));
	test.off();
}
