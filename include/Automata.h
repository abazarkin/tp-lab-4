//
// Created by Оксана on 12.01.2020.
//

#ifndef TASK1_AUTOMATA_H
#define TASK1_AUTOMATA_H

//#include <iostream>
#include <vector>
#include <string>
using namespace std;


enum States{
    OFF, WAIT, ACCEPT, CHECK, COOK
};

class Automata {
public:
    Automata();
    void on();
    void off();
    void coin(unsigned int); //занесение денег на счёт пользователем
    void printMenu(); //отображение меню с напитками и ценами для пользователя
    void printState(); //отображение текущего состояния для пользователя
    void choice(unsigned int); //выбор напитка пользователем
    bool check(int); //проверка наличия необходимой суммы
    void cancel(); //отмена сеанса обслуживания пользователем
    void cook(int); //имитация процесса приготовления напитка
    void finish();  //завершение обслуживания пользователя
    unsigned int getChange();  //сдача
    States getState(); //статус




private:
    int cash; //текущая сумма
    vector<string> menu = {"Black tea", "Green tea", "Cocoa", "Hot chocolate", "Milk"};
    vector<int> prices = {40, 40, 55, 50, 25};
    States state; //текущее состояние автомата
    vector<string> stateNames = {"OFF", "WAIT", "ACCEPT", "CHECK", "COOK"};
};


#endif //TASK1_AUTOMATA_H
