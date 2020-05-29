#pragma once
#include <iostream>
#include <string>

using namespace std;

#ifndef AUTOMATA_H
#define AUTOMATA_H



class Automata
{
private:
	enum STATES
	{
		OFF = 0, WAIT, ACCEPT, CHECK, COOK
	};
	unsigned int cash;
	string menu[5] = { "amerikano", "espresso", "latte", "cappuccino", "chocolate" };
	unsigned int prices[5] = { 40, 50, 45, 35, 30 };
	STATES state;
	string state_str[5] = { "OFF", "WAIT", "ACCEPT", "CHECK", "COOK" };
public:
	Automata();
	void on();
	void off();
	unsigned int coin(unsigned int);
	void printMenu();
	void printState();
	void choice(unsigned int);
	bool check(unsigned int);
	void cancel();
	void cook(unsigned int);
	void finish();
	unsigned int change();
};



#endif