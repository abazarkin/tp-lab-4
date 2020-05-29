#include <iostream>
#include "Automata.h"
using namespace std;

int main() {
	Automata machine("menu.txt", "prices.txt");
	machine.makeMenu();
	machine.makePrices();
	machine.on();
	machine.printMenu();
	machine.coin(45);
	machine.choice(4);
	machine.off();

}