//
//  Automata.hpp
//  lab4
//
//  Created by Андрей Журавлев on 11.12.2019.
//  Copyright © 2019 Андрей Журавлев. All rights reserved.
//

#ifndef Automata_hpp
#define Automata_hpp
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <unistd.h>
#include <map>
//#include <pair>
//#include <curses.h>

enum States {OFF, WAIT, ACCEPT, CHECK, COOK};

struct Position {
    std::string name;
    unsigned int price;
};

class Automata {
private:
    unsigned long cash = 0;
    std::map<int, Position> menu;
    States state = OFF;
    unsigned int curr_choice = 0;
    
public:
    Automata();
    Automata(std::string);
    ~Automata();
    States on();
    States off();
    std::pair<std::string, States> print_menu();
    std::string print_state();
    States get_state();
    States coin(unsigned int);
    unsigned int choice();
    unsigned int choice(unsigned int);
    bool check();
    States cancel();
    std::pair<int, bool> cook();
    void finish();
    
};
#endif /* Automata_hpp */
