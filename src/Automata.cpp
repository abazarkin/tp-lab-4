#include "Automata.h"
#include <string>
#include <vector>
#include <unistd.h>

static enum states {OFF = 0, WAIT, ACCEPT, CHECK, COOK} x;
static std::string Nstates[] = {"OFF", "WAIT", "ACCEPT", "CHECK", "COOK"};
static std::vector<unsigned int> prices = {35, 30, 20, 35, 30, 25};
static std::vector<std::string> menu = {"Cappuccino", "American", "Black_coffee", "Latte", "Espresso", "Hot_chocolate"};

Automata::Automata() {
    cash = 0;
    state = OFF;
    ans = -1;
    std::cout << "Automat was created" << std::endl;
}

Automata::~Automata() {
}

bool Automata::on() {
    if (state != OFF){
        return false;
    }
    state = WAIT;
    return true;    
}

bool Automata::off() {
    if (state == OFF) {
        return false;
    }
    state = OFF;
    return true;
}

bool Automata::coin(unsigned int coins){
    if (state == WAIT || state == ACCEPT) {
        cash += abs(coins);
        if (state == WAIT) {
            state = ACCEPT;
        }
        return true;
    }
    else {
        return false; 
    }
}

bool Automata::printMenu() {
    if (state == OFF){
        return false;
    }
    for (int i = 0; i < menu.size(); i++)
        std::cout << i << " " << menu[i] << " - " << prices[i] << std::endl;
    return true;
}

std::string Automata::printState() const {
    std::cout << "State = " << Nstates[state] << std::endl;
    return Nstates[state];
}
 
bool Automata::choice(int local_ans) {
    if (state == ACCEPT){ 
        ans = local_ans;
        state = CHECK;
        return true;
    }
    else {
        return false; 
    }
}

bool Automata::check() {
    if (state == CHECK) {
        if (cash >= prices[ans])
            return true;
        else {
            return false;    
        }
    }
    else {
        return false; 
    }
}


bool Automata::cancel() {
    if (state == ACCEPT || state == CHECK) {
        state = WAIT;
        ans = -1;
        return true;
    }
    else {
        return false;
    }
}

bool Automata::cook() {
    if (state == CHECK && cash-prices[ans] >= 0) {
        state = COOK;
        cash -= prices[ans];
        return true; 
    }
    else {
        return false; 
    }
}

bool Automata::finish() {
    if (state == COOK){
        std::cout << "Return your " << cash << " coins" << std::endl;
        cash = 0;
        ans = -1;
        state = WAIT;
        return true;
    }
    return false;
}

void Automata::printInform() const {
    std::cout << "__state = " << Nstates[state] << std::endl;
    std::cout << "__coins = " << cash << std::endl;
    std::cout << "__ansver= " << ans << std::endl;
    std::cout << std::endl;
}

void Automata::processing(){
    for (int i = 0; i < 10; i++){
        std::cout << "#";
        usleep(1000000);;
    }
    std::cout << std::endl;
}
