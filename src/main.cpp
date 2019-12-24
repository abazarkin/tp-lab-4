#include "Automata.h"
#include <iostream>

using namespace std;

int main() 
{
	Automata coffee;

	coffee.printState();
 
	coffee.on(); 
	coffee.printState();

	coffee.printMenu();
	coffee.coin(35);
	coffee.coin(15);
	coffee.choice(2);
	coffee.check();
	coffee.cook();
	coffee.finish();
	coffee.off();

	return 0;
}