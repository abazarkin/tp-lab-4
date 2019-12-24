#include "gtest/gtest.h"
#include "automata.h"

TEST(CoffeeMachine, task1_1) {
	CoffeeMachine Philips = CoffeeMachine();
	EXPECT_EQ(100, Philips.on());
}
