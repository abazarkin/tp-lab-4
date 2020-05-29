//
// Created by Илья Соловьёв on 02.12.2019.
//

#ifndef TP_LAB_4_AUTOMATA_H
#define TP_LAB_4_AUTOMATA_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum STATES {
    OFF, WAIT, ACCEPT, CHECK, COOK
};

class Automata {
private:
    int cash;
    int total;
    vector<string> menu;
    vector<int> prices;
    STATES state;


public:

    Automata(vector<string> menu, vector<int> prices);

    void on();

    void off();

    void coin(int cash);

    void printMenu();

    STATES printState();

    bool choice(int number);

    bool check(int choice);

    int cancel();

    void cook(int choice);

    int finish(int choice);

    int getCash();
};

#endif //TP_LAB_4_AUTOMATA_H
