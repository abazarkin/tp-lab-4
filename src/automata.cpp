//
// Created by Mikhail on 15.12.2019.
//

#include <automata.h>
using std::cout;
using std::endl;
Automata::Automata() {
    state = States::OFF;
    cash = 0;
}
int Automata::getCash() {
    return cash;
}
void Automata::on() {
    if (state == States::OFF) {
        state = States::WAIT;
        cout << "The machine is on";
    } else {
        cout << "Error. The machine is already on";
    }
    cout << endl;
}

void Automata::off() {
    if (state == States::WAIT) {
        state = States::OFF;
        cout << "Machine turned off successfully";
    } else {
        cout << "Error! The machine is doing business";
    }
    cout << endl;
}

void Automata::coin(int coins) {
    if (state == States::WAIT || state == States::ACCEPT) {
        state = States::ACCEPT;
        cash += coins;
        cout << "Money successfully credited";
    } else {
        cout << "Error! The machine is doing business";
    }
    cout << endl;
}

void Automata::printMenu() {
    for (size_t i = 0; i < menu.size(); i++){
        cout << "Drink #" << i + 1 << ' ' << menu[i] << " by price: " << prices[i] << endl;
    }
}

void Automata::printState() {
    cout << stateNames[state] << endl;
}

void Automata::choice(int drinkNum) {
    if (drinkNum > 0 && drinkNum <= menu.size()) {
       if (check(drinkNum)) {
           cook(drinkNum);
           finish();
       } else {
           cout <<  "No money for a drink" << endl;
           cancel();
       }
    } else {
        cout << "There is no such drink :(" << endl;
    }
}

bool Automata::check(int drinkNum) {
    state = States::CHECK;
    return prices[drinkNum - 1] <= cash;
}

void Automata::cancel() {
    if (state != States::OFF) {
        state = States::WAIT;
        cout << "Action canceled";
    } else {
        cout << "Error! The machine is off";
    }
    cout << endl;
}

void Automata::cook(int drinkNum) {
    state = States::COOK;
    cout << "Drink successfully purchased\nWait, the drink is getting ready" << endl;
    for (signed i = 0;i < 10;i++){
        cout << '.' << std::flush;
    }
    cout << "\nThe drink is successfully prepared, take" << endl;
    cash -= prices[drinkNum - 1];
}

void Automata::finish() {
    state = States::WAIT;
}

States Automata::getState() {
    return state;
}





