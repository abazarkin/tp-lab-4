#include "Automata.h"
#include <iostream>
#include <string>

int main() {
	std::vector<std::string> menu { "Drink 1", "Drink 2", "Drink 3" };
	std::vector<unsigned> prices { 10, 15, 25 };
	Automata automata(menu, prices);
	automata.on();
	automata.coin(14);
	automata.choise(1);
	bool qwe = automata.check();
	return 0;
}