#include "gtest/gtest.h"
#include "Automata.h"

TEST(testStates, creation) 
{
	Automata coffee;
	EXPECT_EQ(coffee.printState(), "OFF");
}