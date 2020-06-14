#pragma once
#include <string>

using namespace std;

enum STATES { OFF, WAIT, ACCEPT, CHECK, COOK };

class Automata {
private:
	STATES CurrentState;
	string Menu[9] = { "Cappuccino", "Latte", "Green tea", "Black tea", "Americano", "Espresso", "Russiano", "Cacao", "Milk" };
	unsigned Prices[9] = { 40, 50, 20, 25, 55, 60, 30, 70, 65};
	unsigned int Money;
public:
	Automata();
	void on();
	void off();
	int coin(unsigned int sum);
	void printMenu();
	void printState();
	string choice(string);
	void check(const int);
	void cancel();
	void cook();
	void finish();
};
