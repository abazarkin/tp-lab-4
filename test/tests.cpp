#include "gtest/gtest.h"
#include "automata.h"


TEST(lab4, check1)
{
	Automata Coffe;
	EXPECT_EQ(OFF, Coffe.getState());
}