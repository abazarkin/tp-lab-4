
#include "task1.h"
#include <iostream>

using namespace std;



int main() {
	Automata automata;
	automata.on();
	automata.printMenu();
	automata.coin(5);
	automata.choice("Coffee");
	automata.coin(123);
	automata.choice("Coffee");
	string Coffee = automata.choice("Coffee");
	cout << Coffee << endl;
	automata.printState();
	automata.off();
}
