#include "gtest/gtest.h"
#include "Automata.h"

TEST (Automata, state1) {
	Automata nescafe;
	nescafe.on();
	EXPECT_EQ("WAIT", nescafe.getState());
}

TEST (Automata, state2) {
	Automata nescafe;
	EXPECT_EQ("OFF", nescafe.getState());
}

TEST (Automata, state3) {
	Automata nescafe;
	nescafe.on();
	nescafe.coin(5);
	EXPECT_EQ("ACCEPT", nescafe.getState());
}

TEST (Automata, state4) {
	Automata nescafe;
	nescafe.on();
	nescafe.coin(40);
	nescafe.choice(2);
	EXPECT_EQ("WAIT", nescafe.getState());
}

TEST (Automata, balance1) {
	Automata nescafe;
	nescafe.on();
	int balance = nescafe.coin(50);
	EXPECT_EQ(50, balance);
}

TEST (Automata, balance2) {
	Automata nescafe;
	nescafe.on();
	nescafe.coin(300);
	int balance = nescafe.coin(6);
	EXPECT_EQ(306, balance);
}

TEST (Automata, balance3) {
	Automata nescafe;
	int balance = nescafe.coin(50);
	EXPECT_EQ(0, balance);
}

TEST (Automata, balance4) {
	Automata nescafe;
	nescafe.on();
	int balance = nescafe.coin(-50);
	EXPECT_EQ(0, balance);
}

TEST (Automata, choice1) {
	Automata nescafe;
	nescafe.on();
	bool value = nescafe.choice(3);
    EXPECT_EQ(false, value);
}

TEST (Automata, choice2) {
	Automata nescafe;
	nescafe.on();
	nescafe.coin(30);
	bool value = nescafe.choice(4);
    EXPECT_EQ(false, value);
}

TEST (Automata, choice3) {
	Automata nescafe;
	nescafe.on();
	nescafe.coin(60);
	bool value = nescafe.choice(10);
    EXPECT_EQ(false, value);
}

TEST (Automata, choice4) {
	Automata nescafe;
	nescafe.on();
	nescafe.coin(60);
	bool value = nescafe.choice(4);
    EXPECT_EQ(true, value);
}
