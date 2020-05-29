#pragma once
#include <string>
#include <iostream>
using namespace std;

class automata
{
private:
	enum STATES {ON, OFF, WAIT,	ACCEPT, CHECK,	COOK, CANCEL}; 
	int cash;
	static string menu[];
	static int prices[];
	STATES state;
	int drink_id;
	int sugar_id;
	int flag;
	int printMenu();
	int printState();
	//void changeState(STATES state);
public:
	automata();
	int on();
	int off();
	int coin(int money);
	int choice(int drink);
	int check();
	int cancel();
	int cook();
	int add_sugar();
	int remove_sugar();
	int finish();
	void return_coins();
	void printSugarLvl();
};
