#include "gtest/gtest.h"
#include "automata.h"
#include <string>

TEST(coffeeMachine, task1_1){
    Automata coffee;
    STATES testState = coffee.on();
    EXPECT_EQ(STATES::WAIT, testState);
}

TEST(coffee_machine, task1_2){
    Automata coffee;
    STATES testState = coffee.off();
    EXPECT_EQ(STATES::OFF, testState);
}

TEST(coffee_machine, task1_3){
    Automata coffee;
    coffee.on();
    double exp = 10;
    coffee.coin(10);
    EXPECT_EQ(exp, coffee.cash);

}
