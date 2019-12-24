#include "CoffeeMachine.h"

TEST(lab4, CoffeeMachine_) {
	CoffeeMachine Philips = CoffeeMachine();
	EXPECT_EQ(100, Philips.on());
}
