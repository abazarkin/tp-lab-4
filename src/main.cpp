#include "automata.h"

int main()
{
	Automata Drinks_Maker = Automata();
	Drinks_Maker.printState();
	Drinks_Maker.on();

	cout << endl;

	Drinks_Maker.printMenu();
	Drinks_Maker.coin(15);
	Drinks_Maker.choice(1);

	cout << endl;

	Drinks_Maker.coin(40);
	Drinks_Maker.choice(1);

	cout << endl;

	Drinks_Maker.coin(100);
	Drinks_Maker.choice(2);

	cout << endl;

	Drinks_Maker.coin(100);
	Drinks_Maker.cancel();

	Drinks_Maker.off();
}