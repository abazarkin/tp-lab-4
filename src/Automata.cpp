//
//  Automata.cpp
//  lab4
//
//  Created by Андрей Журавлев on 11.12.2019.
//  Copyright © 2019 Андрей Журавлев. All rights reserved.
//

#include "Automata.hpp"


Automata::Automata() {
    menu = {
        {1, {"Water", 10}},
        {2, {"Soda", 15}},
        {3, {"Green tea", 15}},
        {4, {"Black tea", 15}},
        {5, {"Espresso", 30}},
        {6, {"Latte", 45}},
        {7, {"Cappuccino", 50}},
        {8, {"Double espresso", 60}},
        {9, {"Double latte", 75}},
        {10, {"Mocaccino", 100}}};
}

Automata::~Automata() {
    menu.clear();
}

Automata::Automata(std::string file_name) {
    std::fstream file(file_name);
    if(!file.is_open()) return;
    int i = 1;
    while (!file.eof()) {
        std::string temp_str;
        int temp_int;
        file >> temp_str >> temp_int;
        Position temp;
        temp.name = temp_str;
        temp.price = temp_int;
        menu.insert(std::pair<int, Position>(i, temp));
        i++;
    }
}

States Automata::on() {
    if (state != OFF) return state;
    state = WAIT;
    return state;
}

States Automata::off() {
    if (state != WAIT) return state;
    state = OFF;
    return state;
}

std::string Automata::print_state() {
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
            return "STATE OUT OF RANGE";
    }
}

States Automata::get_state() {
    return state;
}

std::pair<std::string, States> Automata::print_menu() {
    if (state == OFF) return std::pair<std::string, States>("", OFF);
    std::string str = "";
    for (auto par : menu) {
        str += std::to_string(par.first) + ": " + par.second.name + " " + std::to_string(par.second.price) + " R" + "\n";
    }
    return std::pair<std::string, States>(str, state);
}

States Automata::coin(unsigned int value) {
    if (value == 0 || state == OFF || state == COOK) {
        state = WAIT;
        return WAIT;
    }
    state = ACCEPT;
    cash += value;
    return state;
}

unsigned int Automata::choice() {
    unsigned int choice_index;
    std::cin >> choice_index;
    while (choice_index >= 1 && choice_index <= menu.size()) {
        std::cout << "Wrong index" << std::endl;
        std::cout << "Please choose from 1 to " << menu.size() << std::endl;
        std::cin >> choice_index;
    }
    curr_choice = choice_index;
    return choice_index;
}

unsigned int Automata::choice(unsigned int ind) {
    if (ind < 1  || ind > menu.size()) return 0;
    curr_choice = ind;
    return ind;
}

bool Automata::check() {
    if (state != ACCEPT) return false;
    if (cash < menu[curr_choice].price) return false;
    state = CHECK;
    return true;
}

States Automata::cancel() {
    if (state != CHECK || state != ACCEPT) return state;
    state = WAIT;
    curr_choice = 0;
    return state;
}

std::pair<int, bool> Automata::cook() {
    if (curr_choice == 0 || !check()) {
        return std::pair<int, bool>(cash, false);
    }
    state = COOK;
    cash -= menu[curr_choice].price;
    return std::pair<int, bool>(cash, true);
}

void Automata::finish() {
    if (state != COOK) return;
    state = WAIT;
}
