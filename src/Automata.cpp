//
// Created by Илья Соловьёв on 02.12.2019.
//

#include "Automata.h"
#include <unistd.h>

/*
   * 0 - turned off
   * 1 - wait
   * 2 - accept
   * 3 - check
   * 4 - cook
   */


Automata::Automata(vector<string> menu, vector<int> prices) {
    this->cash = 0;
    for (int i = 0; i < menu.size(); i++) {
        this->menu.push_back(menu[i]);
        this->prices.push_back(prices[i]);
    }
    this->state = OFF;
    this->total = 0;
};


void Automata::printMenu() {
    cout << "\tMENU" << endl;
    for (int i = 0; i < menu.size(); i++) {
        cout << " " << i + 1 << " " << menu[i] << " " << prices[i] << endl;
    }
}


void Automata::on() {
    if (state != OFF) {
        cout << "Already ON" << endl;
    }
    state = WAIT;
}


void Automata::coin(int cash) {
    if (state == WAIT || state == ACCEPT) {
        {
            this->cash += cash;
            state = ACCEPT;
        }
    } else {
        cout << "Wrong state" << endl;
    }
}


bool Automata::choice(int number) {
    if (state == ACCEPT) {
        if (number < menu.size() && number >= 0) {
            state = CHECK;
            return true;
        } else {
            cout << "Wrong choice" << endl;
        }
    } else {
        cout << "Wrong state" << endl;
    }
    return false;
};


bool Automata::check(int choice) {
    if (state == CHECK) {
        if (prices[choice] > cash) {
            return false;
        } else {
            state = COOK;
            return true;
        }
    } else {
        cout << "Wrong state" << endl;
    }
}


void Automata::cook(int choice) {
    cout << menu[choice] << " is cooking. Wait some time." << endl;
    sleep(5);
    cout << "Almost done" << endl;
    sleep(3);
    cout << "Take your drink. Be careful - it\'s HOT!" << endl;
}


int Automata::finish(int choice) {
    if (state == COOK) {
        int cashTMP = cash - prices[choice];
        total += prices[choice];
        cash = 0;
        state = WAIT;
        return cashTMP;
    } else {
        cout << "Wrong state" << endl;
    }
}


int Automata::cancel() {
    if (state == ACCEPT || state == CHECK) {
        int cashTmp = cash;
        cash = 0;
        state = WAIT;
        return cashTmp;
    } else {
        cout << "Wrong state" << endl;
        return 0;
    }
}


void Automata::off() {
    state = OFF;
}

STATES Automata::printState() {
    return state;
}

int Automata::getCash() {
    return this->cash;
}







