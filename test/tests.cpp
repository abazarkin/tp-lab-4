#include "gtest/gtest.h"
#include "automata.h"
#include <string>

TEST(coffeeMachine, task_1){
Automata coffee;
STATES tmp = coffee.getState();
EXPECT_EQ(STATES::OFF, tmp);
}
