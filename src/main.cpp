#include "coffee_machine.h"
#include <iostream>

int main()
{
	Automata starbucks_coffee;
	cout << starbucks_coffee.printState() << endl;
	cout << starbucks_coffee.on() << endl;
	cout << starbucks_coffee.printMenu() << endl;
	cout << starbucks_coffee.off() << endl;
	cout << starbucks_coffee.on() << endl;
	cout << starbucks_coffee.printMenu() << endl;
	cout << starbucks_coffee.coin(6) << endl;
	cout << starbucks_coffee.choice(3) << endl;
	cout << starbucks_coffee.finish() << endl;
	cout << starbucks_coffee.off() << endl;
	cout << endl;

	Automata Nescafe;
	cout << Nescafe.on() << endl;
	cout << Nescafe.printMenu() << endl;
	cout << Nescafe.coin(2) << endl;
	cout << Nescafe.cancel() << endl;
	cout << Nescafe.coin(2) << endl;
	cout << Nescafe.coin(4) << endl;
	cout << Nescafe.choice(2) << endl;
	cout << Nescafe.finish() << endl;
	cout << Nescafe.cancel() << endl;
	cout << Nescafe.off() << endl;
	cout << endl;

	system("pause");
	return 0;
}