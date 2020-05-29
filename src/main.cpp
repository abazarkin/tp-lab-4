//
// Created by Оксана on 14.01.2020.
//
#include <iostream>
#include <vector>
//#include "windows.h"
#include "Automata.h"


int main(){
    auto t = Automata();
    t.on();
    t.coin(10);
    t.choice(3);
    t.coin(100);
    t.choice(3);
    int res = t.getChange();
    return 0;
}