#include <iostream>
#include "Automata.h"

using namespace std;

int main() {
	Automata hotdrinks;
	string current_state;
	
	hotdrinks.on();
	hotdrinks.printMenu();
	hotdrinks.coin(10);
	hotdrinks.coin(50);
	hotdrinks.choice(7);
	hotdrinks.off();
	return 0;	
}