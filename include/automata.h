#ifndef automata_h
#define automata_h

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

enum States {OFF, WAIT, ACCEPT, CHECK, COOK};

class Automata
{
    
private:
    int cash;
    std::vector<std::string> menu = {"Water", "Juice", "Coffee", "Yellow Tea", "Milk", "Coca-Cola", "Fanta"};
    std::vector<int> prices = {10, 25, 30, 30, 20, 40, 40};
    States current_state;
    std::vector<std::string> state_labels = {"OFF", "WAIT", "ACCEPT", "CHECK", "COOK"};


public:
    Automata();
    void on();
    void off();
    void coin(int value);
    void printMenu();
    void printState();
    void choice(int drink);
    bool check(int drink);
    void cancel();
    void cook(int drink);
    void finish();
    States get_current_state();
    int get_current_cash();
    
};

#endif
