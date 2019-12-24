#include <iostream>
#include "Automata.h"

Automata::Automata() {
    this->state = OFF;
    this->cash = 0;
}

void Automata::on() {
    if (this->state == OFF) {
        std::cout << "Включаюсь\n";
        this->state = WAIT;
    }
}

void Automata::off() {
    if (this->state == WAIT) {
        std::cout << "Выключаюсь\n";
        this->state = OFF;
    }
}

void Automata::coin(int coin) {
    if (this->state == WAIT || this->state == ACCEPT) {
        this->state = ACCEPT;
        this->cash += coin;
    }
}

void Automata::printMenu() {
    if (!(this->state == OFF)) {
        for (int i = 0; i < nMenuItems; i++) {
            std::cout << "id " << i << " Название: " << this->menu[i] << "\tЦена: " << this->prices[i] << std::endl;
        }
        std::cout << "У вас " << this->cash <<"\n";
    }
}

void Automata::printState() {
    std::cout << this->state << "\n";
}

void Automata::choice(int id) {
    if (id >= 0 && id < nMenuItems && this->state == ACCEPT) {
        check(id);
    }
}

void Automata::check(int id) {

    if (this->prices[id] <= cash) {
        std::cout << "Вы купили " << this->menu[id] << "\n";
        this->cash -= this->prices[id];
        cook();
    } else {
        std::cout << this->menu[id] << " стоит дороже" << "\n";
    }
}

void Automata::cancel() {
    if (this->state == ACCEPT) {
        std::cout << "Прием денег завершен, ваша сдача: " << this->cash << "\n";
        this->cash = 0;
        this->state = WAIT;
    }
}

void Automata::cook() {
    this->state = COOK;
    std::cout << "Идет приготовление напитка\n";
    finish();
}

void Automata::finish() {
    std::cout << "Напиток подан\n";
    this->state = ACCEPT;
}

STATES Automata::getState() {
    return this->state;
}
