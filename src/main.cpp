#include "automata.h"

#include <string>
#include <vector>
#include <iostream>

int main()
{
	std::vector<std::string> menu = { "Cola","Rum","Milk" };
	std::vector<int>        prise = {  10,    20,   30 };

	Automata automata(menu, prise);

	std::cout << "Larry comes to drink machine and try to get some drink.\n";
	std::cout << automata.getState() << " - says drink machine.\n";

	std::cout << "Larry turn drink machine on.\n";
	automata.on();
	std::cout << automata.getState() << " - says drink machine.\n";

	std::cout << "Larry push some button to see menu.\n\n";
	menu = automata.getMenu();

	for (int i = 0; i < menu.size(); i++)
	{
		std::cout << menu[i];
	}

	std::cout << "says drink machine.\n";

	std::cout << "Larry incert 12 coins.\n";
	automata.coin(12);
	std::cout << automata.getState() << " - says drink machine.\n";

	std::cout << "Larry choose 2 in menu.\n";
	automata.choise(2);
	std::cout << automata.getState() << " - says drink machine.\n";

	std::cout << "Larry check than he was incert enough coins.\n";
	std::cout << automata.check() << " - says drink machine.\n";

	std::cout << "Larry push cancel button.\n";
	automata.cancel();
	std::cout << automata.getState() << " - says drink machine.\n";
	
	std::cout << "Larry incert 32 coins.\n";
	automata.coin(32);
	std::cout << automata.getState() << " - says drink machine.\n";

	std::cout << "Larry choose 2 in menu.\n";
	automata.choise(2);
	std::cout << automata.getState() << " - says drink machine.\n";

	std::cout << "Larry check than he was incert enough coins.\n";
	std::cout << automata.check() << " - says drink machine.\n";

	std::cout << "Larry push some button to prepare drink.\n";
	automata.cook();
	std::cout << automata.getState() << " - says drink machine.\n";

	std::cout << "Larry push some button to get drink.\n";
	std::cout << automata.finish() << "\n";
	std::cout << "says drink machine.\n";
	std::cout << automata.getState() << " - says drink machine.\n";

	std::cout << "Larry turn drink machine off.\n";
	automata.off();
	std::cout << automata.getState() << " - says drink machine.\n";

	return 0;
}