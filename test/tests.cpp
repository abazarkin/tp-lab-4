#include "gtest/gtest.h"
#include "../include/task1.h"




TEST(TestS, task1)
{
	Automata automata;
	automata.on();
	EXPECT_EQ(20, automata.coin(20));
	automata.off();
}
TEST(TestS,task2)
{
	Automata automata;
	automata.on();
	automata.coin(220);
	EXPECT_EQ(320,automata.coin(100));
	automata.off();
}
TEST(TestS,task3)
{
	Automata automata;
	automata.on();
	EXPECT_EQ("Coffee", automata.choice("Coffee"));
	automata.off();
}
