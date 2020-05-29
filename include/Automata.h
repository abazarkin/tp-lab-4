#ifndef Automata_h
#define Automata_h

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

enum STATES {
    OFF,
    WAIT,
    ACCEPT,
    CHECK,
    COOK
};

class Automata{
private:
    int cash;
    vector<string> menu = {"Default", "Coffee", "Tea", "Juice", "Vodka"};
    vector<int> prices = {0, 25, 20, 45, 900};
    STATES state;
public:
    Automata();
    void on();
    void off();
    void coin(int money);
    void printMenu();
    void printState();
    void choice(int drink_number);
    bool check(int money);
    void cancel();
    void cook(int drink_number);
    void finish();
    string get_state();
};

#endif /* Automata_h */
