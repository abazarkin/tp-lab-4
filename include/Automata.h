//
// Created by Илья on 011 11.12.19.
//

#ifndef TASK1_AUTOMATA_H
#define TASK1_AUTOMATA_H

#include <string>
using std::string;

enum _state{
    OFF,
    WAIT,
    ACCEPT,
    CHECK,
    COOK
};

class Automata{
private:
    unsigned int cash;
    string* beverage_menu;
    string* condiment_menu;
    unsigned int* beverage_prices;
    unsigned int* condiment_prices;
    _state state;
public:
    Automata(unsigned int*, unsigned int*, string*, string*);
    void on();
    unsigned int off();
    void coin(unsigned int);
    string* getBeverageMenu();
    string* getCondimentMenu();
    unsigned int* getBeveragePrices();
    unsigned int* getCondimentPrices();
    _state getState();
    unsigned int getCash();
    unsigned int choice(unsigned int, unsigned int*, unsigned int);  // return the overall cost of beverage with all selected condiments
    bool check(unsigned int);
    unsigned int cancel();
    unsigned int cook(unsigned int, string);
    unsigned int finish();
};
#endif //TASK1_AUTOMATA_H
