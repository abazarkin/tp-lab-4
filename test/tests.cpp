#include "gtest/gtest.h"
#include "Automata.h"

TEST(Test_states, test_creation) {
   Automata obj;
   EXPECT_EQ(obj.printState(), "OFF");
}

TEST(Test_states, test_on) {
   Automata obj;
   obj.on();
   EXPECT_EQ(obj.printState(), "WAIT");
}

TEST(Test_states, test_off) {
   Automata obj;
   obj.on();
   obj.off();
   EXPECT_EQ(obj.printState(), "OFF");
}

TEST(Test_states, test_coin_1) {
   Automata obj;
   obj.on();
   obj.coin(10);
   EXPECT_EQ(obj.printState(), "ACCEPT");
}

TEST(Test_states, test_coin_2) {
   Automata obj;
   obj.on();
   obj.coin(10);
   obj.coin(5);
   EXPECT_EQ(obj.printState(), "ACCEPT");
}

TEST(Test_states, test_cansel_1) {
   Automata obj;
   obj.on();
   obj.coin(10);
   obj.coin(5);
   obj.cansel();
   EXPECT_EQ(obj.printState(), "WAIT");
}

TEST(Test_states, test_choice) {
   Automata obj;
   obj.on();
   obj.coin(10);
   obj.coin(50);
   obj.choice(1);
   EXPECT_EQ(obj.printState(), "CHECK");
}

TEST(Test_states, test_cansel_2) {
   Automata obj;
   obj.on();
   obj.coin(10);
   obj.coin(5);
   obj.choice(1);
   obj.cansel();
   EXPECT_EQ(obj.printState(), "WAIT");
}

TEST(Test_states, test_check_1) {
   Automata obj;
   obj.on();
   obj.coin(10);
   obj.coin(50);
   obj.choice(1);
   EXPECT_EQ(obj.check(), true);
}

TEST(Test_states, test_check_2) {
   Automata obj;
   obj.on();
   obj.coin(1);
   obj.coin(5);
   obj.choice(1);
   EXPECT_EQ(obj.check(), false);
}

TEST(Test_states, test_cook) {
   Automata obj;
   obj.on();
   obj.coin(10);
   obj.coin(50);
   obj.choice(1);
   obj.cook();
   EXPECT_EQ(obj.printState(), "COOK");
}

TEST(Test_states, test_finish) {
   Automata obj;
   obj.on();
   obj.coin(10);
   obj.coin(50);
   obj.choice(1);
   obj.cook();
   obj.finish();
   EXPECT_EQ(obj.printState(), "WAIT");
}
