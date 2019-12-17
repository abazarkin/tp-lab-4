//
// Created by aklen on 17.12.2019.
//
#include "gtest/gtest.h"
#include "Automata.h"


TEST(automata_cash,test4){
    Automata my_purchase;
    my_purchase.on();
    my_purchase.coin(100);
    my_purchase.coin(50);
    EXPECT_EQ(150,my_purchase.getCash());
}

TEST(automata_refund, test5){
    Automata my_purchase;
    my_purchase.on();
    my_purchase.coin(2121);
    my_purchase.refund_of_money();
    EXPECT_EQ(0,my_purchase.getCash());

}
