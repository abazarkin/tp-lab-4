#include "gtest/gtest.h"
#include "Automata.h"

TEST(lab4,task1) {
    Automata automata = Automata();
    automata.on();
    EXPECT_EQ("WAIT", automata.getState());
}