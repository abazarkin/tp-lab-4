#pragma once

#include <vector>
#include <string>
#include <iostream>

using namespace std;

enum STATES { ON, OFF, WAIT, ACCEPT, CHECK, COOK };
enum DRINKS { TEA, COFFE, COLA };

class Automata{
private:
	int cash;
	//vector<string> menu = { "tea", "coffe", "cola" };
	//vector<int> prices = { 2, 1, 5 };
	string menu[3];
	int prices[3];
	STATES state;
	bool check(DRINKS drink);
	void cook(DRINKS drink);
	void finish();
public:
	Automata();
	void on();
	void off();
	void coin(int income);
	void printMenu();
	void printState();
	void choice(DRINKS drink);
	//bool check(DRINKS drink);
	void cancel();
	//void cook(DRINKS drink);
	//void finish();
	void returnMoney();
	int getCash();
};