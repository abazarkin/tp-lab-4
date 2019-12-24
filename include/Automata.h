#pragma once

#include "states.h"
#include <string>

class Automata {

private:

    STATES state;

    int cash;

    static const int nMenuItems = 4;
    std::string menu[nMenuItems]{"Вода", "Чай", "Кофе", "Сок"};
    int prices[nMenuItems]{40, 70, 50, 60};

    void check(int id);
    void cook();
    void finish();

public:

    Automata();
    STATES getState();
    void on();
    void off();
    void coin(int coin);
    void printMenu();
    void printState();
    void choice(int id);
    void cancel();



};

