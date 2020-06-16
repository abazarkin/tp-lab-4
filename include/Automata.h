#pragma once
#include <string>
#include <iostream>

using namespace std;

class Automata {
private:
	enum STATES { OFF, WAIT, ACCEPT, CHECK, COOK };
	int cash;
	static string menu[9];
	static int prices[9];
	STATES state;
	void cook();
	void cancel();
	void finish();
	bool check(int drink);

public:
	Automata();
	void on();
	void off();
	int coin(int money);
	bool choice(int drink);
	void getMenu();
	const string getState();
};
