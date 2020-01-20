#pragma once

#include <vector>
#include <string>
struct Drink{
    std::string name;
    unsigned int price;
};
class Automata{
public:
    Automata(const std::vector<Drink>&);
    void on();
    void off();
    unsigned int coin(unsigned int);
    void printMenu();
    void printState();
    bool choice(unsigned int);
    bool check(unsigned int);
    unsigned int cancel();
    void cook();
    void finish();
private:
    enum STATES {OFF, WAIT, ACCEPT, CHECK, COOK, FINISH, NOT_ENOUGH_MONEY};
    std::vector<std::string> string_STATES = { "OFF", "WAIT", "ACCEPT", "CHECK", "COOK", "FINISH", "NOT ENOUGH MONEY" };
    unsigned int cash = 0;
    STATES state = STATES::OFF;
    std::vector<Drink> menu;
    bool isOn();
};