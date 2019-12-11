#pragma once
#include <iostream>
#include <string>
using namespace std;

struct menu
{
	string* dishes;
	int* prices;
	int n;
};

enum returns {FAIL, CORRECT, MISTAKE};



enum states
{
	OFF,
	WAIT,
	ACCEPT,
	CHECK,
	COOK,
	ERROR
};


class Automata
{
public:
	Automata();
	~Automata();

	
	int coin();
	int choise();
	int cansel();

	returns on();
	returns off();

	states getState() const;
	int getCash() const;
	menu getMenu() const;
	
	void admin(int key);

private:
	states state;
	int cash;
	
	menu m;

	int chosenNum;
	int key;

	

	
	void setMenu(string* strs, int* pr, int N);
	void setMenu(int N);
	bool check();
	int cook();
	int finish();

};



Automata::~Automata()
{
}