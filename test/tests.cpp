#include "gtest/gtest.h"
#include"../include/automata.h"

TEST(lab4, task1) 
{
	Automata automata();
	automata.on();
	EXPECT_EQ("Coffee", automata.choice("Coffee"));
	automata.off();
}

TEST(lab4, task2)
{
	Automata automata();
	automata.on();
	EXPECT_EQ("Tea", automata.choice("Tea"));
	automata.off();
}

TEST(lab4, task3)
{
	Automata automata();
	automata.on();
	EXPECT_EQ("Milk", automata.choice("Milk"));
	automata.off();
}

TEST(lab4, task4)
{
	Automata automata();
	automata.on();
	EXPECT_EQ("Espresso", automata.choice("Espresso"));
	automata.off();
}

TEST(lab4, task5)
{
	Automata automata();
	automata.on();
	EXPECT_EQ("Chocolate", automata.choice("Chocolate"));
	automata.off();
}

TEST(lab4, task6)
{
	Automata automata();
	automata.on();
	EXPECT_EQ("Water", automata.choice("Water"));
	automata.off();
}