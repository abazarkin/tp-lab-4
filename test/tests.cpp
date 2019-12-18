#include "gtest/gtest.h"
#include "automata.h"


TEST(lab4, check1)
{
	Automata Coffee;
	EXPECT_EQ(OFF, Coffee.getState());
	Coffee.on();
	EXPECT_EQ(WAIT, Coffee.getState());
	EXPECT_EQ(MISTAKE, Coffee.on());
	Coffe.off();
	EXPECT_EQ(OFF, Coffee.getState());
}

TEST(lab4, coin_check)
{
	Automata A;
	EXPECT_EQ(FAIL, A.on());
	A.on();
	EXPECT_EQ(CORRECT, A.coin(1));
	EXPECT_EQ(ACCEPT, A.getState());
	EXPECT_EQ(1, A.getCash());
	A.coin(4);
	EXPECT_EQ(5, A.getCash());
	
}

TEST(lab4, check3)
{
	Automata A;
	EXPECT_EQ(FAIL, A.choise(101));
	EXPECT_EQ(FAIL, A.choise(2));
	A.on();
	EXPECT_EQ(FAIL, A.choise(101));
	EXPECT_EQ(FAIL, A.choise(2));
	A.coin(1);
	EXPECT_EQ(MISTAKE, A.choise(101));
	EXPECT_EQ(MISTAKE, A.choise(2));
	A.coin(39);
	EXPECT_EQ(MISTAKE, A.choise(101));
	EXPECT_EQ(CORRECT, A.choise(1));
}

TEST(lab4, cansel_check)
{
	Automata A;
	EXPECT_EQ(FAIL, A.cansel());
	A.on();
	EXPECT_EQ(CORRECT, A.cansel());
	EXPECT_EQ(WAIT, A.getState());
	A.coin(1);
	EXPECT_EQ(CORRECT, A.cansel());
	EXPECT_EQ(WAIT, A.getState());
	EXPECT_EQ(0, A.getCash());
}

TEST(lab4, finish_check)
{
	Automata A;
	EXPECT_EQ(MISTAKE, A.finish());
	A.on();
	EXPECT_EQ(MISTAKE, A.finish());
	A.coin(100);
	EXPECT_EQ(MISTAKE, A.finish());
	A.choise(3);
	EXPECT_EQ(CORRECT, A.finish());
}

TEST(lab4, cook_check)
{
	Automata A;
	A.on();
	A.coin(100);
	A.choise(2);
	EXPECT_EQ(READY, A.getState());
	EXPECT_EQ(CORRECT, A.finish());
	EXPECT_EQ(WAIT, A.getState());
}

TEST(lab4, off_check)
{
	Automata A;
	EXPECT_EQ(MISTAKE, A.off());
	A.on();
	EXPECT_EQ(CORRECT, A.off());
	EXPECT_EQ(OFF, A.getState());
	A.coin(100);
	EXPECT_EQ(MISTAKE, A.off());
	A.choise(2);
	EXPECT_EQ(MISTAKE, A.off());
}