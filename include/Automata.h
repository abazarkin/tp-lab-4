#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

class Automata {
private:
	int cash;
	string menu[6] = { "TEA","COF","CHOCL","GLINT","SMTHNG","ALSOSMTH" };
	int prices[6] = { 11, 22, 33, 44, 55, 66 };
	int state;// 0 - off | 1 - wait | 2 - accept | 3 - check | 4 - cook //
public:
	Automata();//конструктор
	void on();
	void off();
	int coin(int _cash);
	void printMenu();
	int printState();
	void choice();
	bool check(int i);
	int cancel();
	void cook();
	void finish();
};