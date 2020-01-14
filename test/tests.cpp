#include "gtest/gtest.h"
#include "Automata.h"



TEST(Automata, buy1)
{
	Automata automat = Automata();
	automat.on();
	automat.coin(150);
	int res = automat.choice(2);
    EXPECT_EQ(20,res);
}
TEST(Automata, cancel1)
{
    Automata automat = Automata();
	automat.on();
	automat.coin(150);
	int res = automat.cancel();
    EXPECT_EQ(150,res);
}
TEST(Automata, cancel2)
{
    Automata automat = Automata();
	automat.on();
	int res = automat.cancel();
    EXPECT_EQ(-1,res);
}

TEST(Automata, state1)
{
	Automata automat;
	EXPECT_EQ("OFF", automat.getState());
}

TEST(Automata, state2)
{
	Automata automat;
	automat.on();
	automat.coin(150);
	EXPECT_EQ("ACCEPT", automat.getState());
}
TEST(Automata, state3)
{
	Automata automat;
	automat.on();
	automat.coin(150);
	automat.choice(2);
	EXPECT_EQ("CHECK", automat.getState());
}
TEST(Automata, error_cancel)
{
	Automata automat;
	automat.on();
	EXPECT_EQ(-1, automat.cancel());
	automat.off();
	EXPECT_EQ(-1, automat.cancel());
}
