#include <iostream>
#include "Automata.h"
bool Automata::isOn(){
    return state == STATES::OFF;
}

Automata::Automata(const std::vector<Drink>& _menu) {
    menu = _menu;
}

void Automata::on() {
    state = STATES::WAIT;
    printState();
}

void Automata::off() {
    state = STATES::OFF;
    printState();
}

unsigned int Automata::coin(unsigned int coins) {
    if(isOn())
        return 0;
    state = STATES::ACCEPT;
    cash += coins;
    printState();
    return cash;
}

void Automata::printMenu() {
    if(isOn())
        return;
    size_t sizeOfMenu = menu.size();
    for(size_t i = 0; i < sizeOfMenu; i++)
        std::cout << i + 1 << ": " <<  menu[i].name << " - " << menu[i].price << std::endl;
    printState();
}

void Automata::printState() {
    std::cout << "State: " << string_STATES[state] << std::endl;
    std::cout << "Current cash: " << cash << std::endl;
}

bool Automata::choice(unsigned int drink) {
    if(isOn())
        return 0;
    state = STATES::CHECK;
    if(check(drink)) {
        cook();
        printState();
        finish();
        printState();
        return true;
    }
    else
    {
        state = STATES::NOT_ENOUGH_MONEY;
        printState();
        state = STATES::ACCEPT;
        printState();
        return false;
    }
}

bool Automata::check(unsigned int drink) {
    if(isOn())
        return 0;
    return menu[drink - 1].price <= cash;
}

unsigned int Automata::cancel() {
    if(isOn())
        return 0;
    state = STATES::WAIT;
    unsigned int cashToReturn = cash;
    cash = 0;
    printState();
    return cashToReturn;
}

void Automata::cook() {
    if(isOn())
        return;
    cash = 0;
    state = STATES::COOK;
}

void Automata::finish() {
    if(isOn())
        return;
    state = STATES::FINISH;
    printState();
    state = STATES::WAIT;
}




