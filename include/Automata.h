//
// Created by aklen on 17.12.2019.
//
#include <iostream>
#include "string.h"

#define N 5
using namespace std;

enum STATES {OFF, WAIT, ACCEPT, CHECK, COOK, ERROR};

class Automata{
private:
    int cash;
    int position;
    int prices[N]={40, 60, 25, 90, 45};
    STATES state;
    string menu[N]={"tea", "coffee", "water", "hot chocolate", "juice"};

public:
    Automata(){
        cash=0;
        state=OFF;
    }
    void off();
    void on();
    void cancel();
    void coin(int deposit);
    void choice(int step);
    void cook();
    void printMenu();
    STATES printState();
    bool check();
    void finish();
    void refund_of_money();
    int getCash();
};
