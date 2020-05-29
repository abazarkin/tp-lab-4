#pragma once
#include <string>

using namespace std;

enum STATES { OFF, WAIT, ACCEPT, CHECK, COOK };

class Automata {

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

private:
	STATES CurrentState;
	string Menu[6] = { "Green Tea", "Latte", "Cappuccino", "Espresso", "Americano", "Black Tea" };
	unsigned Prices[6] = { 50, 80, 100, 45, 75, 60 };
	unsigned int Money;

};