#include "gtest/gtest.h"
#include "automata.h"

TEST(lab1,task1_1)
 {
    auto Test_Automata = Automata();
    Test_Automata.printState();
    Test_Automata.on();
    Test_Automata.printState();
    Test_Automata.coin(100);
    Test_Automata.printState();
    Test_Automata.printMenu();
    Test_Automata.choice(0);
    Test_Automata.choice(2);
    int current_cash = Test_Automata.get_current_cash();
    EXPECT_EQ(75, current_cash);
 }

TEST(lab1,task1_2)
 {
    auto Test_Automata = Automata();
    Test_Automata.printState();
    Test_Automata.on();
    Test_Automata.printState();
    Test_Automata.coin(50);
    Test_Automata.printState();
    Test_Automata.printMenu();
    Test_Automata.choice(6);
    int current_cash = Test_Automata.get_current_cash();
    EXPECT_EQ(10, current_cash);
 }
