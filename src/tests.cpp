#include "gtest/gtest.h"
#include "../include/Automata.h"

TEST(lab4, task_1) {
	Automata automata;
	automata.on();

	int tmp = automata.getCash();
	EXPECT_EQ(0, tmp);
}

TEST(lab4, task_2) {
	Automata automata;
	automata.on();
	automata.coin(12);

	int tmp = automata.getCash();
	EXPECT_EQ(12, tmp);
}

TEST(lab4, task_3) {
	Automata automata;
	automata.on();
	automata.coin(25);
	automata.choice(1);
	int tmp = automata.getCash();
	EXPECT_EQ(10, tmp);
}


TEST(lab4, task_4) {
	Automata automata;
	automata.on();
	automata.coin(20);
	automata.choice(1);
	int tmp = automata.getCash();
	EXPECT_EQ(5, tmp);
}

TEST(lab4, task_5) {
	Automata automata;
	automata.on();
	automata.coin(20);
	automata.choice(2);
	int tmp = automata.getCash();
	EXPECT_EQ(0, tmp);
}