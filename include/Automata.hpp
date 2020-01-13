//
//  Automata.hpp
//  Shtanyuk4
//
//  Created by Коля on 12/01/2020.
//  Copyright © 2020 Коля. All rights reserved.
//

#ifndef Automata_hpp
#define Automata_hpp

#include <stdio.h>
#include <vector>
#include <string>

enum States {OFF, WAIT, ACCEPT, CHECK, COOK};

class Automata {
private:
    unsigned int cash;
    std::vector <std::string> menu = {"Latte", "Cappuccino", "Espresso", "Water", "Tea", "Purple drank"};
    std::vector <unsigned int> prices = {10, 15, 13, 8, 9, 228};
    States state;
    int current_choice;
    std::vector <std::string> StatesNames {"OFF", "WAIT", "ACCEPT", "CHECK", "COOK"};
public:
    Automata();
    States on();
    States off();
    States coin(unsigned int);
    std::string printMenu();
    std::string printState();
    void choice(unsigned int);
    bool check();
    States cancel();
    bool cook();
    States finish();
};


#endif /* Automata_hpp */
