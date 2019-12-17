#ifndef AUTOMATA_H
#define AUTOMATA_H
#include <string>
#include <iostream>
#include "Drink.h"


using namespace std;

enum STATE{off, wait, accept, check, cook};

class Automata
{
    private:
        int cash = 0;
        Drink* menu;
        int curSt;
    public:
        Automata();
        void on(){this->curSt = wait; showMenu();};
        void off(){this->curSt = STATE::off;};
        void coin();
        Drink* getMenu(){return this->menu;};
        void showMenu();
        int getState(){return this->curSt;};
        void choice();
        void cancel();
        bool check(int chDr);
        void cook();
        void finish();
};

#endif // AUTOMATA_H
