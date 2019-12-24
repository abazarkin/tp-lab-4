#include "gtest/gtest.h"
#include "automata.h"

TEST (automata,test1){
    Automata* automata = new Automata();
    automata->on();
    automata->coin(2000);
    automata->off();
    int odd_money = automata->cancel();
    EXPECT_EQ(0,odd_money);
    automata->on();
    odd_money = automata->cancel();
    EXPECT_EQ(2000,odd_money);
}

