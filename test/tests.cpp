#include "gtest/gtest.h"
#include "../include/Automata.h"


TEST(TestS, task1)
{
	Automata run;
	run.on();
	EXPECT_EQ(20, run.coin(20));
	run.off();
}
TEST(TestS,task2)
{
	Automata run;
	run.on();
	run.coin(220);
	EXPECT_EQ(320,run.coin(100));
	run.off();
}
TEST(TestS,task3)
{
	Automata run;
	run.on();
	EXPECT_EQ("Latte", run.choice("Latte"));
	run.off();
}