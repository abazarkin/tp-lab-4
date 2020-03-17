#include "gtest/gtest.h"
#include "Automata.h"

TEST(lab4,task1)
{
   std::vector<std::string> menu = {"Drink 1", "Drink 2", "Drink 3"};
   std::vector<int> prices = {10, 15, 25};
   Automata automata(menu, prices);
   automata.on();
   automata.coin(14);
   automata.choise(1);
   EXPECT_EQ(automata.check(), false);
}