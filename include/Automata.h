//
// Created by Mary on 25.11.2019.
//
#include <vector>
#include <string>
#include <map>
#ifndef TASK1_AUTOMATA_H
#define TASK1_AUTOMATA_H

enum STATES{
    OFF, WAIT, ACCEPT, CHECK, COOK
};

using namespace std;
class Automata {
private:
    int cash;
    static string menu[9];
    static int prices[9];
    STATES state;
    bool check(int choice); // проверка наличия необходимой суммы
    void cook(int choice); // имитация процесса приготовления напитка
    void finish(); // завершение обслуживания пользователя


    void setCash(int cash);
    void setState(STATES state);
public:
    //void start();
    Automata();// конструктор
    void on(); // включение автомата
    void off(); // выключение автомата
    void coin(); // занесение денег на счёт пользователем
    void printMenu(); //  отображение меню с напитками и ценами для пользователя
    void choice(); // выбор напитка пользователем
    void cancel(); // отмена сеанса обслуживания пользователем
    STATES getState();
    int getCash();
};



#endif //TASK1_AUTOMATA_H
