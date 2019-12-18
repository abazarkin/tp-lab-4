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
    Beverage* bev = new HouseBlend(10);
    bev = new Sugar(bev, 10);
    bev = new Milk(bev, 15);
    std::cout << "Order: " << bev->getDescription() << std::endl << "Cost: " << bev->getCost() << std::endl;
    bev = new Mocha(bev, 13);
    std::cout << "Order: " << bev->getDescription() << std::endl << "Cost: " << bev->getCost();
    string bev_menu[4] = {"Espresso", "Dark roast", "Hot chocolate", "House blend"};
    string con_menu[3] = {"Milk", "Sugar", "Mocha"};
    int bev_cost[4] = {1, 2, 3, 4};
    int con_cost[3] = {1, 2, 3};
    Automata* aut = new Automata(bev_cost, con_cost, bev_menu, con_menu);
    aut->coin(15);
    int m[2] = {0, 1};
    aut->on();
    aut->coin(40);
    aut->choice(1, m, 2);

    return 0;
}
