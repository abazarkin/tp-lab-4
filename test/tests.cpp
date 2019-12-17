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
    EXPECT_EQ(States::WAIT, tmp);
}

TEST(lab4, task_3) {
    Automata automata;
    automata.on();
    automata.off();

    States tmp = automata.getState();
    EXPECT_EQ(States::OFF, tmp);
}

TEST(lab4, task_4) {
    Automata automata;
    automata.on();

    int tmp = automata.getCash();
    EXPECT_EQ(0, tmp);
}

TEST(lab4, task_5) {
    Automata automata;
    automata.on();
    automata.coin(12);

    int tmp = automata.getCash();
    EXPECT_EQ(12, tmp);
}

TEST(lab4, task_6) {
    Automata automata;
    automata.on();
    automata.coin(12);

    bool tmp = automata.choice(0);
    EXPECT_EQ(false, tmp);
}

TEST(lab4, task_7) {
    Automata automata;
    automata.on();
    automata.coin(12);

    bool tmp = automata.choice(1);
    EXPECT_EQ(true, tmp);
}

TEST(lab4, task_8) {
    Automata automata;
    automata.on();
    automata.coin(12);
    automata.choice(1);

    int tmp = automata.getCash();
    EXPECT_EQ(2, tmp);
}

TEST(lab4, task_9) {
    Automata automata;
    automata.on();
    automata.coin(12);
    automata.choice(1);
    automata.coin(40);


bool tmp = automata.choice(3);
EXPECT_EQ(true, tmp);
}

TEST(lab4, task_10) {
    Automata automata;
    automata.on();
    automata.coin(12);
    automata.choice(1);

    States tmp = automata.getState();
    EXPECT_EQ(States::WAIT, tmp);
}