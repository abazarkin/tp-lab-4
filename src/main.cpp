#include "Automata.h"
#include <iostream>

using namespace std;


int main() {
	Automata automat;
	automat.on();
	automat.printMenu();
	automat.coin(100);
	automat.choice("Cappuccino");
	automat.printState();
	automat.off();
}