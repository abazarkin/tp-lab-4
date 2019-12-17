//
// Created by Mary on 25.11.2019.
//
#include "../include/Automata.h"
#include <iostream>
using namespace std;
string Automata::menu[9]= {"Black Tea", "Green Tea", "Latte", "Hot chocolate", "Water",
                                     "Espresso", "Cappuccino", "Macchiato", "Cocoa"};
int Automata::prices[9]  = {30, 30, 45, 40, 20, 35, 45, 45, 35};
Automata::Automata() {
    this->setCash(0);
    this->setState(STATES :: OFF);
}
void Automata::on() {
    if (this->getState() == (STATES::OFF)) {
        this->setState(STATES::WAIT);
        cout << "Automat is on and ready to work\n";
    }
    else{
        cout << "Incorrect. Automat has already on\n";
    }
}

void Automata::printMenu() {
    for (int i = 0; i <9; i ++){
        cout << i + 1<<" : "<< Automata::menu[i] << " - " <<Automata:: prices[i] << endl;
    }
}
void Automata ::coin() {
    if (this->getState() == STATES ::WAIT || this->getState() == STATES ::ACCEPT) {
        cout << "If you wat to enter the money - print 1\nGo to choice of drinks - print 0\n" << endl;
        int choice;
        cin >> choice;
        this->setState(STATES::ACCEPT);
        while (choice != 0) {
            int money;
            cin >> money;
            this->setCash(this->getCash()+  money);
            cout << "You entered " << this->getCash()<< endl;
            cout << "If you wat to enter the money - print 1\nGo to choice of drinks - print 0" << endl;
            cin >> choice;
        }
    }
    else{
        cout << "Incorrect.\n";
    }
}
void Automata::choice() {
    if (this->getState() == STATES::ACCEPT){
        cout << "please, input a number a drink\n";
        int choice;
        cin >> choice;
        choice--;
        this->setState(STATES ::CHECK);
        if (check(choice)){
            cook(choice);
        }
        else{
            cout << "A lack of cash\n";
            cancel();
        }
    }
    else{
        cout <<"Incorrect.\n";
    }

}
bool Automata::check(int choice) {
    if (this->getCash() >= Automata::prices[choice]){
        return true;
    }else{
        return false;
    }
}
void Automata::cook(int choice) {
    this->setState(STATES ::COOK);
    this->setCash(this->getCash()- Automata::prices[choice]);
    cout << "Cooking: "<<Automata::menu[choice]<<endl;
    cout << "Done! Take your cup\n";

    Automata::finish();
}
void Automata::finish() {
    this->setState(STATES ::WAIT);
}
void Automata::cancel() {
    if (this->getState() != STATES ::OFF)
        this->setState( STATES ::WAIT);
    else{
        cout << "Incorrect. Sorry, automat is off\n";
    }
}
void Automata::off() {
    if (this->getState() == STATES::WAIT){
        cout << "Take your change "<< this->getCash() << " rubles\n";
        this->setState(STATES::OFF);
        cout << "Automat is off\n";
    }else{
        cout << "Incorrect.";
    }
}
int Automata::getCash(){
    return this->cash;
}
STATES Automata::getState() {
    return this->state;
}
void Automata::setCash(int cash){
    this->cash = cash;
}
void Automata::setState(STATES state) {
    this->state = state;

}
