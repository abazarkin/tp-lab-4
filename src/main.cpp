//
// Created by Mikhail on 15.12.2019.
//
#include <iostream>
#include "automata.h"
#include <vector>

int main(){
    auto t = Automata();
    t.on();
    t.coin(10);
    std::cout << t.getCash() << '\n';
    t.printState();
    t.printMenu();
    t.choice(0);
    t.choice(3);
    t.coin(100);
    t.choice(3);
    t.getCash();
    t.off();
    return 0;
}