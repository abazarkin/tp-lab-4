#pragma once
#include <string>
#include <iostream>
using namespace std;

enum States { OFF, WAIT, ACCEPT, CHECK, COOK };

class Automata
{
private:
	States state;
	int cash;
	int drink;
	const string menu[4] = { "tea", "cofe", "milk","kakava" };
	const int prices[4] = { 15,20,10,20 };
public:
	Automata();
	int on();
	int off();
	int coin(int coins);
	int printMenu();
	int printState();
	int choice(int numb);
	int check();
	int cancel();
	int cook();
	int finish();
}; 