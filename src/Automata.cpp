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
    if (state == WAIT){
        std::cout << "Automat is already on!" << std::endl;
        return false;
    }
    state = WAIT;
    std::cout << "Automat is switched on!" << std::endl;
    return true;    
}

bool Automata::off() {
    if (state == OFF) {
        std::cout << "Automat is already off!" << std::endl;
        return false;
    }
    state = OFF;
    std::cout << "Automat is switched off!" << std::endl;
    return true;
}

bool Automata::coin(unsigned int coins){
    if (state == OFF) {
        std::cout << "Automat is already off!" << std::endl;
        return false;
    }
    else if (state == WAIT || state == ACCEPT) {
        //unsigned int coins;
        //std::cout << "Enter coins: ";
        //std::cin >> coins;
        cash += abs(coins);
        state = ACCEPT;
        return true;
    }
    else {
        std::cout << "ERROR!" << std::endl;
        return false; 
    }
}

bool Automata::printMenu() {
    if (state == OFF){
        std::cout << "Automat is already off!" << std::endl;
        return false;
    }
    for (int i = 0; i < menu.size(); i++)
        std::cout << i << " " << menu[i] << " - " << prices[i] << std::endl;
    return true;
}

void Automata::printState() const {
    std::cout << "State = " << Nstates[state] << std::endl;
}
 
bool Automata::choice(int local_ans) {
    if (state == OFF){
        std::cout << "Automat is already off!" << std::endl;
        return false;
    }
    else if (state == ACCEPT){
    //int local_ans;
        while (true)
        {
            //std::cout << "Select a drink or press 9 to display the menu again: ";
            //std::cin >> local_ans; 
            if(local_ans > -1 && local_ans < 7)
                break;
            else if (local_ans == 9)
                printMenu();
            else 
                std::cout << "Incorrect answer, try again, pls..." << std::endl;    
        }
        ans = local_ans;
        state = CHECK;
        return true;
    }
    else {
        std::cout << "ERROR!" << std::endl;
        return false; 
    }
}

bool Automata::check() {
    if (state == OFF){
        std::cout << "Automat is already off!" << std::endl;
        return false;
    }
    else if (state == CHECK) {
        if (cash >= prices[ans])
            
            return true;
        else {
            std::cout << "You have not enough money" << std::endl;
            return false;    
        }
    }
    else {
        std::cout << "ERROR!" << std::endl;
        return false; 
    }
}


bool Automata::cansel() {
    if (state == OFF){
        std::cout << "Automat is already off!" << std::endl;
        return false;
    }
    else if (state == WAIT) {
        std::cout << "ERROR!" << std::endl;
        return false;
    }
    state = WAIT;
    ans = -1;
    return true;
}

bool Automata::cook() {
    if (state == OFF){
        std::cout << "Automat is already off!" << std::endl;
        return false;
    }
    else if (state == CHECK) {
        state = COOK;
        processing();
        cash -= prices[ans];
        return true; 
    }
    else {
        std::cout << "ERROR!" << std::endl;
        return false; 
    }
}

bool Automata::finish() {
    if (state == OFF){
        std::cout << "Automat is already off!" << std::endl;
        return false;
    }
    std::cout << "Return your " << cash << " coins" << std::endl;
    cash = 0;
    ans = -1;
    return true;
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