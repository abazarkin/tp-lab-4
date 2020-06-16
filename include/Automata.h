#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

enum AState
{
	aOff = 0, aWait, aAccept, aCheck, aCook
};

class Automata
{
private:
	AState state;
	unsigned int coins;
	vector<string> menu{ "Americano", "Latte", "Espresso", "Tea" };
	vector<unsigned int> price{ 15, 20, 25, 30 };

public:
	Automata();
	void on();
	void off();
	void coin(unsigned int);
	void cancel();
	void choice(unsigned int);
	bool check(unsigned int);
	void cook(unsigned int);
	int getCash();
};