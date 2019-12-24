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
    automata.choice("apple");
    automata.coin(123);
    automata.choice("apple");
    string potato = automata.choice("potato");
    cout<< potato <<endl;
    automata.printState();
    unsigned int odd_money = automata.cancel();
    cout<< odd_money <<endl;
    automata.off();

    return 0;
}