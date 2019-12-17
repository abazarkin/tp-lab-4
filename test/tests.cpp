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

    States tmp = automata.getState();
    EXPECT_EQ(STATES::WAIT, tmp);
}

TEST(lab4, task_3) {
    Automata automata;
    automata.on();
    automata.off();

    States tmp = automata.getState();
    EXPECT_EQ(STATES::OFF, tmp);
}
