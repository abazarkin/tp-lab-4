//
// Created by Оксана on 12.01.2020.
//
#include <iostream>
#include <Automata.h>
//#include "windows.h"

using namespace std;

Automata::Automata(){
    state = States::OFF;
    cash = 0;
};

void Automata::on() {
    if (state == States::OFF) {
        state = States::WAIT;
        cout << "The machine is on and ready to work\n";
    } else {
        cout << "Incorrect! The machine is already on\n";
    }
    cout << endl;
}


void Automata::off() {
    if (state == States::WAIT) {
        state = States::OFF;
        cout << "Machine is off\n Your change is " << getChange();
    } else {
        cout << "Error! The machine is in the process of working\n";
    }
    cout << endl;
}

void Automata::coin(unsigned int coins) {
    if (state == States::WAIT || state == States::ACCEPT) {
        state = States::ACCEPT;
        cash += coins;
        cout << "Money successfully credited. Your cash balance is "<< cash << "\n";
    } else {
        cout << "Eror! The machine is busy with another thing\n";
    }
    cout << endl;
}

void Automata::printMenu() {
    for (size_t i = 0; i < menu.size(); i++){
        cout << "Drink " << i + 1 << ' ' << menu[i] << " by price: " << prices[i] << "\n";
    }
}

void Automata::printState() {
    cout << "Current state  " << stateNames[state] << "\n";
}

void Automata::choice(unsigned int num_drink) {
    if ((state == States::ACCEPT) || (state == States::WAIT)){
        printMenu();
        if (check(num_drink)){
             cook(num_drink);
             state = States::WAIT;
        }
        else{
            cout << "Not enough cash\n";
            cancel();
        }
    }
    else{
        cout <<"Error! The machine is busy with another thing\n";
    }

}

bool Automata::check(int num_drink) {
    state = States::CHECK;
    return prices[num_drink - 1] <= cash;
}

void Automata::cancel() {
    if (state != States::OFF)
        state = States::WAIT;
    else{
        cout << "Error. Sorry, automat is off\n";
    }
}

void Automata::cook(int num_drink) {
    state = States::COOK;
    cout << "Wait, the drink is getting ready\n" << endl;
    for (int i = 0; i < 10; i++){
        cout << '.';
        //Sleep(500);
    }

    cout << "\nThe drink is successfully prepared, please, take\n" << endl;
    cash -= prices[num_drink - 1];
    finish();
}

void Automata::finish() {
    if (state == States::COOK){
        state = States::WAIT;
    }
}

unsigned int Automata::getChange() {

    cout << "Your change is " << cash << "\n";
    unsigned int change = cash;
    cash = 0;
    return change;
}
States Automata::getState() {
    return state;
}




