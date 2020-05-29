//
// Created by aklen on 17.12.2019.
//
#include "Automata.h"
#include <iostream>
using namespace std;

int main(){
    Automata my_purchase;
    my_purchase.on();
    my_purchase.printMenu();
    my_purchase.coin(100);
    my_purchase.coin(50);
    cout<<my_purchase.getCash()<<endl;
    //my_purchase.refund_of_money();
    //cout<<my_purchase.getCash()<<endl;
    my_purchase.choice(1);
    //my_purchase.cook();
    my_purchase.cancel();
    //my_purchase.finish();
}