#include "automata.h"
#include <iostream>

int main() {
    Automata coffee;
    coffee.printState();
    coffee.on();
    coffee.printMenu();
    coffee.off();
    coffee.on();
    coffee.printMenu();
    coffee.coin(27);
    coffee.choice(4);
    coffee.finish();
    coffee.off();
    return 0;
}