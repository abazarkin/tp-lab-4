#include "Automata.h"

int main() {
	Automata nescafe;
	nescafe.on();
	std::cout << nescafe.getState() << std::endl;
	nescafe.getMenu();
	nescafe.coin(150);
	nescafe.choice(4);
	nescafe.off();
	std::cout << nescafe.getState() << std::endl;
}