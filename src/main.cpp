#include "Automata.h"
#include <iostream>

using namespace std;


int main() {
	Automata run;
	run.on();
	run.printMenu();
	run.coin(150);
	run.choice("Latte");
	run.printState();
	run.off();
} 