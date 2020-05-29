#include "gtest/gtest.h"
#include "Automata.h"



TEST(lab4,task1)
{
	Automata Nescafe;
	Nescafe.on();
	unsigned int money = 30;
	unsigned int current_cash = Nescafe.coin(money);
	EXPECT_EQ(money, current_cash);
}

TEST(lab4,task2)
{
	Automata Nescafe;
	Nescafe.on();
	unsigned int money = 30;
	unsigned int current_cash = Nescafe.coin(money);
	current_cash = Nescafe.coin(25);
	unsigned int expected = 55;
	EXPECT_EQ(expected, current_cash);
}

TEST(lab4,task3)
{
	Automata Nescafe;
	Nescafe.on();
	unsigned int money = 30;
	unsigned int current_cash = Nescafe.coin(money);
	current_cash = Nescafe.coin(25);
	Nescafe.choice(3);
	unsigned int res = Nescafe.change();
	unsigned int expected = 10;
	EXPECT_EQ(expected, res);
}

TEST(lab4,task4)
{
	Automata Nescafe;
	Nescafe.on();
	unsigned int money = 30;
	unsigned int current_cash = Nescafe.coin(money);
	current_cash = Nescafe.coin(25);
	bool res = Nescafe.check(3);
	bool expected = true;
	EXPECT_EQ(expected, res);
}

TEST(lab4,task5)
{
	Automata Nescafe;
	Nescafe.on();
	unsigned int money = 30;
	unsigned int current_cash = Nescafe.coin(money);
	bool res = Nescafe.check(2);
	bool expected = false;
	EXPECT_EQ(expected, res);
}

TEST(lab4,task6)
{
	Automata Nescafe;
	Nescafe.on();
	unsigned int current_cash = Nescafe.coin(40);
	Nescafe.choice(1);
	unsigned int res = Nescafe.change();
	unsigned int expected = 0;
	EXPECT_EQ(expected, res);
}
