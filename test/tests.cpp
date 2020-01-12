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
