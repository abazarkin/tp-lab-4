#include "gtest/gtest.h"
#include "automata.h"

TEST(automata, if_cancel)
{
	Automata automat = Automata();
	automat.on();
	automat.coin(130);
	int money = automat.cancel();
	EXPECT_EQ(130, money);
}

TEST(automata, if_not_enough)
{
	Automata automat = Automata();
	automat.on();
	automat.coin(13);
	int money = automat.choice(1);
	EXPECT_EQ(13, money);
}

TEST(automata, if_equal)
{
	Automata automat = Automata();
	automat.on();
	automat.coin(40);
	int money = automat.choice(1);
	EXPECT_EQ(0, money);
}

TEST(automata, if_more)
{
	Automata automat = Automata();
	automat.on();
	automat.coin(100);
	int money = automat.choice(1);
	money = automat.off();
	EXPECT_EQ(60, money);
}

TEST(automata, more_than_one)
{
	Automata automat = Automata();
	automat.on();
	automat.coin(100);
	int money = automat.choice(1);
	money = automat.choice(1);
	money += automat.off();
	EXPECT_EQ(20, money);
}