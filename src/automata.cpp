//
// Created by Sergey Baranenkov on 17.12.2019.
//
#include <automata.h>
#include <chrono>
#include <thread>
#include <string>
using namespace std;
string Automata::STATE_NAMES[5] = {"OFF","WAIT","ACCEPT","CHECK","COOK"};
Automata::Automata(){
    cash = 0;
    current_operation_cash = 0;
    state = OFF;
}

bool Automata::on() {
    if (state == OFF){
        state = WAIT;
        return true;
    }
    return false;
}
bool Automata::off(){
    if (state == COOK || state==CHECK)return false;
    state = OFF;
    return true;

}
bool Automata::coin(unsigned int money){
    if (state == ACCEPT || state == WAIT){
        state = ACCEPT;
        current_operation_cash += money;
        return true;
    }
    return false;
}

map<string,int> Automata::printMenu() {
    if (state == OFF) return map <string, int>{};
    return menu;
}

string Automata::printState() {
    if (state == OFF) return "";
    return STATE_NAMES[state];
}

unsigned int Automata::cancel() {
    if (state == OFF) return 0;
    cout << "CANCELLING..."<<endl;
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
        return "NO SUCH DRINK";
    }else if (!check(drink)){
        return "U NEED TO PAY " + to_string(menu[drink] - current_operation_cash) + " MORE TO BUY THIS DRINK";
    }else{
        cash += menu[drink];
        current_operation_cash -= menu[drink];
        return cook(drink);
    }
}
string Automata::cook(const string& drink){
    state = COOK;
    this_thread::sleep_for(chrono::milliseconds(3000));
    return finish(drink);
}
string Automata::finish(const string& drink) {
    state = WAIT;
    return drink;
}