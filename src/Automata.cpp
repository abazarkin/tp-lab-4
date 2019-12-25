#include <iostream>
#include "Automata.h"

Automata::Automata() {
    cash = 0;
    state = OFF;
}

void Automata::on() {
    if (state == OFF) {
        state = WAIT;
        std::cout << "The automata turns on\n";
    }
    else {
       std::cout << "The automata is already on\n";
    }
}

void Automata::off() {
    if (state == WAIT) {
        state = OFF;
        std::cout << "The automata turns off\n";
    }
    else {
       std::cout << "The automata cannot be turned off now\n";
    }
}

void Automata::coin(int coins) {
    if (state == WAIT || state == ACCEPT) {
        state = ACCEPT;
        cash += coins;
        std::cout << "The money was successfully laid\n";
    }
    else {
       std::cout << "You can't put money now\n";
    }
}

void Automata::printMenu() {
    for (int i = 0; i < 4; i++) {
       std::cout << i << ": " << menu[i] << " - " << prices[i] << "\n";
    }
    std::cout << "You have " << cash << " coins\n";
}

void Automata::printState() {
    std::cout << "State: " << getState() << "\n";
}

void Automata::choice(int number) {
    if (number >= 0 && number < numberOfItems && state == ACCEPT) {
        state = CHECK;
        check(number);
    } else {
        std::cout << "Purchase is not possible\n";
    }
}

void Automata::check(int number) {
    if (state == CHECK ) {
        if (prices[number] <= cash) {
            std::cout << "You are bought " << menu[number] << "\n";
            cash -= prices[number];
            cook();
        } else {
            std::cout << "You don't have enough money for " << menu[number] << "\n";
        }
    }
    else {
       std::cout << "Purchase is not possible\n";
    }
}

void Automata::cancel() {
    if (state == CHECK || state == ACCEPT) {
        state = WAIT;
        std::cout << "Your change: " << cash << "\n";
        cash = 0;
    }
    else {
       std::cout << "You can't get change now\n";
    }
}
void Automata::cook() {
    state = COOK;
    std::cout << "The drink is being prepared...\n";
    finish();
}

void Automata::finish() {
    std::cout << "The drink is ready!\n";
    state = ACCEPT;
}

std::string Automata::getState() {
    switch (state) {
        case OFF:
            return "OFF";
        case WAIT:
            return "WAIT";
        case ACCEPT:
            return "ACCEPT";
        case CHECK:
            return "CHECK";
        case COOK:
            return "COOK";
        default:
            return "We have a problem";
    }
}
