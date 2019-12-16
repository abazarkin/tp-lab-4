#ifndef AUTOMATA_H
#define AUTOMATA_H

#include <iostream>

class Automata {
private:
    //enum menu {};
    /*enum prices {Cappuccino = 35, 
                American = 30, 
                Black_coffee = 20,
                Latte = 35,
                Espresso = 30,
                Hot_chocolate = 25}; */
    //enum states {OFF = 0, WAIT, ACCEPT, CHECK, COOK};
    int cash;
    int state;
    int ans;

public:
    Automata();
    ~Automata();
    bool on();
    bool off();
    bool coins();
    bool printMenu();
    void printState();
    bool choice();
    bool check();
    bool cansel();
    bool cook();
    bool finish();

    void processing();
};



#endif // AUTOMATA_H