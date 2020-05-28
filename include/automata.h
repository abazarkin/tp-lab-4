//
// Created by Sergey Baranenkov on 17.12.2019.
//

#ifndef TASK1_AUTOMATA_H
#define TASK1_AUTOMATA_H
#pragma once
#include <iostream>
#include <map>
using namespace std;
class Automata
{
private:
    map <string, int> menu {{"coffee",40},
                            {"tea",35},
                            {"fanta",60},
                            {"beer",100}};

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
#endif //TASK1_AUTOMATA_H
