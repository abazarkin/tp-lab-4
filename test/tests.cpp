#include "gtest/gtest.h"
#include "Automata.h"
#include <string>

TEST(automata_cash,test3){
Automata box;
box.on();
box.coin(100);
box.coin(150);
int current_cash = box.getCash();
EXPECT_EQ(250,current_cash);
}

TEST(automata_remain,test2){
Automata box;
box.on();
box.coin(100);
box.coin(150);
box.choice(4);
box.cook();
int current_cash = box.getCash();
EXPECT_EQ(240,current_cash);
}
