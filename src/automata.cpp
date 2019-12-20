#include "automata.h"
#include <iostream>
#include <string>

using namespace std;
string Automata::menu[10] = {"Cappucino", "Latte", "Espresso Single", "Espresso Double", "Mocha", "Soda", "Green Tea",
                             "Black Tea",
                             "Water", "Cocoa"};
double Automata::prices[10] = {20.5, 14, 23, 26.5, 19.5, 10.5, 10, 10, 5, 14.5};

Automata::Automata() {
    cash = 0;
    state = OFF;
}

void Automata::on() {
    if (state == OFF) {
        state = WAIT;
        cout << "The coffee machine is ready for use!" << endl;
    } else cout << "Error: The coffee machine is already ON!" << endl;
}

void Automata::off() {
    if (state != OFF) {
        state = OFF;
        cout << "The coffee machine is OFF!" << endl;
    } else cout << "Error: The coffee machine is already OFF!" << endl;
}

void Automata::coin(double money) {
    if (state == WAIT || state == ACCEPT) {
        state = ACCEPT;
        cash += money;
        cout << "Your balance: " << cash << endl;
    } else cout << "Error..." << endl;
}

void Automata::printMenu() {
    cout << "Number \tdrink\tcost" << endl;
    for (int i = 0; i < 10; i++) {
        cout << i + 1 << ") " << menu[i] << "\t" << prices[i] << endl;
    }
}

void Automata::printState() {
    switch (state) {
        case (OFF):
            cout << "The coffee machine is turned OFF!"<<endl;
            break;
        case (WAIT):
            cout << "Waiting..."<<endl;
            break;
        case (ACCEPT):
            cout << "Please make payment..."<<endl;
            break;
        case (CHECK):
            cout << "Check if the selected beverage is available..."<<endl;
            break;
        case (COOK):
            cout << "Making a drink"<<endl;
            break;
    }
}

void Automata::choice(int typeOfDrink) {
    if (typeOfDrink > 0 && typeOfDrink < 11) {
        typeOfDrink--;
        state = CHECK;
        if (check(typeOfDrink)) {
            cook(typeOfDrink);
        } else cout << "Insufficient funds..." << endl;

    } else cout << "Invalid input!" << endl;
}

bool Automata::check(int typeOfDrink) {
    if (cash >= prices[typeOfDrink]) {
        return true;
    } else return false;
}

void Automata::cancel() {
    if (state != OFF) {
        state = WAIT;
        cout << "Waiting..." << endl;
    } else {
        cout << "Error: the coffee machine is OFF" << endl;
    }
}

void Automata::cook(int typeOfDrink) {
    if (state == CHECK) {
        state = COOK;
        cash = cash - prices[typeOfDrink];
        cout << "Your change: " << cash << endl;
        cout << "Your drink get ready..." << endl;
    } else cout << "Error!" << endl;
}

void Automata::finish() {
    if (state == COOK) {
        if (cash != 0) {
            cout << "Your change: " << cash << endl;
        }
        state = WAIT;
        cout << "Waiting..." << endl;
    } else cout << "Error!" << endl;
}

double Automata::getCash(){
    return cash;
}
STATES Automata::getState() {
    return state;
}