#ifndef AUTOMATA_H
#define AUTOMATA_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Automata
{
private:
	int cash;
	vector<string> menu = {"Tea", "Coffee", "Milk", "Water", "Juice"};
	vector<int> prices = { 30, 40, 35, 20, 35 };
	enum STATES { OFF, WAIT, ACCEPT, CHECK, COOK };
	vector<string> states = { "OFF", "WAIT", "ACCEPT", "CHECK", "COOK" };
	STATES state;
	
	bool check(int drink);
	void cook(int drink);
	int finish();
public:
	Automata();
	void on();
	int off();
	void coin(int money);
	void printMenu();
	void printState();
	int choice(int drink);
	int cancel();
};

#endif
