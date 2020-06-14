#include "gtest/gtest.h"
#include "../include/Automata.h"

TEST(TestS, task1)
{
	Automata test;
	test.on();
	EXPECT_EQ(300, test.coin(300));
	test.off();
}
TEST(TestS, task2)
{
	Automata test;
	test.on();
	test.coin(10);
	EXPECT_EQ(110, test.coin(100));
	test.off();
}
TEST(TestS, task3)
{
	Automata test;
	test.on();
	EXPECT_EQ("Black tea", test.choice("Black tea"));
	test.off();
}
