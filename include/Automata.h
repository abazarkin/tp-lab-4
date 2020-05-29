#pragma once
#include <string>
using namespace std;

enum STATES { OFF, WAIT, ACCEPT, CHECK, COOK };
void pause(int seconds);

class Automata {
private:
	unsigned int cash;
	string menu[8] = { "chocolate", "espresso", "lemon tea", "mochaccino", "americano", "ristretto", "latte", "russiano =)" };
	unsigned int prices[8] = { 35, 30, 20, 30, 35, 25, 40, 50 };
	STATES state;
	string state_text[5] = { "OFF", "WAIT", "ACCEPT", "CHECK", "COOK" };

	void check(unsigned int drink_num);
	void cook();
	void finish();
public:
	Automata();
	void on();
	void off();
	unsigned int coin(unsigned int money);
	void printMenu();
	void printState();
	string getState();
	void printBalance();
	unsigned int getBalance();
	void choice(unsigned int drink_num);
	void cancel();
};
