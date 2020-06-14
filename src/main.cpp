#include "Automata.h"
#include <iostream>

int main() {
	Automata my{};

	cout << my.on() << endl;
	cout << my.printState() << endl;
	cout << my.printMenu() << endl;
	cout << my.coin(250) << endl;
	cout << my.printState() << endl;
	cout << my.choice("Latte") << endl;
	cout << my.printState() << endl;
	cout << my.cook() << endl;
	cout << my.printState() << endl;
	cout << my.finish() << endl;
	cout << my.printState() << endl;
	cout << my.off() << endl;
	cout << my.printState() << endl;


}