#include "gtest/gtest.h"
#include "coffee_machine.h"
#include <string>

// ON/OFF test
TEST(coffee_machine, task1_1)
{
    Automata coffee;
    string exp = "The coffee machine is ON.";
    EXPECT_EQ(exp, coffee.on());
}
TEST(coffee_machine, task1_2)
{
    Automata coffee;
    coffee.on();
    string exp = "The coffee machine is OFF.";
    EXPECT_EQ(exp, coffee.off());
}

// State test
TEST(coffee_machine, task1_3)
{
    Automata coffee;
    coffee.on();
    string exp = "Waiting...";
    EXPECT_EQ(exp, coffee.printState());
}

// Choice test
TEST(coffee_machine, task1_4)
{
    Automata coffee;
    coffee.on();
    coffee.coin(2);
    string exp = "Error: This type of coffee is not available. Please select a type of coffee from the menu or cancel.";
    EXPECT_EQ(exp, coffee.choice(20));
}

// Coin test
TEST(coffee_machine, task1_5)
{
    Automata coffee;
    coffee.on();
    coffee.coin(2);
    coffee.coin(2);
    coffee.coin(2);
    int exp = 9;
    EXPECT_EQ(exp, coffee.coin(3));
}

// Not enough money test
TEST(coffee_machine, task1_6)
{
    Automata coffee;
    coffee.on();
    coffee.coin(2);
    string exp = "2.000000";
    EXPECT_EQ(exp, coffee.choice(1));
}

// Coffee cooked test
TEST(coffee_machine, task1_7)
{
    Automata coffee;
    coffee.on();
    coffee.coin(6);
    string exp = "Enjoy your coffee :)";
    EXPECT_EQ(exp, coffee.choice(1));
}

// Return change test
TEST(coffee_machine, task1_8)
{
    Automata coffee;
    coffee.on();
    coffee.coin(6.35);
    coffee.choice(3);
    EXPECT_EQ(1, int(coffee.finish()));
}
