#include <iostream>
#include "Automata.h"

int main(){
    Automata automata = Automata();

    automata.on();
    automata.coin(100);
    automata.printMenu();
    automata.choice(2);

    return 0;
}