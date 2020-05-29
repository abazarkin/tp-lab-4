#pragma once
#include <string>
#include <iostream>

enum States {OFF, WAIT, ACCEPT, CHECK, COOK};

class Automata {

private:

    States state;
    int cash;
    static const int numberOfItems = 4;
    std::string menu[numberOfItems] = {"Chocolate milk", "Cappuccino", "Black Tea", "Green Tea"};
    int prices[numberOfItems] = {50, 100, 40, 45};

public:

    Automata();
    void on();
    void off();
    void coin(int coins);
    void printMenu();
    void printState();
    void choice(int number);
    void check(int number);
    void cancel();
    void cook();
    void finish();
    std::string getState();
};