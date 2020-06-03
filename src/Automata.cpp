#include "Automata.h"
#include <iostream>

Automata::Automata() {
    menu.push_back(Drink());
    menu[0].name = "Coffe";
    menu[0].price = 100;
    menu.push_back(Drink());
    menu[1].name = "Tea";
    menu[1].price = 80;
    menu.push_back(Drink());
    menu[2].name = "Cocka Cola";
    menu[2].price = 120;
    menu.push_back(Drink());
    menu[3].name = "Milk";
    menu[3].price = 60;
}

void Automata::on() {
    if(state == OFF)
        state = WAIT;
}

void Automata::off() {
    if(state == WAIT)
        state = OFF;
}

void Automata::coin(int newCash) {
    if(state == OFF)
        return;
    state = ACCEPT;
    cash += newCash;
    std::cout << "Current balance: " << cash <<"$" << std::endl;
}

void Automata::printMenu() {
    std::cout << "==============MENU=================\n";
    for(int i = 0; i < menu.size(); i++)
        std::cout << i+1 << ". "<< menu[i].name << " - " << menu[i].price << "$\n";
    std::cout << "===================================\n";
}

void Automata::printState() {
    switch (state) {
        case (OFF):
            std::cout << "The coffee machine is DEAD!\n";
            break;
        case (WAIT):
            std::cout << "Waiting...\n";
            break;
        case (ACCEPT):
            std::cout << "Please give more your money...\n";
            break;
        case (CHECK):
            std::cout << "Checking\n";
            break;
        case (COOK):
            std::cout << "Making a drink\n";
            break;
    }
}

void Automata::cook() {
    cash -= menu[current].price;
    state = COOK;

    std::cout << "The " << menu[current].name << " is cooking\n";
}

bool Automata::check(int choosed) {
    if(cash >= menu[choosed].price)
        return true;
    return false;
}

void Automata::choice(int choosed) {
    choosed--;
    if(state==ACCEPT)
        state = CHECK;
    else{
        std::cout<<"The state of machine is supposed to be ACCEPT\n";
        return;
    }
    if(choosed < 1 || choosed > menu.size()) {
        std::cout << "ERR0R, There are only " << menu.size() << " products\n";
        return;
    }
    if(check(choosed)) {
        current = choosed;
        std::cout << "You choosed " << menu[current].name << ". Poor choice\n";
    }
}

void Automata::cancel() {
    if(state != OFF) {
        if(COOK) {
            cash += menu[current].price;
            current = -1;
        }
        state = WAIT;
        std::cout << "Take your dirty " << cash <<  "$ back!!1\n";
        cash = 0;
    }
    else
        std::cout << "ERRR0R\n";
}

void Automata::finish() {
    if(state == COOK) {
        if(cash != 0)
            std::cout << "Your change: " << cash << std::endl;
        state = WAIT;
        std::cout << "Here is your " << menu[current].name << std::endl;
        current = -1;
    }
}

int Automata::getCash() {
    return cash;
}
