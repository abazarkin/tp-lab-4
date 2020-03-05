#include "automata.h"

int main()
{
	Automata *atm = new Automata();
	atm->on();
	atm->printMenu();
	atm->printState();
	atm->coin(100);
	atm->choice(0);
	atm->finish();
	atm->off();
	delete atm;
	return 0;
}