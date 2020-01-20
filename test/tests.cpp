#include "gtest/gtest.h"
#include "../include/task1.h"




TEST(lab1, task1)
{
	Automata automata;
	automata.on();
	EXPECT_EQ("WAIT", automata.printState());
	automata.off();
}
TEST(lab1,task2)
{
	Automata automata;
	automata.coin(20);
	EXPECT_EQ("ACCEPT",automata.printState());
}
TEST(lab1,task3)
{
	Automata automata;
	automata.on();
	automata.coin(200);
	automata.choice("Coffee");
	EXPECT_EQ("OFF", automata.printState());
}
