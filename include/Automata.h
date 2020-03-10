#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
enum STATES { OFF, WAIT, ACCEPT, CHECK, COOK };

class Automata {
private:
	int cash=0;
	vector<string>menu;
	vector<int>prices;
	STATES state;
public:
	Automata(string file_menu,string file_prices);
	void makeMenu();
	void makePrices();
	void on();
	void off();
	int coin(int NewSum); 
	void printMenu(); 
	string printState(); 
	string choice(int Choise); 
	void check(int VPrice); 
	void cancel();
	void cook(); 
	void finish();
	int GetCash();
};