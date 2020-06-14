#pragma once

#include <string>

enum states { OFF, WAIT, ACCEPT, CHECK, COOK };
using namespace std;

class Automata
{
private:
	unsigned cash;
	states currentState;
	size_t currentOrder;

	string menu[6]={"Black tea", "Latte", "Cappuccino", "Espresso", "Americano", "Frappuccino" };
	unsigned prices[6] = { 60, 120, 100, 80, 70, 150 };

public:

	Automata();

	string on();
	string off();
	string coin(const unsigned);
	string choice(string);
	string printMenu();
	string printState();
	bool check();
	string cancel();
	string cook();
	string finish();


};
