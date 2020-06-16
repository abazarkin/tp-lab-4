#include <iostream>
#include <string>
#include "Automata.h"

int main() {
    Automata box;
    box.printState();
    box.on();
    box.printState();
    box.printMenu();
    box.coin(100);
    box.printState();
    box.choice(2);
    box.printState();
    box.cook();
    box.printState();
    box.cancel();
    box.printState();
    box.coin(100);
    box.coin(100);
    box.coin(100);
    box.choice(4);
    box.cook();
    box.finish();
    return 0;
}
