#include "gtest/gtest.h"
#include "automata.h"

// task1
TEST(lab4,task1_1)
{
	automata L = automata();
	EXPECT_EQ(-1, L.on());
	EXPECT_EQ(-1, L.off());
}
TEST(lab4,task1_2)
{
	automata L = automata();
	L.on();
	EXPECT_EQ(2, L.coin(-12)); // no eq
}

TEST(lab4,task1_3)
{
	automata L = automata();
	L.on();
	L.coin(2);
	EXPECT_EQ(5,L.choice(20));
}
TEST(lab4,task1_4)
{
	automata L = automata();
	L.on();
	L.coin(100);
	EXPECT_EQ(-1, L.choice(5));
}
TEST(lab4,task1_5)
{
	automata L = automata();
	L.on();
	L.coin(20);
	L.choice(5);
	EXPECT_EQ(7, L.check());
}
TEST(lab4,task1_6)
{
	automata L = automata();
	L.on();
	L.coin(50);
	L.choice(5);
	EXPECT_EQ(-1, L.check());
}
TEST(lab4,task1_7)
{
	automata L = automata();
	L.on();
	L.coin(50);
	L.choice(5);
	L.check();
	EXPECT_EQ(-1, L.cook());
}
TEST(lab4,task1_8)
{
	automata L = automata();
	L.on();
	EXPECT_EQ(6, L.cook());
}
