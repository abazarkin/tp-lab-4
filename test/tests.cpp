#include "gtest/gtest.h"
#include "../include/automata.h"

TEST(lab4, automata_1)
{
	Automata atm;
	atm.on();
	atm.coin(100);
	bool flag = atm.check(0);
	EXPECT_EQ(flag, true);
}

TEST(lab4, automata_2) 
{
	Automata atm;
	atm.on();
	atm.coin(10);
	bool flag = atm.check(3);
	delete atm;
	EXPECT_EQ(flag, true);
}