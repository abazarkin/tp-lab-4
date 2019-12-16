#include "gtest/gtest.h"
#include "automata.h"


TEST(lab4, check1)
{
	Automata Coffe;
	EXPECT_EQ(OFF, Coffe.getState());
	Coffe.on();
	EXPECT_EQ(WAIT, Coffe.getState());
	EXPECT_EQ(MISTAKE, Coffe.on());
	Coffe.off();
	EXPECT_EQ(OFF, Coffe.getState());
	Coffe.~Automata
}

TEST(lab4, check2)
{
	Automata A;
	A.on();
	EXPECT_EQ(MISTAKE, A.choise(101));
}