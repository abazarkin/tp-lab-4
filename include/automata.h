#pragma once
#include <iostream>
#include <string>
#include<fstream>
#include <stdio.h>

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
	READY,
	ERROR
};


class Automata
{
public:
	Automata();
	~Automata();

	
	returns coin(int sum);
	returns choise(int Num);
	returns cansel();

	returns on();
	returns off();

	states getState() const;
	int getCash() const;
	menu getMenu() const;
	
	returns finish();


private:
	states state;
	int cash;
	menu m;
	int chosenNum;
	int key;
	//void setMenu(string* strs, int* pr, int N);
	//void setMenu(int N);
	//void setMenu(ifstream fin);
	void setMenu();
	bool check();
	returns cook();
	

};



