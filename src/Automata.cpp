//
// Created by Yakhtin Leonid on 17.12.2019.
//

#include "Automata.h"
#include <iostream>

vector<string> Automata::STATE_DESCRIPTION = { "OFF", "WAIT", "ACCEPT", "CHECK", "COOK" };
vector<Drink>Automata::menu = { {"Espresso", 1}, {"Americano", 2}, {"Cappuccino", 3}, {"Latte", 4}, {"Macchiato", 5}, {"Ristretto", 6}, {"Lungo", 7} };

Automata::Automata() {
    cash = 0;
    state = OFF;
	drink_for_prep = -1;
}

void Automata::on(){
    state = WAIT;
}

void Automata::off(){
	cancel();
    state = OFF;
}

bool Automata::coin(int coins) {
	if (state == ACCEPT || state == WAIT || state == CHECK) {
		drink_for_prep = -1;
		state = ACCEPT;
		cash += coins;
		return true;
	}
	else {
		return false;
	}
}

void Automata::printMenu(std::ostream& out){
	for (size_t i = 0; i < menu.size(); i++) {
		out << i << ")" << " " << menu[i].name << " " << menu[i].price << "$\n";
	}
}

string Automata::getMenu() {
	string result = "";
	for (size_t i = 0; i < menu.size(); i++) {
		result+=std::to_string(i) + ") " + menu[i].name + " " + std::to_string(menu[i].price) + "$\n";
	}
	return result;
}
string Automata::printState() {
	return STATE_DESCRIPTION[state];
}

//void Automata::printState(std::ostream& out) {
//	return STATE_DESCRIPTION[state] << '\n';
//}

bool Automata::choice(int index) {
	if ((state == CHECK || state == ACCEPT) && 0 <= index && index < menu.size()) {
		drink_for_prep = -1;
		state = CHECK;
		return check(index);
	}
	return false;
}

bool Automata::check(int index) {
	if (cash >= menu[index].price) {
		drink_for_prep = index;
		return true;
	}
	else {
		state = ACCEPT;
		return false;
	}
}

void Automata::cancel() {
	std::cout << "Take your cash: " << cash << '\n';
	cash = 0;
	state = WAIT;
	drink_for_prep = -1;
}

bool Automata::cook() {
	if (state == CHECK && drink_for_prep != -1) {
		std::cout << "...sounds of cooking..." << '\n';
		state = COOK;
		cash -= menu[drink_for_prep].price;
		finish();
		return true;
	}
	std::cout << "Can't cook because the drink isn't selected" << '\n';
	return false;
}

void Automata::finish() {
	std::cout << "You can take your " << menu[drink_for_prep].name << " "<<"and remains cash "<<cash<<'\n';
	cash = 0;
	drink_for_prep = -1;
	state = WAIT;
}

int Automata::getCash() {
	return cash;
}
