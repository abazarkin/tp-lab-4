#include "Automata.h"

using namespace std;

Automata::Automata()
{
    this->menu = new Drink[5];
    this->menu[0].setName("Coffee");
    this->menu[0].setPrice(50);
    this->menu[1].setName("Tea");
    this->menu[1].setPrice(25);
    this->menu[2].setName("Cacao");
    this->menu[2].setPrice(30);
    this->menu[3].setName("Green tea");
    this->menu[3].setPrice(25);
    this->menu[4].setName("Coffee with cream");
    this->menu[4].setPrice(60);
}

void Automata::showMenu(){
    string exmpl = "....----''''Automata drink machine''''----....\n";
    cout << exmpl;
    cout << "               Here is our menu:              \n";
    for(int i = 0; i < 5; i++){
        cout << i<<'.' <<this->menu[i].getName();
        for(int j = 0; j < exmpl.length() - menu[i].getName().length() - 5; j++){
            cout << '.';
        }
        cout << this->menu[i].getPrice() << '\n';
    }
}

void Automata::coin(){
    if(curSt == wait || curSt == accept){
        cout << "Insert your coins: ";
        int ammC;
        cin >> ammC;
        this->cash += ammC;
        this->curSt = accept;
    }else{
        cout << "You can't insert cash now\n";
    }
}

void Automata::choice(){
    if(curSt == accept){
        int drNum;
        cout << "Enter a number of drink: ";
        cin >> drNum;
        this->curSt = STATE::check;
        if(drNum > -1 && drNum < 5 && check(drNum)){
            this->cash -= this->menu[drNum].getPrice();
            cook();
        }else{
            cout << "Not enough cash or incorrect choice\n";
            cancel();
        }
    }else{
        cout << "Check your action order. It's not a time to choose a drink\n";
    }
}

bool Automata::check(int chDr){
    if(this->menu[chDr].getPrice() <= this->cash){
        return true;
    }
    return false;
}

void Automata::cook(){
    if(curSt == STATE::check){
        this->curSt = STATE::cook;
        cout << "             Here is your drink            \n";
        cout << "              __________________           \n";
        cout << "             (                  )          \n";
        cout << "              |^^^^^^^^^^^^^^^^|           \n";
        cout << "               |              |           \n";
        cout << "               |*Automata'co.*|            \n";
        cout << "               |              |            \n";
        cout << "               |              |            \n";
        cout << "               |______________|            \n";
        cout << "Be careful drink is hot!\n";
    }else{
        cout << "Check your action order.\n";
    }
}

void Automata::finish(){
    if(curSt == STATE::cook){
        cout << "Here is your change: " << this->cash <<' ' << "Have a nice day!"<<'\n';
        this->cash = 0;
        this->curSt = wait;
        showMenu();
    }else{
        cout << "Incorrect order";
    }
}

void Automata::cancel(){
    this->curSt = wait;
    cout << "Take your cash: " << this->cash << '\n';
    this->cash = 0;
}
