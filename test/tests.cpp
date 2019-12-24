#include "gtest/gtest.h"
#include "Automata.h"

TEST(lab4,task1)
{
    vector<string> menu(0);
    menu.push_back("Tea");
    menu.push_back("Cappuchino");
    menu.push_back("Americano");

    vector<int> prices(0);
    prices.push_back(20);
    prices.push_back(50);
    prices.push_back(40);
    prices.push_back(50);
    Automata coffeeMashine(menu, prices);
    EXPECT_EQ(coffeeMashine.printState(),OFF);
}
