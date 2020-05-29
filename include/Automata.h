#pragma once
#include <iostream>
#include <vector>
enum STATES {
	OFF,
	WAIT,
	ACCEPT,
	CHECK,
	COOK
};
class Automata {
private:
	STATES state;
	int cash;
	std::vector<std::string> menu{ "Coffee", "Juice", "Soda", "Black Tea" };
	int prices[4]{200, 130, 100, 70};
public:
	Automata();
	void on();
	void off();
	void coin(int);
	void getMenu();
	std::string getState();
	int choice(int);
	int check(int);
	int cancel();
	void cook();
	int finish();
};
