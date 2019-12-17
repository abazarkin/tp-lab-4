#include "gtest/gtest.h"
#include "Automata.h"
TEST(lab4, task_1){
    Automata automata;
    STATES tmp = automata.getState();
    EXPECT_EQ(STATES::OFF, tmp);
}
TEST(lab4, task_2) {
    Automata automata;
    automata.on();

    STATES tmp = automata.getState();
    EXPECT_EQ(STATES::WAIT, tmp);
}

TEST(lab4, task_3) {
    Automata automata;
    automata.on();
    automata.off();

    STATES tmp = automata.getState();
    EXPECT_EQ(STATES::OFF, tmp);
}
TEST(lab4, task_4){
    Automata automata;
    automata.on();

    int tmp = automata.getCash();
    EXPECT_EQ(0, tmp);
}
TEST(lab4, task_5){
    Automata automata;
    automata.on();
    automata.coin(20)

    int tmp = automata.getCash();
    EXPECT_EQ(20, tmp);
}
TEST(lab4, task_6){
    Automata automata;
    automata.on();
    automata.coin(20)

    bool tmp = automata.check(0);
    EXPECT_EQ(false, tmp);
}
TEST(lab4, task_7){
    Automata automata;
    automata.on();
    automata.coin(50)

    bool tmp = automata.check(0);
    EXPECT_EQ(true, tmp);
}