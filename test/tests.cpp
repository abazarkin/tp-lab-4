#include "gtest/gtest.h"
#include "automata.h"

TEST (automata,test1_create){
    Automata* automata = new Automata();
	EXPECT_FALSE(automata == nullptr);
	EXPECT_EQ(OFF, automata->state);
}

TEST(automata, test1_on_off) {
	Automata* automata = new Automata();
	automata->on();
	EXPECT_TRUE(automata->condition);
	automata->coin(123);
	automata->off();
	EXPECT_TRUE(0, automata->cancel());
	automata->on();
	EXPECT_TRUE(123, automata->cancel());
}


