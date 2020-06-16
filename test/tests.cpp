#include "gtest/gtest.h"
#include "Automata.h"

TEST(Automata, state) {
	Automata nescafe;
	nescafe.on();
	EXPECT_EQ("WAIT", nescafe.getState());
}

TEST(Automata, balance) {
	Automata nescafe;
	nescafe.on();
	int balance = nescafe.coin(50);
	EXPECT_EQ(50, balance);
}

TEST(Automata, choice) {
	Automata nescafe;
	nescafe.on();
	bool value = nescafe.choice(3);
	EXPECT_EQ(false, value);
}

