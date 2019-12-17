#include "pch.h"
#include "gtest/gtest.h"
#include "../StuffyLab3/Automata.h"
#include <vector>
#include <iostream>
#include <string>

TEST(AutomataTests, checkingOffState) {
	std::vector<Drink> v(5);
	v[0].name = "coffee";
	v[1].name = "tea";
	v[2].name = "water";
	v[3].name = "milk";
	v[4].name = "goo";
	v[0].price = 5;
	v[1].price = 5;
	v[2].price = 5;
	v[3].price = 5;
	v[4].price = 5;

	Automata box(v);
	box.coin(10);
	EXPECT_EQ("OFF", box.printState());
}

TEST(AutomataTests, checkingOnState) {
	std::vector<Drink> v(5);
	v[0].name = "coffee";
	v[1].name = "tea";
	v[2].name = "water";
	v[3].name = "milk";
	v[4].name = "goo";
	v[0].price = 5;
	v[1].price = 5;
	v[2].price = 5;
	v[3].price = 5;
	v[4].price = 5;

	Automata box(v);
	box.on();
	EXPECT_EQ("WAIT", box.printState());
}

TEST(AutomataTests, workScenario) {
	std::vector<Drink> v(5);
	v[0].name = "coffee";
	v[1].name = "tea";
	v[2].name = "water";
	v[3].name = "milk";
	v[4].name = "goo";
	v[0].price = 5;
	v[1].price = 5;
	v[2].price = 5;
	v[3].price = 5;
	v[4].price = 5;

	Automata box(v);
	box.on();
	std::string log = "";

	log = box.coin(3);
	EXPECT_EQ("Current balance: 3\n", log);

	log = box.printMenu();
	EXPECT_EQ("coffee costs 5\ntea costs 5\nwater costs 5\nmilk costs 5\ngoo costs 5\n", log);

	log = box.printState() + "\n";
	EXPECT_EQ("ACCEPT\n", log);

	log = box.choice("milk");
	EXPECT_EQ("You wish to cook milk\n", log);

	log = box.printState() + "\n";
	EXPECT_EQ("CHECK\n", log);

	log = box.cook();
	EXPECT_EQ("Operation is invalid\n", log);

	log = box.printState() + "\n";
	EXPECT_EQ("CHECK\n", log);

	log = box.cancel();
	EXPECT_EQ("Your money: 3\n", log);

	log = box.printState() + "\n";
	EXPECT_EQ("WAIT\n", log);

	log = box.coin(10);
	EXPECT_EQ("Current balance: 10\n", log);

	log = box.printState() + "\n";
	EXPECT_EQ("ACCEPT\n", log);

	log = box.choice("tea");
	EXPECT_EQ("You wish to cook tea\n", log);

	log = box.printState() + "\n";
	EXPECT_EQ("CHECK\n", log);

	log = box.cook();
	//EXPECT_EQ("Your drink is ready\nYour change: 5\n", clog);
	
	log = box.printState() + "\n";
	EXPECT_EQ("WAIT\n", log);
	
	box.off();
	log = box.printState() + "\n";
	EXPECT_EQ("OFF\n", log);
}