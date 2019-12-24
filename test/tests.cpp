#include "gtest/gtest.h"
#include "Automata.hpp"

TEST(States_test, check_off_state) {
	Automata aut;
	EXPECT_EQ(aut.print_state(), "OFF");
}

TEST(States_test, check_on_state) {
	Automata aut;
	aut.on()
	EXPECT_EQ(aut.print_state(), "ON");
}

TEST(States_test, check_off_func_state) {
	Automata aut;
	aut.on();
	aut.off();
	EXPECT_EQ(aut.print_state(), "OFF");
}

TEST(States_test, coin_test) {
	Automata aut;
	aut.on();
	aut.coin(50)
	EXPECT_EQ(aut.print_state(), "ACCEPT");
}

TEST(Cash_test, cash_check_test) {
	Automata aut;
	aut.on();
	aut.coin(50);
	aut.choice(8);
	EXPECT_EQ(aut.check(), false);
	aut.choice(4);
	EXPECT_EQ(aut.check(), true);
}

TEST(Cash_test, cash_after_buy_test1) {
	Automata aut;
	aut.on();
	aut.coin(50);
	aut.choice(6);
	EXPECT_EQ(aut.check(), true);
	aut.cook();
	aut.choice(1);
	EXPECT_EQ(aut.check(), false);
}

TEST(Cash_test, cash_after_buy_test2) {
	Automata aut;
	aut.on();
	aut.coin(50);
	aut.choice(6);
	auto pair = aut.cook();
	EXPECT_EQ(pair.first, 5);
}

TEST(Funcs_test, cancel_test1) {
	Automata aut;
	aut.on();
	aut.coin(50);
	EXPECT_EQ(aut.print_state(), "ACCEPT");
	aut.cancel()
	EXPECT_EQ(aut.print_state(), "WAIT");
}

TEST(Funcs_test, cancel_test2) {
	Automata aut;
	aut.on();
	aut.coin(50);
	aut.choice(6);
	aut.check();
	EXPECT_EQ(aut.print_state(), "CHECK");
}

TEST(Funcs_test, finish_test) {
	Automata aut;
	aut.on();
	aut.coin(50);
	aut.choice(6);
	aut.cook();
	aut.finish();
	EXPECT_EQ(aut.print_state(), "WAIT");
}

TEST(Menu_test, menu_test) {
	std::string str = "1: Water 10 R\n2: Soda 15 R\n3: Green tea 15 R\n4: Black tea 15 R\n5: Espresso 30 R\n6: Latte 45 R\n7: Cappuccino 50 R\n8: Double espresso 60 R\n9: Double latte 75 R\n10: Mocaccino 100 R\n";
	Automata aut;
	aut.on();
	EXPECT_EQ(aut.print_state(), str);
}


