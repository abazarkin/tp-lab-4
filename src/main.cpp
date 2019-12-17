//
// Created by Sergey Baranenkov on 17.12.2019.
//
#include <iostream>
#include <map>
#include <string>
#include "automata.h"
using namespace std;
int main() {
    Automata automata;
    automata.on();
    automata.printMenu();
    automata.coin(5);
    automata.choice("russiano");
    automata.choice("fanta");
    automata.coin(123);
    automata.choice("fanta");
    automata.choice("coffee");
    automata.printState();
    int odd_money = automata.cancel();
    cout<<odd_money<<endl;
    automata.off();

    return 0;
}