#ifndef coffee_machine_h
#define coffee_machine_h

#include <string>
#include <iostream>
using namespace std;
enum STATES {
	ON,
	OFF,
	WAIT,
	ACCEPT,
	CHECK,
	COOK
};

class Automata
{
private:
	int balance;
	string menu[10] =
	{
		"Doubleshot Espresso",
		"Chesnut Praline Latte",
		"Iced Cocoa Cloud Macchiato",
		"Cappuccino",
		"Salted Caramel Mocha",
		"Americano",
		"Cold Brew Coffee",
		"Peppermint Frappuchino",
		"Hot cocoa",
		"Cinnamon Dolce Creme"
	};
	float prices[10] = { 3.99, 4.75, 5.35, 2.5, 4.15, 3.5, 4.25, 3.15, 4.99, 2.99 };
	STATES state;
	float costOfCoffee;

public:
	Automata();
	string on();
	string off();
	float coin(float);
	string printMenu();
	string printState();
	string choice(int);
	string check();
	float cancel();
	string cook();
	float finish();
};

#endif