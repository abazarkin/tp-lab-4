#pragma once
#include <iostream>
#include <string>
using namespace std;

class Automata
{
public:
	Automata();
	~Automata();

	int coin();
	int choise();
	int cansel();
	void admin(int key);

private:
	string state;
	int cash;
	string* menu;
	int* prices;
	int dishes;
	int chosenNum;
	int key;

	int on();
	int off();

	void printState();
	void printMenu();
	void setMenu(string* strs, int* pr, int N);
	void setMenu(int N);
	bool check();
	int cook();
	int finish();

};

Automata::Automata()
{
	chosenNum = -1;
	key = 1234;
	state = "FIRST START";
}

Automata::~Automata()
{
}