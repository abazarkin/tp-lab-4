#include "gtest/gtest.h"
#include "Automata.h"

TEST(Cash_test, cash_check_test) {
   Automata aut;
   aut.on();
   aut.coin(50);
   aut.choice(4);
   EXPECT_EQ(aut.check(), false);
   aut.choice(1);
   EXPECT_EQ(aut.check(), true);
 }

 TEST(Cash_test, cash_after_buy_test1) {
   Automata aut;
   aut.on();
   aut.coin(50);
   aut.choice(2);
   EXPECT_EQ(aut.check(), true);
   aut.cook();
   aut.choice(2);
   EXPECT_EQ(aut.check(), true);
 }


 TEST(Funcs_test, cancel_test1) {
   Automata aut;
   aut.on();
   aut.coin(50);
   EXPECT_EQ(state, "ACCEPT");
   aut.cancel();
   EXPECT_EQ(state, "WAIT");
 }

 TEST(Funcs_test, cancel_test2) {
   Automata aut;
   aut.on();
   aut.coin(50);
   aut.choice(1);
   aut.check();
   EXPECT_EQ(state, "CHECK");
 }

 TEST(Funcs_test, finish_test) {
   Automata aut;
   aut.on();
   aut.coin(50);
   aut.choice(3);
   aut.cook();
   aut.finish();
   EXPECT_EQ(state, "WAIT");
 }

