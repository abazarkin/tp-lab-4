//
// Created by Илья on 011 11.12.19.
//
#include <iostream>
#include "Automata.h"
#include "HouseBlend.h"
#include "DarkRoast.h"
#include "Espresso.h"
#include "HotChocolate.h"
#include "Mocha.h"
#include "Sugar.h"
#include "Milk.h"
using std::cin;
using std::cout;
using std::endl;

Automata::Automata(int* beverage_prices, int* condiment_prices, string* beverage_menu, string* condiment_menu){
    cash = 0;
    this->beverage_prices = beverage_prices;
    this->condiment_prices = condiment_prices;
    this->beverage_menu = beverage_menu;
    this->condiment_menu = condiment_menu;
    state = OFF;
}
void Automata::on(){
    state = WAIT;
}

void Automata::off(){
    cancel();
    state = OFF;
}

void Automata::coin(int money){
    if (state == WAIT || state == ACCEPT || state == CHECK){
        cash += money;
        state = ACCEPT;
    }
}

string* Automata::getBeverageMenu(){
    return beverage_menu;
}

string* Automata::getCondimentMenu(){
    return condiment_menu;
}

int* Automata::getBeveragePrices(){
    return beverage_prices;
}

int* Automata::getCondimentPrices(){
    return condiment_prices;
}

_state Automata::getState(){
    return state;
}

void Automata::choice(int main_index, int* condiment_indexes, int n){
    Beverage* bev;

    // choice of beverages
    if (beverage_menu[main_index] == "Espresso"){
        bev = new Espresso(beverage_prices[main_index]);
    }
    else if (beverage_menu[main_index] == "Dark roast"){
        bev = new DarkRoast(beverage_prices[main_index]);
    }
    else if (beverage_menu[main_index] == "Hot chocolate"){
        bev = new HotChocolate(beverage_prices[main_index]);
    }
    else if (beverage_menu[main_index] == "House blend"){
        bev = new HotChocolate(beverage_prices[main_index]);
    }

    // choice of condiments
    for(int i = 0; i < n; i++){
        if (condiment_menu[condiment_indexes[i]] == "Milk"){
            bev = new Milk(bev, beverage_prices[condiment_indexes[i]]);
        }
        else if (condiment_menu[main_index] == "Sugar"){
            bev = new Sugar(bev, beverage_prices[condiment_indexes[i]]);
        }
        else if (condiment_menu[main_index] == "Mocha"){
            bev = new Mocha(bev, beverage_prices[condiment_indexes[i]]);
        }
    }
    if (check(bev->getCost())){
        cook(bev->getCost(), bev->getDescription());
    }
    else{
        cancel();
    }
}

bool Automata::check(unsigned int needed){
    if (cash >= needed){
        state = COOK;
        return true;
    }
    else
        state = WAIT;
    return false;
}

void Automata::cancel(){
    cash = 0;
    state = WAIT;
}

void Automata::cook(unsigned int price, string description){
    state = COOK;
    cout << endl << "Your beverage: " << description << endl << "Cost: " << price << endl;
    cash -= price;
    finish();
}
void Automata::finish(){
    state = WAIT;
}


