#pragma once
#include <string>

enum states { OFF, WAIT, ACCEPT, CHECK, COOK };
using namespace std;

class Automata {
private:
	unsigned cash;
	states state;
	unsigned prices[6] = { 100, 90, 50, 150, 160, 20 };
	string menu[6] = { "Coffee", "Tea", "Milk", "Espresso", "Chocolate", "Water" };
public:
	Automata();
	void on();
	void off();
	void coin(unsigned int);
	void printMenu();
	void printState();
	string choice(string);
	void check(const int);
	void cancel();
	void cook();
	void finish();
};