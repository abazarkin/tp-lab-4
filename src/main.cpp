#include <iostream>
#include "automata.h"
int main()
{
	Automata mac = Automata();
	mac.on();
	mac.coin(10);
	mac.coin(15);
	mac.printMenu();
	mac.choice(2);
	mac.check();
	mac.cook();
	mac.finish();
	mac.off();
}

