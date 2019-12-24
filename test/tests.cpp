#include "gtest/gtest.h"
#include "Automata.h"

TEST(States_test, check_off_state) {
   Automata aut;
   EXPECT_EQ(aut.print_state(), "OFF");
 }

 TEST(States_test, check_on_state) {
   Automata aut;
   aut.on();
   EXPECT_EQ(aut.print_state(), "WAIT");
 }

 TEST(States_test, check_off_func_state) {
   Automata aut;
   aut.on();
   aut.off();
   EXPECT_EQ(aut.print_state(), "OFF");
 }

 TEST(States_test, coin_test) {
   Automata aut;
   aut.on();
   aut.coin(50);
   EXPECT_EQ(aut.print_state(), "ACCEPT");
 }

 TEST(Cash_test, cash_check_test) {
   Automata aut;
   aut.on();
   aut.coin(50);
   aut.choice(8);
   EXPECT_EQ(aut.check(), false);
   aut.choice(4);
   EXPECT_EQ(aut.check(), true);
 }

 TEST(Cash_test, cash_after_buy_test1) {
   Automata aut;
   aut.on();
   aut.coin(50);
   aut.choice(6);
   EXPECT_EQ(aut.check(), true);
   aut.cook();
   aut.choice(1);
   EXPECT_EQ(aut.check(), false);
 }

 TEST(Cash_test, cash_after_buy_test2) {
   Automata aut;
   aut.on();
   aut.coin(50);
   aut.choice(6);
   auto pair = aut.cook();
   EXPECT_EQ(pair.first, 5);
 }

 TEST(Funcs_test, cancel_test1) {
   Automata aut;
   aut.on();
   aut.coin(50);
   EXPECT_EQ(aut.print_state(), "ACCEPT");
   aut.cancel();
   EXPECT_EQ(aut.print_state(), "WAIT");
 }

 TEST(Funcs_test, cancel_test2) {
   Automata aut;
   aut.on();
   aut.coin(50);
   aut.choice(6);
   aut.check();
   EXPECT_EQ(aut.print_state(), "CHECK");
 }

 TEST(Funcs_test, finish_test) {
   Automata aut;
   aut.on();
   aut.coin(50);
   aut.choice(6);
   aut.cook();
   aut.finish();
   EXPECT_EQ(aut.print_state(), "WAIT");
 }

 