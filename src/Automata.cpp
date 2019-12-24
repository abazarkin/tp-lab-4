#include "Automata.h"

Automata::Automata(){ // конструктор
    state = STATES::OFF;
    cash = 0;
}

void Automata::on(){ // включение автомата
    if (state == STATES::OFF){
        state = STATES::WAIT;
        cout << "The automata is on.\n";
    }
    else{
        cout << "It's already on.\n";
    }
}

void Automata::off(){ // выключение автомата
    if (state == STATES::WAIT){
        state = STATES::OFF;
        cout << "The automata is off.\n";
    }
    else{
        cout << "To turn of the automata you should go to the waiting state.\n";
    }
}

void Automata::coin(int money){ // занесение денег на счёт пользователем;
    if (state == STATES::ACCEPT || state == STATES::WAIT) {
        if (money > 0){
            cash += money;
            state = STATES::ACCEPT;
            cout << money << " rubles were added." << endl;
            cout << "Now you have " << cash << " rubles" << endl;
        }
        else{
            cout << "Please, add any money.\n";
        }
    }
    else{
        cout << "You cannot add money in this state.\n";
    }
}

void Automata::printMenu(){ // отображение меню с напитками и ценами для пользователя
    cout.width(7);
    cout << "Number ";
    cout.width(8);
    cout << "Product";
    cout.width(11);
    cout << "Price" << endl;
    for (int i = 1; i < menu.size(); i++)    {
        cout.width(7);
        cout << i;
        cout.width(8);
        cout << menu[i];
        cout.width(8);
        cout << prices[i] << " rub" << endl;
    }
}

void Automata::printState(){ // отображение текущего состояния для пользователя;
    cout << state << endl;
}

void Automata::choice(int drink_number){ // выбор напитка пользователем
    if (drink_number <= menu.size() && drink_number >= 1) {
       if (check(drink_number)){
           cook(drink_number);
           finish();
       }
       else {
           cout << "Not enough money." << endl;
           cout << "You have only " << cash << " rubles" << endl;
           cancel();
       }
    }
    else{
        cout << "Invalid drink number.\n";
    }
}

bool Automata::check(int drink_number) { // проверка наличия необходимой суммы
    state = STATES::CHECK;
    if (prices[drink_number] <= cash) {
        return true;
    }
    else {
        return false;
    }
}

void Automata::cancel() { // отмена сеанса обслуживания пользователем
    if (state == STATES::ACCEPT || state == STATES::CHECK) {
        state = STATES::WAIT;
        cout << "The action is cancelled." << endl;
    }
    else {
        if (state == STATES::OFF){
            cout << "The automata is off.\n";
        }
        if (state == STATES::WAIT){
            cout << "The automata is waiting for action.\n";
        }
    }
}

void Automata::cook(int drink_number) { // имитация процесса приготовления напитка
    state = STATES::COOK;
    cash -= prices[drink_number];
    cout << "The drink is ready. Take your order.\n";
}

void Automata::finish(){ // завершение обслуживания пользователя
    state = STATES::WAIT;
}

