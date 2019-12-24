#include "gtest/gtest.h"
#include "CoffeeMachine.h"

//on/off test
TEST(lab4, on_off_test) {
	CoffeeMachine Philips = CoffeeMachine();
	EXPECT_EQ(100, Philips.on());
	EXPECT_EQ(100, Philips.off());
}

//cash test
TEST(lab4,cash_test) {
	CoffeeMachine Igor = CoffeeMachine();
	Igor.on();	
	Igor.coin(3);
	Igor.coin(6);
	EXPECT_EQ(9, Igor.getCash());
}

//choice test
TEST(lab4, choice_test) {
	CoffeeMachine Igor = CoffeeMachine();
	Igor.on();
	Igor.coin(6);
	//error
	EXPECT_EQ(3, Igor.choice(6));

	CoffeeMachine Philips = CoffeeMachine();
	Philips.on();
	Philips.coin(70);
	//success
	EXPECT_EQ(100, Philips.choice(2));
}

//check test
TEST(lab4, check_test) {	
	CoffeeMachine Igor = CoffeeMachine();	
	Igor.on();
	Igor.coin(3);
	Igor.choice(1);
	//error
	EXPECT_EQ(5, Igor.check());

	CoffeeMachine Philips = CoffeeMachine();
	Philips.on();
	Philips.coin(40);
	Philips.choice(1);
	//success
	EXPECT_EQ(100, Philips.check());
}

//cook test
TEST(lab4, cancel_test) {
	CoffeeMachine Igor = CoffeeMachine();
	Igor.on();
	//error
	EXPECT_EQ(4, Igor.cook());
	Igor.coin(345);
	Igor.choice(1);
	Igor.check();
	//success
	EXPECT_EQ(100, Igor.cook());
}
*/