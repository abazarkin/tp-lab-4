#ifndef AUTOMATA_H
#define AUTOMATA_H
#include <iostream>
#include <vector>

struct Drink{
    std::string name;
    int price;
};

class Automata {
private:
    enum STATES{OFF, WAIT, ACCEPT, CHECK, COOK} state = OFF;
    int cash = 0;
    int current = -1;
    std::vector<Drink> menu;

public:
    Automata();
    void on();
    void off();
    void coin(int newCash);
    void printMenu();
    void printState();
    void choice(int choosed);
    bool check(int choosed);
    void cancel();
    void cook();
    void finish();
    int getCash();
};
#endif
