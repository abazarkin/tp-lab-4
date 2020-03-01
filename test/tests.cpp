#include "gtest/gtest.h"
#include "automata.h"
#include "string_def.h"

TEST (automata,test1_system){
    Automata* automata = new Automata();
	EXPECT_FALSE(automata == nullptr);
	EXPECT_FALSE( _cook_.empty());
	EXPECT_FALSE( _off_.empty());
	EXPECT_FALSE( _add_coin_message_.empty());
	EXPECT_FALSE( _menu_names_.size() != _menu_prices_.size());
	EXPECT_TRUE( _menu_names_.size() > 0);
	EXPECT_FALSE( _cancel_.empty());
	EXPECT_FALSE( _choice_.empty());
	EXPECT_FALSE( _not_enough_money_.empty());
	EXPECT_FALSE( _error_choice_.empty());
	EXPECT_FALSE( _return_money_.empty());
}

TEST(automata, test1_on_off) {
	Automata* automata = new Automata();
	automata->on();
}


