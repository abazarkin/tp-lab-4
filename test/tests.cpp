#include "gtest/gtest.h"
#include "Automata.h"


TEST(automata_cash,test4){
Automata my_purchase;
my_purchase.on();
my_purchase.coin(100);
my_purchase.coin(50);
int current_cash=my_purchase.getCash();
EXPECT_EQ(150,current_cash);
}

TEST(automata_refund, test5){
Automata my_purchase;
my_purchase.on();
my_purchase.coin(2121);
my_purchase.refund_of_money();
int current_cash=my_purchase.getCash();
EXPECT_EQ(0,current_cash);

}
