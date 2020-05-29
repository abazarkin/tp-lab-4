#pragma once
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;


class Automata
{
private:
    enum STATES {
        OFF,
        WAIT,
        ACCEPT,
        CHECK,
        COOK
    };

    STATES state;
	STATES cached_state;

	int cash;
	int cached_cash;
	int number_choice;

	std::vector<std::string> menu_names;
	std::vector<int> menu_prices;

public:
    Automata();
    void on();
    void off();
	void console();
    void coin();
    void menu();
    void cancel();
    void choice();
	void cook();
	void return_money();
};
