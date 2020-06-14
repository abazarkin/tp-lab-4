#include "gtest/gtest.h"
#include "../include/Automata.h"



TEST(lab4,task1)
{
    Automata run;
    run.on();
    std::string expect = "Deposit 100;\nBalance: 100;";
    run.on();
    EXPECT_EQ(expect, run.coin(100));
    run.off();
}



TEST(lab4,task2)
{
    Automata run;
    run.on();
    run.coin(100);
    EXPECT_EQ("You've ordered Latte, nice taste :))", run.choice("Latte"));
    EXPECT_EQ("You`ve canceled the operation:(((  Your change is: 100;", run.cancel());
    run.off();
}
