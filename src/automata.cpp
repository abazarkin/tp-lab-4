#include "automata.h"
#include <string>

using namespace std;

string Automata::STATE_NAMES[5] = {"OFF","WAIT","ACCEPT","CHECK","COOK"};


Automata::Automata(){
    cash = 0;
    current_operation_cash = 0;
    state = OFF;
}

void Automata::on() {
    if (state == OFF){
        state = WAIT;
    }
}

void Automata::off(){
    state = OFF;
}

void Automata::coin(unsigned int money){
    if (state == ACCEPT || state == WAIT){
        state = ACCEPT;
        current_operation_cash += money;
    }
}

map<string, int> Automata::printMenu() {
    return menu;
}

string Automata::printState() {
    return STATE_NAMES[state];
}

unsigned int Automata::cancel() {
    if (state == OFF) return 0;
    cout << "cancel" <<endl;
    unsigned int tmp = current_operation_cash;
    current_operation_cash = 0;
    state = WAIT;
    return tmp;
}

bool Automata::check(const string& drink) {
    state = CHECK;
    if (current_operation_cash < menu[drink]) {
        state = ACCEPT;
        return false;
    }
    return true;
}

string Automata::choice(const string& drink) {
    if (state == OFF) return "";
    auto it = menu.find(drink);
    if(it == menu.end()) {
        string ret_str;
		ret_str += "no juice named ";
		ret_str += drink;
		return ret_str;
    }
	else if (!check(drink)){
        return "need " + to_string(menu[drink] - current_operation_cash) + " $ more";
    }
	else{
        cash += menu[drink];
        current_operation_cash -= menu[drink];
        return cook(drink);
    }
}

string Automata::cook(const string& drink){
    state = COOK;
    finish();
    return drink;
}

void Automata::finish() {
    state = WAIT;
}