#include <iostream>
#include "Automata.h"

using namespace std;

int main(int argc, const char * argv[]) {
    Automata DrinkRobot = Automata();
    DrinkRobot.on();
    DrinkRobot.coin(40);
    DrinkRobot.printMenu();
    DrinkRobot.choice(4);
    DrinkRobot.coin(5);
    DrinkRobot.choice(3);
    DrinkRobot.off();
}
