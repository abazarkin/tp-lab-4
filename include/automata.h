//
// Created by Mikhail on 15.12.2019.
//

#ifndef TASK1_AUTOMATA_H
#define TASK1_AUTOMATA_H

#include <iostream>
#include <vector>
#include <string>



enum States{
    OFF, WAIT, ACCEPT, CHECK, COOK
};

class Automata{
public:
    Automata();
    void on();
    void off();
    void coin(int coins);
    void printMenu();
    void printState();
    void choice(int drinkNum);
    bool check(int drinkNum);
    void cancel();
    void cook(int drinkNum);
    void finish();
    int getCash();
    States getState();
private:
    States state;
    int cash;
    std::vector<std::string> menu = {"Black tea", "Green tea", "Espresso", "Chocolate"};
    std::vector<int> prices = {30, 30, 40, 50};
    std::vector<std::string> stateNames = {"OFF", "WAIT", "ACCEPT", "CHECK", "COOK"};
};
#endif //TASK1_AUTOMATA_H
