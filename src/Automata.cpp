//
// Created by Anton Korkunov on 09/02/2020.
//


#include "Automata.h"
#include <stdio.h>
#include <string>
#include <iostream>
//#include "windows.h"


using namespace std;

// 0 - off | 1 - wait | 2 - accept | 3 - check | 4 - cook //
Automata::Automata() {
    cash = 0;
    state = WAIT;
}

void Automata::on() {
    if (state == WAIT) {
        std::cout << "\n" << "Machine is already ON";
        return;
    }
    state = WAIT;
    printState();
}

void Automata::off() {
    std::cout << "\n" << "Have a nice day!";
    state = OFF;
    printState();
    //exit(1);
}

int Automata::coin(int _cash) {
    state = ACCEPT;
    if (_cash < 0) {
        std::cout << "\n" << "Incorrect number!";
        return -1;
    }
    printState();
    if (_cash == 0) {
        cancel();
    }
    this->cash += _cash;
    return this->cash;
}

void Automata::printMenu() {
    if (state != OFF) {
        std::cout << "Drink" << "|   |" << "Price";
        for (int i = 0; i < 6; i++) {
            std::cout << "\n" << i + 1 << ".|" << this->menu[i] << " |" << " - " << "| " << this->prices[i] << " |";
        }
    }
}

int Automata::printState() {
    if (state == OFF) {
        std::cout << "\n" << "OFF" << "\n";
    }

    if (state == WAIT) {
        std::cout << "\n" << "WAIT" << "\n";
    }

    if (state == ACCEPT) {
        std::cout << "\n" << "ACCEPT" << "\n";
    }

    if (state == CHECK) {
        std::cout << "\n" << "CHECK" << "\n";
    }

    if (state == COOK) {
        std::cout << "\n" << "COOK" << "\n";
    }
    return(state);
}

void Automata::choice() {
    int choice;
    int _cash;
    if (state == OFF) {
        std::cout << "\n" << "The Machine is OFF";
        return;
    }
    state = WAIT;
    printState();
    printMenu();
    std::cout << "\n" << "Please, choose the number of drink you want ";
    std::cin >> choice;
    choice -= 1;
    if ((choice > 5) or (choice < 0)) {
        std::cout << "\n" << "You have inserted incorrect number";
        return;
    }
    std::cout << "\n" << "Now insert cash or cancel by pressing 0: ";
    std::cin >> _cash;
    coin(_cash);
    while (!(check(choice))) {
        std::cout << "\n" << "Please, Add money or cancel by pressing 0: ";
        std::cin >> _cash;
        coin(_cash);
    }
    //if (check(choice)) {
    cook();
    state = WAIT;
    finish();
    //}
} //- âûáîð íàïèòêà ïîëüçîâàòåëåì;

bool Automata::check(int _i) {
    state = CHECK;
    printState();
    if (prices[_i] > cash) {
        std::cout << "\n" << "Not enough money";
        return false;
    }
    else {
        cash -= prices[_i];
        return true;
    }
}

int Automata::cancel() {
    std::cout << "\n" << "Take your money - " << cash;
    return cash;
    //off();
}

void Automata::cook() {
    state = COOK;
    printState();
    std::cout << "\n" << "Your drink is preparing now";
    std::cout << "\n" << ".";
    std::cout << "\n" << "..";
    std::cout << "\n" << "...";
    std::cout << "\n" << "Your drink is ready";
}

void Automata::finish() {
    std::cout << "\n" << "Take your money - " << cash;
    off();
}
