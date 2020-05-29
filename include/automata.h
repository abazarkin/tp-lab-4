#ifndef COFFEEMACHINE_AUTOMATA_H
#define COFFEEMACHINE_AUTOMATA_H
#include <string>
using namespace std;

enum STATES{
    OFF,WAIT,ACCEPT,CHECK,COOK
};

class Automata{
private:
    double cash;    // для хранения текущей суммы
    static string menu[10];
    static double prices[10];
    STATES state;   //текущее состояние автомата
public:
    Automata();
    void on();
    void off();
    void coin(double money);
    void printMenu();
    void printState();
    void choice(int typeOfDrink);
    bool check(int typeOfDrink);
    void cancel();
    void cook(int typeOfDrink);
    void finish();
    double getCash();
    STATES getState();
};

#endif //COFFEEMACHINE_AUTOMATA_H
