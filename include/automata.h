//
// Created by Sergey Baranenkov on 17.12.2019.
//

#ifndef TASK1_AUTOMATA_H
#define TASK1_AUTOMATA_H
#pragma once
#include <iostream>
#include <map>
#include <string>

class Automata
{
private:
    std::map <std::string, int> menu {{"coffee",40},
                            {"tea",35},
                            {"fanta",60},
                            {"beer",100}};

    int cash, current_operation_cash;
    enum STATES {
        OFF,
        WAIT,
        ACCEPT,
        CHECK,
        COOK
    };
    static std::string STATE_NAMES[5];
    STATES state;

    void cook(std::string);
    bool check(std::string);
    void finish();
public:
    Automata();
    void on();
    void off();
    void coin(unsigned int);
    void printMenu();
    void printState();
    int cancel();
    void choice(std::string);
};
#endif //TASK1_AUTOMATA_H
