#pragma once
#include <iostream>
#include <map>
#include <string>
using namespace std;


class Automata
{
	
private:

    static map <string, int> menu {std::make_pair("apple",40)};
    unsigned int cash, current_operation_cash;
	
    enum STATES {
        OFF,
        WAIT,
        ACCEPT,
        CHECK,
        COOK
    };
	
    static string STATE_NAMES[5];
    STATES state;

    string cook(const string&);
    bool check(const string&);
    void finish();
	
public:

    Automata();
    bool on();
    bool off();
    bool coin(unsigned int);
    map<string,int> printMenu();
    string printState();
    unsigned int cancel();
    string choice(const string&);
};
