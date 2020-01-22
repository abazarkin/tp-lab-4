#include "gtest/gtest.h"
#include "Automata.h"



TEST(lab4, test1)
{
	Automata Nescafe();
	Nescafe.on();
	unsigned int money = 30;
	unsigned int current_cash = Nescafe.coin(money);
	EXPECT_EQ(money, current_cash);
}

TEST(lab4, test1)
{
	Automata Nescafe();
	Nescafe.on();
	unsigned int money = 30;
	unsigned int current_cash = Nescafe.coin(money);
	current_cash = Nescafe.coin(25);
	unsigned int expected = 55;
	EXPECT_EQ(expected, current_cash);
}

TEST(lab4, test3)
{
	Automata Nescafe();
	Nescafe.on();
	unsigned int money = 30;
	unsigned int current_cash = Nescafe.coin(money);
	current_cash = Nescafe.coin(25);
	Nescafe.choice(2);
	unsigned int res = Nescafe.change();
	unsigned int expected = 10;
	EXPECT_EQ(expected, res);
}

TEST(lab4, test4)
{
	Automata Nescafe();
	Nescafe.on();
	unsigned int money = 30;
	unsigned int current_cash = Nescafe.coin(money);
	cuurent_cash = Nescafe.coin(25);
	bool res = Nescafe.check(3);
	bool expected = true;
	EXPECT_EQ(expected, res);
}

TEST(lab4, test5)
{
	Automata Nescafe();
	Nescafe.on();
	unsigned int money = 30;
	unsigned int current_cash = Nescafe.coin(money);
	bool res = Nescafe.check(4);
	bool expected = false;
	EXPECT_EQ(expected, res);
}

TEST(lab4, test6)
{
	Automata Nescafe();
	Nescafe.on();
	unsigned int current_cash = Nescafe.coin(40);
	Nescafe.choice(1);
	unsigned int res = Nescafe.change();
	unsigned int expected = 0;
	EXPECT_EQ(expected, res);
}
