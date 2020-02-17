#include "gtest/gtest.h"
#include "Automata.hpp"

TEST(Test_states, test_creation) {
    Automata a;
    EXPECT_EQ(a.printState(), "OFF");
 }
 
 
TEST(Test_states, test_on) {
  Automata a;
  a.on();
  EXPECT_EQ(a.printState(), "WAIT");
}
 
 
TEST(Test_states, test_off) {
  Automata a;
  a.on();
  a.off();
  EXPECT_EQ(a.printState(), "OFF");
}
 
TEST(Test_states, test_coin) {
  Automata a;
  a.on();
  a.coin(228);
  a.coin(10);
  EXPECT_EQ(a.printState(), "ACCEPT");
}

TEST(Test_states, test_cancel_1) {
  Automata a;
  a.on();
  a.coin(10);
  a.coin(5);
  a.cancel();
  EXPECT_EQ(a.printState(), "WAIT");
}


TEST(Test_states, test_cook) {
  Automata a;
  a.on();
  a.coin(10);
  a.choice(0);
  a.cook();
  EXPECT_EQ(a.printState(), "COOK");
}

TEST(Test_states, test_finish) {
  Automata a;
  a.on();
  a.coin(10);
  a.coin(50);
  a.choice(1);
  a.cook();
  a.finish();
  EXPECT_EQ(a.printState(), "WAIT");
}