#include "Automata.h"


int main()
{
	Automata atm;
	atm.on();
	atm.printMenu();
	atm.coin(1000);
	atm.choice(2);
	atm.getMoney();
	atm.off();
}