#pragma once
#include <vector>
#include <string>
#include <map>
#include <iostream>

enum STATES {
	STATE_OFF = 0,
	STATE_WAIT,
	STATE_ACCEPT,
	STATE_CHECK,
	STATE_WORK
};

class Automata {
private:
	STATES state;
	std::vector<int> price{50, 70, 90, 100};
	std::vector<std::string> product{"Tea", "Espresso", "Doppi", "Irish"};
	std::vector<std::pair<std::string, int>> menu {
		std::make_pair("Tea", 50),
		std::make_pair("Espresso", 70),
		std::make_pair("Doppi", 90),
		std::make_pair("Irish", 100)
	};
	
	int money;
public:
	Automata();
	void on();
	void off();
	void coin(int);
	void cancel();
	void choice(int);
	bool check(int);
	void cook(int);
	void finish();
	int getMoney();
	void printMenu();
};

