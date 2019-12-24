#include "gtest/gtest.h"
#include "Automata.h"

// Test 1 (1 == 1)
TEST(lab4, task1){
    Automata shop = Automata();
    shop.on();
    EXPECT_EQ(WAIT, shop.getState())
}

// Test 2 (0 == 0)
TEST(lab4, task2){
    Automata shop = Automata();
    shop.on();
    shop.off();
    EXPECT_EQ(OFF, shop.getState())
}

// Test 3 (2 == 2)
TEST(lab4, task3){
    Automata shop = Automata();
    shop.on();
    shop.coin(50);
    EXPECT_EQ(ACCEPT, shop.getState());
}

// Test 4 (2 == 2)
TEST(lab4, task4){
    Automata shop = Automata();
    shop.on();
    shop.coin(100);
    shop.off();
    EXPECT_EQ(ACCEPT, shop.getState());
}
