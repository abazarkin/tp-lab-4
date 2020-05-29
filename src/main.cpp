//
// Created by Илья on 011 11.12.19.
//
#include <iostream>
#include <Automata.h>
// Beverages
#include "HouseBlend.h"
#include "Espresso.h"
#include "HotChocolate.h"
#include "DarkRoast.h"
// Condiments
#include "Milk.h"
#include "Mocha.h"
#include "Sugar.h"
#include <string>

int main(){
    string bev_menu[4] = {"Espresso", "Dark roast", "Hot chocolate", "House blend"};
    string con_menu[3] = {"Milk", "Sugar", "Mocha"};
    unsigned int bev_cost[4] = {1, 2, 3, 4};
    unsigned int con_cost[3] = {1, 2, 3};
    Automata* aut = new Automata(bev_cost, con_cost, bev_menu, con_menu);
    aut->on();
    aut->coin(3);
    unsigned int* cond = nullptr;
    std::cout << aut->choice(1, cond, 0);

    return 0;
}
