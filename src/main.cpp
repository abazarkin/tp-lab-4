#include "Automata.h"
int main()
{
	Automata automat;
	automat.on();
	std::cout << automat.getState() << std::endl;
	automat.getMenu();
	automat.coin(200);
	automat.choice(4);
	automat.cook();
	automat.finish();
	automat.off();
}