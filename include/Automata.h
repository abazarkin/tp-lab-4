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
    int* beverage_prices;
    int* condiment_prices;
    _state state;
public:
    Automata(int*, int*, string*, string*);
    void on();
    void off();
    void coin(int);
    string* getBeverageMenu();
    string* getCondimentMenu();
    int* getBeveragePrices();
    int* getCondimentPrices();
    _state getState();
    void choice(int main_index, int* condiment_indexes, int n);  // return the overall cost of beverage with all selected condiments
    bool check(unsigned int);
    void cancel();
    void cook(unsigned int, string);
    void finish();
};
#endif //TASK1_AUTOMATA_H
