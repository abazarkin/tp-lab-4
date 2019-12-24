#include "gtest/gtest.h"
#include "automata.h"
TEST (automata,test1){
    Automata automata;
    automata.on();
    automata.coin(5000);
    automata.off();
    int odd_money = automata.cancel();
    EXPECT_EQ(0,odd_money);
    automata.on();
    odd_money = automata.cancel();
    EXPECT_EQ(5000,odd_money);
}

TEST (automata,test2){
    Automata automata;
    automata.on();
    automata.coin(1);
    automata.coin(2);
    int odd_money = automata.cancel();
    EXPECT_EQ(3,odd_money);
}

TEST(automata,test3){
    Automata automata;
    automata.on();
    automata.coin(200);
    automata.choice("coffee");
    int odd_money = automata.cancel();
    EXPECT_EQ(160,odd_money);
}

TEST(automata,test4){
    Automata automata;
    automata.on();
    automata.coin(40);
    std::string coffee = automata.choice("coffee");
    EXPECT_EQ(coffee,"coffee");
}
TEST(automata,test5){
    Automata automata;
    EXPECT_EQ(automata.printState(),std::string("OFF"));
    automata.on();
    EXPECT_EQ(automata.printState(),std::string("WAIT"));
    automata.coin(40);
    EXPECT_EQ(automata.printState(),std::string("ACCEPT"));
    std::string coffee = automata.choice("coffee");
    EXPECT_EQ(coffee,"coffee");
    EXPECT_EQ(automata.printState(),std::string("WAIT"));
}