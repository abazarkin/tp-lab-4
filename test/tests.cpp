#include "gtest/gtest.h"
#include "automata.h"

TEST(lab4,task1)
{
	Automata mac = Automata();
	EXPECT_EQ(0,mac.on());
}