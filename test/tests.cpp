#include "gtest/gtest.h"
#include "../tp-lab-4/Automata.h"
#include <string>


class drinkTest : public ::testing::Test {
	protected:
		void SetUp() override {}

	Automata coffeMachine{};
};

TEST_F(drinkTest, on) {
	coffeMachine.on();
	EXPECT_EQ("The state is: WAIT", coffeMachine.printState());
	coffeMachine.off();
}

TEST_F(drinkTest, coin1) {
	std::string expect = "You deposit 100;\nYour balance: 100;";
	coffeMachine.on();
	EXPECT_EQ(expect, coffeMachine.coin(100));
	coffeMachine.off();
}

TEST_F(drinkTest, coin2) {
	std::string expect = "You deposit 1000;\nYour balance: 1100;";
	coffeMachine.on();
	coffeMachine.coin(100);
	EXPECT_EQ(expect, coffeMachine.coin(1000));
	coffeMachine.off();

}

TEST_F(drinkTest, coin3) {
	std::string expect = "Can`t deposit. Try again;";
	EXPECT_EQ(expect, coffeMachine.coin(1000));
}

TEST_F(drinkTest, choice_cancel) {
	coffeMachine.on();
	coffeMachine.coin(100);
	EXPECT_EQ("You have ordered Coffee;",coffeMachine.choiñe("Coffee"));
	EXPECT_EQ("You`ve canceled the operation;  Your change is: 100;", coffeMachine.cancel());
	coffeMachine.off();
}

TEST_F(drinkTest, choice_cook) {
	coffeMachine.on();
	coffeMachine.coin(100);
	EXPECT_EQ("You have ordered Coffee;", coffeMachine.choiñe("Coffee"));
	EXPECT_EQ("Cooking...\n Coffee is done!;", coffeMachine.cook());
	EXPECT_EQ("Bon appetit! Your change is: 0;", coffeMachine.finish());
	coffeMachine.off();
	
}

TEST_F(drinkTest, incorrect_finish) {
	coffeMachine.on();
	coffeMachine.coin(100);
	coffeMachine.choiñe("Coffee");
	EXPECT_EQ("Can`t finish the operation;", coffeMachine.finish());
	coffeMachine.off();
}

TEST_F(drinkTest, incorrect_cancel) {
	coffeMachine.on();
	coffeMachine.coin(150);
	coffeMachine.choiñe("Coffee");
	coffeMachine.cook();
	EXPECT_EQ("Can`t cancel the operation;", coffeMachine.cancel());
	EXPECT_EQ("Bon appetit! Your change is: 50;", coffeMachine.finish());
	coffeMachine.off();
}