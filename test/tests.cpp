#include "gtest/gtest.h"
#include "CoffeeMachine.h"

TEST(lab4, Coffee) {
	CoffeeMachine Philips = CoffeeMachine();
	EXPECT_EQ(100, Philips.on());
}
