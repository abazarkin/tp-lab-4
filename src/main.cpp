//
// Created by Mary on 25.11.2019.
//
#include <iostream>
#include "Automata.h"
using namespace std;
int main(){
    Automata automata;
    cout <<automata.getState();

    Automata Auto = Automata();
    int command = 0;
    while (command != 6){
        cout <<"0 - OFF\n1-COIN\n2-CHOOSE THE DRINK\n3-PRINT A MENU\n4-CANCEL\n5-ON\n6-finish the program\n";
        cin >> command;
        if (command == 0){
            Auto.off();
        }
        else if (command == 1){
            Auto.coin();
        }
        else if (command == 2){
            Auto.choice();
        }
        else if (command == 3){
            Auto.printMenu();
        }
        else if (command == 4){
            Auto.cancel();
        }
        else if (command == 5){
            Auto.on();
        }
    }
    return 0;
}