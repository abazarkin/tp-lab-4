//
// Created by Anton Korkunov on 09/02/2020.
//

#include "gtest/gtest.h"
#include "Automata.h"


TEST(TestState, test1)
{
Automata AA;
AA.coin(20);
EXPECT_EQ(2,AA.printState());

}

TEST(TestState, test2)
{
Automata AA;
EXPECT_EQ(WAIT, AA.printState());	
}

TEST(TestState, test3)
{
Automata AA;
AA.off();
EXPECT_EQ(OFF, AA.printState());
}

TEST(TestState, test4)
{
Automata AA;
AA.cook();
EXPECT_EQ(COOK, AA.printState());
}

TEST(TestCheck, test1)
{

Automata AA;
AA.coin(20);
EXPECT_EQ(20, AA.cancel());

}

TEST(TestCheck, test2)
{

Automata AA;
AA.coin(20);
AA.check(0);
EXPECT_EQ(9, AA.cancel());

}

TEST(TestCheck, test3)
{
Automata AA;
AA.coin(40);
AA.check(1);
EXPECT_EQ(18, AA.cancel());
}

TEST(TestCheck, test4)
{
Automata AA;
AA.coin(4);
EXPECT_FALSE(AA.check(1));
}

TEST(TestCheck, test5)
{
Automata AA;
AA.coin(400);
EXPECT_TRUE(AA.check(1));
}

TEST(TestCoin, test1)
{
Automata AA;
EXPECT_EQ(1,AA.coin(1));
}

TEST(TestCoin, test2)
{
Automata AA;
AA.coin(100);
EXPECT_EQ(123, AA.coin(23));
}

TEST(TestCoin, test3)
{
Automata AA;
EXPECT_EQ(-1, AA.coin(-223));
}
