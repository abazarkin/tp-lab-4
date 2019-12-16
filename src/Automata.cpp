#include "Automata.h"
#include <string>
#include <vector>
#include <unistd.h>

static enum states {OFF = 0, WAIT, ACCEPT, CHECK, COOK} x;
static std::string Nstates[] = {"OFF", "WAIT", "ACCEPT", "CHECK", "COOK"};
static std::vector<int> prices = {35, 30, 20, 35, 30, 25};
static std::vector<std::string> menu = {"Cappuccino", "American", "Black_coffee", "Latte", "Espresso", "Hot_chocolate"};

/*static enum prices {Cappuccino = 35, 
                    American = 30, 
                    Black_coffee = 20,
                    Latte = 35,
                    Espresso = 30,
                    Hot_chocolate = 25} x; */
//static std::string menu[] = {"Cappuccino", "American", "Black_coffee", "Latte", "Espresso", "Hot_chocolate"};


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

bool Automata::coins(){
    if (state == OFF) {
        std::cout << "Automat is already off!" << std::endl;
        return false;
    }
    else if (state == WAIT || state == ACCEPT) {
        int coins;
        std::cout << "Enter coins: ";
        std::cin >> coins;
        cash += coins;
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

void Automata::printState() {
    std::cout << "State = " << Nstates[state] << std::endl;
}
 
bool Automata::choice() {
    if (state == OFF){
        std::cout << "Automat is already off!" << std::endl;
        return false;
    }
    else if (state == ACCEPT){
    int local_ans;
        while (true)
        {
            std::cout << "Select a drink or press 9 to display the menu again: ";
            std::cin >> local_ans; 
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
        else 
            return false;    
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
    return true;
}

bool Automata::cook() {
    if (state == OFF){
        std::cout << "Automat is already off!" << std::endl;
        return false;
    }
    else if (state == CHECK) {
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
    return true;
}

void Automata::processing(){
    for (int i = 0; i < 10; i++){
        std::cout << "#";
        usleep(1000000);;
    }
}