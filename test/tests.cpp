#include "gtest/gtest.h"
#include "Automata.h"


TEST(test1,StateOFF )
	{
    Automata* c=new Automata ("s","b");
	EXPECT_EQ(c->printState(), "State is OFF");
	}

TEST(test2,TestCoin){
Automata* c=new Automata ("s","b");
c->coin(45);
	EXPECT_EQ(c->GetCash(), 45);
}
