//#include "pch.h"
#include "gtest/gtest.h"
#include "Automata.h"

//TEST(Test_states, test_all) {
//	Automata box;
//	EXPECT_EQ(box.printState(), "OFF");
//	box.on();
//	EXPECT_EQ(box.printState(), "WAIT");
//	box.coin(1);
//	EXPECT_EQ(box.printState(), "ACCEPT");
//	box.choice(0);
//	EXPECT_EQ(box.printState(), "CHECK");
//	box.cook();
//	EXPECT_EQ(box.printState(), "WAIT");
//	box.coin(1);
//	EXPECT_EQ(box.printState(), "ACCEPT");
//	box.choice(5);
//	EXPECT_EQ(box.printState(), "ACCEPT");
//	box.coin(10);
//	box.choice(8);
//	EXPECT_EQ(box.printState(), "ACCEPT");
//	box.choice(2);
//	box.choice(4);
//	EXPECT_EQ(box.printState(), "CHECK");
//	box.off();
//	EXPECT_EQ(box.printState(), "OFF");
//	box.coin(1);
//	EXPECT_EQ(box.printState(), "OFF");
//}

TEST(Test_states, test_off_1) {
	Automata box;
	EXPECT_EQ(box.printState(), "OFF");
}

TEST(Test_states, test_wait_1) {
	Automata box;
	box.on();
	EXPECT_EQ(box.printState(), "WAIT");
}

TEST(Test_states, test_accept_1) {
	Automata box;
	box.on();
	box.coin(1);
	EXPECT_EQ(box.printState(), "ACCEPT");
}

TEST(Test_states, test_check_1) {
	Automata box;
	box.on();
	box.coin(1);
	box.choice(0);
	EXPECT_EQ(box.printState(), "CHECK");
}

TEST(Test_states, test_wait_2) {
	Automata box;
	box.on();
	box.coin(1);
	box.choice(0);
	box.cook();
	EXPECT_EQ(box.printState(), "WAIT");
}

TEST(Test_states, test_accept_2) {
	Automata box;
	box.on();
	box.coin(1);
	box.choice(0);
	box.cook();
	box.coin(1);
	EXPECT_EQ(box.printState(), "ACCEPT");
}

TEST(Test_states, test_accept_3) {
	Automata box;
	box.on();
	box.coin(1);
	box.choice(0);
	box.cook();
	box.coin(1);
	box.choice(5);
	EXPECT_EQ(box.printState(), "ACCEPT");
}

TEST(Test_states, test_accept_4) {
	Automata box;
	box.on();
	box.coin(1);
	box.choice(0);
	box.cook();
	box.coin(1);
	box.choice(5);
	box.coin(10);
	EXPECT_EQ(box.printState(), "ACCEPT");
}

TEST(Test_states, test_accept_5) {
	Automata box;
	box.on();
	box.coin(1);
	box.choice(0);
	box.cook();
	box.coin(1);
	box.choice(5);
	box.coin(10);
	box.choice(8);
	EXPECT_EQ(box.printState(), "ACCEPT");
}

TEST(Test_states, test_check_2) {
	Automata box;
	box.on();
	box.coin(1);
	box.choice(0);
	box.cook();
	box.coin(1);
	box.choice(5);
	box.coin(10);
	box.choice(8);
	box.choice(2);
	EXPECT_EQ(box.printState(), "CHECK");
}

TEST(Test_states, test_off_2) {
	Automata box;
	box.on();
	box.coin(1);
	box.choice(0);
	box.cook();
	box.coin(1);
	box.choice(5);
	box.off();
	EXPECT_EQ(box.printState(), "OFF");
}

TEST(Test_states, test_off_3) {
	Automata box;
	box.on();
	box.coin(1);
	box.choice(0);
	box.cook();
	box.coin(1);
	box.choice(5);
	box.off();
	box.coin(1);
	EXPECT_EQ(box.printState(), "OFF");
}

TEST(Test_states, test_cancel) {
	Automata box;
	box.on();
	box.coin(1);
	box.cancel();
	EXPECT_EQ(box.printState(), "WAIT");
}

TEST(Test_methods, test_coin_off) {
	Automata box;
	EXPECT_EQ(box.coin(1), false);
}

TEST(Test_methods, test_coin_on) {
	Automata box;
	box.on();
	EXPECT_EQ(box.coin(1), true);
}

TEST(Test_methods, test_choice_off) {
	Automata box;
	EXPECT_EQ(box.choice(1), false);
}

TEST(Test_methods, test_choice_enough_cash) {
	Automata box;
	box.on();
	box.coin(10);
	EXPECT_EQ(box.choice(3), true);
}

TEST(Test_methods, test_choice_not_enough_cash) {
	Automata box;
	box.on();
	box.coin(0);
	EXPECT_EQ(box.choice(3), false);
}

TEST(Test_methods, test_getCash_off) {
	Automata box;
	EXPECT_EQ(box.getCash(), 0);
}

TEST(Test_methods, test_getCash) {
	Automata box;
	box.on();
	box.coin(15);
	EXPECT_EQ(box.getCash(), 15);
}