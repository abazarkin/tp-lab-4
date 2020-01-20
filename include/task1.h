#pragma once
#include <string>

#ifndef TASK1_H
#define TASK1_H

using namespace std;

enum states{OFF,WAIT,ACCEPT,CHECK,COOK};


class Automata {

private:
	unsigned cash;
	string menu[6] = { "Coffee", "Tea", "Milk", "Espresso", "Moka", "Water" };
	unsigned prices[6] = {100, 40, 50, 120, 140, 20};
	states state;

public:

	Automata();
	void on();
	void off();
	int coin(unsigned int);
	void printMenu();
	void printState();
	string choice(string);
	void check(const int);
	void cancel();
	void cook();
	void finish();
};

#endif
