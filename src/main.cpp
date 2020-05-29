#include <iostream>
#include <string>
#include "Automata.h"

using namespace std;

int main()
{
	Automata Nescafe;
	Nescafe.on();
	Nescafe.printState();

	Nescafe.coin(35);
	Nescafe.printState();

	Nescafe.choice(2);
	Nescafe.printState();
	Nescafe.cancel();

	Nescafe.coin(20);
	Nescafe.printState();
	Nescafe.choice(2);
	unsigned int my_change = Nescafe.change();
	//Nescafe.printState();

	int z;
	cin >> z;
	getchar();
}