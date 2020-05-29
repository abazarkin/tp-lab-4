//
// Created by aklen on 17.12.2019.
//
#include "Automata.h"
#include "string.h"
using namespace std;

void Automata::on(){
    state = WAIT;
    cout<<"Machine the process started"<<endl;
}

void Automata::off(){
    if(state==WAIT){
        state=OFF;
        cout<<"The process finished"<<endl;
    }
    else{
        cout<<"The state of machine is supposed to be WAIT"<<endl;
        state=ERROR;
    }
}

STATES Automata::printState(){
    switch (state)
    {
        case(OFF):
            cout<<"The state of the machine is OFF"<<endl;
            return OFF;
        case (WAIT):
            cout<<"Waiting..."<<endl;
            return WAIT;
        case (ACCEPT):
            cout<<"Insert ur money"<<endl;
            return ACCEPT;
        case (CHECK):
            cout<<"Cash is checking, wait please"<<endl;
            return CHECK;
        case (COOK):
            cout<<"The product is cooking"<<endl;
            return COOK;
        case (ERROR):
            cout<<"Error!"<<endl;
            return state = ERROR;
    }
}

void Automata::coin(int deposit) {
    if (state == WAIT || state == ACCEPT){
        state = ACCEPT;
        cash += deposit ;
        cout<<"The current balance: " << getCash() <<endl;
    }
    else if ((state != CHECK)){
        cout << "The state of the machine is supposed to be ACCEPT, WAIT or CHECK.\n"
                "Try again, please!"<<endl;
        state = ERROR;
    }

}

void Automata::printMenu(){
    cout<<"Menu:\n";
    for (int i=0;i<N;i++){
        cout<<i+1<<"."<<menu[i]<<" - "<<prices[i]<<endl;
    }
}

void Automata::choice(int step){
    if(state==ACCEPT)
        state = CHECK;
    else{
        cout<<"The state of machine is supposed to be ACCEPT"<<endl;
        state = ERROR;
        return;
    }
    position = step;
    if(step>N){
        cout<<"There are only 5 products, please try again"<<endl;
        state = ERROR;
        return;
    }
    cout<<"Your choice is: "<< menu[step]<<"\nPrice is "<<prices[step]<<endl;
}

bool Automata::check(){
    return(cash>=prices[position]);
}

void Automata::cook(){
    if(state==CHECK || state == ACCEPT){
        if(check()){
            cash -=prices[position];
            state = COOK;
            cout<<"The product is cooking"<<endl;
        }
        else{
            cout<<"Sorry, u dont have enough money"<<endl;
        }
    }
    else{
        cout<<"The state of machine is supposed to be CHECK or ACCEPT"<<endl;
        state = ERROR;
        return;
    }
}
 int Automata::getCash(){
    return cash;
}

void Automata::refund_of_money(){
    cout<<"Take ur money:"<<cash<<endl;
    cash=0;
}

void Automata::cancel(){
    if ((state != ACCEPT) &&(state != CHECK)) {
        cout << "The state of the machine is supposed to be ACCEPT or CHECK"<<endl;
        state = ERROR;
    } else if (cash == 0) {
        state = WAIT;
    } else {
        cout<<"Offer canceled\n";
        refund_of_money();
        state = WAIT;
    }
}

void Automata::finish(){
    if(state == COOK){
        state = WAIT;
        cout<<"Get ur drink"<<endl;
        refund_of_money();
    }
    else{
        cout<<"The state of machine is supposed to be COOK";
        state = ERROR;
    }
}