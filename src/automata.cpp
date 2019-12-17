//
// Created by Sergey Baranenkov on 17.12.2019.
//
#include <automata.h>
#include <chrono>
#include <thread>
std::string Automata::STATE_NAMES[5] = {"OFF","WAIT","ACCEPT","CHECK","COOK"};
Automata::Automata(){
    cash = 0;
    current_operation_cash = 0;
    state = OFF;
}

void Automata::on() {
    if (state == OFF) state = WAIT;
}
void Automata::off(){
    state = OFF;
}
void Automata::coin(unsigned int money){
    if (state == OFF) return;
    if (state != ACCEPT && state != WAIT){
        std::cout << "WAIT FOR OTHER OPERATIONS PLEASE"<<std::endl;
        return;
    }
    state = ACCEPT;
    current_operation_cash += money;
}

void Automata::printMenu() {
    if (state == OFF) return;
    std::cout<<"MENU"<<std::endl;
    for(auto it = menu.begin(); it != menu.end(); ++it){
        std::cout << it->first << ":" << it->second << std::endl;
    }
}

void Automata::printState() {
    if (state == OFF) return;
    std::cout <<"STATE: "<<STATE_NAMES[state]<<std::endl;
}

int Automata::cancel() {
    if (state == OFF) return 0;
    std::cout << "CANCELLING..."<<std::endl;
    int tmp = current_operation_cash;
    current_operation_cash = 0;
    state = WAIT;
    return tmp;
}
bool Automata::check(std::string drink) {
    state = CHECK;
    if (current_operation_cash < menu[drink]) {
        state = ACCEPT;
        return false;
    }
    return true;
}

void Automata::choice(std::string drink) {
    if (state == OFF) return;
    auto it = menu.find(drink);
    if(it == menu.end()) {
        std::cout<<"THERE IS NO SUCH DRINK"<<std::endl;
    }else if (!check(drink)){
        std::cout<<"U NEED TO PAY "<<menu[drink] - current_operation_cash <<" MORE TO BUY THIS DRINK"<<std::endl;
    }else{
        cash += menu[drink];
        current_operation_cash -= menu[drink];
        cook(drink);
    }
}
void Automata::cook(std::string drink){
    state = COOK;
    std::cout << "COOKIN...'" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    std::cout << "GET UR TASTIEST " << drink << std::endl;
    finish();
}
void Automata::finish() {
    state = WAIT;
    std::cout<<"U HAVE "<<current_operation_cash<<" ON THE BALANCE"<<std::endl;
    std::cout<<"PRESS CANCEL IF U WANT TO TAKE MONEY BACK"<<std::endl;
}